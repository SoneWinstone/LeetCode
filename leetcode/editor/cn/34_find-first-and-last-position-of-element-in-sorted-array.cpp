//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 进阶： 
//
// 
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
// Related Topics 数组 二分查找 
// 👍 1129 👎 0
#include <iostream>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    Solution solution;
    auto rst = solution.searchRange(nums, target);
    cout << "[" << rst[0] << ", " << rst[1] << "]" << endl;
    return 0;
}
