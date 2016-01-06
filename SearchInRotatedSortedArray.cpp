ass Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size() - 1;
        int pivot;
        //find the pivot index first (it could be 0) with complexity of O(logN)
        
            //rotation does exist
        while (st < ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] > nums[ed]) {
                //definitely pivot is to the right of the mid
                st = mid + 1;
            } else if (nums[mid] < nums[st]) {
                //no duplicate, pivot is to the left of the mid, could be mid
                ed = mid;
            } else {
                //mid is between the values of st and ed, indicating a sorted array
                break;
            }
        }
        pivot = st;
        st = 0;
        ed = nums.size() - 1;
        if (pivot == 0) {
            //not rotated
            return findTarget(st, ed, target, nums);
        }
        
        //rotated
        //left section
        if (nums[ed] < target) {
            return findTarget(st, pivot - 1, target, nums);
        } else {
            //right section or not exist
            return findTarget(pivot, ed, target, nums);
        }
    }
    
    int findTarget(int st, int ed, int target, vector<int>& nums) {
        while (st < ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                //move right
                st = mid + 1;
            } else {
                //move left
                ed = mid;
            }
        }
        return (nums[st] == target) ? st : -1;
    }
};
