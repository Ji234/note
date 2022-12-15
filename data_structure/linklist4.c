//递归的查看链表
#include <stdio.h>
#include <stdlib.h>
#define ALENGTH 5
struct Node {
    int v;
    struct Node* next;
};


int show_list(struct Node* node);
void show_list1(struct Node* node);
void insert(int num, struct Node** node);
int main() {
    int i, j;
    int len;
    j = 0;
    int array[ALENGTH] = { 5,4,3,2,1 };//要插入的数据
    struct Node* node;//根节点
    node = NULL;
    struct Node** temp;//临时节点用来操作链表
    struct Node* temp1;
    //未初始化变量
    temp1 = NULL;
    temp = &temp1;
    for (i = 0; i <ALENGTH; i++) {
        int input;
        insert(array[i], temp);
        if (i == 0) node = *temp;

        //Node 中next 的位置
        temp = &((*temp)->next);
        show_list(node);
    }
    show_list1(node);
}

int show_list(struct Node* node) {
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

void show_list1(struct Node* node){
    if(node == NULL){
        printf("\n");
        return;
    }
    printf("%d ",node->v);
    show_list1(node->next);
}


//插入
void insert(int num, struct Node** node) {
    *node = malloc(sizeof(struct Node));
    (*node)->v = num;
    (*node)->next = NULL;
}
