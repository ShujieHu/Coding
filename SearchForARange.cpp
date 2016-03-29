class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        int l = 0;
        int r = n - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target) {
            res.push_back(l);
        } else {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (nums[l] == target) {
            res.push_back(l);
        } else {
            res.push_back(l - 1);
        }
        return res;
    }
};
