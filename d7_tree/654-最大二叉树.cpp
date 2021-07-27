//给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下： 
//
// 
// 二叉树的根是数组 nums 中的最大元素。 
// 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。 
// 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。 
// 
//
// 返回有给定数组 nums 构建的 最大二叉树 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,2,1,6,0,5]
//输出：[6,3,5,null,2,0,null,null,1]
//解释：递归调用如下所示：
//- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//        - 空数组，无子节点。
//        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//            - 空数组，无子节点。
//            - 只有一个元素，所以子节点是一个值为 1 的节点。
//    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//        - 只有一个元素，所以子节点是一个值为 0 的节点。
//        - 空数组，无子节点。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[3,null,2,null,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 1000 
// nums 中的所有整数 互不相同 
// 
// Related Topics 栈 树 数组 分治 二叉树 单调栈 
// 👍 305 👎 0


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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        return transal(nums);
    }

    TreeNode* transal(vector<int>& nums){
        if (nums.empty())
            return nullptr;

        if (nums.size() == 1){
            return new TreeNode(nums[0]);
        }

        int rootValue = nums[0];
        int delimiter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (rootValue < nums[i]){
                rootValue = nums[i];
                delimiter = i;
            }
        }
        auto* root = new TreeNode(rootValue);
        vector<int> left(nums.begin(), nums.begin() + delimiter);
        vector<int> right(nums.begin() + delimiter + 1, nums.end());

        cout << "----------------" << endl;
        cout << "left" << endl;
        for (int i = 0; i < left.size(); ++i) {
            cout << left[i] << ", ";
        }
        cout << endl;
        cout << "right" << endl;
        for (int i = 0; i < right.size(); ++i) {
            cout << right[i] << ", ";
        }
        cout << endl;

        root->left = transal(left);
        root->right = transal(right);

        return root;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,6,0,5};
    s.constructMaximumBinaryTree(nums);
}
//leetcode submit region end(Prohibit modification and deletion)
