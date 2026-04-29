class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int j=0;j<nums.size();j++)
        {
            while(!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
                
                 dq.push_back(j);
            while(!dq.empty() && j-dq.front()+1 > k) dq.pop_front();
            if (j >= k - 1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
