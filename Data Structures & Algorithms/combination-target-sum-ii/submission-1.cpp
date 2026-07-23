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
    if(index==num.size())return;
    for(int i = index; i<num.size(); i++){
        if(i>index&&num[i]==num[i-1])continue;
              curr.push_back(num[i]);
          find(num,i+1,curr,target);
          curr.pop_back();
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
       sort(candidates.begin(),candidates.end());
        find(candidates,0,curr,target);
        return ans;
    }
};
