//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
//
//
//
// 示例：
//
//
//输入：S = "ababcbacadefegdehijhklij"
//输出：[9,7,8]
//解释：
//划分结果为 "ababcbaca", "defegde", "hijhklij"。
//每个字母最多出现在一个片段中。
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
//
//
//
//
// 提示：
//
//
// S的长度在[1, 500]之间。
// S只包含小写字母 'a' 到 'z' 。
//
// Related Topics 贪心 哈希表 双指针 字符串
// 👍 594 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
     * 贪心法：
     * 1. 找到每个字母在字符串最后一次出现的下标
     * 2. 遍历字符串，根据当前字母不断更新最远下标，当当前字母的下标等于最远下标时，该点就是分割点
     * @param s
     * @return
     */
    public List<Integer> partitionLabels(String s) {
        List<Integer> result = new ArrayList<>();
        List<Integer> cutPoint = new ArrayList<>();
        cutPoint.add(0);
        int[] edge = new int[26];
        for (int i = 0; i < s.length(); i++){
            edge[s.charAt(i) - 'a'] = i;
        }

        int far = 0;
        for (int i = 0; i < s.length(); i++){
            far = Math.max(far, edge[s.charAt(i) - 'a']);
            if (far == i){
                cutPoint.add(i + 1);
                result.add(cutPoint.get(cutPoint.size() - 1) - cutPoint.get(cutPoint.size() - 2));
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.partitionLabels("a"));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
