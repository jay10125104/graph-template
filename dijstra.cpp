vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S){
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      q.push({0,S});
      vector<int>distance(V,INT_MAX);
      vector<int>visited(V);
      while(q.size()){
          auto x = q.top();
          q.pop();
          int srcw = x.first;
          int srcidx = x.second;
          if(visited[srcidx]==1){
              continue;
          }
          else{
              distance[srcidx] = srcw;
              visited[srcidx]=1;
              for(auto i:adj[srcidx]){
                  if(visited[i.second]==0){
                      q.push({srcw+i.first,i.second});
                  }
              }
          }
      }
      return distance;
}
