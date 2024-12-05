#include <bits/stdc++.h>
using namespace std;

int getParent(int i, int parent[])
{
    if (parent[i] == i)
        return i;
    return getParent(parent[i], parent);
}

bool isCycle(int u, int v, int parent[])
{
    int i = getParent(u, parent);
    int j = getParent(v, parent);
    // cout << i << " " << j << "\n";
    if (i != j)
    {
        parent[i] = j;
        return false;
    }
    return true;
}
void krushkals(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p, int n)
{
    int totalWeight = 0;
    vector<pair<int, int>> v;
    int parent[n + 1];
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    while (!p.empty())
    {
        auto top = p.top();
        if (!isCycle(top.second.first, top.second.second, parent))
        {
            v.push_back({top.second.first, top.second.second});
            totalWeight += top.first;
        }
        p.pop();
    }
    cout << "Edges\n";
    for (auto i : v)
    {
        cout << i.first << " " << i.second << "\n";
    }
    cout << "Total Spanning tree for Krushkals is: " << totalWeight << "\n";
}
int main()
{
    int n, e;
    cin >> n >> e;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        p.push({w, {u, v}});
    }
    krushkals(p, n);
}