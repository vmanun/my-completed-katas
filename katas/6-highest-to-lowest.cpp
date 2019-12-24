// 6. Highest and Lowest; by user Deantwo
// In this little assignment you are given a string of space separated numbers, 
// and have to return the highest and lowest number.

// Example:

// highAndLow("1 2 3 4 5");  // return "5 1"
// highAndLow("1 2 -3 4 5"); // return "5 -3"
// highAndLow("1 9 3 4 -5"); // return "9 -5"

// Notes:

//     All numbers are valid Int32, no need to validate them.
//     There will always be at least one number in the input string.
//     Output string must be two numbers separated by a single space, and highest number is first.

#include <string>

std::string highAndLow(const std::string& numbers){
  std::string placeholder = "";
  int max = 0, min = 0, i = 0;
  bool isAtStart = true;
  
  for (i; i <= numbers.length(); i++){
    if (numbers[i] != 32 && numbers[i] != 0) placeholder += numbers[i];
    else {
      if (isAtStart == true){
        min = stoi(placeholder, nullptr);
        max = stoi(placeholder, nullptr);
        isAtStart = false;
      }
      else {
        if (stoi(placeholder, nullptr) > max) max = stoi(placeholder, nullptr);
        if (stoi(placeholder, nullptr) < min) min = stoi(placeholder, nullptr);
      }
      placeholder = "";
    }
  }
  return std::to_string(max) + " " + std::to_string(min);
}