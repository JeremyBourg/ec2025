#include <stdio.h>
#include <string.h>

void swap(char **str1, char **str2) {
	char *t=*str1;
	*str1=*str2;
	*str2=t;
}

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

	getchar();
	while(1){
		char dir=getchar();
		int num;

		scanf("%d", &num);
		num=num%count;
		if(!num) {
			if(getchar() != ',') break;
			continue;
		}

		if(dir=='R')
			swap(&names[0], &names[num]);
		else
			swap(&names[0], &names[count-num]);

		if(getchar() != ',') break;
	}

	printf("%s\n", names[0]);
}
