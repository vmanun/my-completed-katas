// 8. Vasya - Clerk; by user AlexIsHappy
// The new "Avengers" movie has just been released! There are a lot of 
// people at the cinema box office standing in a huge line. 
// Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" 
// ticket costs 25 dollars.

// Vasya is currently working as a clerk. He wants to sell 
// a ticket to every single person in this line.

// Can Vasya sell a ticket to every person and give change 
// if he initially has no money and sells the tickets strictly 
// in the order people queue?

// Return YES, if Vasya can sell a ticket to every person and 
// give change with the bills he has at hand at that moment. Otherwise return NO.

public class Line {
  public static String Tickets(int[] peopleInLine)
  {
    int billCount25  = 0, billCount50  = 0;
    
    for(int person : peopleInLine) {
      if(person == 25) ++billCount25;
      else if(person == 50) {
        ++billCount50;
        if(billCount25 >= 1) --billCount25;
        else return "NO";
      } else if(person == 100) {
        ++billCount100;
        if((billCount25 >= 1 && billCount50 >= 1)) {
          --billCount25;
          --billCount50;
        } else if(billCount25 >= 3) billCount25 -= (billCount25 * 3);
        else return "NO";
      }
    }
    return "YES";
  }
}