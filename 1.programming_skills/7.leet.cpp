/*  
    1502. Can Make Arithmetic Progression From Sequence
    
    A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

    Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        for(int i = 0; i < arr.size()-1; i++)
        {
            for(int j = i+1; j < arr.size(); j++)
            {
                if(arr[i] > arr[j]) swap(arr[i], arr[j]);
            }
        }
        int res = arr[1] - arr[0];
        for(int i = 1; i < arr.size() -1 ; i++)
        {
            if(arr[i + 1] - arr[i] != res) return false;
        }
        return true;
    }
};

int main()
{
    Solution Sol;
    vector<int> v {3, 6, 1};
    int result = Sol.canMakeArithmeticProgression(v);

    cout << result << endl;
    return 0;
}