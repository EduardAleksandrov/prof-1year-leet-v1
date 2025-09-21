/*  
    1822.Sign of the Product of an Array
    Implement a function signFunc(x) that returns:

    1 if x is positive.
    -1 if x is negative.
    0 if x is equal to 0.
    You are given an integer array nums. Let product be the product of all values in the array nums.

    Return signFunc(product).

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count{0};
        for(auto x: nums)
        {
            if(x == 0) return 0;
            if(x < 0) count++;
        }
        if(count % 2 == 0) return 1;
        else return -1;
    }
};

int main()
{
    Solution Sol;
    vector<int> v {-1,-2,-3,0,3,2,1};
    int result = Sol.arraySign(v);

    cout << result << endl;
    return 0;
}