
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None


def insert_last(head, key):
    if head is None:
        return Node(key)
    else:
        iterator = head
        while iterator.next is not None:
            iterator = iterator.next
        iterator.next = Node(key)
        return head


def insert_first(head, key):
    if head is None:
        return Node(key)
    else:
        new_node = Node(key)
        new_node.next = head
        return new_node


def delete_last(head):
    if head is None:
        return None
    elif head.next is None:
        return None
    else:
        iterator = head
        while iterator.next.next is not None:
            iterator = iterator.next
        iterator.next = None
        return head


def delete_first(head):
    if head is None:
        return None
    elif head.next is None:
        return None
    else:
        return head.next


def find(head, key):
    while head is not None:
        if head.key == key:
            return head
        head = head.next
    return None


def find_all(head, key):
    results = []
    while head is not None:
        if head.key == key:
            results.append(head)
        head = head.next
    return results


def print_list(head):
    while head is not None:
        print(head.key, end=" -> ")
        head = head.next
    print("NULL")




if __name__ == "__main__":
    head = None  # không cần init()

    head = insert_last(head, 10)
    head = insert_last(head, 20)
    head = insert_first(head, 5)
    head = insert_last(head, 20)

    print_list(head)  # 5 -> 10 -> 20 -> 20 -> NULL

    found = find(head, 20)
    if found is not None:
        print("Tìm thấy 20:", found.key)
    else:
        print("Không tìm thấy 20")

    results = find_all(head, 20)
    if results:
        for node in results:
            print(node.key, end=" ")
    print()

    head = delete_first(head)
    head = delete_last(head)
    print_list(head)  # 10 -> 20 -> NULL

