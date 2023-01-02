
#include <stdio.h>
#define MaxSize 20

//使用list,并且牺牲一个单元来判断队列是否为空,的循环队列
//从尾部插入,从头出
typedef int ElemType;
typedef struct Queue {
    ElemType data[MaxSize];
    int front, rear;//头指针,尾指针
}SeqQueue;

void InitQueue(SeqQueue* q);//初始化,seqQueuerq,把front 和rear置零
int EnQueue(SeqQueue* q, ElemType elem);//如果没有满,front向后移动一位,再在后面插入
int DeQueue(SeqQueue* q);//如果没有空就,rear 的位置向后移动一位
ElemType GetHead(SeqQueue *q);//给出front位置的数值
int IsEmpty(SeqQueue* q); //front == rear
int GetCount(SeqQueue* q);//(front - rear + maxsize)%maxsize

int main() {
    int array[10] = { 1,3,5,7,9 };
    SeqQueue seqQueue;
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

void InitQueue(SeqQueue* q) {
    q->front = q->rear = 0;
}

int EnQueue(SeqQueue* q, ElemType elem) {
    if ((q->rear - q->front+ MaxSize) % MaxSize != MaxSize - 1) {
        q->data[q->rear] = elem;
        q->rear = (q->rear + 1) % MaxSize;
        return 0;
    }
    return 1;

}
int DeQueue(SeqQueue* q) {
    if (q->front != q->rear ) {
        q->front = (q->front + 1) % MaxSize;
        return 0;
    }
    return 1;
}
ElemType GetHead(SeqQueue *q) {
    if (q->front == q->rear) return 0;
    return q->data[q->front];
}
int IsEmpty(SeqQueue* q) {
    if (q->rear == q->front) return 1;
    return 0;
}
int GetCount(SeqQueue* q) {
    return (q->rear - q->front + MaxSize) % MaxSize;
}
