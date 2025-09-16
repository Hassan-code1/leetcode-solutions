#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for (auto& i : nums) {
            while (!st.empty() && gcd(st.top(), i) > 1) {
                i = lcm(i, st.top());
                st.pop();
            }
            st.push(i);
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
