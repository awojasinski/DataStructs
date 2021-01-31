#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

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

inline ll_t* createLL() {
    ll_t *list = (ll_t*)malloc(sizeof(ll_t));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}

size_t sizeLL(ll_t *list);

void push_front(ll_t *list, int data);
void push_back(ll_t *list, int data);
void insert_node(ll_t *list, int data, size_t n);

void pop_front(ll_t *list);
void pop_back(ll_t *list);

Node_t *front(ll_t *list);
Node_t *back(ll_t *list);

Node_t *get(ll_t *list, size_t n);

void destroy_list(ll_t *list);
void destroy_node(ll_t *list, size_t n);

#endif