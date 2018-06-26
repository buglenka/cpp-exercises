#include <stdio.h>
#include <iostream>

#include "../../include/cpp-exercises/Solution.h"

// ---------------------------------------------------------------------------------------------------------------------- //
// Two Sum Problem (https://leetcode.com/problems/two-sum/description/)
// 
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//  Given nums = [2, 7, 11, 15], target = 9,
//
//  Because nums[0] + nums[1] = 2 + 7 = 9,
//  return [0, 1].
// ---------------------------------------------------------------------------------------------------------------------- //

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    if (nums.empty()) return std::vector<int> ();
        
    int forward, backward;
    std::vector<int> result;
        
    for (forward = 0; forward < nums.size(); forward++) 
    for (backward = nums.size() - 1; forward < backward; backward--) {
        int sum = nums[forward] + nums[backward];

        if (sum == target) {
            result.push_back(forward);
            result.push_back(backward);

            return result;
        }
    }
    
    return std::vector<int> ();
}
