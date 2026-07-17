class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int>a1(26,0),a2(26,0);
        for(auto c:s1)a1[c-'a']++;
        for(int i = 0; i<s1.size(); i++)a2[s2[i]-'a']++;
        int left = 0,right = s1.size()-1;
        while(right<s2.size()){
            if(a2==a1)return true;
            a2[s2[left]-'a']--,left++;
            if(right<s2.size()-1){
             right++;
             a2[s2[right]-'a']++;
            }else return false;
        }
    }
};