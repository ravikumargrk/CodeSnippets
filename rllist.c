#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

// Linked list functions with recursion

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep) {
    while (node) {
        printf("%d", node->data);

        node = node->next;

        if (node) {
            printf("%s", sep);
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

// exhaustive read from singly linked linked list
void printLinkedList(SinglyLinkedListNode* head, char seperator) {
    SinglyLinkedListNode* NodePtr = head;
    while(NodePtr){
        printf("%d%c",NodePtr->data,seperator);
        NodePtr = NodePtr->next;
    }
    if(seperator!='\n') printf("\n");
}

void reversePrint(SinglyLinkedListNode* head) {
    if(!head) return;
    reversePrint(head->next);
    printf("%d\t",head->data);
}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* NodePtr = head;
    SinglyLinkedListNode* NextNodePtr = NULL;
    SinglyLinkedListNode* PrevNodePtr = NULL;
    while(NodePtr){
        //Update next node pointer
        NextNodePtr = NodePtr->next;
        // overwrite
        NodePtr->next = PrevNodePtr;
        // update PrevNodePtr
        PrevNodePtr = NodePtr;
        // goto next node pointer
        NodePtr = NextNodePtr;
    }
    return PrevNodePtr;
}

void add_node_to_list(SinglyLinkedList** singly_linked_list, SinglyLinkedListNode* node){
    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }
    (*singly_linked_list)->tail = node;
    (*singly_linked_list)->tail->next = NULL;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // init
    SinglyLinkedListNode* Node;
    SinglyLinkedListNode* NodeExtra;
    // new list
    SinglyLinkedList* mergedlist = malloc(sizeof(SinglyLinkedList));
    mergedlist->head = NULL;
    mergedlist->tail = NULL;
    
    // traverse
    int current_data = 0, counter = 0;
    while(head1 && head2){
        // get the value to append to linked list
        if(head1->data < head2->data){
            Node = head1;
            head1 = head1->next;
        }else{
            Node = head2;
            head2 = head2->next;
        }
        // Append node to merged list : llist
        add_node_to_list(&mergedlist, Node);
    }
    if((!head1) &&(!head2)){
        return mergedlist->head;
    }else{
        if(head1){
            Node = head1;
        }else{
            Node = head2;
        }
        while(Node){
            NodeExtra = Node->next;
            add_node_to_list(&mergedlist, Node);
            Node = NodeExtra;
        }
    }
    return mergedlist->head;
}

int main(){
    testcase* input = readtest("input_x.txt");
    int cursor = 0;
    // t = input[0]
    int test_count = input->data[cursor++];
    int list1_size = 0, list2_size = 0;
    SinglyLinkedListNode* head;
    SinglyLinkedList* llist1 = malloc(sizeof(SinglyLinkedList)); 
    SinglyLinkedList* llist2 = malloc(sizeof(SinglyLinkedList)); 
    for (int i = 0; i < test_count; i++) {
        llist1->head = NULL; llist1->tail = NULL;
        llist2->head  = NULL; llist2->tail = NULL;
        // read list1
        list1_size = input->data[cursor++];
        for (int j = 0 ; j < list1_size; j++) {
            insert_node_into_singly_linked_list(&llist1,input->data[cursor++]);
        }
        // read list2
        list2_size = input->data[cursor++];
        for (int j = 0 ; j < list2_size; j++) {
            insert_node_into_singly_linked_list(&llist2,input->data[cursor++]);
        }
        head = mergeLists(llist1->head,llist2->head); // All nodes are here now
        reversePrint(head);
        free_singly_linked_list(head);
        // printLinkedList(llist1->head,'\t');
        // printLinkedList(llist2->head,'\t');
    }
    printf("\n");
    return 0;
}
