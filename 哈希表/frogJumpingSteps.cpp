/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
class Solution {
public:
    //使用哈希map，充当备忘录的作用
    unordered_map<int, int> tempMap;
    int numWays(int n) {
        // n = 0 也算1种
        if (n == 0) {
            return 1;
        }
        if (n <= 2) {
            return n;
        }
        //先判断有没计算过，即看看备忘录有没有
        if (tempMap.count(n)) {
            //备忘录有，即计算过，直接返回
            return tempMap[n];
        } else {
            // 备忘录没有，即没有计算过，执行递归计算,并且把结果保存到备忘录map中，对1000000007取余（这个是leetcode题目规定的）
            tempMap[n] = (numWays(n - 1) + numWays(n - 2)) % 1000000007;
            return tempMap[n];
        }
    }
};
