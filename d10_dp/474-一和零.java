//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//
//
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
//
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
//
//
//
//
// 示例 1：
//
//
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//输出：4
//解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
//其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于
//n 的值 3 。
//
//
// 示例 2：
//
//
//输入：strs = ["10", "0", "1"], m = 1, n = 1
//输出：2
//解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
//
//
//
//
// 提示：
//
//
// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] 仅由 '0' 和 '1' 组成
// 1 <= m, n <= 100
//
// Related Topics 数组 字符串 动态规划
// 👍 620 👎 0


import com.sun.tools.javac.util.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //01背包：相当于背包有两层，一层放0，一层放1，物品的重量和价值相等，且一个物品放入时，每次都要放到上下两层中
    public int findMaxForm(String[] strs, int m, int n) {
        //1. dp数组：dp[i][j]，表示第一层容量为i，第二层容量为j的背包，最多可装入的物品个数。
        int[][] dp = new int[m + 1][n + 1];
        //2. 初始化：dp[0][0] = 0。且由于m和n[1, 100]，那么其他位置都初始化为0即可
        //3. 递推公式：dp[i][j]可以有两种选择
        //      a. 放入当前物品（该物品有zeroNum个0，oneNum个1）。dp[i - zeroNum][j - oneNum] + 1
        //      b. 不放入当前物品。dp[i][j]
        //4. 确定遍历顺序：同样是01背包，所以还是先遍历物品在遍历背包。
        int zeroNum = 0;
        int oneNum = 0;
        List<List<Integer>> list = new ArrayList<>();
        for (String s : strs) {
            for (int i = 0; i < s.length(); i++){
                if (s.charAt(i) - '0' == 0){
                    zeroNum++;
                }else {
                    oneNum++;
                }
            }
            List<Integer> oneList = new ArrayList<>();
            oneList.add(zeroNum);
            oneList.add(oneNum);
            list.add(oneList);
            zeroNum = 0;
            oneNum = 0;
        }
        System.out.println(list);
        for (int z = 0; z < strs.length; z++){
            for (int i = m; i >= list.get(z).get(0); i--){
                for (int j = n; j >= list.get(z).get(1); j--){
                    dp[i][j] = Math.max(dp[i][j], dp[i - list.get(z).get(0)][j - list.get(z).get(1)] + 1);
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        String[] strs = {"10", "0001", "111001", "1", "0"};
        int m = 5;
        int n = 3;
//        String[] strs = {"10", "0", "1"};
//        int m = 1;
//        int n = 1;
        System.out.println(s.findMaxForm(strs, m, n));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
