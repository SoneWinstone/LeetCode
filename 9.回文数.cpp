/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(long x)
    {
        if (x < 0) {
            return false;
        }
        string s = to_string(x);
        bool ret = true;
        for (int i = 0; i < s.length() / 2; ++i)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                ret = false;
            }
        }
        return ret;
    }
};
