#include <iostream>
#include <fstream>

#include "gtest/gtest.h"

using namespace std;

TEST(File, Write) {
  cout << "Running..." << endl;
  ofstream out("foo", ios_base::app);
  out << "Go\n";
}