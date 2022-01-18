//给你一个整数数组 nums 和一个整数 target 。
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//
//
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
//
//
// 示例 2：
//
//
//输入：nums = [1], target = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000
//
// Related Topics 数组 动态规划 回溯
// 👍 1007 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        // 01背包问题组合问题。
        // 大体思路：可以将这些nums划分为两块，left和right，那么left - right = target。且left + right = sum。那么left = (target + S) / 2。其中target 和 S都是固定的，那么left也是可以求出来了的。
        // 那么，相当于找出有多少种组合，可以组成left这个具体的数字。
        //1. 确定dp数组。dp[j]，表示容量为j的背包最多有dp[j]种方式装满。数组长度为left。
        int sum = 0;
        for (int i = 0; i < nums.length; i++){
            sum += nums[i];
        }
        int left = (sum + target) / 2;
        if (Math.abs(target) > sum) {
            //如果目标和 比 数组的sum都要大，那么不可能组成
            return 0;
        }
        if ((target + sum) % 2 == 1){
            return 0;
        }
        int[] dp = new int[left + 1];

        //2. 初始化：容量为0的背包有1种方式装满。（装入一个重量为0的物品）
        dp[0] = 1;
        //3. 递推公式：dp[j] = dp[j] + dp[j - nums[i]]
        for (int i = 0; i < nums.length; i++){
            for (int j = left; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[left];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {100};
        System.out.println(s.findTargetSumWays(nums, -200));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
