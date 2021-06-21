//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。 
//
// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层
//为第 h 层，则该层包含 1~ 2h 个节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,4,5,6]
//输出：6
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目范围是[0, 5 * 104] 
// 0 <= Node.val <= 5 * 104 
// 题目数据保证输入的树是 完全二叉树 
// 
//
// 
//
// 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？ 
// Related Topics 树 二分查找 
// 👍 485 👎 0


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
     * 层序遍历
     * @param root
     * @return
     */
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int count = 0;
        while (!queue.empty()){
            int size = queue.size();
            count += size;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left != NULL)
                    queue.push(node->left);
                if (node->right != NULL)
                    queue.push(node->right);
            }
        }
        return count;
    }

    /**
     * 递归法
     * @param root
     * @return
     */
    int countNodes1(TreeNode* root) {
        if (root == NULL)
            return 0;
        return getCount(root);
    }

    int getCount(TreeNode* node){
        if (node == NULL)
            return 0;
        int left = getCount(node->left);
        int right = getCount(node->right);
        return left + right + 1;
    }

    /**
     * 根据完全二叉树的特性
     * @param root
     * @return
     */
    int countNodes2(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left){
            left = left->left;
            leftHeight++;
        }
        while (right){
            right = right->right;
            rightHeight++;
        }
        if (leftHeight == rightHeight)
            return (2 << leftHeight) - 1;
        return countNodes2(root->left) + countNodes2(root->right) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
