#include <stdio.h>

int main(int argc, char * argv[]) {
	if (argc > 2) {
		printf("Co qua nhieu doi so\n");
	} else if (atoi(argv[1]) > 0){
		int n = atoi(argv[1]), s = 0;
		for(int i=1;i<=n;i++){
			s+=i;
		}
		printf("S = %d\n",s);
	} else {
		printf("Doi so khong phai la so nguyen duong\n");
	}
}