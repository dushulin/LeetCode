//给定一个字符串，逐个翻转字符串中的每个单词。
//
// 说明： 
//
// 
// 无空格字符构成一个 单词 。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 
//
// 示例 1： 
//
// 输入："the sky is blue"
//输出："blue is sky the"
// 
//
// 示例 2： 
//
// 输入："  hello world!  "
//输出："world! hello"
//解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入："a good   example"
//输出："example good a"
//解释：如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 示例 4： 
//
// 输入：s = "  Bob    Loves  Alice   "
//输出："Alice Loves Bob"
//
//
// 示例 5： 
//
// 输入：s = "Alice does not even like bob"
//输出："bob like even not does Alice"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 包含英文大小写字母、数字和空格 ' ' 
// s 中 至少存在一个 单词 
// 
//
// 
// 
//
// 
//
// 进阶： 
//
// 
// 请尝试使用 O(1) 额外空间复杂度的原地解法。 
// 
// Related Topics 字符串 
// 👍 289 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
        //先去掉多余的空格，转化为首位无空格，且每个单词之间只间隔一个空格的形式。双指针
        int i, j;
        for(i = 0, j = 0; j < s.size(); j++){
            if(s[j] != ' '){//如果是字母的话，直接赋值
                s[i++] = s[j];
            }else{
                if(j >= 1 && s[j - 1] != ' '){//如果当前是空格，但是前一个是字母，直接赋值
                    s[i++] = s[j];
                }else{//如果当前是空格，且前一个也是空格，跳过
                    continue;
                }
            }
        }
        if(i - 1 > 0 && s[i - 1] == ' ')
            s.resize(i - 1);
        else
            s.resize(i);

        //对整个字符串翻转
        reverseString(s, 0, s.size());

        //对每个子字符串内部翻转
        for(int k = 0, m = 0; k < s.size();){
            if(m < s.size() && s[m] != ' '){
                m++;
            }else{
                reverseString(s, k, m);
                k = m + 1;
                m = m + 1;
            }
        }
        return s;
    }

    //翻转字符串内[start, end)之间的字符
    string& reverseString(string& s, int start, int end){
        for(int i = start, j = end - 1; i < start + (end - start) / 2; i++, j--){
            swap(s[i], s[j]);
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
