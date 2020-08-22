#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct List
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push_back(int x) //method to add the new node to the end of the list
    {
        if (head == NULL)
        {
            tail = new Node(x);
            head = tail;
        }
        else
        {
            tail->next = new Node(x);
            tail = tail->next;
        }
        size++;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n"
             << size << "\n";
    }
};

int main()
{
    List list;

    for (size_t i = 0; i < 5; ++i)
    {
        list.push_back(2 * i + 1);
    }

    return 0;
}