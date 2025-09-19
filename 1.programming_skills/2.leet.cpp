/**
    242. Valid Anagram
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    Done.
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length()) return false;

        std::map<char, unsigned int> ss;
        std::map<char, unsigned int> tt;

        for(const auto l: s)
        {
            ss[l] += 1;
        }

        for(const auto l: t)
        {
            tt[l] += 1;
        }
        return ss == tt;
        // return ss.size() == tt.size() && std::equal(ss.begin(), ss.end(), tt.begin(), [] (auto a, auto b) { return a.first == b.first && a.second == b.second; });
    }
};

int main()
{
    Solution Sol;
    bool result = Sol.isAnagram("aa", "a");
    cout << result << endl;

    return 0;
}