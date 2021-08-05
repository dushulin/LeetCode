//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 1150 👎 0


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
#include <climits>

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
     * 递归法：主要熟悉BST的定义
     * BST：二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树：
     * 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
     * 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
     * 它的左、右子树也分别为二叉排序树。
     * @param root
     * @return
     */
    long long MAX_VALUE = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        bool left = isValidBST(root->left);
        if (MAX_VALUE < root->val){
            MAX_VALUE = root->val;
        } else{
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
    }

    /**
     * 迭代法：利用二叉搜索树中序遍历数组有序的特性
     * @param root
     * @return
     */
    bool isValidBST1(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur != NULL || !stack.empty()){
            if (cur != NULL){
                stack.push(cur);
                cur = cur->left;
            } else{
                cur = stack.top();
                stack.pop();
                if (cur->val > MAX_VALUE){
                    MAX_VALUE = cur->val;
                } else{
                    return false;
                }
                cur = cur->right;
            }
        }
        return true;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(6);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    Solution s;
    cout << s.isValidBST1(root);
}
//leetcode submit region end(Prohibit modification and deletion)
