//计算给定二叉树的所有左叶子之和。 
//
// 示例： 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24 
//
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 319 👎 0


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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = sumOfLeftLeaves(root->left);//左 左子树左叶子之和
        int right = sumOfLeftLeaves(root->right);//右 右子树左叶子之和

        int mid = 0;//中
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL){//通过左叶子的父节点（即root节点）判断其左儿子是否为左叶子
            mid = root->left->val;
        }
        return mid + left + right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
