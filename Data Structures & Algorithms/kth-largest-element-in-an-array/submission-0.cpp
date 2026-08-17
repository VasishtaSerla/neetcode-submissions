class Solution {
public:
    int kn;
    priority_queue<int,vector<int>,greater<int>>minheap;
    void insert_heap(int num){
        if(minheap.size()<kn){
            minheap.push(num);
        return;
        }
        if(minheap.top()<num){
            minheap.pop();
            minheap.push(num);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        kn = k;
        for(auto x:nums)insert_heap(x);
        return minheap.top();
    }
};
