//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
//
//
//
// 示例 1：
//
//
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//
// 示例 2：
//
//
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//
//
//
// 提示：
//
//
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104
//
// Related Topics 数组 排序
// 👍 1170 👎 0


import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 1)
            return intervals;
        int[][] result = new int[intervals.length][2];
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });
        System.out.println(Arrays.deepToString(intervals));
        int count = 0;
        result[0][0] = intervals[0][0];
        for (int i = 1; i < intervals.length; i++){
            if (intervals[i][0] <= intervals[i - 1][1]){
                //有重叠，merge
                intervals[i][1] = Math.max(intervals[i][1], intervals[i - 1][1]);
            }else {
                //没有重叠，填充result
                result[count][1] = intervals[i - 1][1];
                result[count + 1][0] = intervals[i][0];
                count++;
            }
        }
        result[count][1] = intervals[intervals.length - 1][1];
        return Arrays.copyOf(result, count + 1);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] intervals = {{1,4},{4,5}};
        System.out.println(Arrays.deepToString(s.merge(intervals)));
    }
}
//leetcode submit region end(Prohibit modification and deletion)
