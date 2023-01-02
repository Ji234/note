//实现需求:使链表实现queue
//实现思路,用一个指针当头,像实现链表一样实现链表队列
#include <stdio.h>

typedef int ElemType;
typedef struct Queue {
    ElemType data;//存储数据
    struct Queue *next;//下一个数据的位置
}LinkQueue;

int EnQueue(LinkQueue** q, ElemType elem);//如果在链表头部的位置插入的话就要在队列尾部删除,这样的话每次删除就要遍历一次链表,很不划算,算了也就这样吧!先实现了再说
int DeQueue(LinkQueue** q);//如果没有空就,rear 的位置向后移动一位
ElemType GetHead(LinkQueue **q);//给出front位置的数值
int IsEmpty(LinkQueue** q); //front == rear

int main() {
    int array[10] = { 1,3,5,7,9 };
    LinkQueue *head;
    InitQueue(&seqQueue);
    //    printf("%d,%d", seqQueue.front,seqQueue.rear);
    for (int i = 0; i < 23; i++) {
        EnQueue(&seqQueue, i);
    }

    for (int i = 0; i < 23; i++) {
        printf("%d\n", GetHead(&seqQueue));
        printf("%d\n", DeQueue(&seqQueue));
    }
    //printf("%d\n", seqQueue.front);
    //printf("%d\n",GetCount(&seqQueue));

}

}

int EnQueue(LinkQueue** q, ElemType elem) {
    //在头部插入
    //如果为空直接赋值
    if (*q ==NULL ) {
        *q = malloc (sizeof(LinkQueue));
        (*q)->data = elem;
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
int DeQueue(SeqQueue** q) {
    if(*q == NULL) return -1;

}
ElemType GetHead(SeqQueue *q) {
    if (q->front == q->rear) return 0;
    return q->data[q->front];
}
int IsEmpty(SeqQueue* q) {
    if (q->rear == q->front) return 1;
    return 0;
}
