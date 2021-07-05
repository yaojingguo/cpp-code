#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int one() {
  int is_ok = EXIT_FAILURE;
  FILE* fp = fopen("test.txt", "r");
  if (!fp) {
    perror("failed to open file");
  }

  int c;
  while ((c = fgetc(fp)) != EOF) {
    putchar(c);
  }
  putchar('\n');

  if (ferror(fp)) {
    puts("I/O error when reading");
  } else if (feof(fp)) {
    puts("EOF reached successfully");
  }

  fclose(fp);
  return is_ok;
}

void two() {
  string filename = "test.bin";
  fstream s(filename, s.binary | s.trunc | s.in | s.out);

  if (!s.is_open()) {
    cout << "failed to open " << filename << endl;
  } else {
    double d = 3.14;
    s.write(reinterpret_cast<char*>(&d), sizeof(d));
    s << 123 << "abc";

    s.seekp(0);
    
    s.read(reinterpret_cast<char*>(&d), sizeof(d));
    int n;
    string str;
    if (s >> n >> str) {
      cout << "read back from file: " << d << " " << n << " " << endl;
    }
  } 
}

int main() {
  two();
}

// C++ file system API
// System call
// C I/O library
// fstream