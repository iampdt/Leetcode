class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        
        stack<int> stk;
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        { 
          
        
             while(!stk.empty() && nums[i] < stk.top()) 
             {
                mp[stk.top()]--;
                if(mp[stk.top()] == 0) mp.erase(stk.top());
                stk.pop();
             } 
             ans += (stk.size() - mp[nums[i]]);
             mp[nums[i]]++;// everthing in the stack is less the top element
             stk.push(nums[i]);

        }
        // while(!stk.empty())
        // {
        //     cout<<stk.top()<<" ";
        //     stk.pop();
        // }
        return ans;
       
    }
};