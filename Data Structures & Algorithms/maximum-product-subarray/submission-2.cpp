class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int prevmin = nums[0];
       int prevmax = nums[0];
       //the final value of prevmax is the answer;
       int maxx = nums[0];
       for(int i = 1; i<nums.size(); i++){
        int pmax = max({prevmax*nums[i],prevmin*nums[i],nums[i]});
        int pmin = min({prevmin*nums[i],prevmax*nums[i],nums[i]});
        prevmax = pmax;
        if(prevmax>maxx)maxx = prevmax;
        prevmin = pmin;
       } return maxx;
    }
};
