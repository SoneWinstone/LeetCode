//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。 
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。 
//
// 你可以认为每种硬币的数量是无限的。 
//
// 
//
// 示例 1： 
//
// 
//输入：coins = [1, 2, 5], amount = 11
//输出：3 
//解释：11 = 5 + 5 + 1 
//
// 示例 2： 
//
// 
//输入：coins = [2], amount = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：coins = [1], amount = 0
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：coins = [1], amount = 1
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：coins = [1], amount = 2
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= coins.length <= 12 
// 1 <= coins[i] <= 231 - 1 
// 0 <= amount <= 104 
// 
// Related Topics 广度优先搜索 数组 动态规划 
// 👍 1391 👎 0

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return  -1;
        }

        // 设置一个默认的不可能值
        int result = amount + 1;
        for (int coin : coins) {
            // 取子问题最优解
            int subProblem = dp(coins, amount - coin);
            if (subProblem == -1) continue;
            result = min(subProblem + 1, result);
        }

        result = result == amount + 1 ? -1 : result;
        cout << "amount " << amount << " --- result " << result << endl;
        return result;
    }

    map<int, int> memo{};

    int dp2(vector<int>& coins, int amount) {
        if (amount < 0) {
            return  -1;
        }
        if (amount == 0) {
            return 0;
        }

        // 注意C++ map的坑，直接insert如果有重复元素不会替换
        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        // 设置一个默认的不可能值
        int result = amount + 1;
        for (int coin : coins) {
            // 取子问题最优解
            int subProblem = dp2(coins, amount - coin);
            if (subProblem == -1) continue;
            result = min(subProblem + 1, result);
        }

        result = result == amount + 1 ? -1 : result;
        memo.insert(make_pair(amount, result));
        return result;
    }

    /// ------------------------------------------------------------------------
    // dpVec[i] 表示当amount为i时的最优解
    vector<int> dpVec;
    void initVec(int amount) {
        dpVec = vector<int>(amount + 1, amount + 1);
        // base case
        dpVec[0] = 0;
    }

    int dp3(vector<int>& coins, int amount) {
        if (amount < 0) {
            return  -1;
        }

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin < 0) {
                    // 无解
                    continue;
                }
                dpVec[i] = min(dpVec[i - coin] + 1, dpVec[i]);
            }
        }

        return dpVec[amount] == amount + 1 ? -1 : dpVec[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // 1. 基础解法 递归,暴力破解 会超时
//        return dp(coins, amount);

        // 2. 添加中间结果记录 自顶向下
//        return dp2(coins, amount);

        // 3. 自底向上
        initVec(amount);
        return dp3(coins, amount);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution = Solution();
    vector<int> coins{1,2,5};
    int coinNumber = solution.coinChange(coins,130);
    cout << "min coins = " << coinNumber << endl;
    return 0;
}
