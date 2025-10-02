/*
    860. Lemonade Change

    At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a 
    time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
    You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

    Note that you do not have any change in hand at first.

    Given an integer array bills where bills[i] is the bill the ith customer pays, return true 
    if you can provide every customer with the correct change, or false otherwise.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int mas[3] {};
        for(auto& b: bills)
        {
            if(b == 5) mas[0]+=1;
            if(b == 10)
            {
                mas[0] -= 1;
                mas[1] += 1;
            } 
            if(b == 20) 
            {
                if(mas[1] > 0) 
                {
                    mas[0] -= 1;
                    mas[1] -= 1;
                    mas[2] += 1;
                } else if(mas[0] > 2){
                    mas[0] -= 3;
                    mas[2] += 1;
                } else {
                    return false;
                }
            }
            if(mas[0] < 0 || mas[1] < 0 || mas[2] < 0) return false;
        }
        return true;
    }
};

int main()
{
    Solution Sol;
    vector<int> bills {5,5,5,10,5,5,10,20,20,20};
    bool result = Sol.lemonadeChange(bills);

    cout << result << endl;

    return 0;
}