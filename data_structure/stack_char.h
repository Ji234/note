//用数组实现栈，top用一个integr数表示,stack本体用一个数组表示，如果超过数组的长度和小于 0 的时候就报错
#ifndef STACK_CHAR_H
#define STACK_CHAR_H
#include <stdio.h>
#include <limits.h>
#define slength 101

void Push(char num);
void Pop();
char Top();
int isEmpty();
void Print_stack();
//全局变量
int top = -1;
char stack[slength];

#endif
void Push(char num) {
    if (top > slength - 1) {
        printf("error: overflow");
        return;
    }
    top++;
    stack[top] = num;
}
void Pop() {
    if (top < 0) {
        printf("error: overflow");
        return;
    }
    top--;
}
char Top() {
	if (top > slength - 1 || top < 0) {
        printf("error: overflow");
        return '\0';
    }
    return stack[top];
}
int isEmpty() {
    return top == -1;
}

void Print_stack() {
    int temp;
    temp = top;
    //printf("%d\n", temp);
    while (temp > -1) {
        printf("%c", stack[temp]);
        temp--;
    }
    printf("\n");
}


