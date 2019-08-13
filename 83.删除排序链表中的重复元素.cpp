/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (46.98%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    38.1K
 * Total Submissions: 81.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 * 示例 1:
 *
 * 输入: 1->1->2
 * 输出: 1->2
 *
 *
 * 示例 2:
 *
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *temp = head;
    ListNode *next = temp->next;
    while (next != nullptr) {
      if (temp->val == next->val) {
        temp->next = next->next;
        delete next;
        next = temp->next;
      } else {
        next = next->next;
        temp = temp->next;
      }
    }
    return head;
  }
};
