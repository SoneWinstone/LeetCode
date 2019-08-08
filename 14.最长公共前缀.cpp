/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.32%)
 * Likes:    634
 * Dislikes: 0
 * Total Accepted:    104.4K
 * Total Submissions: 304.2K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

bool isSame(vector<string> &strs, int vLen, int index)
{
    for (int j = 1; j < vLen; ++j)
    {
        if (strs[0][index] != strs[j][index])
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int vLen = strs.size();
        if (vLen == 0)
        {
            return "";
        }

        int s = INT32_MAX;
        string shortest;
        for (auto str : strs)
        {
            if (str.length() < s)
            {
                s = str.length();
                shortest = str;
            }
        }

        int longest = 0;

        for (int i = 0; i < s; ++i)
        {
            if (isSame(strs, vLen, i))
            {
                ++longest;
            }
            else
            {
                break;
            }
        }

        if (longest == 0)
        {
            return "";
        }
        else
        {
            return strs[0].substr(0, longest);
        }
    }
};
