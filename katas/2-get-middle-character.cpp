// 2. Get the Middle Character; by user Shivo
// You are going to be given a word. Your job is to return the middle
// character of the word. If the word's length is odd, return the middle 
// character. If the word's length is even, return the middle 2 characters.

// #Input

// A word (string) of length 0 < str < 1000 (In javascript you may get slightly more 
// than 1000 in some test cases due to an error in the test cases). You do not need 
// to test for this. This is only here to tell you that you do not need 
// to worry about your solution timing out.

// #Output

// The middle character(s) of the word represented as a string. 

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