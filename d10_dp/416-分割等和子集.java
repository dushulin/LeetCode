//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。
//
// 示例 2：
//
//
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
//
// Related Topics 数组 动态规划
// 👍 1085 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean canPartition(int[] nums) {
        //1. 理解本题：数组分割成两个子数组，子数组和相等 ==> 一个子数组的值正好是 sum / 2即可。可以想到套用01背包
        //2. 转化为01背包问题：背包大小是sum/2，物品weight和物品value均为为数组值的大小。每个数字不能重复装入背包。如果最终容量为sum/2的背包刚好被物品装满，则说明可以分割成功。
        //3. 进行01背包的五部曲
        //3.1 dp数组及定义：数组长度不超过200，值不超过100，因此sum/2不超过10000
        int[] dp = new int[10001];
        //3.3 数组初始化：值都是正整数，直接初始化为0即可
        //3.2 递推公式：
        //3.4 遍历顺序：
        int sum = 0;
        for (int i = 0; i < nums.length; i++){
            sum += nums[i];
        }
        for (int i = 0; i < nums.length; i++){
            for (int j = sum / 2; j >= nums[i]; j--){
                dp[j] = Math.max(dp[j], dp[j - nums[i]] + nums[i]);
                System.out.println("dp[" + j + "] = " + dp[j]);
            }
        }
        //3.5 举例：
        if (sum % 2 == 0 && dp[sum / 2] == sum / 2){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1,2,3,5};
        System.out.println(s.canPartition(nums));
    }
}
//leetcode submit region end(Prohibit modification and deletion)

