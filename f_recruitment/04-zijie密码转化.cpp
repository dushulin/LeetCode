//
// Created by 杜树林 on 2021/8/2.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minConvert(std::string s) {
        // write code here
        bool hasNum = false;
        bool hasUpper = false;
        bool hasLower = false;
        bool hasSig = false;
        int Num = 0;
        int Upper = 0;
        int Lower = 0;
        int Sig = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (isupper(s[i])) {
                hasUpper = true;
                Upper++;
            } else if (islower(s[i])) {
                hasLower = true;
                Lower++;
            } else if (isdigit(s[i])) {
                hasNum = true;
                Num++;
            } else if (isSig(s[i])) {
                hasSig = true;
                Sig++;
            }
            //0. 满足条件
            if (hasNum && hasUpper && hasLower && hasSig) {
                return 0;
            }
        }
        cout << "num: " << Num << ", Upper: " << Upper << ", lower: " << Lower << ", Sig: " << Sig << endl;
        //1. 差小写
        if (!hasLower && hasUpper && hasSig && hasNum) {

            return 1;
        }
        //2. 差大写
        if (hasLower && !hasUpper && hasSig && hasNum) {
            return 1;
        }
        //3. 差数字
        if (hasLower && hasUpper && hasSig && !hasNum) {
            return 1;
        }
        //4. 差符号
        if (hasLower && hasUpper && !hasSig && hasNum) {
            return 1;
        }
        //5. 差小写+大写
        if (!hasLower && !hasUpper && hasSig && hasNum) {
            return 2;
        }
        if (!hasLower && hasUpper && !hasSig && hasNum) {
            return 2;
        }
        if (!hasLower && hasUpper && hasSig && !hasNum) {
            return 2;
        }
        if (hasLower && !hasUpper && !hasSig && hasNum) {
            return 2;
        }
        if (hasLower && !hasUpper && hasSig && !hasNum) {
            return 2;
        }
        if (hasLower && hasUpper && !hasSig && !hasNum) {
            return 2;
        }

        if (!hasLower && !hasUpper && !hasSig && hasNum) {
            return 3;
        }
        if (!hasLower && !hasUpper && hasSig && !hasNum) {
            return 3;
        }
        if (!hasLower && hasUpper && !hasSig && !hasNum) {
            return 3;
        }
        if (hasLower && !hasUpper && !hasSig && !hasNum) {
            return 3;
        }

        if (!hasLower && !hasUpper && !hasSig && !hasNum) {
            return 4;
        }
    }

    bool isSig(char c){
        if (c == ',' || c == '.' || c == '!' || c == '?' || c == ';'){
            return true;
        } else{
            return false;
        }
    }

    int minConvert1(std::string s) {
        
    }
};

int main(){
    Solution solution;
    std::string s;
    cin >> s;
    cout << solution.minConvert(s);
}
