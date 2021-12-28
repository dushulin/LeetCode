//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//
// 问总共有多少条不同的路径？
//
//
//
// 示例 1：
//
//
//输入：m = 3, n = 7
//输出：28
//
// 示例 2：
//
//
//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向下
//
//
// 示例 3：
//
//
//输入：m = 7, n = 3
//输出：28
//
//
// 示例 4：
//
//
//输入：m = 3, n = 3
//输出：6
//
//
//
// 提示：
//
//
// 1 <= m, n <= 100
// 题目数据保证答案小于等于 2 * 109
//
// Related Topics 数学 动态规划 组合数学
// 👍 1216 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int uniquePaths(int m, int n) {
        //1. dp数组及下标含义：二维dp数组dp[m][n]，表示从(0, 0)出发到(m, n)有dp[m][n]种路径
        int[][] dp = new int[m][n];

        //3. dp数组初始化：由于机器人只能向下或者向右，因此从(0,0)移动到地图的上边界和右边界的任意一点，都只有一种走法
        for (int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        //4. 确定遍历顺序：右下角的点都可以由其上方和左方的点推导出来，因此顺序从左到右，从上到下
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                //2. 递推公式：要求出dp[m][n]，只能从两个方向来推导，从[m-1][n]向下走一格，或者，从[m][n-1]向右走一格。因此dp[m][n] = dp[m-1][n] + dp[m][n - 1]
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        //5. 举例推导
        return dp[m - 1][n - 1];
    }
}
//leetcode submit region end(Prohibit modification and deletion)
