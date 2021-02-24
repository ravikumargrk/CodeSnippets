#include <stdio.h>
#include "test.h"

typedef struct _node {
    int data;
    struct node *left;
    struct node *right;
}node;

node* newtreenode(int data){
    node* new = malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inOrder(node *root) {
    if(!root) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(node *root) {
    if(!root) return ;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);   
}

void preOrder(node *root) {
    if(!root) return ;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    testcase* test = readtest("tree.txt");
    
}