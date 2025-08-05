#include <iostream>
using namespace std;

// Singly Linked List 

struct SNode {
    int data;
    SNode* next;
};

// Insertions
void insertSLLBegin(SNode*& head, int data) {
    head = new SNode{data, head};
}

void insertSLLEnd(SNode*& head, int data) {
    SNode* newNode = new SNode{data, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    SNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertSLLAtPos(SNode*& head, int data, int pos) {
    if (pos == 1) {
        insertSLLBegin(head, data);
        return;
    }
    SNode* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) return;
    SNode* newNode = new SNode{data, temp->next};
    temp->next = newNode;
}

// Deletions
void deleteSLLBegin(SNode*& head) {
    if (!head) return;
    SNode* temp = head;
    head = head->next;
    delete temp;
}

void deleteSLLEnd(SNode*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    SNode* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteSLLAtPos(SNode*& head, int pos) {
    if (pos == 1) {
        deleteSLLBegin(head);
        return;
    }
    SNode* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp || !temp->next) return;
    SNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void printSLL(SNode* head) {
    cout << "SLL: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Doubly Linked List

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Insertions
void insertDLLBegin(DNode*& head, int data) {
    DNode* newNode = new DNode{data, nullptr, head};
    if (head) head->prev = newNode;
    head = newNode;
}

void insertDLLEnd(DNode*& head, int data) {
    DNode* newNode = new DNode{data, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertDLLAtPos(DNode*& head, int data, int pos) {
    if (pos == 1) {
        insertDLLBegin(head, data);
        return;
    }
    DNode* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
    if (!temp) return;
    DNode* newNode = new DNode{data, temp, temp->next};
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

// Deletions
void deleteDLLBegin(DNode*& head) {
    if (!head) return;
    DNode* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void deleteDLLEnd(DNode*& head) {
    if (!head) return;
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = nullptr;
    else head = nullptr;
    delete temp;
}

void deleteDLLAtPos(DNode*& head, int pos) {
    if (pos == 1) {
        deleteDLLBegin(head);
        return;
    }
    DNode* temp = head;
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void printDLL(DNode* head) {
    cout << "DLL: ";
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

//  Circular Linked List 

struct CNode {
    int data;
    CNode* next;
};

// Insertions
void insertCLLBegin(CNode*& head, int data) {
    CNode* newNode = new CNode{data, nullptr};
    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertCLLEnd(CNode*& head, int data) {
    if (!head) {
        insertCLLBegin(head, data);
        return;
    }
    CNode* newNode = new CNode{data, head};
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
}

void insertCLLAtPos(CNode*& head, int data, int pos) {
    if (pos == 1) {
        insertCLLBegin(head, data);
        return;
    }
    CNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) temp = temp->next;
    CNode* newNode = new CNode{data, temp->next};
    temp->next = newNode;
}

// Deletions
void deleteCLLBegin(CNode*& head) {
    if (!head) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    CNode* temp = head;
    while (temp->next != head) temp = temp->next;
    CNode* toDelete = head;
    head = head->next;
    temp->next = head;
    delete toDelete;
}

void deleteCLLEnd(CNode*& head) {
    if (!head) return;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    CNode* temp = head;
    while (temp->next->next != head) temp = temp->next;
    delete temp->next;
    temp->next = head;
}

void deleteCLLAtPos(CNode*& head, int pos) {
    if (pos == 1) {
        deleteCLLBegin(head);
        return;
    }
    CNode* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) temp = temp->next;
    if (temp->next == head) return;
    CNode* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void printCLL(CNode* head) {
    if (!head) {
        cout << "CLL: Empty\n";
        return;
    }
    cout << "CLL: ";
    CNode* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}


int main() {
  
    // Singly Linked List
  
    SNode* sll = nullptr;
    insertSLLBegin(sll, 10);
    insertSLLEnd(sll, 30);
    insertSLLAtPos(sll, 20, 2);
    printSLL(sll);
    deleteSLLBegin(sll);
    deleteSLLEnd(sll);
    deleteSLLAtPos(sll, 1);
    printSLL(sll);

    // Doubly Linked List
    DNode* dll = nullptr;
    insertDLLBegin(dll, 10);
    insertDLLEnd(dll, 30);
    insertDLLAtPos(dll, 20, 2);
    printDLL(dll);
    deleteDLLBegin(dll);
    deleteDLLEnd(dll);
    deleteDLLAtPos(dll, 1);
    printDLL(dll);

    // Circular Linked List
    CNode* cll = nullptr;
    insertCLLBegin(cll, 10);
    insertCLLEnd(cll, 30);
    insertCLLAtPos(cll, 20, 2);
    printCLL(cll);
    deleteCLLBegin(cll);
    deleteCLLEnd(cll);
    deleteCLLAtPos(cll, 1);
    printCLL(cll);

    return 0;
}
