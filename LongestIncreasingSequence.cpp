//typical example of LIS(longest increasing sequence)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        vector<int>temp;
        temp.reserve(n);
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            int low = 0;
            int high = temp.size() - 1;
            if (nums[i] > temp[high]) {
                temp.push_back(nums[i]);
            } else {
                //doing a binary search to find out the possible position for nums[i]
                while (low < high) {
                    int mid = (low + high) / 2;
                    if (temp[mid] < nums[i]) {
                        //search to the right
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }
                temp[high] = nums[i];
            }
        }
        return temp.size();
    }
};
