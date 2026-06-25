class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto c:s){
      if(st.empty())st.push(c);
      else{
        
        if(st.top() == '(' && c==')'){st.pop();
        continue;
        }
        else if(st.top() == '{' && c=='}'){st.pop();
        continue;}
        else if(st.top() == '[' && c==']'){st.pop();
        continue;}
        st.push(c);
      }
        }
        if(st.empty())return true;
        else return false;
    }
};