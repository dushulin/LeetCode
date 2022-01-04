import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
     * 01背包：有N件物品和一个最多能背重量为W 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大
     *
     * 二维dp数组解法
     *
     * N = 3, W = 4
     *       重量   价值
     * 物品0	  1	    15
     * 物品1	  3	    20
     * 物品2	  4	    30
     * Answer: 35
     * @return
     */
    public int weightBag01(int[]weight, int[] value, int W, int N) {
        //1. dp数组及其含义：二维dp[i][j]，表示从下标[0-i]的物品里任意取，放入容量为j的背包，价值总和的最大
        int[][] dp = new int[N][W + 1];

        //3. 数组初始化：
        //          a. 如果背包容量j为0的话，即dp[i][0]，无论是选取哪些物品，背包价值总和一定为0
        //          b. 根据递推公式，可以知道i是由i - 1推导出来的，因此i=0的时候需要初始化。dp[0][j] = if(weight[0] < j) 0 : value[0]。意思是，当放入物品0的时候，如果背包容量j压根装不下，则价值是0，否则就是物品0的价值
        for (int j = W; j >= weight[0]; j--){
            dp[0][j] = value[0];
        }
        System.out.println("初始化dp：" + Arrays.deepToString(dp));
        //2. 递推公式：dp[i][j]可以从两个方向推到出来：
        //          a. 不放物品i的时候，dp[i][j] = dp[i - 1][j]。其实就是当物品i的重量大于背包j的重量时，物品i无法放进背包中，所以被背包内的价值依然和前面相同
        //          b. 放物品i的时候，dp[i][j] = dp[i - 1][j - weight[i]] + value[i]。其中dp[i - 1][j - weight[i]]，表示背包容量为j - weight[i]时(极限情况，放了物品i刚好就满了)，不放物品i，最大的价值。那么当放入物品i是，价值变为dp[i - 1][j - weight[i]] + value[i]
        //              因此，dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])

        //4. 遍历顺序：难点
        //          a. 先遍历物品i，再遍历背包容量j
        //          b. 先遍历背包容量j，在遍历物品i
        for (int i = 1; i < weight.length; i++){
            for (int j = 0; j <= W; j++){
                if (weight[i] > j){
                    dp[i][j] = dp[i - 1][j];
                }else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
                System.out.println("dp[" + i + "]" + "[" + j + "]" + " = " + dp[i][j]);
            }
        }
        System.out.println("递推后：" + Arrays.deepToString(dp));
        //5. 举例推导
        return dp[N - 1][W];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int N = 3;
        int W = 4;
        int[] weight = {1, 3, 4};
        int[] value = {15, 20, 30};
        s.weightBag01(weight, value, W, N);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
