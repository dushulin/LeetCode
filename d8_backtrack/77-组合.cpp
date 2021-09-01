//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 数组 回溯 
// 👍 686 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> onePath;
    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result;
    }

    void backTracking(int n, int k, int startIndex){
        if (onePath.size() == k){
            result.push_back(onePath);
            return;
        }

        for (int i = startIndex; i <= n; ++i) {
            onePath.push_back(i);
            backTracking(n, k, i + 1);
            onePath.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
