#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node{
    int count;
    char* key;
    char* bits;
    struct node* next;
    struct node* left;
    struct node* right;
};

struct node *create_node(char* key){
    struct node* new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL) exit(1);
    else{
        new_node->key=(char*)malloc(sizeof(char));
        new_node->bits=(char*)malloc(20*sizeof(char));
        new_node->count=1;
        strcpy(new_node->key,key);
        strcpy(new_node->bits,"\0");
        new_node->next=new_node->left=new_node->right=NULL;
        return new_node;
    }
}

struct node* push(char* key,struct node** head){
    struct node* new_node=create_node(key);
    new_node->next=*head;
    *head=new_node;
    return new_node;
}

struct node* append(char* key,struct node** head){
    struct node* new_node=create_node(key);
    if(*head==NULL){
        new_node->next=*head;
        *head=new_node;
    }
    else{
        struct node* temp=*head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new_node;
    }
    return new_node;
}

struct node* in_order_insert(char* key,int count,struct node **head){
    struct node *a, *b, *new;
    b=*head;
    while(b!=NULL && b->count <= count){
        a = b;
        b= b->next;
    }
    new=create_node(key);
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


void print_list(struct node* head){
    if(head==NULL) printf("empty list!\n");
    else{
        while(head!=NULL){
            printf("%s - %d\n",head->key,head->count);
           head=head->next;
        }
        printf("\n");
    }
}

void print_list_n(struct node* head){
    if(head==NULL) printf("empty list!\n");
    else{
        while(head!=NULL){
            printf("%s",head->key);
            head=head->next;
        }
        printf("\n");
    }
}

int inList(char* key,struct node* head){
    int in_list=0;
    while(head!=NULL){
        if(strcmp(head->key,key)==0){
            in_list=1;
            break;
        }
        head=head->next;
    }
    return in_list;
}
void distinct(struct node* file,struct node** freq){
    if(file==NULL) printf("empty list!\n");
    else{
        int counter;
        struct node* temp;
        while(file->next!=NULL){
            if(!inList(file->key,*freq)){
                counter=count(file->key,file);
                temp=in_order_insert(file->key,counter,freq);
                temp->count=counter;
            }
            file=file->next;
        }
    }
}
 int count(char* key,struct node* file){
    int count=0;
    while(file!=NULL){
        if(strcmp(file->key,key)==0){
            count++;
        }
        file=file->next;
    }
    return count;
}

void destroy_list(struct node **head){
    struct node *current;
    while(*head!=NULL){
        current=(*head);
        *head=(*head)->next;
        free(current);
    }
}


void sort_list(struct node **head){
    struct node *a,*b,*c,*d;
    
    if(*head == NULL || (*head)->next==NULL) return;
    
    d=(*head)->next;
    (*head)->next=NULL;
    
    while(d!=NULL){
        c=d;
        d=d->next;
        b=*head;
        while(b!=NULL && b->count < c->count){
            a=b;
            b=b->next;
        }
        if(b==*head){
            c->next=*head;
            *head=c;
        }
        else {
            a->next = c;
            c->next = b;
        }
        }
    }