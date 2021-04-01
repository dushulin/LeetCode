//编写一个算法来判断一个数 n 是不是快乐数。 
//
// 「快乐数」定义为： 
//
// 
// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。 
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。 
// 如果 可以变为 1，那么这个数就是快乐数。 
// 
//
// 如果 n 是快乐数就返回 true ；不是，则返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
// 
//
// 示例 2： 
//
// 
//输入：n = 2
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 231 - 1 
// 
// Related Topics 哈希表 数学 
// 👍 541 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
最后一次变化必须是所有位数中，只有一个1，其他全是0
对于哪些无限循环下去的非快乐数，肯定是在各位数求和相加的过程中，遇到了同样的sum，因此才会不断的循环。
因此遇到这种情况，就可以结束循环，返回false了
*/
class Solution {
public:

    //返回n的各位数平方之和
    int digitSum(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum = digitSum(n);
        unordered_set<int> sumSet;//存放各位数平方和
        while(sumSet.find(sum) == sumSet.end()){//如果set中不存在当前的sum，则有可能是快乐数
            if(sum == 1)
                return true;
            sumSet.insert(sum);
            sum = digitSum(sum);
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
