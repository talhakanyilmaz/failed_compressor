#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* key2;

struct binary_tree{
    struct node* root;
};

void tree_init(struct binary_tree** tree){
    *tree=(struct binary_tree*)malloc(sizeof(struct binary_tree));
    if(*tree==NULL) exit(1);
    (*tree)->root=NULL;
}

struct node *create_node_T(char* key,struct node* node){
    struct node* new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL) exit(1);
    else{
        new_node->key=(char*)malloc(sizeof(char));
        new_node->count=node->count+node->next->count;
        strcpy(new_node->key,key);
        new_node->next=NULL;
        new_node->left=node;
        new_node->right=node->next;
        return new_node;
    }
}

int leaf_path(struct node* node,int dir,char* prebits){
    if(node==NULL) return 1;
    else{
        strcat(node->bits,prebits);
        if(dir==0){
            strcat(node->bits,"0");
        }
        else if(dir==1){
            strcat(node->bits,"1");
        }
        else{
            strcat(node->bits,"\0");
        }
        leaf_path(node->left,0,node->bits);
        leaf_path(node->right,1,node->bits);
    }
}

struct node* in_order_insert_T(char* key,struct node **head,struct node* temp){
    struct node *a, *b, *new;
    b=*head;
    int count=temp->count+temp->next->count;
    while(b!=NULL && b->count <= count){
        a = b;
        b= b->next;
    }
    new=create_node_T(key,temp);
    if(b==*head){
        new->next=*head;
        *head=new;
    }
    else {
        a->next=new;
        new->next=b;
    }

    return new;
 }

void find_leaf(struct node* root,char* key){
    if(root==NULL) return;
    if(strcmp(root->key,key)==0) strcpy(key2,root->bits);// return root->bits;
    find_leaf(root->left,key);
    find_leaf(root->right,key);
 }

 void write_tree(struct node* root,FILE *fp){
     if(root==NULL) return;
     if(strcmp(root->key,"\'")!=0){
         strcpy(key2,root->key);
         strcat(key2,":");
         strcat(key2,root->bits);
         strcat(key2,";");
         fprintf(fp,key2);
     }
     write_tree(root->left,fp);
     write_tree(root->right,fp);
 }
