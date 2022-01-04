package stack.leetcode.editor;
//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
//
//
//
// 示例 1：
//
//
//输入：n = 3
//输出：5
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= n <= 19
//
// Related Topics 树 二叉搜索树 数学 动态规划 二叉树
// 👍 1462 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int numTrees(int n) {
        //1. dp数组及其含义：dp[n] 表示n个数字可组成的二叉搜索树的个数
        int[] dp = new int[n + 1];
        //2. 递推公式：j从[1, i]遍历，dp[i] = dp[j - 1] * dp[i - j]
        //3. 数组初始化：空树也可以是一个二叉搜索树
        dp[0] = 1;
        //4. 遍历顺序：从小到大
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        //5. 举例推导：4个节点  其中左子树和右子树分别可以有几个节点，要根据二叉搜索树的特性来确定，比如头结点为2的时候，左子树都要比2小（一共有4个节点），那么左子树个数是（2-1），右子树个数（4-2）
        //          头结点为1：左子树0个节点 * 右子树3个节点 ==> dp[0] * dp[3]
        //          头结点为2：左子树1个节点 * 右子树2个节点 ==> dp[1] * dp[2]
        //          头结点为3：左子树2个节点 * 右子树1个节点 ==> dp[2] * dp[1]
        //          头结点为4：左子树3个节点 * 右子树0个节点 ==> dp[3] * dp[0]
        //          最终结果是四种情况的和
        //          PS：为什么每种情况用乘法连接：比如当左子树是1个节点的时候，右子树2个节点的情况是可以变化的，因此固定左子树，右子树有dp[2]种变化。
        return dp[n];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.numTrees(3);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
