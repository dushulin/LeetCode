//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
// 👍 80 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size();
        //计算填充后的字符串长度
        int spaceCount = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                spaceCount++;
        }
        //重新分配字符串长度
        int newSize = s.size() + 2 * spaceCount;
        s.resize(newSize);
        //从后往前遍历字符串，进行替换操作
        for(int i = oldSize - 1, j = newSize - 1; i >=0 ;i--, j--){
            if(s[i] != ' '){
                s[j] = s[i];
            }else{
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
