#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef std::vector<std::string> StringVector;
// Const cannot be used, since we are changing the vector
// bool myMethod(const StringVector &input, StringVector &output) {
bool myMethod(StringVector &input, StringVector &output) {
  StringVector::iterator first = find(input.begin(), input.end(), "Fabiano");
  StringVector::iterator last = find(input.begin(), input.end(), "Vector");
  *last = "Victor";
  for (StringVector::iterator it = first; it != last; ++it) {
    std::cout << *it << std::endl;
  }
  // A clearer notation:
  //input.insert(--(input.end()), "XXX");
  input.pop_back();       // Remove last element
  input.push_back("XXX"); // Add XXX as last element
  // if (first != input.end())  // Always true, since first -> "Fabiano", end -> "XXX"
    std::cout << *first << std::endl;
  // Vectorized operations runs faster than iterating over the vector
//  for (StringVector::iterator it = input.begin(); it != input.end(); ++it) {
//    output.push_back(*it);
//  }
  output.insert(output.end(), input.begin(), input.end());
  return true;
}
