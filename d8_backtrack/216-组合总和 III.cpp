//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 
//
// 说明： 
//
// 
// 所有数字都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
// 
//
// 示例 2: 
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
// 
// Related Topics 数组 回溯 
// 👍 345 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> onePath;
    int sum;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        backTracing(k, n, 1);
        return result;
    }

    void backTracing(int k, int n, int startIndex){
        if (onePath.size() == k && sum == n){
            result.push_back(onePath);
            return;
        }
        for (int i = startIndex; i <= 10 - (k - onePath.size()) && sum < n; ++i) {
            onePath.push_back(i);
            sum += i;
            backTracing(k, n, i + 1);
            sum -= i;
            onePath.pop_back();
        }
    }
};

int main(){
    Solution s;
    cout << s.combinationSum3(3, 7).size() << endl;

}

/**
 * class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (sum > targetSum) { // 剪枝操作
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // 剪枝
            sum += i; // 处理
            path.push_back(i); // 处理
            backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex
            sum -= i; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear();   // 可以不加
        backtracking(n, k, 0, 1);
        return result;
    }
};

 */
//leetcode submit region end(Prohibit modification and deletion)
