/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash_table;
        int n = s.size();
        if(n == 0) {
            return 0;
        }

        int maxSize = 0;
        int left = 0;
        for(int i = 0; i < n; i++) {
            while(hash_table.find(s[i]) != hash_table.end()) {
                // 如果出现过，移除左
                hash_table.erase(s[left]);
                left++;
            }
            maxSize = max(maxSize, i - left + 1);
            hash_table.insert(s[i]);
        }
        return maxSize;
    }
};
