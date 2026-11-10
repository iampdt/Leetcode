class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, unordered_set<int>> busMap, routeMap;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                busMap[stop].insert(i);
                routeMap[i].insert(stop);
            }
        }

        unordered_set<int> visStops, visRoutes;
        queue<pair<int, int>> q;

        for(int routes: busMap[source])
        {
            for(int stops: routeMap[routes])
            {
                if (!visStops.count(stops)) {
                    visStops.insert(stops);
                    q.push({stops, 1});
                }
            }
            visRoutes.insert(routes);
        }

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int cnt = it.second;
            if(stop == target) return cnt;

            for(int route: busMap[stop])
            {
                if(visRoutes.find(route) != visRoutes.end()) continue;
                for(int next: routeMap[route])
                {
                    if(!visStops.count(next))
                    {
                        visStops.insert(next);
                        q.push({next,cnt+1});
                    }

                }
                visRoutes.insert(route);
            }
        }

        return -1;
    }
};