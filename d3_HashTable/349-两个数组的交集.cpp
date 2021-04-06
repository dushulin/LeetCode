//给定两个数组，编写一个函数来计算它们的交集。 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
// 
//
// 示例 2： 
//
// 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4] 
//
// 
//
// 说明： 
//
// 
// 输出结果中的每个元素一定是唯一的。 
// 我们可以不考虑输出结果的顺序。
//
// Related Topics 排序 哈希表 双指针 二分查找 
// 👍 330 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //将vector转化为set
        set<int> left(nums1.begin(), nums1.end());
        set<int> ans;
        //遍历right，在left中找有没有同样的元素
        for(int i = 0; i < nums2.size(); i++){
            if(left.find(nums2[i]) != left.end()){
                ans.insert(nums2[i]);
            }
        }
        vector<int> result(ans.size());
        copy(ans.begin(), ans.end(), result.begin());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
