#include <stdio.h>
#include <stdlib.h>
typedef struct node{    
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(){
    int data,choice;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\n0. Exit\n1. Insert Nodes\nEnter your choice : ");
    scanf("%d",&choice);
    if(choice == 0){
        return 0;
    }
    else {
        printf("\nEnter data : ");
        scanf("%d",&data);
        temp->data = data;
        printf("\nEnter left child of %d\n",temp->data);
        temp->left = create();
        printf("\nEnter right child of %d\n",temp->data);
        temp->right = create();
        return temp;
    }
}
void inOrder(struct node* r){
    if(r!=NULL){
        inOrder(r->left);
        printf("%d ",r->data);
        inOrder(r->right);
    }
};
void preOrder(struct node* r){
    if(r!=NULL){
        printf("%d ",r->data);
        preOrder(r->left);
        preOrder(r->right);
    }
};
void postOrder(struct node* r){
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%d ",r->data);
    }
};
int main()
{
    struct node* root;
    root = create();
    int option;
    while(1){
        printf("\n1. Pre-Order Traversal\n2. In-Order Traversal\n3. Post-Order Traversal\n->");
        scanf("%d",&option);
        switch(option){
            case 1:
                preOrder(root);
                break;
            case 2:
                inOrder(root);
                break;
            case 3:
                postOrder(root);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
