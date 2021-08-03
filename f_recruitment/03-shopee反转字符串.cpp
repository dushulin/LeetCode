//
// Created by 杜树林 on 2021/8/2.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     *
     * @param s string字符串vector
     * @return string字符串vector
     */
    vector<string> reverseString(vector<string>& s) {
        // write code here
        int i = 0;
        int j = s.size() - 1;
        cout << i;
        cout << j;
        while (i < j) {
            std::string temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
};

