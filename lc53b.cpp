/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

// Kadane's algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int  i = 1; i < nums.size(); i++){
            currSum = max(nums[i], currSum+nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

//divide and conquer
class Solution {
private:
    int solve(vector<int>& nums, int left, int right){
        if(left > right){
            return INT_MIN;
        }
        int mid = (left+right)/2;
      
        int leftSum = 0;
        int rightSum = 0;
      
        int currSum = 0;
        for(int i = mid-1; i >= left; i--){
            currSum += nums[i];
            leftSum = max(leftSum, currSum);
        }
      
        currSum = 0;
        for(int i = mid+1; i <= right; i++){
            currSum+=nums[i];
            rightSum = max(rightSum, currSum);
        }
        return max({solve(nums, left, mid-1), 
                    solve(nums, mid+1, right),
                    leftSum + nums[mid] + rightSum 
        });
    }
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
