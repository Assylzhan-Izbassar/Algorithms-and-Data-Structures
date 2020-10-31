#include <iostream>

using namespace std;

struct Stack
{
    private:
        int arr[101];
        int size;
        int index;
    public:
        Stack()
        {
            size = 0;
            index = 100;
        }
        void push(int x)
        {
            arr[index] = x;
            index--;
            size++;
            cout << "ok" << endl;
        }
        void pop()
        {
            index++;
            cout << arr[index] << endl;
            arr[index] = 0;
            size--;
        }
        void back()
        {
            int i = index + 1;
            cout << arr[i] << endl;
        }
        int size_()
        {
            return size;
        }
        void clear()
        {
            for(size_t i=index; i < 101; ++i)
                arr[i] = 0;
            index = 100;
            size = 0;
            cout << "ok" << endl;
        }
        bool exit(bool load)
        {
            cout << "bye" << endl;
            load = false;
            return load;
        }
        // void print(){
        //     cout << "stack: ";
        //     for(size_t i = index; i < 101; ++i)
        //         cout << arr[i] << " index:" << i << " ";
        //     cout << endl;
        // }
};


int main()
{
    Stack stack;
    
    bool load = true;

    string s;
    int n;

    while(load != false)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> n;
            stack.push(n);
        }
        else if(s == "pop")
            stack.pop();
        else if(s == "back")
            stack.back();
        else if(s == "size")
            cout << stack.size_() << endl;
        else if(s == "clear")
            stack.clear();
        // else if(s == "print")
        //     stack.print();
        else
            load = stack.exit(load);
    }
    
    return 0;
}