package stack.leetcode.editor;

//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//
//
//
// 示例 1：
//
//
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
//
//
// 示例 2：
//
//
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
//
//
// 示例 3：
//
//
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s 和 wordDict[i] 仅有小写英文字母组成
// wordDict 中的所有字符串 互不相同
//
// Related Topics 字典树 记忆化搜索 哈希表 字符串 动态规划
// 👍 1495 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        //完全背包或者记忆化回溯
        //1. 完全背包：wordict是物品，s是背包。dp[i] 是指长度为i的字符串，是否可以由worddict组成
        //2. 记忆化回溯：字符串的子串分割，保存中间结果

        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        // 先遍历背包
        for (int i = 1; i <= s.length(); i++){
            //再遍历物品
            for (int j = 0; j <= s.length(); j++){
                //递推公式：如果dp[j]为true，则dp[i]为true的条件是，s.substring(j, i)包含在WordDict中，其中j < i
                if (j < i && dp[j] == 1 && wordDict.contains(s.substring(j, i))){
                    dp[i] = 1;
                }
            }
        }
        return dp[s.length()] == 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "leetcode";
        List<String> wordDict = new ArrayList<>();
        wordDict.add("le");
        wordDict.add("et");
        wordDict.add("code");
        System.out.println(solution.wordBreak(s, wordDict));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
