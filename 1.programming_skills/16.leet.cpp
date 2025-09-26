/*
    1672. Richest Customer Wealth
    
    You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

    A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int vecsum{0}, result{0};
        for(int i = 0; i < accounts.size(); ++i)
        {
            int vecSum = std::accumulate(accounts[i].begin(), accounts[i].end(), 0);
            if(vecSum > result) result= vecSum;
        }
        return result;
    }
};

int main()
{
    Solution Sol;
    vector<vector<int>> data = {{1,5},{7,3},{3,5}};
    int result = Sol.maximumWealth(data);
    cout << result << endl;
    return 0;
}