class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adjList;
        // Create a map from the bus stop to all the routes that include this stop.
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                // Add all the routes that have this stop.
                adjList[stop].push_back(route);
            }
        }

        queue<int> q;
        unordered_set<int> vis;
        // Insert all the routes in the queue that have the source stop.
        for (auto route : adjList[source]){
            q.push(route);
            vis.insert(route);
        }

        int busCount = 1;
        while (q.size()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int route = q.front(); q.pop();

                // Iterate over the stops in the current route.
                for (auto stop: routes[route]) {
                    // Return the current count if the target is found.
                    if (stop == target) {
                        return busCount;
                    }

                    // Iterate over the next possible routes from the current stop.
                    for (auto nextRoute : adjList[stop]) {
                        if (!vis.count(nextRoute)) {
                            vis.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};




// class Solution {
// public:
//     unordered_map<int,int> visited;
//     unordered_map<int,vector<int>> availablebuses;
//     int findswaps(int curr,int dest,int swap){
//         if(visited.count(curr)== 0 || visited[curr] == 1){
//             return INT_MAX;
//         }
//         visited[curr] = 1;
//         if(curr == dest){
//             return swap;
//         }
//         // for(int i=0;i<availablebuses[curr].size();i++){
//         //     for(int j=0;j<availablebuses[dest].size();j++){
//         //         if(availablebuses[curr][i] == availablebuses[dest][j]){
//         //             return swap;
//         //         }
//         //     }
//         // }
//         int minways = INT_MAX;
//         for(int i=0;i<availablebuses[curr].size();i++){
//             minways = min(minways,findswaps(availablebuses[curr][i],dest,swap+1));
//         }
//         return minways;


        
//     }
//     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
//         for(int i=0;i<routes.size();i++){
//             for(int j=0;j<routes[i].size();j++){
//                 availablebuses[routes[i][j]].push_back(i);
//                 visited[routes[i][j]] = 0;
//             }
//         }
//         int minways = findswaps(source,target,0);
//         if(minways == INT_MAX)
//             return -1;
//         else
//             return minways;
//     }
// };