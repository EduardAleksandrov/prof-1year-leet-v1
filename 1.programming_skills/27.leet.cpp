/*
    50. Pow(x, n)

    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if (n == 0) {
        return 1;  // Base case: x^0 = 1
        } else if (n < 0) {
            x = 1 / x; // Convert to positive exponent
            nn = -nn;
        }


        double result = 1.0;
        double current_product = x;

        while (nn > 0) {
            if (nn % 2 == 1) {  // If n is odd
                result *= current_product;
            }
            current_product *= current_product; // Square the base
            nn /= 2; // Halve the exponent
        }

        return result;
    }
};

int main()
{
    Solution Sol;
    double result = Sol.myPow(2, 5);

    cout << result << endl;

    return 0;
}