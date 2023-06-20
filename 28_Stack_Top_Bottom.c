#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// Function for IsFull Operation

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
};

// Function for isEmty Operation

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

// Function for push Operation
void push(struct stack *ptr,int val)
{
    if (isFull(ptr))
    {
        printf("\n Stack OverFlow ! %d cannot push\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
};

// Function for pop operation 
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack UnderFlow, Cannot pop");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
};
// Function for Peek Operation
int peek(struct stack *ptr,int i)
{
    int arrayIndex = ptr->top  - i + 1;
    if (arrayIndex < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayIndex];
    }  
};
// Function for Stack top element
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
};

// Function for Stack Bottom element
int stackBottom(struct stack* sp)
{
    return sp->arr[0];
};
int main()
{
    struct stack *sp = (struct stack*)malloc(sizeof(struct      
      stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));

    printf("Before pushing : %d \n",isFull(sp));
    printf("1|===========================\n");
    printf("Before Pop : %d \n",isEmpty(sp));
    printf("2|========================\n");
    push(sp,12);
    push(sp,24);
    push(sp,36);
    push(sp,46);
    push(sp,56);
    printf("3|=========================\n");
    printf("After pushing : %d\n",isFull(sp));
    printf("After Pop : %d\n",isEmpty(sp));
    printf("4|=========================\n");

    // Printing total values in the stack
    for (int i = 1; i < sp->top + 1; i++)
    {
        printf("The values at position %d is %d\n",i,peek(sp,i));
    }

    printf("5.=========================\n");
    //print for stack bottom and  top element
    printf("stack top most element is %d \n",stackTop(sp));
    printf("Stack bottom most element is %d \n",stackBottom(sp));
    



}