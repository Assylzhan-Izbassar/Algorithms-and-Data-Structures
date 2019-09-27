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

            Node* temp = findPostion(position);
            Node* newElement = new Node(x);

            temp->prev->next = newElement;
            newElement->prev = temp->prev;
            newElement->next = temp;
            temp->prev = newElement;

            size = size + 1;
        }

        Node* findPostion(int position)
        {
            int index = 1;
            Node* temp = head;

            while(temp != NULL)
            {
                if(index != position)
                    break;
                temp = temp->next;
                index = index + 1;
            }
            return temp;
        }

        void remove(int x)
        {
            Node* checker = find(x);
            if(checker != NULL)
                remove(checker);
            else
            {
                cout << "This element did not contained in the List!" << endl;
                return;
            }
            size--;
        }

        void remove(Node* element)
        {
            Node* nextEl = element->next;
            Node* prevEl = element->prev;
            element->prev->next = nextEl;
            element->next->prev = prevEl;
            delete(element);
        }

        Node* find(int x)
        {
            Node* result = NULL;
            Node* temp = head;
            while(temp != NULL)
            {
                if(temp->getValue() == x)
                {
                    result = temp;
                    break;
                }
                temp = temp->next;
            }
            return result;
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
    cout << dll.getSize() << endl;
        dll.printList();
    dll.insert(5,6);//insert(index, value);
    cout << dll.getSize() << endl;
        dll.printList();
    dll.remove(9);
    cout << dll.getSize() << endl;
        dll.printList();

    return 0;
}