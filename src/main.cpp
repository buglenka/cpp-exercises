#include <stdlib.h>
#include "../../include/cpp-exercises/Solution.h"

int main(int argc, char *argv[]) {
  std::vector<int> input;
  
  // Load input numbers
  for (int i = 0; i < argc; i++) {
    input.push_back(atoi(argv[i]));
  }
  
  // Do 
  std::vector<int> output = Solution::plusOne(input);
  
  // Print the result
  printf("[");
  for(int i = 0; i < output.size(); i++) {
    if (i != 0) printf(", ");
    
    printf("%i", output[i]);
  }
  printf("]\n");
  
  return 1;
}
