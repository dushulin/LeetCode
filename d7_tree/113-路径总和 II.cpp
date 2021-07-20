//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3], targetSum = 5
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1,2], targetSum = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点总数在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
// 
// 
// Related Topics 树 深度优先搜索 回溯 二叉树 
// 👍 530 👎 0


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
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return result;
        vector<int> oneResult;
        oneResult.push_back(root->val);
        transal(root, targetSum - root->val, oneResult);
        return result;
    }

    void transal(TreeNode* node, int count, vector<int>& oneResult){
        if (node->left == NULL && node->right == NULL && count == 0){
            result.push_back(oneResult);
        }
        if (node->left != NULL){
            count -= node->left->val;
            oneResult.push_back(node->left->val);
            transal(node->left, count, oneResult);
            oneResult.pop_back();
            count += node->left->val;
        }
        if (node->right != NULL){
            count -= node->right->val;
            oneResult.push_back(node->right->val);
            transal(node->right, count, oneResult);
            oneResult.pop_back();
            count += node->right->val;
        }
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(1);
    TreeNode* root1 = new TreeNode(2);
    TreeNode* root2 = new TreeNode(3);
    root->left = root1;
    root1->left = root2;
    cout << solution.pathSum(root, 6).size();
}
//leetcode submit region end(Prohibit modification and deletion)
