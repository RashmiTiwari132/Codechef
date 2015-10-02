#include <stdio.h>

struct OPositionDepth{
		int depth;
		int position;
	};
struct OPositionDepth *temp=NULL;

static char stack[1000];
static int top=-1;

int findLeastDeepO(char *);
void push(char);
struct OPositionDepth * pull(char *);

int main(void) {
	
	char str[1000];
	fgets(str, 1000, stdin);
	
	printf("%d", findLeastDeepO(str));
	return 0;
}

int findLeastDeepO(char *str){
	int i=0, minDepth=0, minPos;
	struct OPositionDepth *retValue;
	
	while(str[i]!='\0'){
		if(str[i]=='('){
			push('(');
		}else if(str[i]=='O'){
			push('O');
		} else if(str[i]==')'){
			retValue=pull(str);
		}
		if(minDepth==0 || minDepth>retValue->depth){
			minDepth=retValue->depth;
			minPos=retValue->position;
		}
	}
	
	return minPos;
}

void push(char ch){
	stack[++top]=ch;
	stack[(top+1)]='\0';
}

struct OPositionDepth * pull(char *str){
	
	int depth, pos;
	temp=(struct OPositionDepth *)malloc(sizeof(struct OPositionDepth));
	
	if(stack[top]=='O'){
		stack[top]='\0';
		pos=top;
		top--;
		while(stack[top]=='('){
			stack[top]='\0';
			depth++;
			top--;
		}
	} else{
		while(stack[top]=='('){
			stack[top]='\0';
			top--;
		}
	}
	temp->depth=depth;
	temp->position=pos;
	return &temp;
}
