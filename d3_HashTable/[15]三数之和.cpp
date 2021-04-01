//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//-4 -1 -1 -1 0 1 2
//输出：[[-1,-1,2],[-1,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 3000 
// -105 <= nums[i] <= 105 
// 
// Related Topics 数组 双指针 
// 👍 3036 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//先给nums排序，保证后续去重逻辑比较好写
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)//如果a>0的话，后面的候选bc都大于0，和必然大于0
                continue;
            if(i > 0 && nums[i] == nums[i - 1])//对于a去重，因为a的值相同，只是位置不一样，那么求出来的结果集是一样的
                continue;
            unordered_set<int> uset;
            for(int j = i + 1; j < nums.size(); j++){
                //对b去重，此时a的值已经固定，
                if(j > i + 2 && nums[j] == nums[j - 1] && nums[j - 2] == nums[j - 1])
                    continue;
                int c = 0 - (nums[i] + nums[j]);
                if(uset.find(c) != uset.end()){
                    result.push_back({nums[i], nums[j], c});
                    uset.erase(c);//对于c去重
                }else{
                    uset.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//先给nums排序
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)//如果a>0的话，后面的候选bc都大于0，和必然大于0
                continue;
            if(i > 0 && nums[i] == nums[i - 1])//对于a去重，因为a的值相同，只是位置不一样，那么求出来的结果集是一样的
                continue;
            int left = i + 1;
            int right = nums.size();
            while(left != right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
