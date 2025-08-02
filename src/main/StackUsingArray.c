#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top=-1;

void push(int data){
        if(top==MAX-1){
                printf("Stack Overflow\n");
                return; }
        top=top+1;
        stack_arr[top]=data;
}
int pop(){
        int value;
        if(top==-1){
                printf("Stack Underflow\n");
                exit(1); }
        value=stack_arr[top];
        top--;
        return value;
}
int peek(){
        if(top==-1){
                printf("Stack Underflow\n");
                exit(1); }
        return stack_arr[top];
}
void print(){
        for(int i=top;i>=0;i--){
        printf("%d\n",stack_arr[i]);}
        printf("\n");

}
int main(){
         int data,choice,val;

         while(choice!=5){
                 printf("\n");
                 printf("1. Push\n");
                 printf("2. Pop\n");
                 printf("3. Print top element\n");
                 printf("4. Print all elements\n");
                 printf("5. Quit\n");
                 printf("Enter your choice: ");
                 scanf("%d",&choice);
                 switch(choice){
                         case 1:
                                 printf("Enter element to be pushed: ");
                                 scanf("%d",&data);
                                 push(data);
                                 break;
                        case 2:
                                 data=pop();
                                 printf("Deleted Element is %d\n",data);
                                 break;
                          case 3:
                                 val=peek();
                                 printf("Top most element: %d ",val);
                                 break;
                        case 4:
                                 print();
                                 break;
                        case 5:
                                 printf("Quit");
                                 break;
                        default:
                        printf("Invalid choice ");

         }
}
}
