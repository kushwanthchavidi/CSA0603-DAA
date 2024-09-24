#include<stdio.h>
int main(){
	int n,p,v;
	int arr[100];
	printf("C.Kushwanthu-192211304\n");
	printf("Enter the size: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the position: ");
	scanf("%d",&p);
	printf("Enter the value: ");
	scanf("%d",&v);
	for(int i=n;i>=p;i--){
		arr[i]=arr[i-1];
	}
	arr[p]=v;  
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
