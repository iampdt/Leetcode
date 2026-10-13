class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        int count = 0;
        float curr_max = INT_MIN;
        stack<pair<int,int>> stk;
        for(int i=v.size()-1;i>=0;i--)
        {
           if(!stk.empty())
           {
             auto it = stk.top();
             cout<<v[i].first<<" "<<v[i].second<<endl;
             cout<<float(target - v[i].first)/v[i].second<<endl;
             if(float(target - v[i].first)/v[i].second > curr_max)
             {
                stk.pop();
                count++;
                curr_max = float(target - v[i].first)/v[i].second;
                stk.push(v[i]);
             }
           }
           else 
           {
             count++;
             float t = float(target - v[i].first)/v[i].second;
             curr_max = max(curr_max,t);
             stk.push(v[i]);
           }
           
        }
        // while(!stk.empty())
        // {
        //     auto it = stk.top();
        //     if(float(target - it.first)/it.second > curr_max)
        //     {
        //         count++;
        //         curr_max = float(target - it.first)/it.second;
        //     }
        //     stk.pop();
        // }

        return count;
    }
};