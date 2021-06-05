#include "httplib.h"

int main(int argc, char const *argv[])
{
  httplib::Server srv;

  srv.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
    res.set_content("Hello World!", "text/plain");
  });
  return 0;
}
