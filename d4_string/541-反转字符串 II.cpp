//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。 
//
// 
// 如果剩余字符少于 k 个，则将剩余字符全部反转。 
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。 
// 
//
// 
//
// 示例: 
//
// 输入: s = "abcdefg", k = 2
//输出: "bacdfeg"
// 
//
// 
//
// 提示： 
//
// 
// 该字符串只包含小写英文字母。 
// 给定字符串的长度和 k 在 [1, 10000] 范围内。 
// 
// Related Topics 字符串 
// 👍 117 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseStr(string s, int k) {
        //将String转为字符数组
        vector<char> result;
        result.resize(s.size());
        result.assign(s.begin(), s.end());

        int start;
        int end;
        for(int i = 0; i < s.size();){
            if(s.size() - i < k){
                start = i;
                end = s.size();
                i = s.size();//最后一组转换，直接将i置为size()
            }else if (s.size() - i >= k && s.size() - i < 2 * k){
                start = i;
                end = i + k;
                i = s.size();//最后一组转换，但是只转换前K个。同样直接将i置为size()
            }else{
                start = i;
                end = i + k;
                i += (2 * k);
            }
            //对[start, end)内的字符进行翻转
            reverseString(result, start, end);
        }
        s.clear();
        return s.assign(result.begin(), result.end());
    }
    void reverseString(vector<char>& s, int start, int end) {
        for(int i = start, j = end - 1; i < start + (end - start) / 2; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
