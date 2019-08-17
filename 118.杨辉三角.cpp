/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (63.38%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 51.4K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
class Solution {
private:
    void generate(vector<vector<int>>& ret, int numRows) {
        if (numRows == 1) {
            vector<int> vec{1};
            ret.push_back(vec);
            return;
        }
        if (((int) ret.size() - 1) < numRows) {
            generate(ret, numRows - 1);
        }

        vector<int> vec{1};
        vector<int> &preVec = ret[numRows - 2];
        int size = preVec.size();
        for (int i = 0; i < size - 1; ++i) {
            vec.push_back(preVec[i] + preVec[i + 1]);
        }
        vec.push_back(1);

        ret.push_back(vec);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0) {
            return ret;
        }
        generate(ret, numRows);
        return ret;
    }
};

