class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n,0);
        for(int i=temperatures.size()-1;i>=0;i--)
        {
            if(!stk.empty())
            {
                while(!stk.empty())
                {
                    int it = stk.top();
                    if(temperatures[i] < temperatures[it])
                    {
                        ans[i] = (it - i);
                        stk.push(i);
                        break;
                    }
                    else stk.pop();
                }
            }
            if(stk.empty())
            {
                ans[i] = 0;
                stk.push(i);
            }

        }
        return ans;
    }
};