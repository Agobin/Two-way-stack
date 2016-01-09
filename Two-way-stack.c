#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
        int value;
        struct node *next;
    };
bool isempty(struct node *);
void sort( struct node *first);
 struct node *add_node( struct node *first,int n);
 bool ispresent(struct node *first, int n);
 struct node *Delete( struct node *first,int n);
 void print( struct node *first);
 void reverse(struct node *);
 void instruction(void){
    printf("\nEnter a to add elements in the stack.\n");
    printf("Enter d to delete elements from the stack.\n");
    printf("Enter i to see instructions.\n");
    printf("Enter p to print sorted stack.\n");
    printf("Enter r to print stack in reverse ( behaves like a queue ).\n");
    printf("Enter c to clear the screen.\n");
    printf("Enter q to quit.\n");
 }
    struct node *first=NULL;
    struct node *lastnode=NULL;
    int inlist=0;
int main(){

    int i,n;
    char c;
    int del;
    instruction();
 for( ; ; ){
    printf("\nEnter mode:");
    c=getch();
    //scanf("%c",&c); fflush(stdin);
    switch (c){
    case 'i':
        instruction();
        break;
    case 'q':
        exit(0);
    case 'a':
        printf("\nEnter value to add: ");
        scanf("%d",&n);
        inlist++;
        first=add_node( first,n);
        sort(first);
        break;
    case 'c':
        system("cls");
        break;
    case 'd':
        printf("\nEnter the element of list to delete: ");
        scanf("%d",&del);
        first =Delete(first,del);
        break;
    case 'r':
        print(first);
        break;
    case 'p':
        reverse(first);
        break;
    }
}

    getchar();
    return 0;

}
struct node *Delete( struct node *first,int n){
    struct node *cur,*prev;
    bool found;
    char *status = malloc( sizeof( char ));
    if(!isempty(first)){
            if( !ispresent( first,n) ){
                printf("\nElement %d not found!\n\n",n);
                    return first;
            }
            else
                    inlist--;
            if ( first->value == n ){
                    cur=first;
                    first=first->next;
                    free(cur);
                    found=true;
                    printf("\nFound in first node. Deleted successfuly!\n\n");
                    return first;
             }
            else{
                for( cur = first,prev=NULL;cur !=NULL,cur->value !=n; prev=cur,cur=cur->next);
                if( cur != NULL && cur->value == n){
                    prev->next=cur->next;
                    printf("Deleted successfuly!\n\n");
                    free(cur);
                    found = true;
                    return first;
                }
            }
    }
    else
            printf("\n\nList is empty!\n\n");
}
struct node *add_node( struct node *first,int n){
    struct node * new_node,*cur,*prev=NULL;
    new_node=malloc( sizeof( struct node));
    if(new_node==NULL){
        printf("Memory full!\n");
        return;
    }
    new_node->value=n;
    new_node->next=first;
    first=new_node;

    return first;
}
void print( struct node *first){
    printf("\n\n\t\tBehaves like a QUEUE.\n\n\t");
    for(;first !=NULL;first=first->next ){
        printf("  %d ->",first->value);
    }
    printf("  NULL");
    printf("\n\n");
}
void reverse(struct node *first){
    int invalue[inlist];
    int i;
    for(i=0;first !=NULL;first=first->next ,  i++ ){
         invalue[i]=first->value ;
    }
    printf("\n\n\t\tSTACK.\n\n\t");
    for(i=inlist-1;i>=1;i--)
           printf("  %d ->",invalue[i]);
    printf("  %d ->  NULL\n\n",invalue[0]);
}
void sort( struct node *first){
    struct node *cur,*prev=NULL,*new_node;
    new_node=malloc( sizeof( struct node));
        for( cur=first->next,prev=first ; cur !=NULL;prev=cur,cur=cur->next){
            if(prev->value > cur->value){
                    new_node->value=prev->value;
                    prev->value=cur->value;
                    cur->value=new_node->value;
            }
        }
        //printf("\nList has being sorted!");
}
bool isempty(struct node *first){
    return first == NULL;
}
bool ispresent( struct node *first, int n){
    struct node *cur,*prev;
    for( cur = first,prev=NULL;cur !=NULL; prev=cur,cur=cur->next){
         if( cur->value ==n)
                    return true;
    }
    return false;
}
