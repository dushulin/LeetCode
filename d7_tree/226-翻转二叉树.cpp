//翻转一棵二叉树。 
//
// 示例： 
//
// 输入： 
//
//      4
//   /   \
//  2     7
// / \   / \
//1   3 6   9 
//
// 输出： 
//
//      4
//   /   \
//  7     2
// / \   / \
//9   6 3   1 
//
// 备注: 
//这个问题是受到 Max Howell 的 原问题 启发的 ： 
//
// 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。 
// Related Topics 树 
// 👍 833 👎 0


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
#include <stack>
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
     * 递归写法
     * @param root
     * @return
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    /**
     * DFS：前序遍历非递归写法
     * @param root
     * @return
     */
    TreeNode* invertTree2(TreeNode* root) {
        if (root == NULL)
            return root;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            swap(node->right, node->left);//交换左右节点
            if (node->right != NULL)
                stack.push(node->right);
            if (node->left != NULL)
                stack.push(node->left);
        }
        return root;
    }

    /**
     * BFS：层序遍历写法
     * @param root
     * @return
     */
    TreeNode* invertTree3(TreeNode* root) {
        if (root == NULL)
            return root;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            swap(node->right, node->left);
            if (node->left != NULL)
                queue.push(node->left);
            if (node->right != NULL)
                queue.push(node->right);
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
