class KthLargest {
public:
    int kn;
    priority_queue<int,vector<int>,greater<int>>minheap;
    KthLargest(int k, vector<int>& nums) {
       kn = k; 
       for(auto x:nums)insert_heap(x);
    }
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
    int add(int val) {
        insert_heap(val);
        return minheap.top();
    }
};
