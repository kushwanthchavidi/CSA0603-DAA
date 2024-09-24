#include<stdio.h>
int main(){
	int n,a,b=0,t;
	printf("Enter the number: ");
	scanf("%d",&n);
	t=n;
	while(n!=0){
		a=n%10;
		b=b*10+a;
		n=n/10;
	}
	printf("C.Kushwanthu-192211304\n");
	printf("The reversed number is: %d",b);
	return 0;
}
