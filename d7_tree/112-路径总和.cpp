//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和
// targetSum 。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 618 👎 0


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
    int target;
    bool findOne;
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        findOne = false;
        if (root == NULL)
            return false;
        return transal(root, 0);
    }

    bool transal(TreeNode* node, int sum){
        if (node->left == NULL && node->right == NULL && sum + node->val == target) {
            return true;
        }
        if (node->left){
            sum += node->val;
            if (transal(node->left, sum)){
                findOne = true;
            }
            sum -= node->val;
        }
        if (node->right){
            sum += node->val;
            if (transal(node->right, sum)){
                findOne = true;
            }
            sum -= node->val;
        }
        return findOne;
    }
};

/**
 * 最佳解法
 */
class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
        return transal(root, targetSum - root->val);
    }

    /**
     * 递归法
     * 不需要遍历整个树，因此需要返回值，当遇到满足条件的路径直接返回
     * 上面的方法使用不断累加的方式判断，代码比较麻烦
     * 本方法使用递减的方式，初始count为target，递减到0时直接返回
     * @param node
     * @param count
     * @return
     */
    bool transal(TreeNode* node, int count){
        if (node->left == NULL && node->right == NULL && count == 0) {
            return true;
        }
        if (node->left == NULL && node->right == NULL){
            return false;
        }
        if (node->left){
            count -= node->left->val;//这里需要想清楚是减node->val还是node->left->val，可以模拟走一遍递归
            if (transal(node->left, count)){
                return true;
            }
            count += node->left->val;
        }
        if (node->right){
            count -= node->right->val;
            if (transal(node->right, count)){
                return true;
            }
            count += node->right->val;
        }
        return false;
    }
};

class Solution2 {
public:
    int target;
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        if (root == NULL)
            return false;
        return transal(root, 0);
    }

    bool transal(TreeNode* node, int sum){
        if (node->left == NULL && node->right == NULL && sum + node->val == target) {
            return true;
        }
        if (node->left){
            sum += node->val;
            if (transal(node->left, sum)){
                return true;
            }
            sum -= node->val;
        }
        if (node->right){
            sum += node->val;
            if (transal(node->right, sum)){
                return true;
            }
            sum -= node->val;
        }
        return false;
    }
};

int main(){
    Solution2 solution;
    TreeNode* root = new TreeNode(1);
    TreeNode* root1 = new TreeNode(2);
    TreeNode* root2 = new TreeNode(3);
    root->left = root1;
    root1->left = root2;
    cout << solution.hasPathSum(root, 5);
}
//leetcode submit region end(Prohibit modification and deletion)
