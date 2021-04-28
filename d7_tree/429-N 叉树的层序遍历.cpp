//给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。 
//
// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1,null,3,2,4,null,5,6]
//输出：[[1],[3,2,4],[5,6]]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,
//null,13,null,null,14]
//输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
// 
//
// 
//
// 提示： 
//
// 
// 树的高度不会超过 1000 
// 树的节点总数在 [0, 10^4] 之间 
// 
// Related Topics 树 广度优先搜索 
// 👍 150 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node{
    int val;
    vector<Node*> children;
    Node(int x) : val(x), children(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> queue;
        if (root != NULL)  queue.push(root);
        while (!queue.empty()){
            int size = queue.size();
            vector<int> vector;
            for (int i = 0; i < size; ++i) {
                Node* node = queue.front();
                queue.pop();
                vector.push_back(node->val);
                for (auto v : node->children){
                    queue.push(v);
                }
            }
            ans.push_back(vector);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
