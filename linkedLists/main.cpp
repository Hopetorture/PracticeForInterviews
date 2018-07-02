#include <iostream>
#include <typeinfo>
#include <unordered_set>
using namespace std;

struct Node{
    Node* next;
    int data;
};

// check if linked list have cycles
bool has_cycle(Node* head) {

    if (head == nullptr) return false;
    if (head->next == nullptr) return false;

    std::unordered_set<Node*> set;
    Node* nextNode = head;
    while(nextNode != nullptr){
        auto isInSet = set.find(nextNode);
        if (isInSet != set.end())
            return true;
        else{
            set.insert(nextNode);
            nextNode = nextNode->next;
        }
    }
    return  false;

}

//iterative reversion of linked list in O(N) time and const memory
Node* reverseIterative(Node* head){
    if (head == nullptr)
        return  nullptr;
    if (head->next == nullptr){
        return head;
    }
    Node* nxt = head->next;
    Node* prev = head;
    prev->next = nullptr;

    while (nxt->next != nullptr){
        Node* nplus1 = nxt->next;
        nxt->next = prev;
        prev = nxt;
        nxt = nplus1;
    }

    nxt->next = prev;
    return nxt;

}

void printList(Node* head){
    Node* iter = head;
    while(iter != nullptr){
        std::cout << iter->data << std::endl;
        iter = iter->next;
    }
}

int main()
{
    Node* head = new Node{};
    Node* node1 = new Node{};
    Node* node2 = new Node{};
    Node* node3 = new Node{};
    Node* node4 = new Node{};
    Node* node5 = new Node{};
    head->data = 1;
    head->next = node1;

    node1->data = 2;
    node1->next = node2;
    node2->data = 3;
    node2->next = node3;

    node3->data = 4;
    node3->next = node4;
    node4->data = 5;
    node4->next = node5;
    node5->data = 6;
    node5->next = nullptr;
    std::cout << "-----Original-----" << std::endl;
    printList(head);
    std::cout << "-----Modified-----" << std::endl;
    Node* newHead = reverseIterative(head);
    printList(newHead);


    return 0;
}
