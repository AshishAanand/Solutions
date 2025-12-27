class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplet;

        // int left = nums[0];
        // int fixed = nums[1];
        // int right = nums[n -1];

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the 'fixed' element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    triplet.push_back({nums[i], nums[left], nums[right]});
                    // Move pointers and skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++; // Sum too small, increase the left pointer
                } else {
                    right--; // Sum too large, decrease the right pointer
                }
            }
        }
        return triplet;
    }
};