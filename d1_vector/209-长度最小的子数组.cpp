//给定一个含有 n 个正整数的数组和一个正整数 target 。 
//
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长
//度。如果不存在符合条件的子数组，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 
//
// 示例 2： 
//
// 
//输入：target = 4, nums = [1,4,4]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target <= 109 
// 1 <= nums.length <= 105 
// 1 <= nums[i] <= 105 
// 
//
// 
//
// 进阶： 
//
// 
// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。 
// 
// Related Topics 数组 双指针 二分查找 
// 👍 558 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int min = INT32_MAX;
        int flag = false;
        for(slow = 0; slow < nums.size(); slow++){
            int sum = 0;
            int size = INT32_MAX;

            for(fast = slow; fast < nums.size(); fast++){
                sum += nums[fast];
                if(sum >= target){
                    size = fast - slow + 1;
                    flag = true;
                    break;
                }
            }
            if(size < min){
                min = size;
            }
        }
        return flag ? min : 0;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int start = 0;
        int sum = 0;
        int subLength = 0;//子序列长度
        for(int end = 0; end < nums.size(); end++){
            sum += nums[end];//快指针不断往后移动，直到当前窗口的和 >= target
            while(sum >= target){
                subLength = (end - start) + 1;//获取当前子序列长度
                result = subLength < result ? subLength : result;
                sum -= nums[start++];//这时候将慢指针向后移动，减小窗口，因为有可能获得更小的窗口
            }
        }
        return result < INT32_MAX ? result : 0;//考虑边界条件
    }
};
//leetcode submit region end(Prohibit modification and deletion)
