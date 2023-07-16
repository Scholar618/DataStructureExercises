/*
  给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
  在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for(char c : s) {
            ++count[c];
        }
        for(auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;
            if(v % 2 == 1 && ans % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};
