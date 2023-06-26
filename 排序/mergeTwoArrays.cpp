/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merge;
        int i = 0, j = 0;
       while(i < m || j < n) {
            if(i < m && (j == n || nums1[i] <= nums2[j])) {
                merge.push_back(nums1[i]);
                i++;
            }
            else {
                merge.push_back(nums2[j]);
                j++;
            }
        }
        if(i < j) {
            while(i < m) {
                merge.push_back(nums1[i]);
            }
        } else {
            while(j < n) {
                merge.push_back(nums2[j]);
            }
        }

        nums1 = merge;

    }
};
