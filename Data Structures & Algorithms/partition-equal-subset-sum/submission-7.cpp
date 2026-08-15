class Solution {
public:
    bool find_arr_with_sum(vector<int>& nums,int sum,int index,vector<vector<int>>&mem){
        if(sum==0)return true;
        if(index==nums.size()||sum<0)return false;
        if(mem[index][sum]!=-1)return mem[index][sum];
        for(int i = index; i<nums.size(); i++){
            if(find_arr_with_sum(nums,sum-nums[i],i+1,mem))return mem[index][sum] = 1;
        }
        return mem[index][sum] = 0;
    }

    bool canPartition(vector<int>& nums) {
       
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        vector<vector<int>>mem(nums.size(),vector<int>(sum/2 + 1,-1));
        sort(nums.begin(), nums.end());
        return find_arr_with_sum(nums,sum/2,0,mem);
    }
};
