//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//
//
//
// 示例 1：
//
//
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
//
//
// 示例 2：
//
//
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//
//
//
// 提示：
//
//
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104
//
// Related Topics 数组 动态规划
// 👍 2305 👎 0


import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //贪心，获得最低点即可
    public int maxProfit(int[] prices) {
        int result = 0;
        int low = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++){
            low = Math.min(low, prices[i]);
            result = Math.max(result, prices[i] - low);
        }
        return result;
    }

    //动态规划
    public int maxProfit_1(int[] prices) {
        if (prices == null || prices.length == 0){
            return 0;
        }
        //1. 确定dp数组：dp[i][0]表示第i天持有股票可以获得的最多现金。dp[i][1]表示第i天不持有股票获得的最多现金
        int[][] dp = new int[prices.length][2];
        //2. 确定地推公式：dp[i][0]可以由第i-1天持有股票得来，或者第i天买入股票。dp[i][1]可以由第i-1天不持有股票得来，或者第i天卖出股票(那么第i-1天一定要持有股票)
            //dp[i][0] = max(dp[i-1][0], -price[i]); dp[i][1] = max(dp[i-1][1], price[i]+dp[i-1][0])
        //3. 初始化：dp[0][0]和dp[0][1]
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.length; i++){
            dp[i][0] = Math.max(dp[i - 1][0], -prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[prices.length - 1][1];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] price = {7,1,5,3,6,4};
        System.out.println(s.maxProfit_1(price));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
