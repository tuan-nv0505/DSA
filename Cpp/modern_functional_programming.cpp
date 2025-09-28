

#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* next;
};

// Khởi tạo head
Node* init(Node* head) {
    head = nullptr;
    return head;
}

// Tạo node mới
Node* createNode(int key) {
    Node* node = new Node; // cấp phát bộ nhớ động
    node->key = key;
    node->next = nullptr;
    return node;
}

Node* insertLast(Node* head, int key) {
    if (head == nullptr)
        head = createNode(key);
    else {
        Node* iterator = head;
        while (iterator->next != nullptr)
            iterator = iterator->next;
        iterator->next = createNode(key);
    }
    return head;
}

Node* insertFirst(Node* head, int key) {
    if (head == nullptr)
        head = createNode(key);
    else {
        Node* newNode = createNode(key);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* deleteLast(Node* head) {
    if (head == nullptr) // danh sách rỗng
        return head;
    else if (head->next == nullptr) { // chỉ có 1 node
        delete head; // giải phóng bộ nhớ
        head = nullptr;
    }
    else { // nhiều node
        Node* iterator = head;
        while (iterator->next->next != nullptr)
            iterator = iterator->next;
        delete iterator->next; // giải phóng node cuối
        iterator->next = nullptr;
    }
    return head;
}

Node* deleteFirst(Node* head) {
    if (head == nullptr)
        return head;
    else if (head->next == nullptr) {
        delete head; // giải phóng node duy nhất
        head = nullptr;
    }
    else {
        Node* tmp = head;
        head = head->next;
        delete tmp; // xóa vùng nhớ mà con trỏ tmp đang trỏ tới
        tmp = nullptr; // cho con trỏ tmp trỏ về null
    }
    return head;
}

Node* find(Node* head, int key) {
    while (head != nullptr) {
        if (head->key == key)
            return head;
        head = head->next;
    }
    return nullptr;
}


std::vector<Node*> findAll(Node* head, int key) {
    std::vector<Node*> results;
    while (head != nullptr) {
        if (head->key == key)
            results.push_back(head);
        head = head->next;
    }
    return results;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->key << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

// Giải phóng toàn bộ danh sách
void freeList(Node* &head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Node* head;
    head = init(head);

    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertFirst(head, 5);
    head = insertLast(head, 20);

    printList(head); // 5 -> 10 -> 20 -> 20 -> NULL

    Node* found = find(head, 20);
    if (found != nullptr) 
        std::cout << "Tim thay 20: " << found->key << "\n";
    else
        std::cout << "khong tim thay 20" << "\n";

    std::vector<Node*> results = findAll(head, 20);
    if (results.empty() == false)
        for (int i = 0; i < results.size(); i++)
            std::cout << results[i]->key << " ";
    std::cout << "\n";

    head = deleteFirst(head);
    head = deleteLast(head);
    printList(head); // 10 -> 20 -> NULL

    freeList(head); // giải phóng bộ nhớ
    return 0;
}

