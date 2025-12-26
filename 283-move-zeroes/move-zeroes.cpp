class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;  // position for next non-zero

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }

        // fill remaining positions with zero
        while (k < nums.size()) {
            nums[k++] = 0;
        }
    }
};