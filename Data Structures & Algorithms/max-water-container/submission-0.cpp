class Solution {
public:
    int maxArea(vector<int>& heights) {
        // We use two pointers to solve this question
        int left = 0;
        int right = heights.size() - 1;
        int max_water = 0;

        while (left < right){
            int width = right - left;
            int current_h = min(heights[left], heights[right]);
            
            int current_area = width * current_h;
            max_water = max(max_water, current_area);

            // move the pointer that points to the shorter bar
            if(heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_water;
    }
};
