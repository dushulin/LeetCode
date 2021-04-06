//实现 strStr() 函数。 
//
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
//果不存在，则返回 -1。 
//
// 示例 1: 
//
// 输入: haystack = "hello", needle = "ll"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: haystack = "aaaaa", needle = "bba"
//输出: -1
// 
//
// 说明: 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 
// Related Topics 双指针 字符串 
// 👍 740 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        //if(needle.size() == 1 && needle[0] == haystack[0])
            //return 0;
        int next[needle.size()];
        getNext(next, needle);//求模式串的next数组
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){//i从0开始。
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if(haystack[i] == needle[j])
                j++;
            if(j == needle.size())//当j指向了模式串的末尾，则说明出现了匹配
                return (i - needle.size() + 1);
        }
        return -1;
    }

    void getNext(int* next, const string& s){
        //初始化i j next数组
        int j = 0;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){//这里i表示后缀末尾，只有一个字符不叫后缀，所以最少两个字符，i指向1
            //前后缀不相同
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];//回退，选择当前j下标的前一个记录的next数组值
            }
            //前后缀相同，j加一
            if(s[i] == s[j])
                j++;
            //填充next数组，因为目前是以i为for循环变量，因此将j（前缀的长度）赋值给next[i]
            next[i] = j;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
