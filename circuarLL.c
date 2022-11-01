//Program to create a node and assign value in it, and then repeat the process to make a linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *create(){
    struct node *head, *last, *temp;
    head = last = NULL;
    char ch;
    do
    {
        temp = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->link = head;

        if(head == NULL)
            head = temp;
        else    
            last -> link = temp;
        last = temp;

        printf("Do you want to continue (Y/N) ");
        fflush(stdin);
        scanf("%c", &ch);
    }
    while(ch == 'Y' || ch == 'y');
    return head;
}

void display(struct node *head){
    struct node *temp = head;
    while(temp -> link != head){
        printf("%d -> ", temp->data);
        temp = temp -> link;
    }
    printf("%d -> ", temp -> data);
    printf("NULL");
}
int main(){
    struct node *head;
    head = create();
    display(head);
    return 0;
}