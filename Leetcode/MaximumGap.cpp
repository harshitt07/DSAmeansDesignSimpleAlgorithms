/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form.
If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxDifference = 0;
        int N = nums.size();
        if(N < 2) return 0;
        int minimumElement = nums[0], maximumElement = nums[0];
        for(int i = 1; i < N; i++) {
            minimumElement = min(minimumElement, nums[i]);
            maximumElement = max(maximumElement, nums[i]);
        }
        
        int gap =  ceil(1.0*(maximumElement - minimumElement)/(N - 1));
        
        if(gap == 0) return 0;
        
        int minimumBucket[N + 1];
        int maximumBucket[N + 1];
        
        for(int i = 0; i < N + 1; i++) {
            maximumBucket[i] = INT_MIN;
            minimumBucket[i] = INT_MAX;
        }
        
        for(int i = 0; i < N; i++) {
            int bucketNumber = (nums[i] - minimumElement)/gap;
            minimumBucket[bucketNumber] = min(minimumBucket[bucketNumber], nums[i]);
            maximumBucket[bucketNumber] = max(maximumBucket[bucketNumber], nums[i]);
        }
        
        int i = 0;
        
        while(i <= N) {
            if(maximumBucket[i] != INT_MIN) {
                int j = i + 1;
                while(j < N and minimumBucket[j] == INT_MAX) {
                    j++;
                }
                if(j != N) {
                    maxDifference = max(maxDifference, minimumBucket[j] - maximumBucket[i]);
                }
                i = j;
            } else {
                i++;
            }
        }
        return maxDifference;
    }
};
