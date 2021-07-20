//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。 
//
// 假设二叉树中至少有一个节点。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: root = [2,1,3]
//输出: 1
// 
//
// 示例 2: 
//
// 
//
// 
//输入: [1,2,3,4,null,5,6,null,null,7]
//输出: 7
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [1,104] 
// -231 <= Node.val <= 231 - 1 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 186 👎 0


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
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    /**
     * 层序遍历（遍历到最底层，记录第一个值即可）
     * @param root
     * @return
     */
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int result;
        while (!queue.empty()){
            int size = queue.size();
            result = queue.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left){
                    queue.push(node->left);
                }
                if (node->right){
                    queue.push(node->right);
                }
            }
        }
        return result;
    }

    /**
     * 迭代法
     * @param root
     * @return
     */

    int MAX_DEPTH;
    int LEFT_VALUE;
    int findBottomLeftValue1(TreeNode* root) {

    }

    /**
     * 可以类比104. 二叉树的最大深度来求解
     * @param node
     * @param leftDepth
     */
    void transal(TreeNode* node, int depth){//1. 参数及返回值：node节点的深度
        //2. 终止条件。访问到叶子节点，就更新当前最大深度和左叶子的节点值
        if (node->left == NULL && node->right == NULL){
            MAX_DEPTH = depth;
            LEFT_VALUE = node->val;
        }
        if (node->left){
            depth++;
            transal(node->left, depth);
            depth--;
        }
        if (node->right){
            depth++;
            transal(node->right, depth);
            depth--;
        }
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
