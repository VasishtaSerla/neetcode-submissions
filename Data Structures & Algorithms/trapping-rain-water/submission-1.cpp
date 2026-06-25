class Solution {
public:
    int trap(vector<int>& height) {
//track max heights from the left and right
int length = height.size();
if(length<3)return 0;
vector<int>max_left(length), max_right(length);
int total_area = 0;
max_left[0] = 0, max_right[0] = 0;

for(int i = 1; i<length; i++){
    if(height[i-1] > max_left[i-1])max_left[i] = height[i-1];
    else max_left[i] = max_left[i-1];

    if(height[length-i] > max_right[i-1])max_right[i] = height[length-i];
    else max_right[i] = max_right[i-1];
}
for(int i = 0; i<length; i++){
    if(min(max_left[i],max_right[length-i-1])>height[i])  total_area += min(max_left[i],max_right[length-i-1])-height[i];
}

return total_area;

}
};
