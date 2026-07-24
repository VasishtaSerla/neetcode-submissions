class Solution {
public:
    vector<string>ans;
    void find(int n, string &s,int count1,int count2){
     if(count1==n&&count2==n){
      stack<char>temp;
      for(auto x:s){
      if(!temp.empty()){
        if(x==')' && temp.top()=='(')temp.pop();
      else temp.push(x);
      }
      else temp.push(x);
      }
       if(temp.empty())ans.push_back(s);
       return;
      }


      if(count1<n){
        s.push_back('(');
        find(n,s,count1+1,count2);
        s.pop_back();
      }
      if(count2<n){
        s.push_back(')');
        find(n,s,count1,count2+1);
        s.pop_back();
      }
    }
    vector<string> generateParenthesis(int n) {
        string s ={};
        find(n,s,0,0);
        return ans;
    }
};
