#include <cxxabi.h>    // for __cxa_demangle
#include <dlfcn.h>     // for dladdr
#include <execinfo.h>  // for backtrace

#include <iostream>
#include <sstream>
#include <string>

void aaa();
void bbb();
void ccc();
std::string Backtrace(int skip);

void aaa() { 
  bbb();
}

void bbb() {
  int i = 10;
  std::cout << i << std::endl;
  ccc();
}

void ccc() {
  std::cout << 1 << std::endl;
  std::string trace = Backtrace(1);
  std::cout << trace << std::endl;
}
int main() { 
  aaa();
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
      // macOS uses this branch.
      char *demangled = NULL;
      int status;
      demangled = abi::__cxa_demangle(info.dli_sname, NULL, 0, &status);
      printf("0x%p, 0x%lx\n", info.dli_fbase, (char *)info.dli_saddr - (char *)info.dli_fbase);
      snprintf(buf, sizeof(buf), "%-3d %*p %s + %zd\n", i,
               (int)(2 + sizeof(void *) * 2), callstack[i],
               status == 0 ? demangled : info.dli_sname,
               (char *)callstack[i] - (char *)info.dli_saddr);
      free(demangled);
    } else {
      // Ubuntu 18.04 uses this branch.
      snprintf(buf, sizeof(buf), "%-3d %*p\n", i, (int)(2 + sizeof(void *) * 2),
               callstack[i]);
    }
    trace_buf << buf;
  }

  if (nFrames == nMaxFrames) trace_buf << "  [truncated]\n";
  return trace_buf.str();
}