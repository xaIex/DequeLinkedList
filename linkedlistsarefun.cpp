#include <iostream>
#include <iomanip>

using namespace std;

class MyDeque
{
private:
    struct Node
    {
        int x;
        Node* next;
    };
    Node* head;

public:
    MyDeque()
    { head = nullptr; }

    ~MyDeque()
    { clear(); }

    void push_back(int v)
    {
        Node* newNode;
        Node* nPtr;

        newNode = new Node;
        newNode->x = v;
        newNode->next = nullptr;

        if (head == nullptr)
            head = newNode;
        else
        {
            nPtr = head;

            while (nPtr->next != nullptr)
                nPtr = nPtr->next;

            nPtr->next = newNode;
        }
    }
    void push_front(int v)
    {
        Node* newNode;
        newNode = new Node;
        newNode->x = v;

        newNode->next = head;
        head = newNode;
       
    }
    int front() const
    {
        if (head == nullptr)
            return -1;
        else 
           return head->x;
    }
    int back() const
    {
        Node* nPtr;
        nPtr = head;
        if (head == nullptr)
            return -1;
        else
        {
            // note to self: cannot be (nPtr != nullptr) otherwise it would it would derefence nPtr which is null
            while (nPtr->next != nullptr)
                nPtr = nPtr->next;
            return nPtr->x;
        }
    }
    void clear()
    {
        Node* nPtr;
        Node* nextNode;

        nPtr = head;
        while (nPtr != nullptr) {
            nextNode = nPtr->next;
            delete nPtr;
            nPtr = nextNode;
        }
    }
    void remove(int v)
    {
        Node* nPtr;
        Node* prevNode = nullptr;// if not nullptr, error says "potentinally unintialized local pointer variable used"

        if (head == nullptr) // if no node
            return;
        if (head->x == v) // if at first node
        {
            nPtr = head->next;
            delete head;
            head = nPtr;
        } 
        else
        {
            nPtr = head;
            while (nPtr != nullptr && nPtr->x != v) 
            {
                prevNode = nPtr;
                nPtr = nPtr->next;
            }

            if (nPtr)
            {
                prevNode->next = nPtr->next;
                delete nPtr;
            }
        }
    }
    int size() const
    {
        Node* nPtr;
        nPtr = head;
        int count = 0;
        while (nPtr != nullptr) {
            nPtr = nPtr->next;
            count++;
        }
        return count;
    }
    friend ostream& operator<<(ostream& o, const MyDeque& m);
};

ostream& operator<<(ostream& o, const MyDeque& m)
{
    o << "[";
    MyDeque::Node* nPtr;
    nPtr = m.head;

    while (nPtr != nullptr) {
        o << nPtr->x << ","; // print val in node
        nPtr = nPtr->next; // go to next node
    }
    o << "]";
        return o;
}

int main()
{
    MyDeque m;
   
    for (int i = 0; i < 5; i++)
        m.push_front(rand() % 100 + 1);

    cout << "The contents of MyDeque: " << m;

    cout << "\nThe front of MyDeque: " << m.front() << endl;
    cout << "The back of MyDeque: " << m.back() << endl;
    cout << "Lets add 88 to the end using push_back()" << endl;
    m.push_back(88);
    cout << "The updated list: " << m;
    cout << "\nMyDeque size: " << m.size() << endl;

    int input;
    cout << "Enter a value to remove from MyDeque: ";
    cin >> input;

    m.remove(input);
    cout << "The updated list: " << m;
  
    return 0;
}
