class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap;
        for(auto x:stones)maxheap.push(x);
        while(!maxheap.empty()){
            if(maxheap.size()==1)return maxheap.top();
            int s1 = maxheap.top();
            maxheap.pop();
            int s2 = maxheap.top();
            maxheap.pop();
            if(s1==s2)continue;
            else{
                if(s1>s2)maxheap.push(s1-s2);
                else maxheap.push(s2-s1);
            }
        }return 0;
    }
};
