//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
// Related Topics 数组 回溯 
// 👍 1470 👎 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums{1,2,3};
    Solution solution;
    auto rst = solution.permute(nums);
    return 0;
}
