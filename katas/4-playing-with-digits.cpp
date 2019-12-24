// 4. Playing with digits; by user g964
// Some numbers have funny properties. For example:

//     89 --> 8¹ + 9² = 89 * 1

//     695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2

//     46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

// Given a positive integer n written as abcd... (a, b, c, d... being digits)
// and a positive integer p

//     we want to find a positive integer k, if it exists, such as the sum of 
//         the digits of n taken to the successive powers of p is 
//         equal to k * n.

// In other words:

//     Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k

// If it is the case we will return k, if not return -1.

// Note: n and p will always be given as strictly positive integers.

#include <math.h>
#include <string>

class DigPow
{
public:
  static int digPow(int n, int p)
  {
      int i = 1, j = 0, k = 0, n_power = 0;
      for (i = 1; (n / i) > 0; i *= 10) 
      {
          n_power += pow(std::stoi(std::to_string(n).substr(j, 1)), p);
          j++;
          p++;
      }
      
      do 
      {
          k++;
          if (n_power == n * k)
              return k;
          else if ((n * k) > n_power)
              return -1;
      } while (n_power != n * k);
  }
};