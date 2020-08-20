#include <iostream>
#include <vector>

using namespace std;

int g[100001][100001];
bool used[100001];
int n;

vector<int> ans;
int counter = 0;

void dfs(int u)
{
    used[u] = true;
    counter++;
    ans.push_back(u);

    for(size_t i=0; i < n; ++i)
    {
        if(g[i][u] == 1 && !used[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;

    for(size_t i=0; i < n; ++i)
        used[i] = false;

    for(size_t i=0; i < n; ++i)
        for(size_t j=0; j < n; ++j)
            g[i][j] = 0;

    int x,y;

    for(size_t i=0; i < m; ++i)
    {
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        g[x][y] = 1;
    }

    int comp = 0;

    for(size_t i=0; i < n; ++i)
    {
        if(!used[i])
        {
            comp++;
            dfs(i);
            ans.clear();
            counter = 0;
        }
    }
    cout << comp << endl;

    for(size_t i=0; i < n; ++i)
        used[i] = false;

    for(size_t i=0; i < n; ++i)
    {
        if(!used[i])
        {
            dfs(i);
            if(counter != 0)
            {
                cout << counter << endl;
                for(size_t i=0; i < ans.size(); ++i)
                {
                    cout << ans[i]+1 << " ";
                }
                cout << endl;
            }
            ans.clear();
            counter = 0;
        }
    }

    return 0;
}