//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 数组 回溯 
// 👍 813 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> subset = new ArrayList<>();

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        int[] used = new int[8];
        backTracing(nums, used);
        return result;
    }

    public void backTracing(int[] nums, int[] used){
        if (subset.size() == nums.length){
            result.add(new ArrayList<>(subset));
            return;
        }

        for (int i = 0; i < nums.length; i++){
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 1){
                continue;
            }
            if (used[i] == 0) {
                subset.add(nums[i]);
                used[i] = 1;
                backTracing(nums, used);
                used[i] = 0;
                subset.remove(subset.size() - 1);
            }
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
