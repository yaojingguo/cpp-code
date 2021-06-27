#include <iostream>
#include "httplib.h"

int main(int argc, char const *argv[])
{
  httplib::Client cli("http://localhost:8080");

  auto res = cli.Get("/hi");

  std::cout << "status: " << res->status << ", body: " << res->body << std::endl;
  
  return 0;
}
