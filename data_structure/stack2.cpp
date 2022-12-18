//反转一个字符串, 直接进入然后top pop出来就行
//反转一个链表：要写一个逻辑一样的代码，视频里面使用C++标准库实现 使用了模板

//在这里我只想实现反转字符串,链表不想实现想用模板实现
#include<iostream>
#include<cstring>
#define ALENGTH 101
using namespace std;

class Stack{
	private:
	    char A[ALENGTH];
	    int top;
	public:
	    void Push(char num);
	    void Pop();
	    char Top();
	    int isEmpty();
		Stack();
};

Stack :: Stack(){
	top = -1;
	memset(A,0,sizeof(A));
}

void Stack::Push(char num){
	if(top>ALENGTH-1){
		printf("error: overflow");
		return;
	}
	top++;
	A[top] = num;
}

void Stack::Pop(){
	if(top<=-1){
		printf("error: overflow");
		return;
	}
	top--;
}

char Stack::Top(){
	if(top <= -1){
		printf("error: overflow");
		return '\0';
	}
	return A[top];
}

int Stack::isEmpty(){
	return top == -1;
}

void reverse(char * str, int len){
	Stack *stack = new Stack();
	int i=0;
	for(i=0 ;i<len ;i++){
		stack->Push(str[i]);
	}
	for(i=0 ; !stack->isEmpty();i++){
		str[i] = stack->Top();
		stack->Pop();
	}
}

int main(){
    char A[ALENGTH];
	printf("input a string:");
    cin.get(A,ALENGTH);
	reverse(A,strlen(A));
	printf("%s\n",A);
}
