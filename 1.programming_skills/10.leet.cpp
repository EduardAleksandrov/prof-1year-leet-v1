/*
    58. Length of Last Word

    Given a string s consisting of words and spaces, return the length of the last word in the string.

    A word is a maximal substring consisting of non-space characters only.

    Done.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count{0};
        int space{0};
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == ' ' && space == 0) 
            {
                continue;
            }
            if(s[i] != ' ' && space == 0)
            {
                space = 1;
            }
            if(s[i] == ' ' && space == 1) break;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution Sol;
    string data = "MCMXCIV get  ";
    int result = Sol.lengthOfLastWord(data);
    cout << result << endl;
    return 0;
}