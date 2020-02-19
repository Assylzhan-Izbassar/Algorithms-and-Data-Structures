#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6;

int arr[101][101];
bool used[101];
vector<int> d(101, -1);

void dijkstra(int n, int s, int f)
{
    d[s] = 0;

    for (size_t i = 0; i < n; ++i)
    {
        int v = -1;
        for (size_t j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;

        if (d[v] == -1)
            break;

        used[v] = true;

        for (size_t j = 0; j < n; ++j)
        {
            int to = -1, len = -1;
            if (arr[v][j] != 0 || arr[v][j] != -1)
            {
                to = j;
                len = arr[v][j];
                
                if (d[v] + len < d[to])
                {
                    d[to] = d[v] + len;
                }
            }
        }
    }
}

int main()
{
    int n, s, f;
    cin >> n >> s >> f;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            cin >> arr[i][j];

    for (size_t i = 0; i < n; ++i)
        used[i] = false;

    dijkstra(n, s, f);

    int path = 0;

    for (int i = min(s, f) - 1; i < max(s, f); ++i)
        path += d[i];

    if (path < 0)
        cout << -1 << endl;
    else
        cout << path << endl;

    return 0;
}