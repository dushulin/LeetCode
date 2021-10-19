//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 判断你是否能够到达最后一个下标。
//
//
//
// 示例 1：
//
//
//输入：nums = [2,3,1,1,4]
//输出：true
//解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
//
//
// 示例 2：
//
//
//输入：nums = [3,2,1,0,4]
//输出：false
//解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 3 * 104
// 0 <= nums[i] <= 105
//
// Related Topics 贪心 数组 动态规划
// 👍 1437 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //贪心法：每一次都尝试跳到某个点，其满足：下一次可以跳最多的步数
    public boolean canJump(int[] nums) {
        if (nums.length == 1){
            return true;
        }
        int cur = 0;
        int next = 0;
        for (int i = cur + 1; i <= cur + nums[cur]; i++){
            //1. 先判断当前这个点能否直接跳到终点
            if (cur + nums[cur] >= nums.length - 1){
                return true;
            }
            //2. 在获取到下一次可以跳最多步数的index
            if (nums[i] >= nums[next]){
                next = i;
            }
            //3. 更新next下标
            if (i == cur + nums[cur]){//本次比较到了最后一个，需要更新next下标了
                if (nums[cur] > nums[next] && nums[cur + nums[cur]] != 0){//如果从当前点起跳比后面任何一个点起跳都跳的远，并且跳到的下一个点非0，则直接从当前点起跳
                    cur = cur + nums[cur];
                    next = cur;
                }else {
                    cur = next;
                }
                i = cur;
                next++;
            }
        }
        return false;
    }

    /**
     * 贪心法：不需要像上面那样想复杂了
     * @param nums
     * @return
     */
    public boolean canJump1(int[] nums) {
        if (nums.length == 1) {
            return true;
        }
        //覆盖范围
        int coverRange = nums[0];
        //在覆盖范围内更新最大的覆盖范围
        for (int i = 0; i <= coverRange; i++) {
            coverRange = Math.max(coverRange, i + nums[i]);
            if (coverRange >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {3,2,1,0,4};
        int[] nums1 = {2,3,1,1,4};
        int[] nums2 = {2,0,1,0,1};
        int[] nums3 = {5,9,3,2,1,0,2,3,3,1,0,0};
        System.out.println(s.canJump1(nums3));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
