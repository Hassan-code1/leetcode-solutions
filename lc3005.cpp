class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxFreq = 1;
        int countMaxFreq = 1;
        int currFreq = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                currFreq = 1;
            }else{
                currFreq++;
            }
            if(currFreq == maxFreq){
                countMaxFreq += currFreq;
            }
            if(currFreq > maxFreq){
                countMaxFreq = currFreq;
                maxFreq = currFreq;
            }
        }
        return countMaxFreq;
    }
};
