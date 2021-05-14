//给定一个二叉树，找出其最大深度。 
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例： 
//给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
// Related Topics 树 深度优先搜索 递归 
// 👍 877 👎 0


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
#include <queue>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /**
     * 递归法
     * 1. 确定输入参数和返回值：int getDepth(TreeNode* node)
     * 2. 确定递归终止条件：left == NULL && right == NULL return 0;
     * 3. 确定单层递归逻辑：maxLevel = max(left.maxLevel, right,maxLevel)
     * @param root
     * @return
     */
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return getDepth(root) + 1;
    }

    int getDepth(TreeNode* node){
        if (node->left == NULL && node->right == NULL)
            return 0;
        if (node->left == NULL && node->right != NULL)
            return getDepth(node->right) + 1;
        else if (node->left != NULL && node->right == NULL)
            return getDepth(node->left) + 1;
        else
            return max(getDepth(node->left), getDepth(node->right)) + 1;
    }

    /**
     * 迭代法：层序遍历
     * @param root
     * @return
     */
    int maxDepth1(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int depth = 0;
        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left != NULL)
                    queue.push(node->left);
                if (node->right != NULL)
                    queue.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
