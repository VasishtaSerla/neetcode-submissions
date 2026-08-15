class Solution {
public:
    bool find_arr_with_sum(vector<int>& nums,int sum,int index){
        if(sum==0)return true;
        if(index==nums.size())return false;
        for(int i = index; i<nums.size(); i++){
            if(find_arr_with_sum(nums,sum-nums[i],i+1))return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        return find_arr_with_sum(nums,sum/2,0);
    }
};
