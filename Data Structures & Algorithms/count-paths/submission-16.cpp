class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m+n-2;
        int x = m-1;
        int y = n-1;
        int minimum = min(x,y);
        int maximum = max(x,y);
        int count = 1;
        long long int res = 1;
        for(int i = maximum+1; i<=a; i++){
         res = (res*i)/count;
         count++;
        }return int(res);
    }
};
