//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = '23'
//输出：['ad','ae','af','bd','be','bf','cd','ce','cf']
// 
//
// 示例 2： 
//
// 
//输入：digits = ''
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = '2'
//输出：['a','b','c']
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
// Related Topics 哈希表 字符串 回溯 
// 👍 1484 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    map<char, vector<string>> numToAlpha;
    vector<string> result;
    string onePath;

    void initMap(){
        numToAlpha['2'] = {"a", "b", "c"};
        numToAlpha['3'] = {"d", "e", "f"};
        numToAlpha['4'] = {"g", "h", "i"};
        numToAlpha['5'] = {"j", "k", "l"};
        numToAlpha['6'] = {"m", "n", "o"};
        numToAlpha['7'] = {"p", "q", "r", "s"};
        numToAlpha['8'] = {"t", "u", "v"};
        numToAlpha['9'] = {"w", "x", "y", "z"};
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        onePath.clear();
        initMap();
        if (digits.length() == 0)
            return result;
        backTracing(digits.size(), 0, digits);
        return result;
    }
    
    void backTracing(int numSize, int curNumIndex, const string& digits){
        if (onePath.length() == numSize){
            result.push_back(onePath);
            return;
        }
        for (int i = 0; curNumIndex < digits.size() && i < numToAlpha[digits[curNumIndex]].size(); ++i) {
            onePath.append(numToAlpha[digits[curNumIndex]][i]);
            backTracing(numSize, curNumIndex + 1, digits);
            onePath.pop_back();
        }
    }
};

int main(){
    Solution s;
    cout << s.letterCombinations("").size();
}
//leetcode submit region end(Prohibit modification and deletion)
