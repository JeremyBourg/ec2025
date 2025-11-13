#include <stdio.h>
#include <stdlib.h>

#define ll long long int

int main() {
	char input[100];
	int a1, a2;

	fgets(input, sizeof(input), stdin);
	sscanf(input, "%*[^0-9]%d%*[^0-9]%d", &a1, &a2);

	int size=101;
	int cnt=size*size;

	int inc=1000/(size-1);

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			int p1=a1+j*inc;
			int p2=a2+i*inc;

			ll r1=0, r2=0;
			int t=100;
			while(t--){
				//multiply by itself
				long double k1 = r1*r1 - r2*r2;
				long double k2 = 2*r1*r2;

				//divide by 100000
				k1/=100000;
				k2/=100000;

				//add p
				k1+=p1;
				k2+=p2;

				r1=k1;
				r2=k2;

				if(llabs(r1) > 1000000 || llabs(r2) > 1000000) {
					cnt--;
					break;
				}
			}
		}
	}

	printf("%d\n", cnt);
}
