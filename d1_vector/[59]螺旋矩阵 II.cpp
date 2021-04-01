//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 
// 👍 302 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));//初始化二位数组
        int loop = n / 2;//需要循环的圈数（若是奇数的话，将最后一个元素单独填写）
        int num = 1;//待填写数字
        //定义每一个圈的起始点（0,0）-->(1,1)-->(2,2)
        int startX = 0;
        int startY = 0;
        int offset = n - 1;//这个需要找规律，而且要保证左闭右开的原则才是n - 1
        int mid = n / 2;
        while(loop--){
            //上
            for(int up = startY; up < startY + offset; up++){
                res[startX][up] = num++;
            }
            //右
            for(int right = startX; right < startX + offset; right++){
                res[right][startY + offset] = num++;
            }
            //下
            for(int down = startY + offset; down > startY; down--){
                res[startX + offset][down] = num++;
            }
            //左
            for(int left = startX + offset; left > startX; left--){
                res[left][startY] = num++;
            }
            startX++;
            startY++;
            offset-= 2;
        }
        if(n % 2 != 0){
            res[mid][mid] = num;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
