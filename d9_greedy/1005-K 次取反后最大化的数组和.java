//给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选
//择同一个索引 i。）
//
// 以这种方式修改数组后，返回数组可能的最大和。
//
//
//
// 示例 1：
//
// 输入：A = [4,2,3], K = 1
//输出：5
//解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
//
//
// 示例 2：
//
// 输入：A = [3,-1,0,2], K = 3
//输出：6
//解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
//
//
// 示例 3：
//
// 输入：A = [2,-3,-1,5,-4], K = 2
//输出：13
//解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
//
//
//
//
// 提示：
//
//
// 1 <= A.length <= 10000
// 1 <= K <= 10000
// -100 <= A[i] <= 100
//
// Related Topics 贪心 数组 排序
// 👍 107 👎 0


import java.util.Arrays;
import java.util.stream.IntStream;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
     * 贪心：
     * 1. 将数组按照绝对值从大到小排列
     * 2. 将负数转为正数，k--
     * 3. k还是不为0，则对最小的数字反复翻转符号
     * 4. 计算最终和
     * @param nums
     * @param k
     * @return
     */
    public int largestSumAfterKNegations(int[] nums, int k) {
        int result = 0;
        nums = IntStream.of(nums)
                .boxed()
                .sorted((o1, o2) -> Math.abs(o2) - Math.abs(o1))
                .mapToInt(Integer::intValue).toArray();
        for (int i = 0; i < nums.length; i++){
            if (nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 == 1){
            nums[nums.length - 1] = -nums[nums.length - 1];
        }
        for (int num : nums) {
            result += num;
        }
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {2,-3,-1,5,-4};
        int k = 2;
        System.out.println(s.largestSumAfterKNegations(nums, k));
    }
}
//leetcode submit region end(Prohibit modification and deletion)

