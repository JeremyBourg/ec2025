#include <stdio.h>

int main() {
	int count=0, mentor=0;
	for(char curr=getchar();; curr=getchar()) {
		if(curr == 'A') mentor++;
		else if(curr == 'a' && mentor) count+=mentor;

		if(curr == '\n') break;
	}
	printf("%d\n", count);
}
