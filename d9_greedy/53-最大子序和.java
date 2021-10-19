//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//
//
// 示例 1：
//
//
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
//
//
// 示例 2：
//
//
//输入：nums = [1]
//输出：1
//
//
// 示例 3：
//
//
//输入：nums = [0]
//输出：0
//
//
// 示例 4：
//
//
//输入：nums = [-1]
//输出：-1
//
//
// 示例 5：
//
//
//输入：nums = [-100000]
//输出：-100000
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
//
//
//
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
// Related Topics 数组 分治 动态规划
// 👍 3840 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    //当连续和加上下一个数字变为负数时，马上舍弃，从下一个数字开始重新计算连续和。因为前面是负数，只会拖累后面的计算。
    //就比如-2 1的序列，一定是从1 开始的连续和最大，而不是从-2开始。（前面计算的连续和可以抽象成-2，下一个数字可以抽象为1）
    public int maxSubArray(int[] nums) {
        int result = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = 0; i < nums.length; i++){
            sum += nums[i];
            if (sum > result){
                result = sum;
            }
            if (sum <= 0){
                sum = 0;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1};
        System.out.println(s.maxSubArray(nums));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
