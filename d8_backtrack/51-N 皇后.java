//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//
//
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//
//
// 示例 1：
//
//
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：[["Q"]]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 9
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
//
//
//
// Related Topics 数组 回溯
// 👍 1040 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    private List<List<String>> result = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        char[][] chessBroad = new char[n][n];
        for (char[] c : chessBroad){
            Arrays.fill(c, '.');
        }
        backTracing(0, 0, n, chessBroad);
        return result;
    }

    /**
     *
     * @param row   标识当前在摆第几行的皇后
     * @param n     棋盘是几乘几的
     */
    private void backTracing(int row, int col, int n, char[][] chessBroad){
        if (row == n){
            result.add(Array2List(chessBroad));
            return;
        }

        for (col = 0; col < n; col++){
            if (isValid(row, col, n, chessBroad)){
                chessBroad[row][col] = 'Q';
                row++;
                backTracing(row, col, n, chessBroad);
                row--;
                chessBroad[row][col] = '.';
            }
        }
    }

    private boolean isValid(int row, int col, int n, char[][] chessBroad) {
        //不需要判断行，因为是以行，作为顺序，依次进行填充皇后，因此不会有出现在同行的情况
        //判断列
        for (int i = 0; i < row; i++){
            if (chessBroad[i][col] == 'Q')
                return false;
        }
        //判断45度（右上方）
        //这里不需要判断左下方，因为已经摆好的棋子都在上面几行
        for (int i = row, j = col; i >= 0 && j < n; i--, j++){
            if (chessBroad[i][j] == 'Q')
                return false;
        }
        //判断135度（左上方）
        //这里不需要判断右下方，道理同上
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if (chessBroad[i][j] == 'Q')
                return false;
        }
        return true;
    }

    private List<String> Array2List(char[][] chessBroad){
        List<String> result = new ArrayList<>();
        for (char[] c : chessBroad){
            String s = String.copyValueOf(c);
            result.add(s);
        }
        return result;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solveNQueens(4));
    }
}
//leetcode submit region end(Prohibit modification and deletion)


