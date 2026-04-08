class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size() - 1;
        int max_i = 0;
        int max_j = 0;
        int max_area = 0;

        while(i<j)
        {
            max_i = max(max_i,height[i]);
            max_j = max(max_j,height[j]);

            max_area = max(max_area,(min(max_i,max_j) * (j-i)));
            if(max_i < max_j) i++;
            else j--;
        }

        return max_area;
        
    }
};