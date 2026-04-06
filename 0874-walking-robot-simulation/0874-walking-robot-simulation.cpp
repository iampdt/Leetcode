class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        set<pair<int,int>> s;
        for(auto &o : obstacles)
            s.insert({o[0], o[1]});

        vector<pair<int,int>> dirs = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int dir = 0; // start facing North
        int x = 0, y = 0;
        int max_dis = 0;

        for(int cmd : commands)
        {
            if(cmd == -1) {
                dir = (dir + 1) % 4;  // turn right
            }
            else if(cmd == -2) {
                dir = (dir + 3) % 4;  // turn left
            }
            else {
                for(int i = 0; i < cmd; i++)
                {
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    if(s.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    max_dis = max(max_dis, x*x + y*y);
                }
            }
        }

        return max_dis;
    }
};