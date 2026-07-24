class Solution {
public:
   vector<vector<int>>ans;
   void find(int index, vector<int>&num, vector<int>&curr){
      ans.push_back(curr);
      for(int i = index; i<num.size(); i++){
        if(i>index&&num[i]==num[i-1])continue;
        curr.push_back(num[i]);
        find(i+1,num,curr);
        curr.pop_back();
      }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int>curr;
     sort(nums.begin(),nums.end());
     find(0,nums,curr);
     return ans;    
    }
};
