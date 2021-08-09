/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
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
// @lc code=end

