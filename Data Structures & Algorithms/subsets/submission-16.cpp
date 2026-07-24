class Solution {
public:
   vector<vector<int>>ans;
   void find(int index, vector<int>&num, vector<int>&curr){
      ans.push_back(curr);
      for(int i = index; i<num.size(); i++){
        curr.push_back(num[i]);
        find(i+1,num,curr);
        curr.pop_back();
      }
   }
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<int>curr;
     find(0,nums,curr);
     return ans;    
    }
};
