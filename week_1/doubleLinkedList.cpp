#include <iostream>

using namespace std;

struct Node
{
    private:
        int value;

    public:
        Node* next;
        Node* prev;

        Node(int x)
        {
            value = x;
            next = NULL;
            prev = NULL;
        }

        int getValue()
        {
            return value;
        }
};

struct DoubleLinkedList
{
    private:
        Node* head;
        Node* tail;
        int size;

    public:

        DoubleLinkedList()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void push_back(int x)
        {
            if(head == NULL)
            {
                tail = new Node(x);
                head = tail;
            }
            else
            {
                tail->next = new Node(x);
                tail->next->prev = tail;
                tail = tail->next;
            }
            size = size + 1;
        }

        void insert(int x, int position)
        {
            if(position > size + 1)
            {
                cout << "Invailid position!" << endl;
                return;
            }
            else if(position == size+1)
            {
                push_back(x);
                return;
            }
            int index = 1;
            Node* temp = head;

            while(index != position)
            {
                temp = temp->next;
                index = index + 1;
            }

            Node* newElement = new Node(x);

            temp->prev->next = newElement;
            newElement->prev = temp->prev;
            newElement->next = temp;
            temp->prev = newElement;

            size = size + 1;
        }

        void printList()
        {
            Node*temp = head;
            while(temp != NULL)
            {
                cout << temp->getValue() << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void printReverseList()
        {
            Node*temp = tail;
            while(temp != NULL)
            {
                cout << temp->getValue() << " ";
                temp = temp->prev;
            }
            cout << endl;
        }

        int getSize()
        {
            return size;
        }
};

int main()
{
    DoubleLinkedList dll;

    for(size_t i=1; i <= 20; i*=2)
    {
        dll.push_back(i);
    }

    dll.insert(5,6);
    cout << dll.getSize() << endl;
    dll.printList();

    return 0;
}