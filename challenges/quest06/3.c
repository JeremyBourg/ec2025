#include <stdio.h>
#include <string.h>

#define MAX_DIST 1000

int main() {
	char input[100000];
	fgets(input, sizeof(input), stdin);
	input[strlen(input)-1] = '\0';

	long long count = 0;

	int t = 1000;
	while(t--){
		for(int i=0; input[i] != '\0'; i++) {
			if(input[i] & 0x20) {
				for(int j=i-MAX_DIST; j<=i+MAX_DIST; j++) {
					int k = j % (strlen(input));
					if((input[k]^0x20) == input[i]) count++;
				}
			}
		}
	}

	printf("%lld\n", count);
}
