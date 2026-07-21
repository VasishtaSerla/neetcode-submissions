class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char,int>tm,dm;
   int length = s.size();
    pair<int,int>p = {0,length-1};
    for(auto x:t){
        tm[x]++;
    }
        int left=0,found=0;
        for(int i = 0; i<s.size(); i++){   
            if(tm.find(s[i])!=tm.end()){
            dm[s[i]]++;
           }
           else continue;
            for(auto x:tm){
             if(dm[x.first]<x.second){
                found = 0;
                break;
             }  
             else found = 1;
            }
            if(found==1){
                //trimming left
                while((tm.find(s[left])==tm.end()) || (tm.find(s[left])!=tm.end() && dm[s[left]]>tm[s[left]])){
                    if(tm.find(s[left])!=tm.end() && dm[s[left]]>tm[s[left]])dm[s[left]]--;
                    left++;
                }
              if(i-left<p.second-p.first)p={left,i}; 
            }
            
        }if(found==0)return "";
        else return s.substr(p.first,p.second-p.first+1);
    }
};