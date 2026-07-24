class Solution {
public:
    vector<string>ans;
    void find(int n, string &s,int count1,int count2){
     if(count1==n&&count2==n){
     ans.push_back(s);
     return;
      }
      if(count1<n){
        s.push_back('(');
        find(n,s,count1+1,count2);
        s.pop_back();
      }
      if(count2<count1){
        s.push_back(')');
        find(n,s,count1,count2+1);
        s.pop_back();
      }
    }
    vector<string> generateParenthesis(int n) {
        string s ="";
        find(n,s,0,0);
        return ans;
    }
};
