class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n <= 2) {
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    vector<int> r = {nums[i], nums[j], nums[k]};
                    res.push_back(r);
                    r.clear();
                    k--;
                    j++;
                    //to get rid of duplicates, skip j when nums[j - 1] == nums[j]
                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }
                }
                
            }
        }
        return res;
    }
};
