//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 535 👎 0


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        return transal(inorder, postorder);

    }

    /**
     * 迭代法（如何切割件md文件）
     * 根据后序数组的最后一个值，切割中序数组，再对切割后的两个数组分别做同样的步骤。
     * @param inorder       中序数组
     * @param postorder     后序数组
     * @return              返回本地迭代获取的节点值
     */
    TreeNode* transal(vector<int>& inorder, vector<int>& postorder){
        //1. 判断后序数组是否为空
        if (postorder.empty())
            return NULL;
        //2. 取得后序数组的最后一个值，作为节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        if (inorder.size() == 1)
            return root;
        //3. 根据rootValue切割中序数组
        int delimiter;
        for (delimiter = 0; delimiter < inorder.size(); ++delimiter) {
            if (inorder[delimiter] == rootValue)
                break;
        }
        //左闭右开：[0, delimiter)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiter);
        vector<int> rightInorder(inorder.begin() + delimiter + 1, inorder.end());

        //4. 根据左中序数组和右中序数组来切割后序数组
        //4.1 先去掉后序数组的最后一个元素，因为已经作为root了
        postorder.resize(postorder.size() - 1);
        //4.2 根据左中序数组的长度可以得到左后序数组
        vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostOrder(postorder.begin() + leftInorder.size(), postorder.end());

        cout << "---------" << endl;
        cout << "leftInorder: ";
        for (int i = 0; i < leftInorder.size(); ++i) {
            cout << leftInorder[i] << ", ";
        }
        cout << endl;
        cout << "rightInorder: ";
        for (int i = 0; i < rightInorder.size(); ++i) {
            cout << rightInorder[i] << ", ";
        }
        cout << endl;
        cout << "leftPostOrder: ";
        for (int i = 0; i < leftPostOrder.size(); ++i) {
            cout << leftPostOrder[i] << ", ";
        }
        cout << endl;
        cout << "rightPostOrder: ";
        for (int i = 0; i < rightPostOrder.size(); ++i) {
            cout << rightPostOrder[i] << ", ";
        }
        cout << endl;

        //5. 根据切割好的子中序和子后序数组，构造root的左右节点
        root->left = transal(leftInorder, leftPostOrder);
        root->right = transal(rightInorder, rightPostOrder);
        return root;
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution s;
    s.buildTree(inorder, postorder);
}
//leetcode submit region end(Prohibit modification and deletion)
