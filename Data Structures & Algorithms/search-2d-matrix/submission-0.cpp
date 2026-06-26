class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int left1 = 0,left2 = 0,right1 = m-1, right2 = n-1, found = 0;
        int mid1;
        while(left1 <= right1){
             mid1 = (left1+right1)/2;
            if(target >= matrix[mid1][0] && target<=matrix[mid1][n-1]){ 
                found = 1;
                break;
            }
            else if(target<matrix[mid1][0])right1 = mid1-1;
            else left1 = mid1+1;
        }
        if(found==0)return false;

        while(left2<=right2){
            int mid2 = (left2+right2)/2;
            if(matrix[mid1][mid2]==target)return true;
            else if(matrix[mid1][mid2]<target)left2 = mid2+1;
            else right2 = mid2-1;
        }
        return false;
    }
};