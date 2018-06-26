#include <stdio.h>
#include <iostream>

#include "../../include/cpp-exercises/Solution.h"

// ---------------------------------------------------------------------------------------------------------------------- //
// Add One To Number (https://www.interviewbit.com/problems/add-one-to-number/)
//  
// Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by 
// the digits ).
// The digits are stored such that the most significant digit is at the head of the list.
//
// Example:
//  If the vector has [1, 2, 3] the returned vector should be [1, 2, 4] as 123 + 1 = 124.
//
// NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
// For example, for this problem, following are some good questions to ask :
//  Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
//  A : For the purpose of this question, YES
//  Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
//  A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
// ---------------------------------------------------------------------------------------------------------------------- //

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