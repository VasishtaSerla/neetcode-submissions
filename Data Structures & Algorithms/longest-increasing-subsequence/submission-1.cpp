class Solution {
public: 
    int number(vector<int>& nums,int index,vector<int>&mem){
        if(index==nums.size())return mem[index] =  0;
        if(mem[index]!=-1)return mem[index];
        //number is the count of elements 
        int num = 0;
        for(int i = index+1; i<nums.size(); i++){
           if(nums[i]>nums[index]) {
              num = max(num,number(nums,i,mem));
        }
        }return mem[index] = 1+num;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = 0;
        vector<int>mem(nums.size(),-1);
        for(int i = 0;i<nums.size();i++){
             n = max(n,number(nums,i,mem));
        }//1,
        return n;
    }
};
