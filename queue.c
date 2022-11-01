#include<stdio.h>
int queue[5], size = 5;
int front = 0, rear = -1;
void display(){
    for(int i=front; i<=rear; i++)
        printf("%d ", queue[i]);
}

void enqueue(){
    if(rear == (size-1))
        printf("\nQueue is full...");
    else
    {
        int ele;
        printf("Enter element to add to queue: ");
        scanf("%d", &ele);
        queue[++rear] = ele;
        // rear++;
    }
}

void dequeue(){
    if(front > rear)
        printf("\nQueue is empty...");
    else
        front++;
}

void status(){
    if(front > rear)
        printf("\nQueue is empty....\n\n");
    else if(rear == size-1)
        printf("\nQueue is full..\n\n");
        else if(front <= rear)
                printf("\nQueue is ready..\n\n");
}

int main(){
    int ch;
    do{
        printf("\n\n****MENU****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Status\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: enqueue();  break;
            case 2: dequeue();  break;
            case 3: display();  break;
            case 4: status();   break;
            case 5: break;
        }
    }while(ch != 5);
    return 0;
}