#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert(struct Node** head_ref, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else {
        struct Node* last = (*head_ref)->prev;
        new_node->next = *head_ref;
        new_node->prev = last;
        last->next = (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

struct Node* merge(struct Node* first, struct Node* second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

struct Node* mergeUtil(struct Node* head1, struct Node* head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    struct Node* last_node;
    if (head1->prev->data < head2->prev->data)
        last_node = head2->prev;
    else
        last_node = head1->prev;

    head1->prev->next = head2->prev->next = NULL;

    struct Node* finalHead = merge(head1, head2);

    finalHead->prev = last_node;
    last_node->next = finalHead;

    return finalHead;
}

void printList(struct Node* head)
{
    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insert(&head1, 8);
    insert(&head1, 5);
    insert(&head1, 3);
    insert(&head1, 1);

    insert(&head2, 11);
    insert(&head2, 9);
    insert(&head2, 7);
    insert(&head2, 2);

    struct Node* newHead = mergeUtil(head1, head2);

    printf("Final Sorted List: ");
    printList(newHead);

    return 0;
}
