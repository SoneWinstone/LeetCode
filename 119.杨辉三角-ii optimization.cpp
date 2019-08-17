/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (57.31%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    20.8K
 * Total Submissions: 36.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
class Solution {
private:
    void generate(vector<int>& ret, int numRows) {
        if ((int)ret.size() < numRows) {
            generate(ret, numRows - 1);
        }

        int size = ret.size();
        int temp = ret[0], old = 0;
        for (int i = 1; i < size; ++i) {
            old = temp;
            temp = ret[i];
            ret[i] = temp + old;
        }
        ret.push_back(1);
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret{1};
        if (rowIndex == 0) {
            return ret;
        }
        generate(ret, rowIndex);
        return ret;
    }
};

