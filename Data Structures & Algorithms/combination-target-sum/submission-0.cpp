class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&num,int index,vector<int>curr,int target){
    int sum = accumulate(curr.begin(),curr.end(),0);
    if(sum>target)return;
   else if(sum==target){
    ans.push_back(curr);
    return;
    }
    for(int i = index; i<num.size(); i++){
              curr.push_back(num[i]);
          find(num,i,curr,target);
          curr.pop_back();
    }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int>curr;
        find(nums,0,curr,target);
        return ans;
    }
};
