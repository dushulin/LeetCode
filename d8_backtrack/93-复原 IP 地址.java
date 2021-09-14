package com.xiaomi.miaisod.ai.platform;

//给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
//和 "192.168@1.1" 是 无效 IP 地址。
//
//
//
// 示例 1：
//
//
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
//
//
// 示例 2：
//
//
//输入：s = "0000"
//输出：["0.0.0.0"]
//
//
// 示例 3：
//
//
//输入：s = "1111"
//输出：["1.1.1.1"]
//
//
// 示例 4：
//
//
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
//
//
// 示例 5：
//
//
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 3000
// s 仅由数字组成
//
// Related Topics 字符串 回溯
// 👍 675 👎 0


import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    private final List<String> result = new ArrayList<>();
    private final List<String> path = new ArrayList<>();

    public List<String> restoreIpAddresses(String s) {
        backTracing(0, s);
        return result;
    }

    private void backTracing(int startIndex, String s){
        int nowSize = path.size();
        if (generateIp(path).length() == s.length() + 3 && path.size() == 4 && isValidIp(generateIp(path))){
            result.add(generateIp(path));
            return;
        }
        if ((s.length() - startIndex) / 3 > 4 - nowSize){
            return;
        }
        for (int i = startIndex; i < s.length(); i++){
            path.add(s.substring(startIndex, i + 1));
            backTracing(i + 1, s);
            path.remove(path.size() - 1);
        }
    }

    private String generateIp(List<String> stringList){
        String resultIp = "";
        for (String s : stringList){
            resultIp = resultIp.concat(".").concat(s);
        }
        return resultIp.isEmpty() ? "" : resultIp.substring(1);
    }

    private boolean isValidIp(String s){
        String[] ips = s.split("\\.");
        if (ips.length != 4){
            return false;
        }
        for (int i = 0; i < 4; i++){
            if (ips[i].startsWith("0") && ips[i].length() > 1){
                return false;
            } else if (Long.parseLong(ips[i]) > 255 || Long.parseLong(ips[i]) < 0){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isValidIp("192.168@1.1"));
        s.result.clear();
        System.out.println(s.restoreIpAddresses("2736786374048"));
        s.result.clear();
        System.out.println(s.restoreIpAddresses("25525511135"));
        s.result.clear();
        System.out.println(s.restoreIpAddresses("0000"));
        s.result.clear();
        System.out.println(s.restoreIpAddresses("010010"));
        s.result.clear();
        System.out.println(s.restoreIpAddresses("101023"));

//        System.out.println(Integer.parseInt(""));
    }
}
//leetcode submit region end(Prohibit modification and deletion)