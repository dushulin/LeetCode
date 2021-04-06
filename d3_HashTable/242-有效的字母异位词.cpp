//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 示例 1: 
//
// 输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "rat", t = "car"
//输出: false 
//
// 说明: 
//你可以假设字符串只包含小写字母。 
//
// 进阶: 
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
// Related Topics 排序 哈希表 
// 👍 348 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ans(26, 0);
        //对于s，每个字母出现一次，在相应的下标+1
        for(int i = 0; i < s.size(); i++){
            ans[s[i] - 'a']++;
        }
        //对于t，每个字母出现一次，在相应下标-1
        for(int i = 0; i < t.size(); i++){
            ans[t[i] - 'a']--;
        }
        //验证ans数组是不是全为0
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != 0){
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
