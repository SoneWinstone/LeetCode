/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (49.38%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 78K
 * Testcase Example:
 * '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 *
 *
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 *
 *
 * 示例:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 *
 *
 */
class MinStack {
private:
  int _min = INT32_MAX;
  int _size = 0;
  vector<int> _stack;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    _stack.push_back(x);
    if (x < _min) {
      _min = x;
    }
    ++_size;
  }

  void pop() {
    int ret = _stack.at(_size - 1);
    _stack.pop_back();
    --_size;
    if (_min == ret) {
      _min = INT32_MAX;
      for (int i = 0; i < _size; ++i) {
        if (_stack[i] < _min) {
          _min = _stack[i];
        }
      }
    }
  }

  int top() { return _stack.at(_size - 1); }

  int getMin() { return _min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
