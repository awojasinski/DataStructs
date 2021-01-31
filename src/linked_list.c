#include <stdlib.h>

#include "linked_list.h"


static inline ll_t* createLL() {
    ll_t *list = (ll_t*)malloc(sizeof(ll_t));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;

    return list;
}


size_t sizeLL(ll_t *list) {
    return list->size;
}


static inline Node_t* createNode() {
    Node_t *node = (Node_t*)malloc(sizeof(Node_t));
    node->next = NULL;

    return node;
}


void push_front(ll_t *list, int data) {
    Node_t *node = createNode();
    node->data = data;

    if (node) {
        node->next = list->begin;
        list->begin = node;
        list->size++;
    }
}


void push_back(ll_t *list, int data) {
    Node_t *node = createNode();
    node->data = data;

    if (node) {
        list->end = node;
        list->size++;
    }
}


void insert_node(ll_t *list, int data, size_t n) {
    if (list->size-1 < n ) return;

    Node_t *node = createNode();
    node->data = data;
    Node_t *temp = list->begin;

    if (node) {
        for (size_t i=0; i<n; ++i) {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        list->size++;
    }
}


void pop_front(ll_t *list) {
    if (list->begin) {
        Node_t *temp = list->begin;
        list->begin = temp->next;
        free(temp);
        list->size--;
    }
}


void pop_back(ll_t *list) {
    if (list->end && list->end != list->begin) {
        list->size--;
    }
    if (list->end == list->begin) {
        free(list->begin);
        list->end = NULL;
    }
    else {
        Node_t *temp = list->begin;
        for (size_t i=0; i<list->size-1; ++i) {
            temp=temp->next;
        }
        list->end=temp;
        list->size--;
        free(temp->next);
    }
}


Node_t *front(ll_t *list) {
    return list->begin;
}


Node_t *back(ll_t *list) {
    return list->end;
}


Node_t *get(ll_t *list, size_t n) {
    if (list->size-1 < n) return NULL;
    
    Node_t *temp = list->begin;

    for (size_t i=0; i<n; ++i) {
        temp = temp->next;
    }
    return temp;
}


static inline void destroy_node_rec(Node_t *node) {
    if (node->next) destroy_node_rec(node->next);
    free(node);
}


void destroy_list(ll_t *list) {
    if (list->size > 0) {
        list->end = NULL;
        destroy_node_rec(list->begin);
    }

    free(list);
}

void destroy_node(ll_t *list, size_t n) {
    if (list->size-1 < n) return;

    Node_t *temp = list->begin;
    Node_t *destroy;

    for (size_t i=0; i<n-1; ++i) {
        temp=temp->next;
    }
    destroy = temp->next;
    temp->next = temp->next->next;

    free(destroy);
    list->size--; 
}

