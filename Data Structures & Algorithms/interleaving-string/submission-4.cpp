class Solution {
public:
    int interleave(string s1, string s2, string s3,int i1,int i2,int k, vector<vector<int>>&mem){
        if(k==s3.size())return 1;
        if(mem[i1][i2]!=-1)return mem[i1][i2];
        int a =0,b=0;
        if(i1<s1.size()){
            if(s1[i1]==s3[k])
            {
                 a = interleave(s1,s2,s3,i1+1,i2,k+1,mem);
            }
        }
        if(i2<s2.size()){
            if(s2[i2]==s3[k])
            {
                 b = interleave(s1,s2,s3,i1,i2+1,k+1,mem);
            }
        }
        return mem[i1][i2] = a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>mem(s1.size()+1,vector<int>(s2.size()+1,-1));
        if(s1.size()+s2.size()!=s3.size())return false;
        return interleave(s1,s2,s3,0,0,0,mem);
    }
};
