class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        int ans = INT_MAX;
        int i = 0;
        unordered_map<int,int> mp;

        for(int j=0;j<cards.size();j++)
        {
           mp[cards[j]]++;
           while(mp[cards[j]] > 1) 
           {
             ans = min(ans, j-i+1);
             mp[cards[i]]--;
             i++;
           }

        }
        return ans == INT_MAX ? -1 : ans;
        
    }
};