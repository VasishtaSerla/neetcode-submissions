class Solution {
public:
    unordered_map<string,int>m;
    bool cansegemented(int start,string s, vector<int> &mem){
    //base case
    if(start==s.size())return true;
    if(mem[start]!=-1)return mem[start];
    for(int i = start; i<s.size(); i++){
       string now = s.substr(start, i-start+1);
       if(m.find(now)!=m.end() && cansegemented(i+1,s,mem)) return mem[start] = 1;
       
    }return mem[start]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict)m[x]++;
        int n = s.size();
        vector<int> mem(n,-1);
       return cansegemented(0,s,mem);
    }
};
