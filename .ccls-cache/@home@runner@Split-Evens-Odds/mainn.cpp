#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H

#include "unorderedLinkedList.h"

class intLinkedList : public unorderedLinkedList<int> {
public:
    // Function to split the original list into evens and odds lists
    void splitEvensOddsList(intLinkedList &evensList, intLinkedList &oddsList);
};

#endif

#include "linkedList.h"

void intLinkedList::splitEvensOddsList(intLinkedList &evensList, intLinkedList &oddsList) {
    // Create a pointer to traverse the original list
    nodeType<int> *current = this->first;
    nodeType<int> *temp;

    // Traverse the original list
    while (current != nullptr) {
        // Save the current node in temp
        temp = current;

        // Move the current pointer to the next node
        current = current->link;

        // Detach the node from the original list
        temp->link = nullptr;

        // Check if the node's data is even or odd and move it to the corresponding list
        if (temp->info % 2 == 0) {
            // Append to evensList
            evensList.insertLast(temp->info);
        } else {
            // Append to oddsList
            oddsList.insertLast(temp->info);
        }
    }

    // Now the original list is empty
    this->first = nullptr;
    this->last = nullptr;
}

#include <iostream>
#include "linkedList.h"

using namespace std;

int main() {
    intLinkedList list;
    intLinkedList evensList, oddsList;

    // Insert integers into the list
    list.insertLast(10);
    list.insertLast(15);
    list.insertLast(20);
    list.insertLast(25);
    list.insertLast(30);
    list.insertLast(35);

    // Split the list into even and odd lists
    list.splitEvensOddsList(evensList, oddsList);

    // Display the evensList using iterator
    cout << "Even numbers: ";
    for (auto it = evensList.begin(); it != evensList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Display the oddsList using iterator
    cout << "Odd numbers: ";
    for (auto it = oddsList.begin(); it != oddsList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

template <class T>
class unorderedlinkedList {
protected:
    nodeType<T> *first;
    nodeType<T> *last;

public:
    // Iterator class to traverse the list
    class iterator {
    private:
        nodeType<T> *current;
    public:
        iterator(nodeType<T> *start = nullptr) : current(start) {}

        T& operator*() {
            return current->info;
        }

        iterator& operator++() {
            if (current != nullptr)
                current = current->link;
            return *this;
        }

        bool operator!=(const iterator& other) {
            return current != other.current;
        }
    };

    // Begin and end functions
    iterator begin() {
        return iterator(first);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

