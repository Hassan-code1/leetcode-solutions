class Solution {
public:
    bool doesAliceWin(string s) {
        int countVowels = 0;
        for(auto& i : s){
            if( i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                countVowels++;
            }
        }
        if(countVowels == 0 )return false;
        return true;
    }
};
