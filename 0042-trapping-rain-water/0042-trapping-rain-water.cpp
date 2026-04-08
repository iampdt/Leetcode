class Solution {
public:
    int trap(vector<int>& height) {

        int i=0;
        int j=height.size()-1;
        int ans =0;
        int max_i =0;
        int max_j=0;

        while(i<j)
        {
            max_i = max(max_i, height[i]);
            max_j = max(max_j, height[j]);

            if(max_i <= max_j)
            {
                ans += max_i - height[i];
                i++;
            }
            else 
            {
                ans += max_j - height[j];
                j--;
            }
        }

        return ans;
        
    }
};