//实现了链表任意位置删除
#include <stdio.h>
#include <stdlib.h>
#define ALENGTH 5
struct Node {
    int v;
    struct Node* next;
};


void delete(int num, struct Node** node);
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
    delete(4,&node);
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


void delete(int index, struct Node** node){
    int i;
    struct Node* temp, *temp1;
    //0 is special case:forward not have Node
    if(index ==0 ){
        temp=(*node);
       *node = (*node)->next;
       free(temp);
       return;
    }
    //backup node head 
    temp1=*node;
    for(i=1 ; i<index && ((*node)->next)->next!=NULL ; i++){
        *node= (*node)->next;
    }
    //it will be free
    temp = (*node)->next;
    
    (*node)->next= ((*node)->next)->next;
    free(temp);
    *node = temp1;

}

//插入
void insert(int num, struct Node** node) {
    *node = malloc(sizeof(struct Node));
    (*node)->v = num;
    (*node)->next = NULL;
}
