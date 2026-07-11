class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>last_ind;
         int left = 0,maxel = 0;
        for(int i = 0; i<s.size(); i++){
            if(last_ind.find(s[i]) != last_ind.end() && last_ind[s[i]]>=left){
            left = last_ind[s[i]] + 1;
            }
            last_ind[s[i]] = i;
            maxel = max(maxel,i-left+1);
     }      
       return maxel;
    }
};