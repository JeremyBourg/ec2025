#include <stdio.h>
#include <string.h>

#define MAX_DIST 1000

int main() {
	char input[100000];
	fgets(input, sizeof(input), stdin);
	input[strlen(input)-1] = '\0';

	long long len = 3*strlen(input);
	char buf[len+1000];

	int t=3;
	while(t--)
		strcat(buf, input);

	printf("%s\n", buf);
	// AaAaAa
	long long count=0;
	for(int i=0; i<strlen(input); i++) {
		if(input[i] & 0x20) {
			for(int j=i-MAX_DIST+strlen(input);
					j<=i+MAX_DIST+strlen(input); j++) {
				if(j < 0) j=0;
				else if(j >=strlen(buf)) break;
				if((buf[j]^0x20) == input[i]) printf("hit!\n");
			}
		}
	}

	count *= 998;
	buf[strlen(input)*2]='\0';
	printf("%s\n", buf);

	for(int i=0; buf[i] != '\0'; i++) {
		if(buf[i] & 0x20) {
			for(int j=i-MAX_DIST; j<=i+MAX_DIST; j++) {
				if(j >= 0 && j < len && (buf[j]^0x20) == buf[i]) count++;
			}
		}
	}

	printf("%lld\n", count);
}
