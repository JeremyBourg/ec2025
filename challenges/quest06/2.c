#include <stdio.h>

int main() {
	int count, a, b, c;
	count = a = b = c = 0;
	for(char curr=getchar();; curr=getchar()) {
		if(curr == 'A') a++;
		else if(curr == 'a' && a) count+=a;

		if(curr == 'B') b++;
		else if(curr == 'b' && b) count+=b;

		if(curr == 'C') c++;
		else if(curr == 'c' && c) count+=c;

		if(curr == '\n') break;
	}
	printf("%d\n", count);
}
