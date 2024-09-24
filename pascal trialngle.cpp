#include<stdio.h>
int main(){
	int i,j,rows,s,coef=1;
	printf("C.Kushwanthu-192211304\n");
	printf("Enter the rows: ");
	scanf("%d",&rows);
	for(i=0;i<rows;i++){
		for(s=1;s<=rows-i;s++){
			printf(" ");
		} for(j=0;j<=i;j++){
			if(j==0||i==0){
				coef=1;
			} else{
				coef=coef*(i-j+1)/j;
			}
			printf("%d ",coef);
		}
		printf("\n");
	}
	return 0;
}
