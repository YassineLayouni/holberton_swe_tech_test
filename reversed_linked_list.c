#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int value;
    struct ListNode *next;
};

// create a new node
struct ListNode* createNewNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// deallocate memory of the linked list
void deleteList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}


// reverse a linked list between positions left and right
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }

    struct ListNode newHead;
    newHead.next = head;
    struct ListNode* previous = &newHead;

    // Move previous to the node before the left position
    for (int i = 1; i < left; i++) {
        previous = previous->next;
    }

    // start is the first node of the sublist to be reversed
    struct ListNode* start = previous->next;
    struct ListNode* after = start->next;

    // Reverse the nodes between left and right
    for (int i = 0; i < right - left; i++) {
        start->next = after->next;
        after->next = previous->next;
        previous->next = after;
        after = start->next;
    }

    return newHead.next;
}


int main() {
    // create a linked list
    struct ListNode* head = createNewNode(1);
    head->next = createNewNode(2);
    head->next->next = createNewNode(3);
    head->next->next->next = createNewNode(4);
    head->next->next->next->next = createNewNode(5);

    printf("Original Linked List:\n");
    printList(head);

    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    printf("Updated Linked List after reversing from position %d to %d:\n", left, right);
    printList(head);

    deleteList(head);

    return 0;
}
