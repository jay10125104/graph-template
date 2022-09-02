bool isbipartitie(vector<int> adj[], vector<int> &visited, map<pair<int, int>, int> &m)
{
    queue<pair<int, int>> q;
    int count = 1;
    q.push({1, 1});
    int flag1 = 1;
    int flag2 = 2;
    while (q.size())
    {
        int x = q.size();
        while (x--)
        {
            auto mid = q.front();
            q.pop();
            if (visited[mid.first] && visited[mid.first] != mid.second)
            {
                return false;
            }
            else
            {
                visited[mid.first] = count;
            }
            for (auto it : adj[mid.first])
            {
                if (visited[it] == 0)
                {
                    q.push({it, count + 1});
                    m[{mid.first, it}] = flag1;
                    m[{it, mid.first}] = flag2;
                }
            }
        }

        swap(flag1, flag2);
        count++;
    }
    return true;
}
