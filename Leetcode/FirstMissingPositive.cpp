/*
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; i++) {
            if(nums[i] <= 0) {
                nums[i] = N + 5;
            }
        }
        for(int i = 0; i < N; i++) {
            int index = abs(nums[i]);
            if(index <= N and nums[index - 1] > 0) {
                nums[index - 1] *= (-1);
            }
        }
        for(int i = 0; i < N; i++) {
            if(nums[i] > 0) {
                return i + 1;
            }
        }
        
        return N + 1;
    }
};
