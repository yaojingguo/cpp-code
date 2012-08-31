// This code shows how C++ implement dynamic function 
// lookup. Use "g++ -S" to generate dynamic.s. Reading dynamic.cpp and 
// dynamic.s gives a good understanding of C++'s dynamic function lookup 
// implementation.
// The following diagrams show Weapon and Bomber objects' runtime representation:
//
// Weapon object
// =============
//                          Weapon vtable 
//       +--------+        +-------------------------+
//   vptr|        |------->| invalid addr of kill    |
//       +--------+        +-------------------------+     +-----------------------+
//   no  |   9    |        | addr of Weapon's save   |---->| code of Weapon's save |
//       +--------+        +-------------------------+     +-----------------------+
//   sex |        |
//       +--------+
//
//
// Bomber object
// =============
//                          Bomber vtable 
//       +--------+        +-----------------------+      +-----------------------+
//   vptr|        |------->| addr of Bomber's kill |----->| code of Bomber's save |
//       +--------+        +-----------------------+      +-----------------------+
//   no  |   9    |        | addr of Bomber's save |----+
//       +--------+        +-----------------------+    +     +-----------------------+
//   sex |        |                                     +---->+ code of Bomber's save |
//       +--------+                                           +-----------------------+
//  bomb |        |
//       +--------+
//
// There is another alternative to implement dynamic function lookup in my mind.
//
// Weapon object
// =============
// +---------------------+
// |no                   |
// +---------------------+
// |sex                  |
// +---------------------+
// |invalid addr of kill |
// +---------------------+
// |addr of Weapon's save|
// +---------------------+
//
// Bomber object
// =============
// +---------------------+
// |no                   |
// +---------------------+
// |sex                  |
// +---------------------+
// |addr of Bomber's kill|
// +---------------------+
// |addr of Bomber's save|
// +---------------------+
// |bomb                 |
// +---------------------+
// This approach avoid indirection caused by vtable. But it use more space since it saves
// function address in every object.
class Weapon {  
  public:
    Weapon() {
      no = 9;
    }
    virtual int kill(int n) = 0;
    virtual int save(int n) {
      return n + 1; 
    }
  private:
    int no;
    int country;
};

class Bomber : public Weapon {
  public:
    Bomber() {
      bomb = 99;
    }
    int kill(int n);
  public:
    int bomb;
};

int
Bomber::kill(int n)
{
  if (n > 10)
    return n - 10;
  else
    return 0;
}

int main(int argc, const char *argv[]) 
{
  int reminder;
  Weapon* w = new Bomber();
  reminder = w->kill(10);
  return reminder;
}
