/*
    67. Add Binary

    Given two binary strings a and b, return their sum as a binary string.
    
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
    string addBinary(string a, string b) {
        string s;
        int prev{0};
        int i{0}, j{0};
        while(true)
        {
            int num1{0};
            if(i > a.length()-1) num1 = 0;
            else num1 = a[a.length()-i-1] - '0';

            int num2{0};
            if(j > b.length()-1) num2 = 0;
            else num2 = b[b.length()-j-1] - '0';

            char step = (num1 + num2 + prev) % 2 + '0';

            s.insert(0, 1, step);

            prev = (num1 + num2 + prev)/2;

            i++;
            j++;

            if(prev == 0 && i > a.length()-1 && j > b.length()-1) break;
        }

        return s;
    }
};

int main()
{
    Solution Sol;
    string s1 {"0"};
    string s2 {"1"};
    string result = Sol.addBinary(s1, s2);

    cout << result << endl;

    return 0;
}