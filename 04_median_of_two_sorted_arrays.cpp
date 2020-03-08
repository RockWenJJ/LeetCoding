class Solution {
public:
    // run time complexity O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len  = len1 + len2;
        vector<int> nums;
        int idx0 = 0, idx1 = 0;
        double res;
        for(int idx = 0; idx <= len/2; ++idx){
            if(idx0 >= nums1.size()){
                nums.push_back(nums2[idx1]);
                ++idx1;
            }
            else if(idx1 >= nums2.size()){
                nums.push_back(nums1[idx0]);
                ++idx0;
            }
            else if(nums1[idx0] < nums2[idx1]) {
                nums.push_back(nums1[idx0]);
                ++idx0;
            }
            else if(nums1[idx0] >= nums2[idx1]){
                nums.push_back(nums2[idx1]);
                ++idx1;
            }
        }
        
        if(len%2==0){
            if(nums.size()>=2){
            res = (nums[nums.size()-2] + nums[nums.size()-1])/2.0;
            }
            else{
                res = 0.0;
            }    
        }else{
            res = nums[nums.size()-1];
        }
        return res;
    }
};