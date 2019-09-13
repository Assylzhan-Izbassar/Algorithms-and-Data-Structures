#include <iostream>

using namespace std;

struct Queqe
{
private:
    int arr[101];
    int length;
    int index;

public:
    Queqe()
    {
        length = 0;
        index = 0;
    }
    void push(int x)
    {
        arr[index] = x;
        index++;
        length++;
        cout << "ok" << endl;
    }
    void pop()
    {
        cout << arr[0] << endl;
        for (size_t i = 1; i <= length; ++i)
        {
            arr[i - 1] = arr[i];
        }
        length--;
        index--;
    }
    void front()
    {
        cout << arr[0] << endl;
    }
    int size()
    {
        return length;
    }
    void clear()
    {
        for (size_t k = 0; k <= 100; ++k)
        {
            arr[k] = 0;
        }
        index = 0;
        length = 0;
        cout << "ok" << endl;
    }
    bool exit(bool exit_)
    {
        exit_ = true;
        cout << "bye" << endl;
        return exit_;
    }
};

int main()
{
    string s;
    int n;

    bool exit_ = false;

    Queqe quequ;

    while (exit_ != true)
    {
        cin >> s;

        if (s == "size")
            cout << quequ.size() << endl;
        else if (s == "push")
        {
            cin >> n;
            quequ.push(n);
        }
        else if (s == "pop")
            quequ.pop();
        else if (s == "front")
            quequ.front();
        else if (s == "clear")
            quequ.clear();
        else
            exit_ = quequ.exit(exit_);
    }

    return 0;
}