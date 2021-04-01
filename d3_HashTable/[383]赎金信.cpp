//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面
//的字符构成。如果可以构成，返回 true ；否则返回 false。 
//
// (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。) 
//
// 
//
// 注意： 
//
// 你可以假设两个字符串均只含有小写字母。 
//
// canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
// 
// Related Topics 字符串 
// 👍 135 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;//<a, a出现的次数>
        //初始化map，统计每个字母出现的次数
        for(char m : magazine){
            umap[m]++;
        }
        //遍历ransomNote，map中找到字母进行减一操作，直到为0，从map中删除该key。
        for(char r : ransomNote){
            if(umap.find(r) != umap.end()){
                umap[r]--;
                if(umap[r] == 0)
                    umap.erase(r);
            }else
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
