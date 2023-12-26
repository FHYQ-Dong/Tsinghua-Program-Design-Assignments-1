#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct node *next;
} Node;
typedef struct List {
    Node *head, *tail;
    int size;
} List;

List create_List() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    return list;
}

void insert(List *list, int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } 
    else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void delete(List* list, Node* node_pre) {
    if (node_pre == NULL) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    } 
    else {
        Node *temp = node_pre->next;
        node_pre->next = node_pre->next->next;
        free(temp);
    }
    list->size--;
}

Node* get_min(List *list) {
    Node *node = list->head;
    Node *min = node, *prev = NULL, *min_prev = NULL;
    while (node != NULL) {
        if (node->value < min->value) {
            min = node;
            min_prev = prev;
        }
        node = node->next;
        prev = node;
    }
    return min_prev;
}

int main() {
    List list = create_List();
    insert(&list, 1); insert(&list, 2); insert(&list, 3); insert(&list, 4); insert(&list, 5);
    while (list.size > 0) {
        Node *min_prev = get_min(&list);
        if (min_prev == NULL) printf("%d ", list.head->value);
        else printf("%d ", min_prev->next->value);
        delete(&list, min_prev);
    }
    return 0;
}