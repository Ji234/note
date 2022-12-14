//实现了链表任意位置插入
#include <stdio.h>
#include <stdlib.h>
#define ALENGTH 5
struct Node {
    int v;
    struct Node* next;
};

void insert_index(int num,int index, struct Node** node);
int show_list(struct Node* node);
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
    insert_index(29,0,&node);
    show_list(node);
    insert_index(40,7,&node);
    show_list(node);
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



//插入
void insert(int num, struct Node** node) {
    *node = malloc(sizeof(struct Node));
    (*node)->v = num;
    (*node)->next = NULL;
}
//num ,index (index>=0), node 指针的指针
void insert_index(int num,int index, struct Node** node) {
    struct Node* temp1;
    int i;i=0;
    struct Node* temp;
    temp = malloc(sizeof(struct Node));
    temp->v =num;
    temp->next=NULL;
    if(index==0) {
         temp->next =*node;
         *node=temp;
         return;
    }

    temp1 =*node;
    for(i=1;i<index&&(*node)-> next!=NULL;i++){
        *node=(*node)->next;   
    }
        temp->next =(*node)->next; 
        (*node)->next=temp;
        *node=temp1;
}
