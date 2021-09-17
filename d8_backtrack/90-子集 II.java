//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//
//
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,2,2,3]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
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
//
//
//
// Related Topics 位运算 数组 回溯
// 👍 651 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private List<Integer> subset = new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        Arrays.stream(nums).forEach(System.out::println);
        backTracing(nums, 0);
        return result;
    }

    void backTracing(int[] nums, int startIndex){
        result.add(new ArrayList<>(subset));
        if (startIndex > nums.length - 1){
            return;
        }

        for (int i = startIndex; i < nums.length; i++){
            if (i != startIndex && nums[i] == nums[i - 1]){
                continue;
            }
            subset.add(nums[i]);
            backTracing(nums, i + 1);
            subset.remove(subset.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {0};
        s.subsetsWithDup(nums);
        System.out.println(s.result);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
