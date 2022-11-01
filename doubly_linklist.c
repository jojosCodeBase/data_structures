// program to delete node from any given position
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *link;
}linklist;
linklist *head = NULL, *current, *last;

void create(){
    current = malloc(sizeof(linklist));
    printf("Enter data: ");
    scanf("%d", &current -> data);
    current -> link = NULL;
    current -> prev = NULL;
    // for next node
    if(head == NULL)
        head = current;
    else
    {
        last -> link = current;
        current -> prev = last;
    }
    last = current;
}

void insert(){
    int pos, count = 2;
    // create node to be inserted
    linklist *newNode = malloc(sizeof(linklist));
    printf("Enter data for new node: ");
    scanf("%d", &newNode -> data);
    newNode -> prev = NULL;
    newNode -> link = NULL;

    printf("Enter postion to insert node: ");
    scanf("%d", &pos);

    // inserting new node
    linklist *temp = head, *curr = head;
    if(pos == 1)
    {
        newNode -> link = head;
        head -> prev = newNode;
        head = newNode;
    }
    else
    {        
        while(temp != NULL)
        {
            if(pos == count)
            {
                if(temp -> link != NULL){
                    newNode -> link = temp -> link;
                    temp -> link = newNode;
                    newNode -> prev = temp;
                    newNode -> link -> prev = newNode;
                }
                else{
                    temp -> link = newNode;
                    newNode -> prev = temp;
                }
            }
            temp = temp -> link;
            count++;
        }
    }
}

void delete(){
    linklist *temp = head, *ptr = head;
    int ele, flag = 0;
    printf("Enter element to delete: ");
    scanf("%d", &ele);

    if(temp -> data == ele){
        head = temp -> link;
        temp -> link -> prev = NULL;
        free(temp);
        flag = 1;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp -> data == ele)
            {
                if(temp -> link != NULL){
                    ptr -> link = temp -> link;
                    flag = 1;
                    free(temp);
                    break;
                }
                else{
                    ptr -> link = NULL;
                    flag = 1;
                    free(temp);
                    break;
                }
            }
            ptr = temp;
            temp = temp -> link;
        }
    }
    if(flag == 0)
        printf("\nNode not found in the list..\n");
}

void display(){
    linklist *temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }
    printf("NULL");
}

void reverseDisplay(linklist *temp){
    if(temp -> link == NULL){
        printf(" <- %d", temp -> data);
        return;
    }
    else{
    reverseDisplay(temp->link);
    printf(" <- %d", temp -> data);
    }
}
int main(){
    int ch;
    do
    {
        printf("\n\nMENU:\n");
        printf("1. Create node\n");
        printf("2. Insert node\n");
        printf("3. Delete node\n");
        printf("4. Display list\n");
        printf("5. Display reverse list\n");
        printf("6. Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: create();   break;
            case 2: insert();   break;
            case 3: delete();   break;
            case 4: display();  break;
            case 5: printf("NULL"); reverseDisplay(head);    break;
            case 6: printf("\n\nExiting program....");  break;
            default:printf("\nInvalid Choice...\n");
        }
    }
    while(ch != 6);
    return 0;
}