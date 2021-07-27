//给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一
//个。 
//
// 更正式地说，root.val = min(root.left.val, root.right.val) 总成立。 
//
// 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [2,2,5,null,null,5,7]
//输出：5
//解释：最小的值是 2 ，第二小的值是 5 。
// 
//
// 示例 2： 
//
// 
//输入：root = [2,2,2]
//输出：-1
//解释：最小的值是 2, 但是不存在第二小的值。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 25] 内 
// 1 <= Node.val <= 231 - 1 
// 对于树中每个节点 root.val == min(root.left.val, root.right.val) 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 198 👎 0


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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int ans = -1;
    int rootValue;
    int findSecondMinimumValue(TreeNode* root) {
        rootValue = root->val;
        level(root);
        return ans;
    }

    void level(TreeNode* root){
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()){
            TreeNode* node = queue.front();
            if (node->val > rootValue && ans == -1){
                ans = node->val;
            }
            if (node->val > rootValue && node->val < ans){
                ans = node->val;
            }
            queue.pop();
            if (node->left != nullptr){
                queue.push(node->left);
            }
            if (node->right != nullptr){
                queue.push(node->right);
            }
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(8);
    TreeNode* node2 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
    Solution s;
    cout << s.findSecondMinimumValue(root);
}
//leetcode submit region end(Prohibit modification and deletion)
