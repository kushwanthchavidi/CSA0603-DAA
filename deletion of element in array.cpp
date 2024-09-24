#include<stdio.h>
int main(){
	int n,p,v;
	int arr[100];
	printf("Enter the size: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the position: ");
	scanf("%d",&p);
	for(int i=p;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	for(int i=0;i<n-1;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
