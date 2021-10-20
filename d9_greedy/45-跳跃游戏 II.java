//给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
// 假设你总是可以到达数组的最后一个位置。
//
//
//
// 示例 1:
//
//
//输入: nums = [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//
//
// 示例 2:
//
//
//输入: nums = [2,3,0,1,4]
//输出: 2
//
//
//
//
// 提示:
//
//
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
//
// Related Topics 贪心 数组 动态规划
// 👍 1228 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int jump(int[] nums) {
        int ans = 0;
        int curDistance = 0;//当前可以到达的最远距离
        int nextDistance = 0;//下一次可以到达的最远距离
        for (int i = 0; i < nums.length; i++){
            nextDistance = Math.max(i + nums[i], nextDistance);//更新下一次可以到达的最远距离
            if (i == curDistance){//判断是否已经遍历到当前可以走到的最远距离了
                if (curDistance != nums.length - 1){//如果当前覆盖的最远距离没有到达终点，则一定需要一步
                    ans++;
                    curDistance = nextDistance;//更新当前可以覆盖的最远距离
                    if (nextDistance >= nums.length - 1){//更新当前可以覆盖的最远距离后，发现已经到达终点了，则直接返回
                        break;
                    }
                }else {
                    break;
                }
            }
            //如果没有走到当前可以去的最远距离，则继续更新nextDistance
        }
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)