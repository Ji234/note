//实现括号匹配判断,对称的两个不一样的括号匹配

//思路: 先用一个char的list存入要匹配的数据
//传入一个函数判断是不是匹配,函数内部用栈
//先将括号的左边放到栈里面,如果有括号的右边就出栈,如果放入括号右边没有匹配相应的括号左边说明括号不相等
//最后判断栈内部是不是为空,如果为空的话就说明完全匹配

#include <stdio.h>
#include <string.h>
#include "stack_char.h"

extern char stack[slength];
extern int top;

char left_bracket[7]={'<','(','{','['};
char right_bracket[7]={'>',')','}',']'};
 
int findIndex(char chr,char *src){
	int i;
	for(i =0; src[i] != '\0';i++){
		if (chr == src[i]) return i;
	}
	return -1;
}

int is_char_in_str(char chr,char src[]){
	int i;
	for(i =0; src[i] != '\0';i++){
		if (chr == src[i]) return 1;
	}
	return 0;
}
int is_barcket_match(char str[]){
	char all[10];
	int i;
	strcat(all,left_bracket);
	strcat(all,right_bracket);
//	printf("%s\n",all);
	for(i=0;str[i]!='\0';i++){
		//是否属于括号
		if ( is_char_in_str(str[i],all)){
//	printf("%d\n",isEmpty());
			//属于左括号,push
			if ( is_char_in_str(str[i],left_bracket) ) Push(str[i]);
			//两个是一对就pop
			else if ( str[i]== right_bracket[findIndex(Top(),left_bracket)] ) Pop();
			//错误情况
			else return 0;
		}
	}
	if(isEmpty()) return 1;	
	return 0;
}
int main(){
	char str[101];
	//两个字符串相对应
	printf("input a string include some bracket:");
	scanf("%s",str);
	printf("括号匹配情况: %d\n",is_barcket_match(str));
}
