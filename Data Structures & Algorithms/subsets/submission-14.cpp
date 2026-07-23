class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>&num,int index,vector<int>&temp){
     if(index==num.size()){
        ans.push_back(temp);
        return;
     }
    //include then find then pop and find
      temp.push_back(num[index]);
     find(num,index+1,temp);
     temp.pop_back();
     find(num,index+1,temp);

     
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>curr;
        find(nums,0,curr);
        return ans;
    }
};
