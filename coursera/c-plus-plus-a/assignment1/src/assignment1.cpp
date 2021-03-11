// assignment1.cpp : Defines the entry point for the application.
//
/*   Convert this program to C++
*   change to C++ io
*   change to one line comments
*   change defines of constants to const
*   change array to vector<>
*   inline any short function
*/
#include <iostream>
#include <vector>
#include <numeric>

const int N = 40;

inline int sum(std::vector<int>& v) {
  return std::accumulate(v.begin(), v.end(), 0, [](int a, int b) { return a + b; });
}

int main() {
  {
    // Allocate vector of size N, fill with 0-39, sum with accumulator, printout
    std::vector<int> v(N);
    std::iota(v.begin(), v.end(), 0);    
    std::cout << "sum is " << sum(v) << std::endl;
  }

  return 0;
}
