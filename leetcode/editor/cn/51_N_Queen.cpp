//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 数组 回溯 
// 👍 956 👎 0

#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> rst;

    bool valid(vector<string> &vector, int row, int col){
        // 检查相同列是否有皇后
        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i][col] == 'Q') {
                return false;
            }
        }
        // 检查左上
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (vector[i][j] == 'Q') {
                return false;
            }
        }
        // 检查右上
        for (int i = row, j = col; i >= 0 && j < vector.size(); --i, ++j) {
            if (vector[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

/**
     * 路径： road中小于row的那些行都已经放置了皇后
     * 选择列表：第row行的所有列都可以选择放置皇后
     * 结束条件：row超过了road的最后一列
     */
    void backtrace(vector<string>& road, int row) {
        if (row == road.size()) {
            rst.push_back(road);
            return;
        }

        for (int col = 0; col < road.size(); ++col) {
            // 判断位置是否有效
            if (!valid(road, row, col)) {
                continue;
            }
            // 做选择
            road[row][col] = 'Q';
            // 处理下一行
            backtrace(road, row + 1);
            // 撤销选择
            road[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // 初始化棋盘
        vector<string> init(n, string(n, '.'));

        backtrace(init, 0);

        return rst;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution;
    auto rst = solution.solveNQueens(8);
    for (auto vec : rst) {
        for (auto str : vec) {
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}
