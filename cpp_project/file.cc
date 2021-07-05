#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
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