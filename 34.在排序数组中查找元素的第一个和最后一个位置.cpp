/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
//    // 版本一：借助二分查找扩展，二分查找找到target后往左右两边搜索
//    // 最差时间复杂度为O(N) 区间内所有元素相同，都为target
//private:
//    int binarySearch(vector<int>& nums, int target) {
//        if (nums.size() == 0) {
//            return -1;
//        }
//
//        int left = 0;
//        int right = nums.size() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] == target) {
//                return mid;
//            } else if (nums[mid] < target) {
//                left = mid + 1;
//            } else if (nums[mid] > target) {
//                right = mid - 1;
//            }
//        }
//
//        return -1;
//    }
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int idx = binarySearch(nums, target);
//        if (idx == -1) {
//            return vector<int>{-1, -1};
//        }
//
//        int left = idx, right = idx;
//        while (left >= 0 && nums[left] == target) {
//            --left;
//        }
//        while (right < nums.size() && nums[right] == target) {
//            ++right;
//        }
//
//        return vector<int>{left + 1, right - 1};
//    }

// 版本二：优化版二分查找
// 时间复杂度为 O(logN)
private:
    static int binarySearchLeft(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        // 可以优化在searchRange中，只计算一次
        if (nums[0] == target) {
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (nums[mid - 1] != target)
                    return mid;
                else
                    right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        return -1;
    }
    static int binarySearchRight(vector<int>& nums, int target) {
        // 这两句都可以优化掉
        if (nums.size() == 0) {
            return -1;
        }
        if (nums[nums.size() - 1] == target) {
            return nums.size() - 1;
        }

        // 起始位置也可以优化为binarySearchLeft的返回值
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (nums[mid + 1] != target)
                    return mid;
                else
                    left = mid + 1;
            } else if (nums[mid] <= target) {
                left = mid + 1;
            } else if (nums[mid] >= target) {
                right = mid - 1;
            }
        }

        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearchLeft(nums, target);
        if (left == -1) {
            return vector<int>{-1, -1};
        }

        return vector<int>{left, binarySearchRight(nums, target)};
    }
};
// @lc code=end

