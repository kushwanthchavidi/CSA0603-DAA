#include<stdio.h>
int main(){
	int n,sum=0,rem;
	printf("Enter the number: ");
	scanf("%d",&n);
	while(n>0){
		rem=n%10;
		sum+=rem;
		n/=10;
	}
	printf("the sum is: %d",sum);
	return 0;
}
