class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int>res;
        int n = nums.size();
        unordered_map<int, int>hash;
        for(int i = n-1; (i >= 0) && (res.size() != k); i--){
            if(hash[nums[i]] != 0){
                continue;
            }
            res.push_back(nums[i]);
            hash[nums[i]]++;
        }
        return res;
    }
};
