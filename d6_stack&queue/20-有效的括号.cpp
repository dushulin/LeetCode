//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 示例 4： 
//
// 
//输入：s = "([)]"
//输出：false
// 
//
// 示例 5： 
//
// 
//输入：s = "{[]}"
//输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由括号 '()[]{}' 组成 
// 
// Related Topics 栈 字符串 
// 👍 2276 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(')');
            }else if(s[i] == '{'){
                st.push('}');
            }else if(s[i] == '['){
                st.push(']');
            }else if(st.empty() || st.top() != s[i]){//如果还没匹配到最后一个字符，stack就空了，或者，当前匹配的符号与栈顶元素不相等。这两种情况都说明匹配失败
                return false;
            }else{//栈不为空，且，当前匹配的符号跟栈顶元素相等，则当前符号匹配成功，将栈顶元素弹出
                st.pop();
            }
        }
        return st.empty();//匹配到最后，栈为空才说明所有符号都匹配成功，若栈不为空，则说明有多余的符号。
    }
};
//leetcode submit region end(Prohibit modification and deletion)
