//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//
// 注意:
//
//
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
//
//
// 示例 1:
//
//
//输入: [ [1,2], [2,3], [3,4], [1,3] ]
//
//输出: 1
//
//解释: 移除 [1,3] 后，剩下的区间没有重叠。
//
//
// 示例 2:
//
//
//输入: [ [1,2], [1,2], [1,2] ]
//
//输出: 2
//
//解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
//
//
// 示例 3:
//
//
//输入: [ [1,2], [2,3] ]
//
//输出: 0
//
//解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
//
// Related Topics 贪心 数组 动态规划 排序
// 👍 528 👎 0


import java.util.Arrays;
import java.util.Comparator;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //贪心：这题跟打气球的思路比较类似。先按照start坐标进行从小到大排序。如果第i个区间的start < 第i-1个区间的end，则任务第i个区间和第i-1个区间重合了。那么删掉第i个区间。
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));
        int result = 0;
        for (int i = 1; i < intervals.length; i++){
            if (intervals[i][0] < intervals[i - 1][1]){
                //有重合
                result++;
                //更新第i个区间的end边界，去第i个区间和第i-1个区间中右边界小的那个（因为要尽量往左边缩，留给右边的区间更大的位置，保证不重合）
                intervals[i][1] = Math.min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] intervals = {{1,2}, {2, 3}};
        System.out.println(s.eraseOverlapIntervals(intervals));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
