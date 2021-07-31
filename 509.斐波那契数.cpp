/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    
public:
    int fib(int n) {
        // 1. 常规解法 递归

        // if (0 == n) {
        //     return 0;
        // }
        // if (n == 1 || n == 2) {
        //     return 1;
        // }
        // return fib(n - 1) + fib(n - 2);

        // 2. 进阶 迭代，保存中间结果，减少重复计算
        // if (0 == n) {
        //     return 0;
        // }
        
        // vector<int> memo(n + 1, 1);
        // for (int i = 3; i <= n; ++i) {
        //     memo[i] = memo[i - 1] + memo[i - 2];
        // }
                
        // return memo[n];

         // 3. 终极版 迭代，中间结果只需要保存两个值
        if (0 == n) {
            return 0;
        }
        int ret = 1;
        int pre = 1;
        int prePre = 1;
        
        for (int i = 3; i <= n; ++i) {
            ret = pre + prePre;
            prePre = pre;
            pre = ret;
        }
                
        return ret;
    }
};
// @lc code=end
