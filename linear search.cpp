#include<stdio.h>
int main(){
	int n,arr[100],i,j,key;
	
	printf("Enetr the size: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the key: ");
	scanf("%d",&key);
	for(i=0;i<n;i++){
		if(arr[i]==key){
			printf("%d",i);
		}
	}
	return 0;
}
