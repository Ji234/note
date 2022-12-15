//双向链表,添加,删除,打印
#include <stdio.h>
#include <stdlib.h>
#define ALENGTH 5
struct Node {
    int v;
    struct Node* next;
    struct Node* prev;

};


int show_list(struct Node* node);
struct Node* insert_head(int num, struct Node** node);
void delete_tail(struct Node** node,struct Node** head);
int main() {
    int i;
    int array[ALENGTH] = { 5,4,3,2,1 };//要插入的数据
    struct Node* head;//根节点
    struct Node* tail;//根节点
    head = NULL;
    tail = NULL;
    for (i = 0; i <ALENGTH; i++) {
        head = insert_head(array[i], &head);
        if (i == 0) tail=head;
        //Node 中next 的位置
        show_list(head);
    }
    for (i = 0; i <ALENGTH; i++) {
        delete_tail(&tail,&head);
        show_list(head);
    }
    //printf("\n");
    //printf("%p\n\n",head);
}
//返回链表的长度
int show_list(struct Node* node) {
    int length;
    length = 0;
    while (node != NULL) {
        length++;
        printf("%d ", node->v);
        node = node->next;
    }
    printf("\n");
    return length;
}
//从尾部删除node
void delete_tail(struct Node** node,struct Node** head){
    //如果是最后一个,先提出地址,直接删除把前面的next 置空, 然后当前node的free,把tail地址修改成prev 的地址
    //如果不是,提地址出来,前面的next等于当前的next,后面的prev等于当前的prev ,让后free,最后再把tail地址修改成prev 的地址
    struct Node * temp;
    temp = *node;
    //删除到最后一个 prev=NULL了已经没有next了,段错误
    if((*node)->prev != NULL) {
        (*node)->prev->next=NULL;
    }
    else 
        //手动把head置为0,不然虽然 free了但是还是指向那个地方
        *head =NULL;

    free(temp);
    //printf("%p\n",temp);
    *node = (*node)->prev;
}


//插入node放在头部
struct Node* insert_head(int num, struct Node** node) {
    struct Node* temp;
    temp = malloc(sizeof(struct Node));
    temp->v = num;
    if(*node == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        return temp; 
    }
    temp->prev = NULL;
    temp->next = *node;
    (*node)->prev = temp;
    return temp;
}
