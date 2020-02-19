#include <iostream>

using namespace std;

int main()
{
    size_t n, m;
    cin >> n >> m;

    size_t i, j;
    size_t degree[n];

    for (size_t k = 0; k < n; ++k)
        degree[k] = 0;

    for (size_t k = 0; k < m; ++k)
    {
        cin >> i >> j;
        degree[i - 1] = degree[i - 1] + 1;
        degree[j - 1] = degree[j - 1] + 1;
    }

    for (size_t k = 0; k < n; ++k)
        cout << degree[k] << " ";
    cout << endl;

    return 0;
}