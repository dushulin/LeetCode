//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。 
//
// 
//
// 示例： 
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
// 
//
// 
//
// 提示： 
//
// 
// 树中至少有 2 个节点。 
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 
//相同 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 二叉树 
// 👍 264 👎 0


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
     * 利用BST的特性，中序遍历有序
     * @param root
     * @return
     */
    int getMinimumDifference(TreeNode* root) {
        //1. 先将BST转成中序遍历数组
        vector<int> result;
        transal(root, result);
        //2. 遍历数组，找到最小值
        int ans = INT16_MAX;
        for (int i = 1; i < result.size(); ++i) {
            ans = std::min(ans, result[i] - result[i - 1]);
        }
        return ans;
    }

    /**
     * BST的中序递归遍历
     * @param node
     * @return
     */
    void transal(TreeNode* node, vector<int>& vec){
        if (node == NULL){
            return ;
        }
        transal(node->left, vec);//左
        vec.push_back(node->val);//中
        transal(node->right, vec);//右
    }
};
//leetcode submit region end(Prohibit modification and deletion)
