#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *push(struct stack *top)
{
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    printf("enter the data you want to store\n");
    scanf("%d", &new->data);
    new->next = top;
    top = new;
    return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *temp = top;
    if (temp->data == -23368)
    {
        printf("stack underflow\n");
    }
    else
    {
        top = top->next;
        printf("popped element is %d\n", temp->data);
        free(temp);
        return top;
    }
}
void peek(struct stack *top)
{
    struct stack *temp = top;
    if (temp->data == -23398)
    {
        printf("stack underflow\n");
    }
    else
    {

        printf("which number's element you want to know\n");
        int f;
        scanf("%d", &f);

        while (f != 1)
        {
            temp = temp->next;
            f--;
        }
        printf("number is %d\n", temp->data);
    }
}
void display(struct stack *ptr)
{
// printf("test test %d\n",ptr->next->data);    
    if (ptr->data == -23398)
    {
        printf("stack underflow\n");
    }
    else
    {

        while (ptr != NULL)
        {
            printf("element is %d\n", ptr->data);
            ptr = ptr->next;
        }
        // printf("test test %d\n",ptr->data);
    }
}
int main()
{
     struct stack *top = (struct stack *)malloc(sizeof(struct stack));
        top->next = NULL;
        top->data = -23368;
    while (1)
    {
        printf("type 1 for push operation\n");
        printf("type 2 for pop operation\n");
        printf("type 3 for peek operation\n");
        printf("type 4 to display all element of stack\n");
        printf("type 5 to quit\n");
        int x;
        scanf("%d", &x);
       
        if (x == 1)
        {
            printf("enter the no. of element you want to push\n");
            int a;
            scanf("%d", &a);
            printf("enter the data you want to store\n");
            scanf("%d", &top->data);
            
            // printf("test\n");
            for (int i = 1; i <= a - 1; i++)
            {
                // printf("test\n");
                top = push(top);
            }
          printf("test test%d\n",top->data);  
        }
        else if (x == 2)
        {
            top = pop(top);
        }
        else if (x == 3)
        {
            peek(top);
        }
        else if (x == 4)
        {
            display(top);
        }
        else
        {
            free(top);
            break;
        }
    }

    return 0;
}