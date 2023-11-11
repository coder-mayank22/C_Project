#include<stdio.h>
#include<ctype.h>
int isNumber(char* exp,int i){
	int c1=i;
	while(exp[++c1]!=' ');
	if(c1==i+1)return -1;
	else
	return c1-i;
}

int main(){
	char exp[]="4 9";
	printf("%d",(exp[2]-'0')+1);
}
