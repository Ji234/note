//用数组实现栈，top用一个integr数表示,stack本体用一个数组表示，如果超过数组的长度和小于 0 的时候就报错
#include <stdio.h>
#include <limits.h>
#define slength 101
void push(int num);
void pop();
int top();
int isEmpty();
void print_stack();
//全局变量
int itop;
int stack[slength];
int main() {
    itop = -1;
	printf("%d \n",top());
    push(3); print_stack();
    push(5); print_stack();
    push(7); print_stack();
    pop(); print_stack();
    pop(); print_stack();

}

void push(int num) {
    if (itop > slength - 1) {
        printf("error: overflow");
        return;
    }
    itop++;
    stack[itop] = num;
    //printf("%d\n", itop);
}
void pop() {
    if (itop < 0) {
        printf("error: overflow");
        return;
    }
    itop--;
}
int top() {
	if (itop > slength - 1 || itop < 0) {
        printf("error: overflow");
        return -INT_MAX;
    }
    return stack[itop];
}
int isEmpty() {
    return itop == -1;
}

void print_stack() {
    int temp;
    temp = itop;
    //printf("%d\n", temp);
    while (temp > -1) {
        printf("%d ", stack[temp]);
        temp--;
    }
    printf("\n");
}
