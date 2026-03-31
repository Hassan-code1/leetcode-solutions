/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        int maxCandies=0;
        //forward itr
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        //backward itr
        for(int i = n-1; i >= 1; i--){
            if(ratings[i-1] > ratings[i]){
                candies[i-1] = max(candies[i-1], candies[i]+1);
            }
            maxCandies+= candies[i-1];
        }

        return maxCandies + candies[n-1];
    }
};
