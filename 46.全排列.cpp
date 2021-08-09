/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    int depth = 0;
    vector<vector<int>> ret{};

    void backtrace(vector<int> vec, vector<int>& nums) {
        if (vec.size() == depth) {
            ret.push_back(vec);
            return;
        }


        for (int num : nums) {
            if (find(vec.begin(), vec.end(), num) == vec.end()) {
                vec.push_back(num);
                backtrace(vec, nums);
                vec.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        depth = nums.size();

        vector<int> vec;

        // 回溯算法
        backtrace(vec, nums);

        return ret;
    }
};
// @lc code=end

