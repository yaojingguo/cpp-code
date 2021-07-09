#include <cxxabi.h>    // for __cxa_demangle
#include <dlfcn.h>     // for dladdr
#include <execinfo.h>  // for backtrace
#include <sstream>
#include <string>
#include <iostream>

void a();
void b();
void c();
std::string Backtrace(int skip);

void a() {
  b();
}
void b() {
  c();
}
void c() {
  std::string trace = Backtrace(1);
  std::cout << trace << std::endl;
}
int main() {
  a();
}

// A C++ function that will produce a stack trace with demangled function and
// method names.
std::string Backtrace(int skip = 1) {
  void *callstack[128];
  const int nMaxFrames = sizeof(callstack) / sizeof(callstack[0]);
  char buf[1024];
  int nFrames = backtrace(callstack, nMaxFrames);

  std::ostringstream trace_buf;
  for (int i = skip; i < nFrames; i++) {
    Dl_info info;
    if (dladdr(callstack[i], &info)) {
      char *demangled = NULL;
      int status;
      demangled = abi::__cxa_demangle(info.dli_sname, NULL, 0, &status);
      printf("%s, 0x%p\n", info.dli_fname, info.dli_fbase);
      snprintf(buf, sizeof(buf), "%-3d %*p %s + %zd\n", i,
               (int)(2 + sizeof(void *) * 2), callstack[i],
               status == 0 ? demangled : info.dli_sname,
               (char *)callstack[i] - (char *)info.dli_saddr);
      printf("offset: %ld\n",  (char *)info.dli_saddr - (char*) info.dli_fbase);
      free(demangled);
    } else {
      snprintf(buf, sizeof(buf), "%-3d %*p\n", i, (int)(2 + sizeof(void *) * 2),
               callstack[i]);
    }
    trace_buf << buf;
  }

  if (nFrames == nMaxFrames) trace_buf << "  [truncated]\n";
  return trace_buf.str();
}