package stack.leetcode.editor;

//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//
// 你可以认为每种硬币的数量是无限的。
//
//
//
// 示例 1：
//
//
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
//
// 示例 2：
//
//
//输入：coins = [2], amount = 3
//输出：-1
//
// 示例 3：
//
//
//输入：coins = [1], amount = 0
//输出：0
//
//
//
//
// 提示：
//
//
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104
//
// Related Topics 广度优先搜索 数组 动态规划
// 👍 1795 👎 0


import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //完全背包问题
    public int coinChange(int[] coins, int amount) {
        //1. dp数组及其含义：dp[i]: 表示凑成金额i的最少硬币总数
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE );
        System.out.println(Arrays.toString(dp));
        //2. 递推公式：两种情况下取最小值：dp[j - coins[i]] + 1（不取coins[i]） 和 dp[j]（取coins[i]）
        //3. 确定初始值: 凑成0金额的最小金币数是0，且其他值都为INT_MAX
        dp[0] = 0;
        //4. 确定遍历顺序：先背包，再物品
        for (int i = 1; i <= amount; i++){
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != Integer.MAX_VALUE) {
                    //这里更新dp数组的条件要注意！！！只有当该位不是初始值时，说明之前已经被赋值过了，才有+1的必要。
                    dp[i] = Math.min(dp[i - coin] + 1, dp[i]);
                    System.out.println("dp[" + i + "] = " + dp[i]);
                }
            }
            System.out.println();
        }
        return dp[amount] == Integer.MAX_VALUE ? -1: dp[amount];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] coins = {2};
        int amount = 3;
        System.out.println(s.coinChange(coins, amount));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
