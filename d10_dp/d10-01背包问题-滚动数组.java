

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
     * 01背包：有N件物品和一个最多能背重量为W 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大
     *
     * 一维滚动数组解法
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
        //1. dp数组及其含义：dp[j]，表示容量为j的背包，所背的物品价值可以最大为dp[j]
        int[] dp = new int[W + 1];

        //3. 数组初始化：递归公式：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        //dp数组在推导的时候一定是取价值最大的数，如果题目给的价值都是正整数那么非0下标都初始化为0就可以了。
        //这样才能让dp数组在递归公式的过程中取的最大的价值，而不是被初始值覆盖了。
        //那么我假设物品价值都是大于0的，所以dp数组初始化的时候，都初始为0就可以了。

        System.out.println("初始化dp：" + Arrays.toString(dp));
        //2. 递推公式：dp[j]有两个选择:
        //              一个是取自己dp[j] 相当于 二维dp数组中的dp[i-1][j]，即不放物品i
        //              一个是取dp[j - weight[i]] + value[i]，即放物品i，指定是取最大的，由于是求最大价值
        //              因此，dp[j] = max(dp[j], dp[j - weight[i]] + value[i])

        //4. 遍历顺序：倒序遍历。且先遍历物品i，再遍历背包容量j。倒序。首先正序遍历，可能会导致一个物品被放多次。其次先遍历背包再遍历物品，会导致背包里只被放入一个物品。
        for (int i = 0; i < weight.length; i++){
            for (int j = W; j >= weight[i]; j--){
                dp[j] = Math.max(dp[j], dp[j - weight[i]] + value[i]);
                System.out.println("dp[" + j + "] = " + dp[j]);
            }
        }
        System.out.println("递推后：" + Arrays.toString(dp));
        //5. 举例推导
        return dp[W];
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
