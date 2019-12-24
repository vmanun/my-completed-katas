// 5. Count the Digit; by user g964

// Take an integer n (n >= 0) and a digit d (0 <= d <= 9) as 
// an integer. Square all numbers k (0 <= k <= n) between 0 and n. 
// Count the numbers of digits d used in the writing of all the k**2. 
// Call nb_dig (or nbDig or ...) the function taking n and d as parameters 
// and returning this count.

#include <regex>
#include <string>

class CountDig
{
public:
    static int nbDig(int n, int d){
        int k = 0, i = 0;
        std::string d_str = std::to_string(d), i_str = std::to_string(i*i);
        for (i = 0; i <= n; (i++, i_str = std::to_string(i*i)))
            k += std::count(i_str.begin(), i_str.end(), d_str[0]);
        return k;
    };
};