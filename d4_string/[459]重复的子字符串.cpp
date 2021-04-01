//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。 
//
// 示例 1: 
//
// 
//输入: "abab"
//
//输出: True
//
//解释: 可由子字符串 "ab" 重复两次构成。
// 
//
// 示例 2: 
//
// 
//输入: "aba"
//
//输出: False
// 
//
// 示例 3: 
//
// 
//输入: "abcabcabcabc"
//
//输出: True
//
//解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
// 
// Related Topics 字符串 
// 👍 469 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0)
            return false;
        int next[s.size()];
        getNext(next, s);
        if(next[s.size() - 1] != -1 && s.size() % (s.size() - (next[s.size() - 1] + 1)) == 0)
            return true;
        return false;
    }

    void getNext(int* next, const string& s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1])
                j = next[j];
            if(s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
