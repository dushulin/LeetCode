//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。 
// 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。 
// 你可以按任意顺序返回答案。 
// 
// Related Topics 堆 哈希表 
// 👍 702 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    //小根堆
    class myCompare {
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. 计算每个元素出现的频率，放入map中
        map<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (numsMap.find(nums[i]) != numsMap.end()){
                numsMap[nums[i]]++;
            }else{
                numsMap.insert(pair<int, int>(nums[i], 1));
            }
        }

        //2. 将map中的元素放入容量为k的小根堆中
        priority_queue<pair<int, int>, vector<pair<int, int> >, myCompare> priorityQueue;
        for (auto & iter : numsMap){
            priorityQueue.push(iter);
            if (priorityQueue.size() > k){
                //容量超过k，则弹出堆顶最小元素
                priorityQueue.pop();
            }
        }

        //3. 输出最大的k个元素。此时堆顶的倒数第k大的元素，所以倒序输出
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = priorityQueue.top().first;
            priorityQueue.pop();
        }
        return ans;
    }
};

int main(){
    int a[] = {1,1,1,2,2,3};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int k = 2;
    Solution solution;
    vector<int> ans = solution.topKFrequent(nums, k);
    for (int an : ans) {
        cout <<  an << " ";
    }
}
//leetcode submit region end(Prohibit modification and deletion)
