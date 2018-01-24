#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.c"
#include "tree.c"

void create_tree(struct binary_tree* tree,struct node** head){
    struct node* temp=*head;
    while((*head)->next!=NULL){
        tree->root=in_order_insert_T("\'",head,*head);
        *head=tree->root->right->next;
        tree->root->left->next=NULL;
        tree->root->right->next=NULL;
    }
}
void read_file(char* file_name,struct node** list,struct node** list2){
    FILE *fp;
    char *ch;
    ch=(char*)malloc(sizeof(char));

    fp=fopen(file_name,"r");

    while( ( *ch =fgetc(fp) ) != EOF ){
        append(ch,list);
        append(ch,list2);

    }

    fclose(fp);
}

void write_file(char* file_name,struct node* file,struct binary_tree* tree){
    FILE *fp;

    fp = fopen(file_name, "w+");

    while(file!=NULL){
        find_leaf(tree->root,file->key);
        fprintf(fp,key2);
        file=file->next;
    }
    fprintf(fp,".");
    write_tree(tree->root,fp);
    fclose(fp);
}

void encode(char* input_file,char* output_file){
    struct node* file=NULL;
    struct node* file2=NULL;
    struct node* freq=NULL;
    struct binary_tree* tree;
    key2=(char*)malloc(20*sizeof(char));
    read_file("deneme.txt",&file,&file2);
    distinct(file,&freq);
    destroy_list(&file);
    tree_init(&tree);
    create_tree(tree,&freq);
    leaf_path(tree->root,-1,"\0");
    write_file("encoded.dat",file2,tree);
    destroy_list(&file2);
}


int main(){
    encode("deneme.txt","encoded.dat");
    return 0;
}
