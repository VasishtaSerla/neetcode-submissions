class Solution {
public:
    int search(vector<int>& nums, int target) {
                int left = 0, right = nums.size()-1;
                while(left<=right){
                    int mid = left + (right - left)/2;
                    if(left<right){
                        auto it = find(nums.begin()+left,nums.begin()+right+1,target);
                        if(it!=nums.end())return it - nums.begin();
                        else return -1;
                    }
                    if(target==nums[mid])return mid;
                    else if(target>nums[mid]){
                        if(target>nums[right])right = mid-1;
                        else left = mid+1;
                    }
                    else {
                        if(target>right)right = mid-1;
                        else left = mid+1;
                    }
                }return -1;
    }
};