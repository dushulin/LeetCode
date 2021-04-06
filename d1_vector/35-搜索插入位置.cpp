//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 
//
// 你可以假设数组中无重复元素。 
//
// 示例 1: 
//
// 输入: [1,3,5,6], 5
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [1,3,5,6], 2
//输出: 1
// 
//
// 示例 3: 
//
// 输入: [1,3,5,6], 7
//输出: 4
// 
//
// 示例 4: 
//
// 输入: [1,3,5,6], 0
//输出: 0
// 
// Related Topics 数组 二分查找 
// 👍 816 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
    [start, end] 左闭右闭
    **/
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;//可以防止越界
            if(target == nums[mid]){
                return mid;
            }else if(target > nums[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return end + 1;
    }

    /**
    [start, end) 左闭右开
    **/
    int searchInsert2(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        while(start < end){
            int mid = start + (end - start) / 2;//可以防止越界
            if(target > nums[mid]){//在[mid + 1, end)里
                start = mid + 1;
            }else if(target < nums[mid]){//在[start, mid)
                end = mid;
            }else{
                return mid;
            }
        }
        return end;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
