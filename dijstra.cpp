// code by CasioFx-69
int main()
{
    int V;
    cin >> V;
    vector<pair<int, int>> adj[V];
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }
    int src;
    cin >> src;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    vector<int> visited(V, 0);
    vector<int>dis(V);
    dis[0]=0;
    while (q.size())
    {
        auto x = q.top();
        q.pop();
        if (visited[x.second] == 1)
        {
            continue;
        }
        else
        {
            visited[x.second]=1;
            dis[x.second] = x.first;
            int t = x.second;
            for (auto i : adj[x.second])
            {
                if(visited[i.second]==0)
                q.push(make_pair(x.first + i.first, i.second));

            }
        }
    }
    printv(dis);
    return 0;
}
