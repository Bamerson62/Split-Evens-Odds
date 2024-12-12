#include <iostream>
#include "unorderedLinkList.h"

using namespace std;

class intLinkedList: public unorderedLinkedList<int> {
public:
void splitEvensOddsList(intLinkedList &evensList,
intLinkedList &oddsList);

};

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    nodeType<int>* current = first;
    while (current != nullptr) {
        if (current->info % 2 == 0) {
            // Even number, add to evensList
            evensList.insertLast(current->info);
        } else {
            // Odd number, add to oddsList
            oddsList.insertLast(current->info);
        }
        current = current->link;
    }
    // Clear the original list
    destroyList();
}

int main() {
  intLinkedList originalList;
  intLinkedList evensList;
  intLinkedList oddsList;

  int num;
  cout << "Enter integers ending with -999" << endl;
  cin >> num;

  while (num != -999) {
      originalList.insertLast(num);
      cin >> num;
  }

  cout << "list: ";
  originalList.print();
  cout << endl;

  originalList.splitEvensOddsList(evensList, oddsList);

  cout << "evensList: ";
      evensList.print();
      cout << endl;

      cout << "oddsList: ";
      oddsList.print();
      cout << endl;

      return 0;
  }

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    nodeType<int>* current = first; // Initialize a pointer to the first node of the original list

    // Traverse the original list
    while (current != nullptr) {
        if (current->info % 2 == 0) {
            // If the current node contains an even number, add it to the evensList
            evensList.insertLast(current->info);
        } else {
            // If the current node contains an odd number, add it to the oddsList
            oddsList.insertLast(current->info);
        }
        current = current->link; // Move to the next node in the original list
    }

    // Clear the original list by destroying its nodes
    destroyList();
}