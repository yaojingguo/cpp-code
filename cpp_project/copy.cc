#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm> 

using namespace std;

int main() {
  vector<int> from_vector(10);
  iota(from_vector.begin(), from_vector.end(), 1);

  vector<int> to_vector(4);

  copy(from_vector.begin(), from_vector.begin() + 4, to_vector.begin());

  for (int v: to_vector) {
    cout << v << endl;
  }
}