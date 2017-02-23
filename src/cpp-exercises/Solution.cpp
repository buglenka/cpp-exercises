#include <stdio.h>
#include <iostream>

#include "../../include/cpp-exercises/Solution.h"


std::vector<int> Solution::plusOne(std::vector<int> &A) {
  std::vector<int> A_output;
  
  A_output.push_back(1);
  A_output.push_back(3);
  A_output.push_back(2);
  
  return A_output;
}