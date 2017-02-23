#include "gtest/gtest.h"

#include "../include/cpp-exercises/Solution.h"

/* Compare actual value with expected. */
inline void compare(std::vector<int> &input, 
            std::vector<int> &output_expected) 
{
  unsigned int size = output_expected.size();

  std::vector<int> output_actual = Solution::plusOne(input);

  EXPECT_EQ(output_actual.size(), size);
    
  for (int i = 0; i < size; i++) {
    EXPECT_EQ(output_actual[i], output_expected[i]);
  }
}


TEST(plusOne_test, single_digit_number)
{
  std::vector<int> input;
  std::vector<int> output;
  
  // ---------- 1 + 1 = 2 ---------- //
  input.push_back(1);
  output.push_back(2);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();

  // ---------- 9 + 1 = 10 ---------- //
  input.push_back(9);
  output.push_back(1);
  output.push_back(0);
  
  compare(input, output);   
}

TEST(plusOne_test, numbers_with_zeros)
{
  std::vector<int> input;
  std::vector<int> output;
  
  // ---------- 0 + 1 = 1 ------------- //
  input.push_back(0);
  output.push_back(1);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();  
  
  // ---------- 01 + 1 = 2 ------------ //
  input.push_back(0);
  input.push_back(1);
  output.push_back(2);
  
  compare(input, output);   
  
  // Clear vectors
  input.clear();
  output.clear();  
  
  // ---------- 10 + 1 = 11 ----------- //
  input.push_back(1);
  input.push_back(0);
  output.push_back(1);
  output.push_back(1);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();  
  
  // ---------- 010 + 1 = 11 ---------- //
  input.push_back(0);
  input.push_back(1);
  input.push_back(0);
  output.push_back(1);
  output.push_back(1);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();  
  
  // ---------- 000 + 1 = 1 ----------- //
  input.push_back(0);
  input.push_back(0);
  input.push_back(0);
  output.push_back(1);
  
  compare(input, output);   
}

TEST(plusOne_test, numbers_with_nines)
{
  std::vector<int> input;
  std::vector<int> output;
  
  // ---------- 99 + 1 = 100 ---------- //
  input.push_back(9);
  input.push_back(9);
  output.push_back(1);
  output.push_back(0);
  output.push_back(0);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();   
  
  // ---------- 69 + 1 = 70 ----------- //
  input.push_back(6);
  input.push_back(9);
  output.push_back(7);
  output.push_back(0);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();     
  
  // ---------- 079 + 1 = 80 ---------- //
  input.push_back(0);
  input.push_back(7);
  input.push_back(9);
  output.push_back(8);
  output.push_back(0);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear(); 
  
  // ---------- 0089 + 1 = 90 --------- //
  input.push_back(0);
  input.push_back(0);
  input.push_back(8);
  input.push_back(9);
  output.push_back(9);
  output.push_back(0);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear(); 
  
  // ---------- 0090 + 1 = 91 --------- //
  input.push_back(0);
  input.push_back(0);
  input.push_back(9);
  input.push_back(0);
  output.push_back(9);
  output.push_back(1);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear(); 
  
  // ---------- 9000 + 1 = 9001 ------- //
  input.push_back(9);
  input.push_back(0);
  input.push_back(0);
  input.push_back(0);
  output.push_back(9);
  output.push_back(0);
  output.push_back(0);
  output.push_back(1);
  
  compare(input, output);   
}

TEST(plusOne_test, many_digits_number)
{
  std::vector<int> input;
  std::vector<int> output;
  
  // ---------- 0012 + 1 = 13 --------- //
  input.push_back(0);
  input.push_back(0);
  input.push_back(1);
  input.push_back(2);
  output.push_back(1);
  output.push_back(3);
  
  compare(input, output);   
  
  // ---------------------------------- //
  input.clear();
  output.clear();   
  
  // ---------- 0030 + 1 = 31 --------- //
  input.push_back(0);
  input.push_back(0);
  input.push_back(3);
  input.push_back(0);
  output.push_back(3);
  output.push_back(1);
  
  compare(input, output);   
}

