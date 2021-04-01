//给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[
//l] = 0。 
//
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最
//终结果不会超过 231 - 1 。 
//
// 例如: 
//
// 
//输入:
//A = [ 1, 2]
//B = [-2,-1]
//C = [-1, 2]
//D = [ 0, 2]
//
//输出:
//2
//
//解释:
//两个元组如下:
//1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
// 
// Related Topics 哈希表 二分查找 
// 👍 338 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;//保存(a+b, a+b出现的次数)
        int count = 0;
        for(int a : A){
            for(int b : B){
                if(map.find(a + b) == map.end())
                    map.insert(pair<int, int>(a + b, 1));
                else{
                    map.find(a + b)->second++;
                }
            }
        }

        for(int c : C){
            for(int d : D){
                if(map.find(0 - (c + d)) != map.end()){
                    count += map.find(0 - (c + d))->second;
                }
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
