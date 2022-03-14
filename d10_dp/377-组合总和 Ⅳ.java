//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。 
//
// 题目数据保证答案符合 32 位整数范围。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3], target = 4
//输出：7
//解释：
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//请注意，顺序不同的序列被视作不同的组合。
// 
//
// 示例 2： 
//
// 
//输入：nums = [9], target = 3
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 1000 
// nums 中的所有元素 互不相同 
// 1 <= target <= 1000 
// 
//
// 
//
// 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？ 
// Related Topics 数组 动态规划 
// 👍 587 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int combinationSum4(int[] nums, int target) {
        //1. dp数组，及其下标含义：dp[i] 表示，组成正整数i的组合个数是dp[i]个
        //2. 初始化dp数组，dp[0]=1, dp[1-i]=0
        int[] dp = new int[target + 1];
        dp[0] = 1;
        //3. 确定递推公式：dp[i] = dp[i] + dp[i -nums[j]] 两种情况：1. 把nums[j]包含进去，2. 不包含nums[j]
        //4. 确定遍历顺序，由于是一个完全背包问题（每次取的数字可以是无限），且是求排列（先遍历背包再遍历物品）
        for (int i = 1; i <= target; i++){
            for (int j = 0; j < nums.length; j++){
                if (i >= nums[j]){
                    dp[i] += dp[i - nums[j]];
                    System.out.println(dp[i]);
                }
            }
            System.out.println();
        }
        return dp[target];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1,2,3};
        System.out.println(s.combinationSum4(nums, 4));
    }

}

//leetcode submit region end(Prohibit modification and deletion)
