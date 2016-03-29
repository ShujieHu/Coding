class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                idx = i;
            }
        }
        if (idx > 0) {
            for (int i = n - 1; i >= idx; i--) {
                if (nums[i] > nums[idx - 1]) {
                    swap(nums[i], nums[idx - 1]);
                    break;
                }
            }
        }
        sort(nums.begin() + idx, nums.end());
    }
};
