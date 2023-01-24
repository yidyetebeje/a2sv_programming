class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeight = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            if(height[left] <= height[right]){
                int area = height[left] * (right - left);
                maxHeight = max(maxHeight, area);
                left++;
            }
            else {
                int area = height[right] *(right - left );
                maxHeight = max(maxHeight, area);
                right--;
            }
        }
        return maxHeight;
    }
};