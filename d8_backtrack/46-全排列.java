//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
// 示例 2：
//
//
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
//
//
// 示例 3：
//
//
//输入：nums = [1]
//输出：[[1]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// nums 中的所有整数 互不相同
//
// Related Topics 数组 回溯
// 👍 1560 👎 0


import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> subset = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        Set<Integer> used = new HashSet<>();
        backTracing(nums, used);
        return result;
    }

    public void backTracing(int[] nums, Set<Integer> used){
        if (subset.size() == nums.length){
            result.add(new ArrayList<>(subset));
            return;
        }
        for (int i = 0; i < nums.length; i++){
            if (used.contains(nums[i])){
                continue;
            }
            subset.add(nums[i]);
            used.add(nums[i]);
            backTracing(nums, used);
            used.remove(nums[i]);
            subset.remove(subset.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1};
        System.out.println(s.permute(nums));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
