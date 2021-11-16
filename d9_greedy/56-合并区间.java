//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
//
// 示例 1:
//
// 输入: N = 10
//输出: 9
//
//
// 示例 2:
//
// 输入: N = 1234
//输出: 1234
//
//
// 示例 3:
//
// 输入: N = 332
//输出: 299
//
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。
// Related Topics 贪心 数学
// 👍 210 👎 0


import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //本题使用数学运算的方法
    //也可以将int n转化为char数组来做，更加直观
    //贪心法：从后往前遍历，若后一个比前一个小，则将后一个变为9，前一个减一。
    public int monotoneIncreasingDigits(int n) {
        int result = 0;
        List<Integer> nList = new ArrayList<>();
        while (n != 0){
            nList.add(n % 10);//nList是倒序的[2,3,3]    原数332
            n = n / 10;
        }
        int flag = -1;//标识从哪一位开始变9
        for (int i = 0; i < nList.size() - 1; i++) {
            if (nList.get(i) < nList.get(i + 1)){
                flag = i;
                nList.set(i + 1, nList.get(i + 1) - 1);
            }
        }
        for (int i = 0; i < nList.size(); i++){
            if (flag == -1 || i > flag){//flag == -1表明n本来就是递增的；i > flag的数字不需要变为9
                result += Math.pow(10, i) * nList.get(i);
            }else {
                result += Math.pow(10, i) * 9;
            }
        }
        return result;
    }


    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.monotoneIncreasingDigits(10));
        System.out.println();
        System.out.println(s.monotoneIncreasingDigits(1234));
        System.out.println();
        System.out.println(s.monotoneIncreasingDigits(332));
        System.out.println();
        System.out.println(s.monotoneIncreasingDigits(100));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
