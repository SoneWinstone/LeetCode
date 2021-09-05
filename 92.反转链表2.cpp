// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (54.56%)
 * Likes:    982
 * Dislikes: 0
 * Total Accepted:    191.6K
 * Total Submissions: 351K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
//// 递归解法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//// 迭代解法
// class Solution {
//     ListNode* successor = nullptr; //后继节点
//     /**
//      * 递归反转前n个节点
//      */
//     ListNode* reverseN(ListNode* head, int n) {
//         if (head == nullptr) return nullptr;
//         if (head->next == nullptr) return head;

//         if (n == 1) {
//             successor = head->next;
//             return head;
//         }

//         ListNode* last = reverseN(head->next, n - 1);
//         head->next->next = head;
//         head->next = successor;

//         return last;
//     }
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         // 递归解法
//         if (left == 1) {
//             return reverseN(head, right);
//         }

//         head->next = reverseBetween(head->next, left - 1, right - 1);

//         return head;
//     }
// };

//// 迭代解法
class Solution {
private:
    ListNode* reverseList(ListNode* head, int n) {
        // 迭代解法
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* successor = nullptr; //后继节点

        int i = 1;
        ListNode* pre = nullptr;
        ListNode* first = head;
        while (head != nullptr && i <= n) {
            successor = head->next;
            head->next = pre;
            pre = head;
            head = successor;
            i++;
        }
        first->next = successor;

        return pre;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 迭代解法
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* precursor = head; //前驱节点

        ListNode* ret = head;
        int i = 1;
        while (head != nullptr && i < left) {
            // 记录反转的前一个节点
            precursor = head;
            head = head->next;
            i++;
        }
        if (left == 1) {
            ret = reverseList(head, right - left + 1);
        } else {
            precursor->next = reverseList(head, right - left + 1);
        }

        return ret;
    }
};
// @lc code=end

int main() {
    ListNode* five = new ListNode(5);
    ListNode* four = new ListNode(4, five);
    ListNode* three = new ListNode(3, four);
    ListNode* two = new ListNode(2, three);
    ListNode* root = new ListNode(1, two);
    Solution solution;
    ListNode * ret = solution.reverseBetween(root, 2, 2);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}
