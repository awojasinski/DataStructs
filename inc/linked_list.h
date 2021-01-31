#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define ll_foreach(list, item) \
        for(Node_t item=list->begin; item; item=item->next)

typedef struct Node_t {
    int data;
    struct Node_t *next;
}Node_t;

typedef struct ll_t {
    Node_t *begin;
    Node_t *end;
    size_t size;
}ll_t;

extern ll_t* createLL();
size_t sizeLL(ll_t *list);

void push_front(ll_t *list, int data);
void push_back(ll_t *list, int data);
void insert_node(ll_t *list, int data, size_t n);

Node_t *pop_front(ll_t *list);
Node_t *pop_back(ll_t *list);

Node_t *front(ll_t *list);
Node_t *back(ll_t *list);

Node_t *get(ll_t *list, size_t n);

void destroy_list(ll_t *list);

#endif