#include <stdio.h>

int main() {
	char input[100];
	int a1, a2;
	int r1=0, r2=0;

	fgets(input, sizeof(input), stdin);
	sscanf(input, "%*[^0-9]%d%*[^0-9]%d", &a1, &a2);

	int t=3;
	while(t--){
		int k1 = r1*r1 - r2*r2;
		int k2 = r1*r2 + r1*r2;
		k1/=10;
		k2/=10;
		k1+=a1;
		k2+=a2;
		r1=k1;
		r2=k2;
	}

	printf("[%d,%d]\n", r1, r2);
}
