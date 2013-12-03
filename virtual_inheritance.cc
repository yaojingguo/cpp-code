// http://www.cprogramming.com/tutorial/virtual_inheritance.html


// Use virtual inheritance to remove compile error.

class storable {
  public:
    virtual void read() {}
    virtual void write() {}
    virtual ~storable() {}
};

class transmitter: public storable {
// class transmitter: virtual public storable {
}; 

class receiver: public storable {
// class receiver: virtual public storable {
};

class radio: public transmitter, public receiver {
};

int main(int argc, const char *argv[]) 
{
  radio r; 
  r.write();
  return 0;
}
