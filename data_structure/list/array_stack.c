#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024

typedef struct {
    int data[MAXSIZE];
    int top;
} SeqStack;

//初始化
SeqStack* init_SeqStack() {
    SeqStack* s = calloc(1, sizeof(SeqStack));
    s->top = -1;
    return s;
}

//判断空
int empty_SeqStack(SeqStack* s) { return s->top == -1; }

//入栈
int push_SeqStack(SeqStack* s, int x) {
    //满了
    if (s->top == MAXSIZE - 1) {
        return 0;
    }

    s->top++;
    s->data[s->top] = x;
    return 1;
}

//出栈
int pop_SeqStack(SeqStack* s, int* x) {
    if (empty_SeqStack(s)) {
        return 0;
    }
    *x = s->data[s->top];
    s->top--;
    return 1;
}

//取栈顶元素
int top_SeqStack(SeqStack* s) {
    if (empty_SeqStack(s)) {
        return 0;
    }
    return s->data[s->top];
}
