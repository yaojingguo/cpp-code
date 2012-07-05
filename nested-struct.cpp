class container {
  // Default modifier is private
  public:
    struct dirent {
      char * name;
    };
};

struct entity {
  int no;
};

int main(int argc, const char *argv[]) 
{
  struct container::dirent instance1; 
  container::dirent instance2;

  struct entity ent1;
  entity ent2;
  return 0;
}
