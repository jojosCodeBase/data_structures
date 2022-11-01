// program to delete node from any given position
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head = NULL, *current, *next;

void create(){
    current = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &current -> data);
    current -> link = NULL;

    // for next node
    if(head == NULL)
        head = current;
    else
        next -> link = current;
    next = current;
}

void insert(){
    int pos, count = 2;
    // create node to be inserted
    struct node *newNode = malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d", &newNode -> data);
    newNode -> link = NULL;

    printf("Enter postion to insert node: ");
    scanf("%d", &pos);

    // inserting new node
    struct node *temp = head;
    if(pos == 1)
    {
        newNode -> link = head;
        head = newNode;
    }
    else
    {        
        while(temp != NULL)
        {
            if(pos == count)
            {
                newNode -> link = temp -> link;
                temp -> link = newNode;
            }
            temp = temp -> link;
            count++;
        }
    }
}

void delete(){
    struct node *temp = head, *ptr = head;
    int ele, flag = 0;
    printf("Enter element to delete: ");
    scanf("%d", &ele);

    if(temp -> data == ele){
        head = temp -> link;
        free(temp);
        flag = 1;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp -> data == ele)
            {
                ptr -> link = temp -> link;
                flag = 1;
                free(temp);
                break;
            }
            ptr = temp;
            temp = temp -> link;
        }
    }
    if(flag == 0)
        printf("\nNode not found in the list..\n");
}

void display(){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }
    printf("NULL");
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
        printf("5. Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: create();   break;
            case 2: insert();   break;
            case 3: delete();   break;
            case 4: display();  break;
            case 5: printf("\n\nExiting program....");  break;
            default:printf("\nInvalid Choice...\n");
        }
    }
    while(ch != 5);
    return 0;
}