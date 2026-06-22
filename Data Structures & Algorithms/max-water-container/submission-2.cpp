class Solution {
public:
    int maxArea(vector<int>& heights) {
  
        int max = 0;
        // for(int i = 0; i<heights.size(); i++){
        //     for(int j = i+1; j<heights.size(); j++){
        //         int area = min(heights[i],heights[j])*(j-i);
        //         if(area > max)max = area;
        //     }
        // }return max;
        int left = 0,right = heights.size()-1;
        while(left<right){
          int small = min(heights[left],heights[right]);
          int product = small*(right-left);
            if(product > max) max = product;
            if(heights[left]<heights[right])left++;
            else right--;
        }return max;
    }
};