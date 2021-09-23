//给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
//
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
//
//
//
// 示例 1：
//
//
//输入：nums = [4,6,7,7]
//输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//
//
// 示例 2：
//
//
//输入：nums = [4,4,3,2,1]
//输出：[[4,4]]
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100
//
// Related Topics 位运算 数组 哈希表 回溯
// 👍 333 👎 0


import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> subset = new ArrayList<>();
    public List<List<Integer>> findSubsequences(int[] nums) {
        backTracing(0, nums);
        return result;
    }

    private void backTracing(int startIndex, int[] nums){
        if (subset.size() >= 2){
            result.add(new ArrayList<>(subset));
        }
        if (startIndex > nums.length - 1){
            return;
        }
        Set<Integer> used = new HashSet<>();//记录本层使用过的元素，set进行去重
        for (int i = startIndex; i < nums.length; i++){
            //1. 判断递增关系，如果一旦发现不对，就后面都不需要再挑选了
            //2. 去掉重复元素，比如7 和 7是一样的
            //3. OR的关系
            if (!subset.isEmpty() && nums[i] < subset.get(subset.size() - 1) || used.contains(nums[i])){
                continue;
            }
            used.add(nums[i]);
            subset.add(nums[i]);
            backTracing(i + 1, nums);
            subset.remove(subset.size() - 1);
        }
    }

    /**
     * 去重优化，不使用set，使用数组，因为题目中的nums是[-100，100]的
     * @param startIndex
     * @param nums
     */
    private void backTracing1(int startIndex, int[] nums){
        if (subset.size() >= 2){
            result.add(new ArrayList<>(subset));
        }
        if (startIndex > nums.length - 1){
            return;
        }
        int[] used = new int[201];//系统为数组元素赋初始值0
        for (int i = startIndex; i < nums.length; i++){
            //1. 判断递增关系，如果一旦发现不对，就后面都不需要再挑选了
            //2. 去掉重复元素，比如7 和 7是一样的
            //3. OR的关系
            if (!subset.isEmpty() && nums[i] < subset.get(subset.size() - 1) || used[nums[i] + 100] == 1){
                continue;
            }
            used[nums[i] + 100] = 1;
            subset.add(nums[i]);
            backTracing(i + 1, nums);
            subset.remove(subset.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {4,7,6,7};
        s.findSubsequences(nums);
        System.out.println(s.result);
    }
}
//leetcode submit region end(Prohibit modification and deletion)

