#include <iostream>
#include <assert.h>

using namespace std;

#define LEN 4

class queue {
  private:
    int head;
    int tail;
    int buf[LEN];
    void increment(int&);
  public:
    queue() : head(0), tail(0) {}
    void enqueue(int);
    int dequeue();
    void info();
};

void queue::increment(int& ptr)
{
  if (ptr == LEN-1)
    ptr = 0;
  else
    ptr++;
}

void queue::enqueue(int x)
{
  assert(!((tail + 1) % LEN == head));
  buf[tail] = x;
  increment(tail);
}

int queue::dequeue()
{
  assert(!(head == tail));
  int x = buf[head];
  increment(head);
  return x;
}

void queue::info()
{
  cout << "head: " << head << ", tail: " << tail << endl;
}

int main(int argc, const char *argv[]) 
{
  queue q;
  q.enqueue(1);
  q.enqueue(2);
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  q.enqueue(10);
  cout << q.dequeue() << endl;
  q.info();
  q.enqueue(100);
  q.info();
  return 0;
}
