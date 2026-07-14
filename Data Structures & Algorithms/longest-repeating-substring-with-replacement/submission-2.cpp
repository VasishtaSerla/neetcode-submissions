class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int>alpha(26,0),ans;
      int left = 0,right = 0;
     alpha[s[right]-'A']++;
      while(right<=s.size()-1){
        int max_window = *max_element(alpha.begin(),alpha.end());
        int to_be_replaced = right - left + 1 - max_window;
       if (to_be_replaced <= k) {
    ans.push_back(right - left + 1);
    right++;
    if (right < s.size()) {          
        alpha[s[right] - 'A']++;
    }
}
        else {
            alpha[s[left]-'A']--;
            left++;
        }
      }
      return *max_element(ans.begin(),ans.end());
    }
};