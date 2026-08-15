class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m+n-2;
        int r = min(m-1,n-1);
       long long  int res = 1;
        for(int i = 1; i<=r; i++){
         res = (res*(a-r+i))/i;
        }return int(res);
    }
};
