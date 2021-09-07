//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
// Related Topics 数组 回溯 
// 👍 684 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backTracing(sum, target, 0, candidates);
        return result;
    }

    void backTracing(int sum, int target, int startIndex, vector<int>& candidates){
        if (sum > target){
            return;
        }
        if (sum == target){
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && candidates[startIndex] <= target; ++i) {
            if (i != startIndex && candidates[i] == candidates[i - 1]){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracing(sum, target, i + 1, candidates);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> v = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int target = 30;
    vector<vector<int>> r = s.combinationSum2(v, target);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout << r[i][j] << ", ";
        }
        cout << endl;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
