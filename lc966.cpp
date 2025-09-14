class Solution {
private:
    string toLower(string s){
        for(char &ch : s){
            ch = tolower(ch);
        }
        return s;
    }
    string deVowel(string s){
        for(char& ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                ch = '*';
            }
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string>caseMap;
        unordered_map<string, string>vowelMap;
        for(string w : wordlist){
            string lower = toLower(w);
            string devowel = deVowel(lower);
            if(!caseMap.count(lower)) caseMap[lower] = w;
            if(!vowelMap.count(devowel)) vowelMap[devowel] = w;
        }
        vector<string> res;
        for(string q: queries){
            if(exact.count(q)){
                res.push_back(q);
            }else{
                string lower = toLower(q);
                string devowel = deVowel(lower);
                if(caseMap.count(lower)){
                    res.push_back(caseMap[lower]);
                }else if(vowelMap.count(devowel)){
                    res.push_back(vowelMap[devowel]);
                }else{
                    res.push_back("");
                }
            }
        }
        return res;
    }
};
