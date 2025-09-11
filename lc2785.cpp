class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int  n = nums.size();
        int positive = 0;
        int negative = 0;
        vector<int> res;
        // int count = 0
        while(positive < n && negative < n){
            while(nums[positive] < 0 ){ 
                positive++;
                if(positive >= n) break;
            }
            while(nums[negative] > 0) { 
                negative++;
                if(negative >= n) break;
            }
            if(positive < n){
                res.push_back(nums[positive++]);
            }
            if(negative < n){
                res.push_back(nums[negative++]);
            }
        }
        return res;
    }
};
