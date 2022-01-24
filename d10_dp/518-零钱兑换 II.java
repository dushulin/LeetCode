//给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
//
// 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
//
// 假设每一种面额的硬币有无限个。
//
// 题目数据保证结果符合 32 位带符号整数。
//
//
//
//
//
//
// 示例 1：
//
//
//输入：amount = 5, coins = [1, 2, 5]
//输出：4
//解释：有四种方式可以凑成总金额：
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
//
//
// 示例 2：
//
//
//输入：amount = 3, coins = [2]
//输出：0
//解释：只用面额 2 的硬币不能凑成总金额 3 。
//
//
// 示例 3：
//
//
//输入：amount = 10, coins = [10]
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// coins 中的所有值 互不相同
// 0 <= amount <= 5000
//
// Related Topics 数组 动态规划
// 👍 700 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
     * 完全背包变种（每个物品有无数个）。求的是组合数（不是排列数）。
     * @param amount
     * @param coins
     * @return
     */
    public int change(int amount, int[] coins) {
        //1. dp数组含义：dp[j] 表示容量为j的背包，装满的组合数
        int[] dp = new int[amount + 1];
        //2. 确定递推公式：dp[j] （考虑coins[i]的组合总和） 就是所有的dp[j - coins[i]]（不考虑coins[i]）相加

        //3. 数组初始化：dp[0] = 1,因为容量为0的背包，装满有一种组合。其他的都初始化为0即可
        dp[0] = 1;
        //4. 遍历顺序：先物品，再背包
        for (int i = 0; i < coins.length; i++){
            for (int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
                System.out.println("dp[" + j + "] = " + dp[j]);
            }
            System.out.println();
        }
        return dp[amount];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int amount = 5;
        int[] coins = {1,2,5};
        System.out.println(s.change(amount, coins));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
