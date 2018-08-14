#include<pthread.h>
#include<stdio.h>
#include <unistd.h>
#include <assert.h>

pthread_key_t key;
pthread_once_t key_once = PTHREAD_ONCE_INIT;

void make_key(void) {
  printf("make_key\n");
  (void) pthread_key_create(&key, NULL);
}

void *thread(void *ptr) {
  // Thread type
  long type = (long) ptr;
  printf("Thread type: %ld\n", type);

  (void) pthread_once(&key_once, make_key);

  void* local_ptr;
  int* int_ptr;
  if ((local_ptr = pthread_getspecific(key)) == NULL) {
    local_ptr = malloc(sizeof(int));
    assert(local_ptr);
    int_ptr = (int*) local_ptr;
    // printf("---------------\n");
    if (type == 1) {
      *int_ptr = 100;
    } else if (type == 2) {
      *int_ptr = 200;
    }
    // printf("===============\n");
    (void) pthread_setspecific(key, local_ptr);
    // printf("+++++++++++++++\n");
  }

  for (int i = 0; i < 3; i++) {
    local_ptr = pthread_getspecific(key);
    // printf("aaaaaaaaaaaaaaaaa\n");
    assert(local_ptr);
    // printf("bbbbbbbbbbbbbbbbb\n");
    int_ptr = (int*) local_ptr;
    // printf("pointer: %p\n", int_ptr);
    // printf("ccccccccccccccccc\n");
    printf("loop value: %d\n", *int_ptr);
    sleep(1);
  }

  // printf("exit...\n");
  return NULL;
}

int main() {
  // Create the thread objs
  pthread_t thread1, thread2;
  long thr1 = 1;
  long thr2 = 2;

  // Start the threads
  pthread_create(&thread1, NULL, *thread, (void*) thr1);
  pthread_create(&thread2, NULL, *thread, (void*) thr2);

  // Wait for the threads to finish
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}

