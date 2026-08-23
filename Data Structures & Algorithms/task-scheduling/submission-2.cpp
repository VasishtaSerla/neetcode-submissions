class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        queue<pair<int, int>> q;
        priority_queue<int> maxheap;
        unordered_map<char, int> m;
        for (auto x : tasks)m[x]++;
        for (auto x : m)maxheap.push(x.second);
        int time = 0;
        while(!maxheap.empty()||!q.empty()){
            time++;
            if(!maxheap.empty()){
                if(maxheap.top()>1)q.push({maxheap.top()-1,time+n});
                maxheap.pop();
            }
            if(!q.empty()&&q.front().second==time){
                    maxheap.push(q.front().first);
                    q.pop();
            }
        }
        return time;
    }
};