//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//
//
// 示例 2：
//
//
//输入：nums = [0]
//输出：[[],[0]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// nums 中的所有元素 互不相同
//
// Related Topics 位运算 数组 回溯
// 👍 1321 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> subset = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        backTracing(0, nums);
        return result;
    }

    public void backTracing(int startIndex, int[] nums){
        result.add(new ArrayList<>(subset));
        if (startIndex == nums.length){
            return;
        }
        for (int i = startIndex; i < nums.length; i++){
            subset.add(nums[i]);
            backTracing(i + 1, nums);
            subset.remove(subset.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {0};
        System.out.println(s.subsets(nums));
    }
}
//leetcode submit region end(Prohibit modification and deletion)

