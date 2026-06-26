class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>infix;
        for(auto s:tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
               int val2 = infix.top();
               infix.pop();
               int val1 = infix.top();
               infix.pop();
               if(s=="+")infix.push(val1+val2);
              else if(s=="-")infix.push(val1-val2);

                else if(s=="*")infix.push(val1*val2);
                else if(s=="/")infix.push(val1/val2);

            }
            else infix.push(stoi(s));
        }
        return infix.top();
    }
};
