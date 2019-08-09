/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (56.22%)
 * Likes:    560
 * Dislikes: 0
 * Total Accepted:    93.7K
 * Total Submissions: 166.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 * 示例：
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(nullptr) {}
// };

ListNode *getLastNode(ListNode *list) {
  ListNode *last = nullptr;
  if (list == nullptr) {
    return last;
  }
  last = list->next;
  while (last->next != nullptr) {
    last = last->next;
  }
  return last;
}

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *ret = nullptr;
    ListNode *next = nullptr;
    ListNode *last = nullptr;
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    } else {
      if (l1->val <= l2->val) {
        ret = new ListNode(l1->val);
        last = ret;

        next = l1->next;
        delete l1;
        l1 = next;
      } else {
        ret = new ListNode(l2->val);
        last = ret;

        next = l2->next;
        delete l2;
        l2 = next;
      }
      for (;;) {
        if (l1 == nullptr) {
          last->next = l2;
          break;
        } else if (l2 == nullptr) {
          last->next = l1;
          break;
        } else {
          if (l1->val <= l2->val) {
            last->next = new ListNode(l1->val);
            last = last->next;

            next = l1->next;
            delete l1;
            l1 = next;
          } else {
            last->next = new ListNode(l2->val);
            last = last->next;

            next = l2->next;
            delete l2;
            l2 = next;
          }
        }
      }
    }
    return ret;
  }
};
