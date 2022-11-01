// program to insert node at any given position
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
    do{
        printf("\n\nMENU:\n");
        printf("1. Create node\n");
        printf("2. Insert node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
            create();
        else if(ch == 2)
                insert();
            else if(ch == 3)
                    display();
                else
                    printf("\n\nExiting program.....");
    }
    while(ch != 4);
    return 0;
}