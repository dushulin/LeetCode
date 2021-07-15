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
     * 递归法（高度求法）
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
     * 递归法+回溯（深度求法）
     * @return
     */

    int result;
    int maxDepth1(TreeNode* root){
        result = 0;
        if (root == NULL)
            return result;
        getDepth1(root, 1);
        return result;
    }

    /**
     * 1. 参数及返回值：node节点当前深度
     * 2. 确定递归终止条件：node节点的左右孩子都为NULL
     * 3. 确定单层递归逻辑：依次访问node的左右孩子，求其左右孩子的深度。
     * PS：result是全局的，每次getDepth的时候要比较当前node的depth与result的大小。这样可以保证result里面保存的是最大深度
     * @param node
     * @param depth
     * @return
     */
    void getDepth1(TreeNode* node, int depth){
        result = depth > result ? depth : result;//每次更新result的值
        if (node->left == NULL && node->right == NULL)//当前node为叶子节点时，则不需要再求深度了，已经最深了，直接返回
            return ;
        if (node->left){//node有左孩子，则需要继续递归求深度
            depth++;//node的左孩子深度为depth+1
            getDepth1(node->left, depth);
            depth--;//回溯到node节点，其深度为depth
        }
        if (node->right){
            depth++;
            getDepth1(node->right, depth);
            depth--;
        }
        return;
    }

    /**
     * 迭代法：层序遍历
     * @param root
     * @return
     */
    int maxDepth2(TreeNode* root) {
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
