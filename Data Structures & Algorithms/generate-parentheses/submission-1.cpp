class Solution {
public:
    string bracket = "()";
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

      for(int i = 0; i<2; i++){
    //this is for pruning the invalid before making the choice
        if((count1==n && !i) || (count2==n && i))continue;
         s.push_back(bracket[i]);
         find(n,s,count1+(i==0),count2+(i==1));
         s.pop_back();
      }
    }
    vector<string> generateParenthesis(int n) {
        string s ={};
        find(n,s,0,0);
        return ans;
    }
};
