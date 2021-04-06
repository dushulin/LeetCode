//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,-1], k = 1
//输出：[1,-1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [9,11], k = 2
//输出：[11]
// 
//
// 示例 5： 
//
// 
//输入：nums = [4,-2], k = 2
//输出：[4] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window 
// 👍 930 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]

class Solution {
private:
    //实现一个单调队列，拥有如下特性：
    //1. 队列元素单调递增或递减
    //实现：使用双向队列deque
    class MyQueue{
        public:
            deque<int> qu;

            //push元素的时候，为了保证单调性，如果比队尾元素大，则将队尾元素出队，直到当前入队元素小于队尾元素
            //因为当前入队的元素如果比队尾元素大的话，无法满足队列单调。而且弹出的队尾元素，未来也不会用上，因为已经有比它大的元素了（即当前需要入队的元素）
            void push(int value){
                while(!qu.empty() && value > qu.back()){
                    qu.pop_back();
                }
                qu.push_back(value);
            }

            //pop元素时，需要判断要弹出的元素是不是跟队头最大值相等，如果等于队头元素（最大值），则弹出，否则不作任何操作
            //因为弹出元素时，只需要关心是不是窗口不包含当前最大元素了，如果由于窗口的滑动将最大元素滑出了，则需要将其删除，如果只是删除了小的元素，则不影响获得最大值
            void pop(int value){
                if(!qu.empty() && value == qu.front())
                    qu.pop_front();
            }

            int front(){
                return qu.front();
            }
    };

public:
    //想用栈实现，基本不可能。
    //[1,3,1,2,0,5],3
    //WA:[3,3,0,5]
    //AC:[3,3,2,5]
    vector<int> maxSlidingWindow_1(vector<int>& nums, int k) {
        vector<int> res;
        //先求出第一个窗口的最大值
        stack<int> st;
        st.push(nums[0]);
        int i = 0;
        for(; i < k; i++){
            if(st.top() <= nums[i]){
                st.pop();//弹出当前栈顶的最大元素
                st.push(nums[i]);
            }
        }
        res.push_back(st.top());//添加第一个窗口的最大值
        for(;i < nums.size(); i++){
            //每移动一次窗口，需要判断当前移走的是不是最大元素
            if(nums[i - k] == st.top())
                st.pop();
            if(!st.empty() && st.top() <= nums[i]){
                st.pop();//弹出当前栈顶的最大元素
                st.push(nums[i]);
            }else if(st.empty()){
                st.push(nums[i]);
            }
            res.push_back(st.top());
        }
        return res;
    }

    //基于单调队列实现
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQueue myQueue;
        //入队前k个元素
        int i = 0;
        for(; i < k; i++){
            myQueue.push(nums[i]);
        }
        res.push_back(myQueue.front());//获取前k个元素的最大值
        for(; i < nums.size(); i++){
            myQueue.pop(nums[i - k]);
            myQueue.push(nums[i]);
            res.push_back(myQueue.front());
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
