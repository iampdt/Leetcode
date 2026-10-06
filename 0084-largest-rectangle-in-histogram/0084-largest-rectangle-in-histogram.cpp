class Solution {
public:
    int helper(vector<int>&heights)
    {
        int n = heights.size();
        int max_area = 0;
        stack<int> stk;
        for(int i=0;i<=n;i++)
        {
              int curr = (i == heights.size()) ? 0 : heights[i];
                while(!stk.empty() && heights[stk.top()] >= curr)
                {
                 int h = heights[stk.top()];
                 stk.pop();
                 int width = 1;
                 if(stk.empty()) width = i;
                 else width = i - stk.top() - 1;
                 max_area = max(max_area,width * h);
                }
               if(i<n) stk.push(i);
        }

        return max_area;
    }
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        vector<int> rev = heights;
        reverse(rev.begin(), rev.end());

        return max(helper(heights),helper(rev));
        
    }
};