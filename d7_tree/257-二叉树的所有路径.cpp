//给定一个二叉树，返回所有从根节点到叶子节点的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3 
// Related Topics 树 深度优先搜索 
// 👍 520 👎 0


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

#include <string>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL){
            return result;
        }
        traversal(root, path, result);
        return result;
    }

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result){
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL){
            transfer(path, result);
            return;
        }
        if (cur->left){
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right){
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

    void transfer(vector<int>& path, vector<string>& result){
        string ans;
        for (int i = 0; i < path.size() - 1; ++i) {
            ans += to_string(path[i]) + "->";
        }
        ans += to_string(path[path.size() - 1]);
        result.push_back(ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
