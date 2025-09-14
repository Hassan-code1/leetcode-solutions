class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double avg = 0;
        for(auto&i : nums){
            avg+=i;
        }
        avg /= nums.size();
        int res = (int)avg + 1;
        if(avg < 0) res = 1;
        while(count(nums.begin(), nums.end(), res)){
            res++;
        }
        return res;
    }
};
