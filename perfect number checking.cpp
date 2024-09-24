#include<stdio.h>
int main(){
	int n,sum=0;
	printf("C.Kushwanthu-192211304\n");
	printf("Enter the number: ");
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		if(n%i==0){
			sum+=i;
		}
	}
	if(sum==n){
		printf("%d is   perfect number",n);
	} else{
		printf("%d is  not perfect number",n);
	}
	return 0;
}
