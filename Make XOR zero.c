#include <iostream>
#include <stdio.h>
using namespace std;

#define max 1000000

int main() {
	
	char buffer[max];
	int t;
	
	unsigned long int N, n, i, x, countOne, countZero;
	
	x=fread(buffer, sizeof(char), max, stdin);
	
	i=0;
	t=0;
	while(i<x && buffer[i]!=10){
		t=(t*10)+(buffer[i]-'0');
		i++;
	}
	i++;
	
	while(t--){
		n=0;
		while(i<x && buffer[i]!=10){
			n=(n*10)+(buffer[i]-'0');
			i++;	
		}
		//printf("N=%lu\n",n);
		N=n;
		i++;
		
		countOne=0;
		countZero=0;
		
		while(i<x && buffer[i]!=10){
			//printf("%d ", buffer[i]);
			if(buffer[i]=='1')
				countOne++;
			else if(buffer[i]=='0')
				countZero++;
			
			i++;
		}
		//printf("\n");
		i++;
		
		if(countZero==N || countOne== N){
			printf("%lu\n",N);
		} else if(countZero==1 || countOne==1){
			printf("1\n");
		} else{
			printf("0");
		}
	}
	
	return 0;
}