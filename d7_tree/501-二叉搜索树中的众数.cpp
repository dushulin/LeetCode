//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。 
//
// 假定 BST 有如下定义： 
//
// 
// 结点左子树中所含结点的值小于等于当前结点的值 
// 结点右子树中所含结点的值大于等于当前结点的值 
// 左子树和右子树都是二叉搜索树 
// 
//
// 例如： 
//给定 BST [1,null,2,2], 
//
//    1
//    \
//     2
//    /
//   2
// 
//
// 返回[2]. 
//
// 提示：如果众数超过1个，不需考虑输出顺序 
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内） 
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 
// 👍 329 👎 0


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

/**
 * https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.md
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
    vector<int> result;
    int MAX_COUNT = INT32_MIN;
    TreeNode* pre = NULL;
    int count;
    vector<int> findMode(TreeNode* root) {
        transal(root);
        return result;
    }

    void transal(TreeNode* node){
        if (node == NULL){
            return;
        }
        transal(node->left);
        if (pre == NULL){//说明当前节点是中序遍历数组的第一个节点
            count = 1;
        }else if (node->val == pre->val){//与前一个节点值相同
            count++;
        } else{//与前一个节点值不同，置count值为1
            count = 1;
        }

        pre = node;//更新上一个节点，必须在这里，因为要防止pre为NULL，导致后面pre->val出错。

        if (count == MAX_COUNT){//当前频率等于最大频率，直接将该节点的值写入结果集
            result.push_back(node->val);
        }
        if (count > MAX_COUNT){//当前频率超过了最大频率，更新
            result.clear();//最新的众数已经大于MAX_COUNT了，那么之前的众数都失效
            result.push_back(pre->val);
            MAX_COUNT = count;
        }
        transal(node->right);
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    root->right = node1;
    node1->left = node2;
    vector<int> ans = s.findMode(root);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
