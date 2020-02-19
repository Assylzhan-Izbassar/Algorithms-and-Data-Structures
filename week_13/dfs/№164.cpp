#include <iostream>
#include <vector>

using namespace std;

int graph[101][101];
bool used[101];
int n, counter = 0;

void dfs(size_t u)
{
    used[u] = true;
    counter++;

    for (size_t v = 0; v < n; ++v)
    {
        if (graph[u][v] == 1 && !used[v])
            dfs(v);
    }
}

int main()
{
    int s;
    cin >> n >> s;
    s--;

    for (size_t i = 0; i < n; ++i)
        used[i] = false;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            cin >> graph[i][j];

    dfs(s);

    cout << counter << endl;

    return 0;
}