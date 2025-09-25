# DequeLinkedList

Custom MyDeque Class (Linked List Implementation)


## 📖 Problem Description

This project implements a simplified version of a double-ended queue (deque) using a singly linked list. The class MyDeque supports insertion at both ends, removal of elements, access to front and back elements, size tracking, and printing.

This assignment reinforces concepts such as:

Dynamic memory management with linked lists

Front and back insertion operations

Element removal and traversal

Encapsulation and operator overloading

## 📂 Files

main.cpp – Contains the MyDeque class definition, implementation, and test program

## 🛠️ Implemented Features
### Core Operations

void push_back(int v) – Inserts a new node at the back of the deque

void push_front(int v) – Inserts a new node at the front of the deque

int front() const – Returns the first element (or -1 if empty)

int back() const – Returns the last element (or -1 if empty)

void remove(int v) – Removes the first occurrence of the value v

int size() const – Returns the total number of elements in the deque

void clear() – Deletes all nodes and resets the deque

## Operator Overloading

friend ostream& operator<<(ostream&, const MyDeque&) – Outputs deque contents in [a,b,c,...] format

## 🧪 Example Tests

Demonstrated in main.cpp:

Inserting random integers at the front using push_front()

Displaying the deque with <<

Accessing the first and last elements with front() and back()

Inserting elements at the back with push_back()

Removing user-specified elements with remove()

Displaying updated contents and size

## 📸 Sample Output

<img width="394" height="167" alt="image" src="https://github.com/user-attachments/assets/60e3357a-4b14-436c-8cbf-2f5cd78fc611" />
## 💡 Key Learnings

Practiced linked list manipulation (insertion, traversal, deletion).

Reinforced dynamic memory handling and cleanup with destructors.

Learned how to implement custom container-like behavior.

Applied operator overloading for clean and intuitive output formatting.
