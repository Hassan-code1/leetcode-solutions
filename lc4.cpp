//Median of two sorted arrays
/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0){
            int n = nums2.size();
            if(n%2 == 0){
                return (double) (nums2[(n/2)-1] + nums2[n/2]) / 2;
            }else{
                return (double) (nums2[(n-1)/2]);
            }
        }
        if(nums2.size() == 0){
            int n = nums1.size();
            if(n%2 == 0){
                return (double) (nums1[(n/2)-1] + nums1[n/2]) / 2;
            }else{
                return (double) (nums1[(n-1)/2]);
            }
        }
        int k = nums1.size() + nums2.size();
        vector<int>sorted;
        int a = 0;
        int b = 0;
        if(k%2 == 0){
            for(int i =0; i < (k/2) + 1; i++){
                if(a < nums1.size() && (b >= nums2.size() || nums1[a] <= nums2[b] )){
                    sorted.push_back(nums1[a]);
                    a++;
                }else{
                    sorted.push_back(nums2[b]);
                    b++;
                }
            }
            return (double) (sorted[(k/2)-1] + sorted[k/2]) / 2;
        }else{
            for(int i = 0; i < (k+1)/2; i++){
                if(a < nums1.size() && (b >= nums2.size() || nums1[a] <= nums2[b] )){
                    sorted.push_back(nums1[a]);
                    a++;
                }else{
                    sorted.push_back(nums2[b]);
                    b++;
                }
            }
        }
        return (double) (sorted[(k-1)/2]);
    }
};
