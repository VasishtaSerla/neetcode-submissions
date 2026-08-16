class Solution {
public:
unordered_map<char,int>m1;
        unordered_map<char,int>m2;
    int common(string &t1,string &t2,int i1,int i2,vector<vector<int>>&mem){
        if(i1==t1.size() || i2==t2.size())return 0;
        if(mem[i1][i2]!=-1)return mem[i1][i2];
        if(m1.find(t1[i1])==m1.end())return common(t1,t2,i1+1,i2,mem);
        if(m2.find(t2[i2])==m2.end())return common(t1,t2,i1,i2+1,mem);
        if(t1[i1]==t2[i2])return mem[i1][i2] = 1+common(t1,t2,i1+1,i2+1,mem);
        
    return mem[i1][i2] = max(common(t1,t2,i1+1,i2,mem),common(t1,t2,i1,i2+1,mem));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>mem(text1.size(),vector<int>(text2.size(),-1));
        
        for(auto x:text1)m1[x]++;
        for(auto x:text2)m2[x]++;
        return common(text1,text2,0,0,mem);
    }
};
