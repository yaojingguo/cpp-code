#include <pthread.h>
#include <assert.h>
#include <stdio.h>

#define N 3

class BoundedBuffer {
  private:
    int buffer[N];
    int last_position;
    int count;

    pthread_mutex_t mutex;
    pthread_cond_t non_full;
    pthread_cond_t non_empty;

  public:
    BoundedBuffer();
    ~BoundedBuffer();
    int remove();
    void append(int item);
};

BoundedBuffer::BoundedBuffer() : last_position(0), count(0) {
  assert(pthread_mutex_init(&mutex, NULL) == 0);
  assert(pthread_cond_init(&non_full, NULL) == 0);
  assert(pthread_cond_init(&non_empty, NULL) == 0);
}

BoundedBuffer::~BoundedBuffer() {
  assert(pthread_mutex_destroy(&mutex) == 0);
  assert(pthread_cond_destroy(&non_full) == 0);
  assert(pthread_cond_destroy(&non_empty) == 0);
}

int BoundedBuffer::remove() {
  int item;
  assert(pthread_mutex_lock(&mutex) == 0);
  printf("buffer remove\n");
  while (count == 0)
    assert(pthread_cond_wait(&non_empty, &mutex) == 0);
  printf("===========\n");
  item = buffer[(last_position - count) % N];
  count--;
  pthread_cond_signal(&non_full);
  assert(pthread_mutex_unlock(&mutex) == 0);
  return item;
}

void BoundedBuffer::append(int item) {
  assert(pthread_mutex_lock(&mutex) == 0);
  while (count == N)
    assert(pthread_cond_wait(&non_full, &mutex) == 0);
  buffer[last_position % N] = item;
  last_position++;
  count++;
  assert(pthread_cond_signal(&non_empty) == 0);
  assert(pthread_mutex_unlock(&mutex) == 0);
}

static void append(BoundedBuffer& buf, int item) {
  printf("appending: %d...\n", item);
  buf.append(item);
}

static void remove(BoundedBuffer& buf) {
  int item;
  printf("removing\n");
  item = buf.remove();
  printf("removed: %d\n", item);
}

static void test1() {
  BoundedBuffer buf;

  append(buf, 1);
  append(buf, 2);
  append(buf, 3);

  remove(buf);
  remove(buf);
}

static void test2() {
  BoundedBuffer buf;
  remove(buf);
}

void *run(void *buf_p) {
  BoundedBuffer buf = *((BoundedBuffer*) buf_p);
  remove(buf);
  pthread_exit(NULL);
}

static void test3() {
  pthread_t t;
  BoundedBuffer buf;
  assert(pthread_create(&t, NULL, run, &buf) == 0);
  append(buf, 1);
  append(buf, 2);
  append(buf, 3);
}

int main(int argc, const char *argv[]) {
  // test2();
  test3();
  
  pthread_exit(NULL);
}
