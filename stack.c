#include<stdio.h>
int size = 5, top = -1;
int stack[5];
int push(){
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    if(top == (size-1))
        printf("Stack is full...");
    else
        top = top + 1;
    stack[top] = value;
}

int pop(){
    if(top == -1)
        printf("Stack is empty");
    else
        top = top - 1;
}
void display(){
    if(top == -1)
        printf("\nStack is empty\n\n");

    for(int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
}
int main(){
    int ch;
    do{
        printf("\n\n****MENU****");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: push(); break;
            case 2: pop();  break;
            case 3: display();  break;
            case 4: break;
        }    
    }
    while(ch != 4);
    
    return 0;
}