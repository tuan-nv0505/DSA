
#include <iostream>
#include <vector>

struct Node {
    int key;
    Node* next;
};

// Khởi tạo head
void init(Node* &head) {
    head = nullptr;
}

// Tạo node mới
Node* createNode(int key) {
    Node* node = new Node; // cấp phát bộ nhớ động
    node->key = key;
    node->next = nullptr;
    return node;
}

/*
Tại sao trong này lại truyền & vì ở đây là kiểu lập trình hàm nên ta truyền head vô hàm bởi vì
khi ta truyền con trỏ head vô hàm thì nó sẽ tạo bản sao cùng trỏ đến vùng nhớ của head đang trỏ tới,
mà trong hàm ta lại có đoạn thay đổi địa chỉ trỏ đến của head, ví dụ head = createNode(key),
nghĩa là head sẽ phải trỏ đến Node mới.
Không giống như OOP, ta có biến head là local trong class, ta có thể lấy ra sài trực tiếp mà không cần truyền vô phương thức.
*/
void insertLast(Node* &head, int key) {
    if (head == nullptr)
        head = createNode(key);
    else {
        Node* iterator = head;
        while (iterator->next != nullptr)
            iterator = iterator->next;
        iterator->next = createNode(key);
    }
}

void insertFirst(Node* &head, int key) {
    if (head == nullptr)
        head = createNode(key);
    else {
        Node* newNode = createNode(key);
        newNode->next = head;
        head = newNode;
    }
}

void deleteLast(Node* &head) {
    if (head == nullptr) // danh sách rỗng
        return;
    else if (head->next == nullptr) { // chỉ có 1 node
        delete head; // giải phóng bộ nhớ
        head = nullptr;
        return;
    }
    else { // nhiều node
        Node* iterator = head;
        while (iterator->next->next != nullptr)
            iterator = iterator->next;
        delete iterator->next; // giải phóng node cuối
        iterator->next = nullptr;
    }
}

void deleteFirst(Node* &head) {
    if (head == nullptr)
        return;
    else if (head->next == nullptr) {
        delete head; // giải phóng node duy nhất
        head = nullptr;
        return;
    }
    else {
        Node* tmp = head;
        head = head->next;
        delete tmp; // xóa vùng nhớ mà con trỏ tmp đang trỏ tới
        tmp = nullptr; // cho con trỏ tmp trỏ về null
    }
}

// trong này không cần truyền & vì chẳng cần thay đổi địa chỉ nó trỏ đến của con trỏ head
Node* find(Node* head, int key) {
    while (head != nullptr) {
        if (head->key == key)
            return head;
        head = head->next; // đoạn này thay đổi head là bản sao, không ảnh hưởng head ngoài hàm
    }
    return nullptr;
}

// Tìm tất cả node có key trùng
std::vector<Node*> findAll(Node* head, int key) {
    std::vector<Node*> results;
    while (head != nullptr) {
        if (head->key == key)
            results.push_back(head);
        head = head->next;
    }
    return results;
}

// In danh sách tương tụ không cần truyền & vì mục tiêu chỉ xuất không cần thay đổi head;
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
    init(head);

    insertLast(head, 10);
    insertLast(head, 20);
    insertFirst(head, 5);
    insertLast(head, 20);

    printList(head); // 5 -> 10 -> 20 -> 20 -> NULL

    Node* found = find(head, 20);
    if (found) 
        std::cout << "Tim thay 20: " << found->key << "\n";
    else
        std::cout << "khong tim thay 20" << "\n";

    std::vector<Node*> results = findAll(head, 20);
    if (results.empty() == false)
        for (int i = 0; i < results.size(); i++)
            std::cout << results[i]->key << " ";
    std::cout << "\n";

    deleteFirst(head);
    deleteLast(head);
    printList(head); // 10 -> 20 -> NULL

    freeList(head); // giải phóng bộ nhớ
    return 0;
}
