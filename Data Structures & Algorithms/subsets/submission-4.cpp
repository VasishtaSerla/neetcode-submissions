class Solution {
public:
    vector<vector<int>>ans;
    void find(vector<int>num,int index,vector<int>temp){
     if(index==num.size()){
        ans.push_back(temp);
        return;
     }
     //exclude and go to the next one
     find(num,index+1,temp);
     //include and go to the next one
     temp.push_back(num[index]);
     find(num,index+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        find(nums,0,{});
        return ans;
    }
};
