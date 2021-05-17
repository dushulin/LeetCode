//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 105] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 506 👎 0


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
     * 递归法
     * [2,null,3,null,4,null,5,null,6]
     * @param root
     * @return
     */
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }

    int getDepth(TreeNode* node){
        if (node == NULL)
            return 0;
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        if (node->left == NULL && node->right != NULL)
            return 1 + right;
        if (node->left != NULL && node->right == NULL)
            return 1+ left;
        return 1 + min(left, right);
    }

    /**
     * 迭代法：层序遍历
     * @param root
     * @return
     */
    int minDepth2(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        int depth = 0;
        while (!queue.empty()){
            int size = queue.size();
            bool isLeft = false;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left == NULL && node->right == NULL)
                    isLeft = true;
                if (node->left != NULL) queue.push(node->left);
                if (node->right != NULL) queue.push(node->right);
            }
            depth++;
            if (isLeft)
                break;
        }
        return depth;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(2);
    TreeNode* root1 = new TreeNode(3);
    TreeNode* root2 = new TreeNode(4);
    TreeNode* root3 = new TreeNode(5);
    TreeNode* root4 = new TreeNode(6);
    root->right = root1;
    root1->right = root2;
    root2->right = root3;
    root3->right = root4;
//    root->left = root1;
//    root->right = root2;
//    root2->left = root3;
//    root2->right = root4;
    cout << solution.minDepth(root);
}
//leetcode submit region end(Prohibit modification and deletion)
