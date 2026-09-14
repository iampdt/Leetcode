class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        // for(int i=0;i<position.size()-1;i++)
        // {
        //     if(position[i+1] - position[i] <= distance) 
        // }
        int count = 1;
        for(int i = speed.size()-1;i>0;i--)
        {
             if(speed[i] < speed[i-1] || position[i] - position[i-1] <= distance) 
             {
                speed[i-1] = speed[i];
                continue;
             }
             else count++;
        }
        return count;
        
        
    }
};