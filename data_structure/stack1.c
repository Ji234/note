//链表实现栈,不用改变空间,top指向头节点,
//push的时候:先创建一个新的节点,节点的next 指向top,再把top指向新构造出来的的节点
//pop的时候: 把top指针复制到temp,修改top = top -> next 把temp的空间free
//isEmpty :注意没有节点的时候把top 置NULL ;如果NULL 就为1 否则为0
//top   :直接返回top->data

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define ALENGTH 5
struct Node {
    int v;
    struct Node* next;
};

int show_stack(struct Node* node);
void push(int num, struct Node** node);
void pop(struct Node** node);
int top(struct Node* node);
int isEmpty(struct Node* node);
int main() {
    struct Node* itop = NULL;//根节点
    printf("top: %d\n",top(itop));
	push(3, &itop);show_stack(itop);
    printf("top: %d\n",top(itop));
	push(5, &itop);show_stack(itop);
    printf("top: %d\n",top(itop));
	push(7, &itop);show_stack(itop);
    printf("top: %d\n",top(itop));
	pop(&itop);show_stack(itop);
    printf("top: %d\n",top(itop));
	pop(&itop);show_stack(itop);
    printf("top: %d\n",top(itop));
}

int show_stack(struct Node* node) {
    int length;
    length = 0;
    while (node!= NULL) {
        length++;
        printf("%d ", node->v);
        node = node->next;
    }
    printf("\n");
    return length;
}

void push(int num, struct Node** node) {
	struct Node* temp;
    temp= malloc(sizeof(struct Node));
    temp->v = num;
    temp->next = *node;
	*node = temp;
}
void pop(struct Node** node){
	struct Node* temp;
    temp = *node;
	if((*node)->next == NULL){
        *node = NULL;
        free(temp);
        return;
    }
    *node= (*node)->next;
    free(temp);
}

int top(struct Node* node){
    if(node == NULL) {
        printf("stack is empty\n");
        return -INT_MAX;
    }
    return node->v;
}
int isEmpty(struct Node* node){
    return node == NULL;
}
