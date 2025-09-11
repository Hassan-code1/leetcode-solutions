class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>count(3);
        for(auto& i: nums){
            if(i == 0) count[0]++;
            if(i == 1) count[1]++;
            if(i == 2) count[2]++;
        }
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            while(count[curr] == 0){
                curr++;
            }
            nums[i] = curr;
            count[curr]--;
        }
    }
};
