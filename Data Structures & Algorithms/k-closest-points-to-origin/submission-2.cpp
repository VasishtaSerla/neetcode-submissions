class Solution {
public:
    int kn;
     priority_queue<tuple<double,int,int>>maxheap;

    void insert_heap(tuple<double,int,int> num){
        if(maxheap.size()<kn){
            maxheap.push(num);
        return;
        }
        if(get<0>(maxheap.top())>get<0>(num)){
            maxheap.pop();
            maxheap.push(num);
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        kn = k;
       
        for(auto x:points){
            auto dist = sqrt(x[0]*x[0] + x[1]*x[1]);
            insert_heap({dist,x[0],x[1]});
        }
        while(!maxheap.empty()){
            int x = get<1>(maxheap.top());
            int y = get<2>(maxheap.top());
            ans.push_back({x,y});
            maxheap.pop();
        }
        return ans;

    }
};
