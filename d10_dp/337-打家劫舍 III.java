package stack.leetcode.editor;

//小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
//
// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接
//相连的房子在同一天晚上被打劫 ，房屋将自动报警。
//
// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
//
//
//
// 示例 1:
//
//
//
//
//输入: root = [3,2,3,null,3,null,1]
//输出: 7
//解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
//
// 示例 2:
//
//
//
//
//输入: root = [3,4,5,1,3,null,1]
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
//
//
//
//
// 提示：
//
//
//
//
// 树的节点数在 [1, 104] 范围内
// 0 <= Node.val <= 104
//
// Related Topics 树 深度优先搜索 动态规划 二叉树
// 👍 1229 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.List;

/**
 * 三种方式：暴力递归、记忆化递归
 */
class Solution {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) {
            this.val = val;
        }
    }

    /**
     * 树形动态规划，在递归遍历树的基础上，用递归函数栈保存每一次状态转移的结果
     * 使用长度为2的数组，保存偷或者不偷可获得的最大值
     * @param root
     * @return
     */
    public int rob(TreeNode root) {
        //1. 确定递归参数和返回值：当前偷的树节点，返回一个数组dp, dp[0]表示不偷该节点获得的金额，dp[1]表示偷该节点获得的金额
        int[] dp = robTree(root);
        return Math.max(dp[0], dp[1]);
    }

    public int[] robTree(TreeNode cur) {
        //2. 确定递归结束条件。也就是动态规划的初始值
        if (cur == null) {
            return new int[]{0, 0};
        }
        //3. 确定遍历顺序
        //确定偷或者不偷左节点，分别可以获得的最大金额
        int[] left = robTree(cur.left);
        //确定偷或者不偷右节点，分别可以获得的最大金额
        int[] right = robTree(cur.right);
        //偷该节点，那么不能偷其左右孩子
        int stole = cur.val + left[0] + right[0];
        //不偷该节点，那么可以*考虑*偷其左右孩子
        int noStole = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return new int[]{noStole, stole};
    }
}
//leetcode submit region end(Prohibit modification and deletion)
