/*
    709. To Lower Case
    Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& x: s)
        {
            x = (char) tolower(x);
        }
        return s;
    }
};

int main()
{
    Solution Sol;
    string data = "MCMXCIV get  ";
    string result = Sol.toLowerCase(data);
    cout << result << endl;
    return 0;
}