#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("\nEnter the Size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));

}

void Display(struct Stack st){
    printf("\n");
    for (int i = st.top; i >= 0; i--){
        printf("%d\t", st.S[i]);
    }
    printf("\n");
}

int isEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st){
    return st.top == st.size-1;
}

int stackTop(struct Stack st){
    if (!isEmpty)
        return st.S[st.top];
    return -1;
}

void push(struct Stack *st, int x){
    if (st->top == st->size-1)
        printf("\nStack Overflow\n");
    else{
        st->top ++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x = -1;
    if (st->top == -1)
        printf("\nStack Underflow\n");
    else
        x = st->S[st->top--];
    return x;
}

int peek(struct Stack st, int index){
    int x = -1;
    if (st.top-index+1 < 0)
        printf("\nInvalid index");
    x = st.S[st.top-index+1];

    return x;
}


int main(){
    struct Stack st;
    create(&st);

    push(&st, 10);

    Display(st);

    push(&st, 69);
    Display(st);
    printf("\nThe deleted term is: %d",pop(&st));
    printf("\nThe deleted term is: %d",pop(&st));
    printf("\nThe deleted term is: %d",pop(&st));
    Display(st);
    return 0;
}
