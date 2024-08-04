#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(s) (s).begin(), (s).end()
#define allr(s) (s).rbegin(), (s).rend()
#define T     \
    int t;    \
    cin >> t; \
    while (t--)
#define OO INT_MAX
#define INF LONG_LONG_MAX
#define fx(x) fixed << setprecision(x)
#define mod 1000000007

void FastFile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //  freopen("metro.in", "r", stdin);
    //    freopen("OOO.txt", "w", stdout);
}

const int MAX = 2002;
int stations, lines, samelineTime, jumbTime, S, E;

// Custom hash function for pair<short, short>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<short, short>, vector<pair<pair<short, short>, int>>, pair_hash> adj;

ll dijkstra(pair<short, short> SS)
{
    unordered_map<pair<short, short>, ll, pair_hash> dist;
    priority_queue<pair<ll, pair<short, short>>> q;
    q.push({0, SS});
    dist[SS] = 0;

    while (!q.empty())
    {
        pair<short, short> k = q.top().second;
        ll so_far_cost = -q.top().first;

        q.pop();

        if (k.first == E)
            return so_far_cost;

        if (so_far_cost > dist[k])
            continue;

        for (auto &ne : adj[k])
        {
            if (dist[ne.first] == 0)
                dist[ne.first] = INF;

            if (so_far_cost + ne.second < dist[ne.first])
            {
                dist[ne.first] = so_far_cost + ne.second;

                q.push({-dist[ne.first], ne.first});
            }
        }
    }

    return INF;
}

void solve()
{
    cin >> stations >> lines >> S >> E >> samelineTime >> jumbTime;

    adj.clear();
    unordered_map<short, vector<short>> common;
    vector<pair<short, short>> start;
    
    for (int i = 1; i <= lines; ++i)
    {
        short q, x, y;
        cin >> q;
        q--;
        cin >> y;
        if (y == S)
            start.push_back({y, i});

        common[y].push_back(i);
        while (q--)
        {
            cin >> x;
            if (x == S)
                start.push_back({x, i});
            adj[{y, i}].push_back({{x, i}, samelineTime});
            common[x].push_back(i);
            y = x;
        }
    }

    for (auto &it : common)
    {
        if (it.second.size())
        {
            int n = it.second.size();
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    adj[{it.first, it.second[i]}].push_back({{it.first, it.second[j]}, jumbTime});
                }
            }
        }
    }
    ll ans = INF;

    for (auto &it : start)
        ans = min(ans, dijkstra(it));

    cout << (ans == INF ? -1 : ans) << endl;
}

int32_t main()
{
    FastFile();
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i)
    {
        solve();
    }
}
