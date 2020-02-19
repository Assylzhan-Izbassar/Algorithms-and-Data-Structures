#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n][n];
    bool used[n][n];

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
            used[i][j] = false;
        }

    size_t count = 0;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
        {
            if (arr[i][j] == 1 && !used[i][j])
            {
                count++;
                if (arr[j][i] == 1)
                    used[j][i] = true;
                used[i][j] = true;
            }
        }

    cout << count << endl;

    return 0;
}