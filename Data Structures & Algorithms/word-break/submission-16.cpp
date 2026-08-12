class Solution {
public:
    unordered_map<string,int>m;
    bool cansegemented(int start,int curr, string &s,vector<string>& wordDict, vector<int> &mem){
    //base case
    if(curr==s.size()){
        mem[start] = 0;
        return false;
        }
    if(mem[start]!=-1){
        if(mem[start])return true;
        else return false;
    }
    string now = s.substr(start, curr-start+1);
    if(m.find(now)!=m.end()){
        //choose now or move to the next character
        if(curr == s.size()-1){
            mem[start] = 1;
            return true;}
        bool b1 = cansegemented(curr+1,curr+1,s,wordDict,mem);
        bool b2 = cansegemented(start,curr+1,s,wordDict,mem);
        return b1||b2;
    }
    else{
        return cansegemented(start,curr+1,s,wordDict,mem);
    }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict)m[x]++;
        int n = s.size();
        vector<int> mem(n,-1);
       return cansegemented(0,0,s,wordDict,mem);
    }
};
