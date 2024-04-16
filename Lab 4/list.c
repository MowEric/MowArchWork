#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void panic(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

struct list *new() {
    struct list *p = (struct list *)malloc(sizeof(struct list));
    if (p == NULL) {
        panic("Yeah no thats a null value, buddy");
    }
    p->size = 0;
    p->head = NULL;
    p->tail = NULL;
    return p;
}

void destroy(struct list *l) {
    assert(l != NULL);
    free(l);
}

int size(struct list *l) {
    assert(l != NULL);
    int i;
    struct node *n = (struct node *)malloc(sizeof(struct node));
    for(i = 0; n->next != NULL; i++) {
        n = n->next;
    }
    free(n);
    return i+1;
}

void add_tail(struct list *l, long val) {
    assert(l != NULL);
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->val = val;
    l->tail->next = n;
    n->prev=l->tail;
    l->tail = n;
    l->size++;
}

long remove_at(struct list *l, int index) {
    assert(l != NULL && index >= 0 && index < l->size);
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n = l->head;
    
    for(int i = 0; i < index; i++) {
        n = n->next;
    }
    long a = n->val;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    l->size--;
    return a;
}

long get(struct list *l, int index) {
    assert(l != NULL && index >= 0 && index < l->size);
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n = l->head;
    for(int i = 0; i < index; i++) {
        n = n->next;
    }
    long a = n->val;
    free(n);
    return a;
}
