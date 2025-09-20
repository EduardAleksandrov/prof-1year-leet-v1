/*
    66. Plus One
    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
    The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
    Increment the large integer by one and return the resulting array of digits.
    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> plusAny(vector<int>& digits) {        
        long long int num {0};
        for(int i = 0; i < digits.size(); i++)
        {
            num += pow(10, (digits.size() - (i+1)))*digits[i];
        }

        num+=2;
        vector<int> result{};
        string myString = to_string(num);

        for(int i = 0; i < myString.length(); i++)
        {
            result.push_back(static_cast<int>(myString[i] - '0'));
        }

        return result;
    }
    vector<int> plusOne(vector<int>& digits) 
    {        
        for (int i = digits.size() - 1; i >= 0; i--) 
        {
            if (digits[i] < 9) 
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution Sol;
    vector<int> data {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,0,1,2};
    vector<int> result = Sol.plusOne(data);

    for(const auto r: result)
        cout << r << "";

    cout << endl;
    return 0;
}