//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 1373 👎 0


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
     * 递归法：
     * 1. 确定参数和返回值：需要比较的是左右子树的对称情况，因此输入参数是左右子树，返回值是 是否对称
     * 2. 确定结束条件：
     *  a. 如果左右子树都为NULL，return true
     *  b. 如果左右子树有一个为NULL，一个不为NULL，return false
     *  c. 如果左右子树都不为NULL，但是值不相等，return false
     *  d. 除了上述三种情况外，只剩下左右子树都不为NULL，且值相等，return true
     * 3. 确定单层递归逻辑
     * @param root
     * @return
     */
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL)  return true;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right != NULL) return false;
        else if(left != NULL && right != NULL && left->val != right->val)   return false;

        //以上情况都排除之后，可以进入单层递归逻辑，开始调用自身
        bool outside = compare(left->left, right->right);//左子树的左子树，与右子树的右子树比较，即外侧是否相等
        bool inside = compare(left->right, right->left);//左子树的右子树，与右子树的左子树比较，即内侧是否相等
        return outside && inside;//左右子树的外侧和内侧都必须相等，才算对称
    }

    /**
     * 迭代法：使用队列或者栈
     * 思路：将节点的左右子节点入队，两两比较
     * @param root
     * @return
     */
    bool isSymmetric2(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);
        while (!queue.empty()){
            TreeNode* left = queue.front();
            queue.pop();
            TreeNode* right = queue.front();
            queue.pop();
            //如果当前比较的左右节点为空，说明是对称的，但是当前比较的左右节点不可能有子节点了，所以直接下一层循环
            if (left == NULL && right == NULL)
                continue;
            //左节点或右节点为空，或者都不为空但是值不相等，return false 不可能对称
            if (left == NULL || right == NULL || left->val != right->val)
                return false;
            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
