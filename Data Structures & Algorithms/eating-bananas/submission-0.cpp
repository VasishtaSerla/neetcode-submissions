class Solution {
public:
    int last;
    //we are searching in a
    int search(vector<int>&piles,int h){
        int left = 1, right  = *max_element(piles.begin(),piles.end());
        while(left <= right){
             int sum = 0;
        int mid = (left+right)/2;
        for(auto x:piles){
            sum += (x+mid-1)/mid;
        }
        if(sum<=h){
            last = mid;
            right = mid-1;  
        }
        else left = mid+1;
    }
    return last;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int length = piles.size(), max = *max_element(piles.begin(),piles.end());
        int sum = 0;
        int ans = search(piles,h);
        return ans;
    }
};
