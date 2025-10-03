/*
    43. Multiply Strings
    
    Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

    Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.    

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
    string multiply(string num1, string num2) {
        if(num1.length() == 1 && num1[0] == '0') return "0";
        if(num2.length() == 1 && num2[0] == '0') return "0";

        string num_first, num_second;
        if(num1.length() > num2.length())
        {
            num_first = num1;
            num_second = num2; 
        } else {
            num_first = num2;
            num_second = num1; 
        }

        vector<string> vec{};

        for(int i = 0; i < num_second.length(); i++)
        {
            int prev {0};
            string s;
            for(int k = 0; k < i; k++)
            {
                s.insert(0, 1, '0');
            }
            for(int j = 0; j < num_first.length(); j++)
            {
                char step = ((num_second[num_second.length()-i-1] - '0') * (num_first[num_first.length()-j-1] - '0') % 10 + prev ) + '0';
                prev = (num_second[num_second.length()-i-1] - '0') * (num_first[num_first.length()-j-1] - '0') / 10;
                s.insert(0, 1, step);
            }
            if(prev != 0) s.insert(0, 1, prev + '0');
            vec.push_back(s);
        }

        for(auto s: vec)
        {
            cout << s << "\n";
        }

        string s;
        int prev{0};
        for(int j = 0; j < vec.back().size(); j++)
        {
            int sum{0};
            
            for(int i = 0; i < vec.size(); i++)
            {
                int r = vec[i].length()-j-1;
                if(r < 0) continue;

                sum += vec[i][vec[i].length()-j-1] - '0';
                
            }
            char step = (sum + prev) % 10 + '0';
            prev = (sum + prev) / 10;
            s.insert(0, 1, step);
        }
        if(prev != 0) s.insert(0, 1, prev + '0');

        return s;
    }
};

int main()
{
    Solution Sol;
    string s1 {"999"};
    string s2 {"0"};
    string result = Sol.multiply(s1, s2);

    cout << result << endl;

    return 0;
}