//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 记忆化搜索 数学 动态规划 
// 👍 2061 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int climbStairs(int n) {
        if (n <= 2){
            return n;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


    //一般化题目：一共n级台阶，每次可以爬1级、2级、3级、m级台阶，问有多少种方法可以爬到顶端
    //可转换为完全背包：类比377。可以爬的台阶数就是物品重量，台阶总数就是背包可装的总重量。求的是排列总和，且物品无限（可每次都跳一个台阶）
    public int climbStairs1(int n, int m) {
            //1. 确定dp含义: 爬i级台阶，的方法总数
            int[] dp = new int[n + 1];
            //2. 确定递推公式: dp[i] += dp[i - j]
            //3. 初始化dp数组
            dp[0] = 1;
            //4. 确定遍历顺序：完全背包的排列总和，先背包、再物品
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                    //这里j从1开始，到m结束，表示物品从1开始到m结束
                    if (i >= j) {
                        dp[i] += dp[i - j];
                    }
                }
            }
            return dp[n];
    }
}
//leetcode submit region end(Prohibit modification and deletion)
