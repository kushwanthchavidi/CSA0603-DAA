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
	printf("R.Babu Eshwar-192211778\n");
	printf("The reversed number is: %d",b);
	return 0;
}
