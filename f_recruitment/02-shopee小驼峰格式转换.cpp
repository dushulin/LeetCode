//
// Created by 杜树林 on 2021/8/2.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     * TestVa
     * test_va
     * TEST_VA
     *
     * testVa
     *
     *
     * @param name string字符串 变量名
     * @return string字符串
     */

    string format(string name) {
        // write code here
        if (name.size() == 0){
            return "";
        }
        vector<string> v;
        split_string(name, v, "_");
        string result;
        if (v.size() == 1){
            if (isupper(v[0][0]) && !isupper(v[0][1])){
                v[0][0] += 32;
            }else if (isupper(v[0][0]) && isupper(v[0][1])){
                transform(v[0].begin(), v[0].end(), v[0].begin(), ::tolower);
            }
            result = v[0];
        }else{
            for (int i = 0; i < v.size(); ++i) {
                if (i == 0){
                    transform(v[i].begin(), v[i].end(), v[i].begin(), ::tolower);
                    result = v[0];
                }else{
                    transform(v[i].begin(), v[i].end(), v[i].begin(), ::tolower);
                    v[i][0] -= 32;
                    result.append(v[i]);
                }
            }

        }
        return result;
    }

    void split_string(const std::string &s, std::vector<std::string> &v, const std::string &c) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while (std::string::npos != pos2) {
            v.emplace_back(s.substr(pos1, pos2 - pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.emplace_back(s.substr(pos1));
    }
};

int main(){
    Solution s;
    cout << s.format("TEST_") << endl;
    cout << s.format("TEST") << endl;
    cout << s.format("Test") << endl;
    cout << s.format("test") << endl;
    cout << s.format("testVa") << endl;
    cout << s.format("test_Va") << endl;
    cout << s.format("TestVa") << endl;
}
