#include<stdio.h>
int main(){
	int n,i,space,j;
	printf("C.Kushwanthu-192211304\n");
	printf("Enter the no.of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(space=1;space<=n-i;space++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}
