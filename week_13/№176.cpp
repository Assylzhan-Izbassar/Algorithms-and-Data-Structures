#include <iostream>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    size_t arr[n][n];

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            cin >> arr[i][j];

    size_t color[n];

    for (size_t i = 0; i < n; ++i)
        cin >> color[i];

    bool used[n][n];

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            used[i][j] = false;

    size_t count = 0;

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (arr[i][j] == 1 && !used[i][j])
            {
                if (color[i] != color[j])
                    count++;
                if (arr[j][i] == 1)
                    used[j][i] = true;
                used[i][j] = true;
            }
        }
    }

    cout << count << endl;

    return 0;
}