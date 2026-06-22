class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>>ans;
     set<vector<int>>s;
        sort(nums.begin(),nums.end());
        int length = nums.size();

        for(int i = 0; i<length; i++){
            int target = -nums[i];
            int left = i+1,right = length-1;
            while(left<right){
            if(left == i){
                left++;
                continue;
            }
            else if(right == i){
                right--;
                continue;
            }

            if(nums[left]+nums[right]<target)left++;
            else if(nums[left]+nums[right]>target)right--;
else{
s.insert({nums[i],nums[left],nums[right]});
    left++;
    right--;
}}}
for(auto x:s){
    ans.push_back(x);
}
return ans;
       
    }
};