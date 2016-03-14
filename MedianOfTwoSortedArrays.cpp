class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2 == 0) {
            //m + n is even
            return (double)(findKthElement(nums1, 0, nums2, 0, (m + n) / 2) + findKthElement(nums1, 0, nums2, 0, (m + n) / 2 + 1)) / 2.0;
        } else {
            return (double)findKthElement(nums1, 0, nums2, 0, (m + n) / 2 + 1);
        }
    }
    int findKthElement(vector<int>& nums1, int st1, vector<int>& nums2, int st2, int k) {
        if (st1 >= nums1.size()) {
            return nums2[st2 + k - 1];
        }
        if (st2 >= nums2.size()) {
            return nums1[st1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[st1], nums2[st2]);
        }
        
        int st1_m = (st1 + k / 2 - 1 >= nums1.size() ? nums1.size() - 1 : st1 + k / 2 - 1);
        int st2_m = (st2 + k / 2 - 1 >= nums2.size() ? nums2.size() - 1 : st2 + k / 2 - 1);
        if (nums1[st1_m] <= nums2[st2_m]) {
            return findKthElement(nums1, st1_m + 1, nums2, st2, k - st1_m + st1 - 1);
        } else {
            return findKthElement(nums1, st1, nums2, st2_m + 1, k - st2_m + st2 - 1);
        }
    }
};
