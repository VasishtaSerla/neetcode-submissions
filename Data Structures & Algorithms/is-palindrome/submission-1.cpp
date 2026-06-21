
class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.length();
        int left = 0,right = length-1;
        while(left<right){
            if(!isalnum(s[right]) && isalnum(s[left])){
            right--;                
            }
            else if(isalnum(s[right]) && !isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right]) && !isalnum(s[left])){
                right--,left++;
            }
            else{
                if(tolower(s[left]) != tolower(s[right])) return false;
                 right--,left++;
            }
        }
        return true;
    }
};
