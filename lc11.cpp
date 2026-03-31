/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

//Two POinter Approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        //two pointer
        int left = 0;
        int right = height.size()-1;
        int maxWater = 0;
        while(left < right){
            int curr = (right-left)*(min(height[left], height[right]));
            maxWater = max(maxWater, curr);
            if(height[left] < height[right]){
                left++;
                continue;
            }
            right--;
        }
        return maxWater;
    }
};


