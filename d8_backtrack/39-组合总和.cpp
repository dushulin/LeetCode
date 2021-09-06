//给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的
//唯一组合。 
//
// candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。
//
// 对于给定的输入，保证和为 target 的唯一组合数少于 150 个。 
//
// 
//
// 示例 1： 
//
// 
//输入: candidates = [2,3,6,7], target = 7
//输出: [[7],[2,2,3]]
// 
//
// 示例 2： 
//
// 
//输入: candidates = [2,3,5], target = 8
//输出: [[2,2,2,2],[2,3,3],[3,5]] 
//
// 示例 3： 
//
// 
//输入: candidates = [2], target = 1
//输出: []
// 
//
// 示例 4： 
//
// 
//输入: candidates = [1], target = 1
//输出: [[1]]
// 
//
// 示例 5： 
//
// 
//输入: candidates = [1], target = 2
//输出: [[1,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯 
// 👍 1509 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        sort(candidates.begin(), candidates.end());
//        for (int i = 0; i < candidates.size(); ++i) {
//            cout << candidates[i] << endl;
//        }
        backTracing(sum, target, candidates, 0);
        return result;
    }

    void backTracing(int sum, int target, vector<int>& candidates, int startIndex){
        if (sum > target){
            return;
        }
        if (sum == target){
            result.push_back(path);
            return;
        }

        for (int i = startIndex; candidates[startIndex] <= target && i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracing(sum, target, candidates, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> v = {1};
    int target = 1;
    cout << s.combinationSum(v, target).size();
}

//leetcode submit region end(Prohibit modification and deletion)
