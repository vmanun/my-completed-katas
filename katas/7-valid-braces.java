// 7. Valid Braces; by users xDranik and arnedag
// Write a function that takes a string of braces, and determines if 
// the order of the braces is valid. It should return true if the 
// string is valid, and false if it's invalid.

// This Kata is similar to the Valid Parentheses Kata, but introduces 
// new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

// All input strings will be nonempty, and will only 
// consist of parentheses, brackets and curly braces: ()[]{}.
// What is considered Valid?

// A string of braces is considered valid if all braces are matched with the correct brace.

public class BraceChecker {
  public boolean isValid(String braces) {  
    int startingPoint = 0,
        y = -1;
    String openStack = "";
    boolean isOpenBrc = false;
    
    for(int i = 0; i < braces.length(); i++) {
      char c = braces.charAt(i);
      if((c == '(' || c == '[' || c == '{')) {       
        if(y < 0) isOpenBrc = true;
        else return false;
      }
      else if(c == ')' || c == ']' || c == '}'){      
        if(isOpenBrc) {
          openStack = braces.substring(startingPoint, i);
          y = openStack.length() - 1;
          startingPoint = i + 1;
          isOpenBrc = false;
        }   
        if(y < 0) return false;
        if((c == ')' && openStack.charAt(y) != '(') ||
           (c == ']' && openStack.charAt(y) != '[') ||
           (c == '}' && openStack.charAt(y) != '{')) return false;    
      }
      if(y >= 0) --y;
    }    
    return !isOpenBrc;
  }
}