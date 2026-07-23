class Solution {
public:
 vector<vector<int>>ans;
 void f(int index,vector<int>&num,vector<int>curr){   
if(index==num.size()){
    ans.push_back(curr);
    return;
    }
for(int i = index; i<num.size(); i++){
//first include the present index
swap(num[index],num[i]);
curr.push_back(num[index]);
f(index+1,num,curr);
curr.pop_back();
swap(num[index],num[i]);
}
 }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<int>curr;
    f(0,nums,curr);
    return ans;    
    }
};
