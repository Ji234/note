//实现需求:使链表实现queue
//实现思路,用一个指针当头,像实现链表一样实现链表队列
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Queue {
    ElemType data;//存储数据
    struct Queue *next;//下一个数据的位置
}LinkQueue;

int EnQueue(LinkQueue** q, ElemType elem);//如果在链表头部的位置插入的话就要在队列尾部删除,这样的话每次删除就要遍历一次链表,很不划算,算了也就这样吧!先实现了再说
int DeQueue(LinkQueue** q);//直接删除尾部
ElemType GetHead(LinkQueue *q);
int IsEmpty(LinkQueue* q);

int main() {
    //int array[10] = { 1,3,5,7,9 };
    LinkQueue *head;
    head = NULL;
    for (int i = 0; i < 23; i++) {
        EnQueue(&head, i);
    }

    for (int i = 0; i < 23; i++) {
        printf("%d\n", GetHead(head));
        //printf("%d\n", DeQueue(&head));
        DeQueue(&head);
    }
    //printf("%d\n", seqQueue.front);
    //printf("%d\n",GetCount(&seqQueue));

}


int EnQueue(LinkQueue** q, ElemType elem) {
    //在头部插入
    //如果为空直接赋值
    if (*q ==NULL ) {
        *q = malloc (sizeof(LinkQueue));
        (*q)->data = elem;
        (*q)->next = NULL;
        return 0;
    }
    //不为空要把新的next赋值为之前的head
    LinkQueue * temp;
    temp = *q;
    *q = malloc (sizeof(LinkQueue));
    (*q)->data = elem;
    (*q)->next = temp;
    return 0;
}
int DeQueue(LinkQueue** q) {
    //为空的话不能删
    if(IsEmpty(*q)) return -1;
    //最后一个特殊情况
    if((*q)->next == NULL ) {
        free(*q);
        //*q = NULL;
        return 0;
    }

    LinkQueue * temp;
    temp = *q;
    while(temp ->next-> next != NULL ) temp = temp ->next;
    free(temp->next);
    temp->next = NULL;
    return 0;

}
ElemType GetHead(LinkQueue *q) {
    if(IsEmpty(q)) return -1;
    LinkQueue * temp;
    temp = q;
    while(temp -> next!= NULL ) temp = temp ->next; 
    return temp->data;
}
int IsEmpty(LinkQueue* q) {
    if(q == NULL) return 1;
    return 0;
}
