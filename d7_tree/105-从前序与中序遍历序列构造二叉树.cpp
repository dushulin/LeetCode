//给定一棵树的前序遍历 preorder 与中序遍历 inorder。请构造二叉树并返回其根节点。 
//
// 
//
// 示例 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均无重复元素 
// inorder 均出现在 preorder 
// preorder 保证为二叉树的前序遍历序列 
// inorder 保证为二叉树的中序遍历序列 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 1121 👎 0


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        return transal(preorder, inorder);
    }

    /**
     * 迭代法
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode* transal(vector<int> preorder, vector<int> inorder){
        //1. 如果前序数组为空，返回NULL
        if (preorder.empty())
            return nullptr;
        //2. 取前序数组的第一个值，作为root
        int rootValue = preorder[0];
        auto* root = new TreeNode(rootValue);

        //3. 如果前序数组只有一个元素，说明是叶子节点，直接返回
        if (preorder.size() == 1)
            return root;

        //4. 根据rootValue切割中序数组
        int delimiter;
        for (delimiter = 0; delimiter < inorder.size(); ++delimiter) {
            if (inorder[delimiter] == rootValue)
                break;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiter);
        vector<int> rightInorder(inorder.begin() + delimiter + 1, inorder.end());

        //5. 先去掉前序数组的首个元素，再根据inorder切割后的数组长度，切割前序数组
        auto i = preorder.begin();
        preorder.erase(i);
        vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + leftInorder.size(), preorder.end());

        cout << "--------" << endl;
        cout << "leftInorder" << endl;
        for (int j = 0; j < leftInorder.size(); ++j) {
            cout << leftInorder[j] << ", ";
        }
        cout << endl;
        cout << "rightInorder" << endl;
        for (int j = 0; j < rightInorder.size(); ++j) {
            cout << rightInorder[j] << ", ";
        }
        cout << endl;
        cout << "leftPreorder" << endl;
        for (int j = 0; j < leftPreorder.size(); ++j) {
            cout << leftPreorder[j] << ", ";
        }
        cout << endl;
        cout << "rightPreorder" << endl;
        for (int j = 0; j < rightPreorder.size(); ++j) {
            cout << rightPreorder[j] << ", ";
        }
        cout << endl;

        root->left = transal(leftPreorder, leftInorder);
        root->right = transal(rightPreorder, rightInorder);

        return root;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
