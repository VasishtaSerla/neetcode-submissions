class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int seq_start = nums[0];
        unordered_set<int>s;
        for(int x:nums){
            s.insert(x);
        }
        unordered_map<int,int>m;
        for(int x:s){
            m[x]++;
        }
        vector<int>starters;
        for(int x:s){
           if(m[x-1]<1){
            starters.push_back(x);
           }
        }
        vector<int>count(starters.size(),1);
        for(int i = 0; i<starters.size(); i++){
            int curr_starter = starters[i];
            while(m[curr_starter+1] >= 1){
                count[i]++;
                curr_starter += 1;
            }
        }
        int max = count[0];
         for(int i = 0; i<count.size(); i++){
        if(count[i]>max){max = count[i];}
        }
      return max;
    }
};