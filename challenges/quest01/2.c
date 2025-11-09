#include <stdio.h>
#include <string.h>

int main() {
	char input[10000];
	char *names[100];

	int count=0;
	
	fgets(input, sizeof(input), stdin);

	char *tok=strtok(input, ",");
	while(tok != NULL) {
		names[count++]=strdup(tok);
		tok=strtok(NULL, ",");
	}

	int pos=0;
	getchar();
	while(1){
		char dir=getchar();
		int num;

		scanf("%d", &num);
		if(dir=='R')
			pos+=num;
		else
			pos-=num;

		pos=pos%count;
		if(pos<0)
			pos+=count;

		if(getchar() != ',') break;
	}

	printf("%s\n", names[pos]);
}
