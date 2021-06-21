//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -104 <= Node.val <= 104 
// 
// Related Topics 树 深度优先搜索 递归 
// 👍 684 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x). left(NULL), right(NULL) {}
};
class Solution {
public:
    /**
     * 递归法
     * @param root
     * @return
     */
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }

    int getDepth(TreeNode* cur){
        if (cur == NULL)
            return 0;
        int leftDepth = getDepth(cur->left);
        //注意：这里要在计算完leftDepth之后，判断一下是否为-1，如果是的话，直接返回。因为后面的过程都不需要计算了。
        if (leftDepth == -1)
            return -1;
        int rightDepth = getDepth(cur->right);
        if (rightDepth == -1)
            return -1;
        if (abs(leftDepth - rightDepth) > 1)
            return -1;
        else
            return max(leftDepth, rightDepth) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
