typedef    struct list
    {
        int *p;
        int len;
        int size;
        int last;
    }stack;

void add(stack*list1,int k);
int pop(stack *l);
int top(stack *stack);