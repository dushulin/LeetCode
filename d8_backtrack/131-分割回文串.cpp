//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 回溯 
// 👍 826 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <utility>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        backTracing(0, s);
        return result;
    }

    void backTracing(int startIndex, const string& s){
        if (startIndex >= s.size()){
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); ++i) {
            if (isReposition(s, startIndex, i)){
                string sub_s = s.substr(startIndex, i - startIndex + 1);
                path.push_back(sub_s);//获取[startIndex, i]的子串
            } else{
                continue;
            }
            backTracing(i + 1, s);//获取
            path.pop_back();
        }
    }

    bool isReposition(const string& s, int start, int end){
        string cur_s = s.substr(start, end - start + 1);
        cout << "start: " << start << ", end: " << end << ", cur_s: " << cur_s << ", ";
        if (cur_s.empty()){
            return false;
        }
        for (int i = 0, j = cur_s.size() - 1; i < j; ++i, j--) {
            if (cur_s[i] != cur_s[j]){
                cout << "false" << endl;
                return false;
            }
        }
        cout << "true" << endl;
        return true;
    }
};

int main(){
    Solution s;
//    cout << s.isReposition("ababa", 0, 6);
    vector<vector<string>> r = s.partition("aaa");
    cout << r.size() << endl;
}
//leetcode submit region end(Prohibit modification and deletion)
