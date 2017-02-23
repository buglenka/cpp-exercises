#include <stdio.h>
#include <iostream>

#include "../../include/cpp-exercises/Solution.h"


std::vector<int> Solution::plusOne(std::vector<int> &A) {
  std::vector<int> A_output;
  
  int A_size = A.size();
  int A_size_wo_0 = A_size;
  
  // check if there is no number
  if (A.empty()) return A;
  
  // check if there is any 0s in the beginning of the number 
  // and omit them
  int count_head_0 = 0;
  for (int i = 0; i < A_size; i++) {
      if (A[i] == 0) {
          count_head_0++;
      } else 
          break;
  }
  
  // define actual size of the number
  if (count_head_0 != 0)
      A_size_wo_0 = A_size - count_head_0;
  
  // the number contains only 0s
  if (count_head_0 == A_size) {
      A_output.push_back(1);
      
      return A_output;
  }

  // check how many 9 are in the tail of the number
  // start from the least significant digit and go to the head of the list
  int count_tail_9 = 0;
  for (int i = A_size - 1; i >= count_head_0; i--) {
      if (A[i] == 9) {
          count_tail_9++;
      } else 
          break;
  }
  
  // the number consists only 9s 
  if (count_tail_9 == A_size_wo_0) {
      // create the list with 1 and 0s
      A_output.assign(A_size_wo_0 + 1, 0);
      A_output[0] = 1; // the most significant digit
  } else if(count_tail_9 == 0) {
      A_output.assign(A.begin() + count_head_0, A.end());
      A_output[A_size_wo_0 - 1]++;
  } else { // the number includes some 9s in the tail
      A_output.reserve(A_size_wo_0);
      A_output.assign(A.begin() + count_head_0, A.end() - count_tail_9);
      A_output[A_size_wo_0 - count_tail_9 - 1]++;
      
      // instead 9s in tail will be 0s
      A_output.insert(A_output.end(), count_tail_9, 0);  
  }
  
  return A_output;
}