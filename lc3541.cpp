class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> hash;
        int maxV = 0, maxC =0;
        for(auto& i: s){
            hash[i]++;
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                maxV = max(maxV, hash[i]);
            }else{
                maxC = max(maxC, hash[i]);
            } 
        }
        return maxC + maxV;
    }
};
