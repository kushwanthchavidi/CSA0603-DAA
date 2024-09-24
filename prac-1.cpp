#include<stdio.h>
int main(){
	int n,i,j;
	printf("C.Kushwanthu-192211304\n");
	printf("Enter the no.of items: ");
	scanf("%d",&n);
	int weight[n],value[n];
	float ratio[n],total_value=0.0;
	float capacity;
	printf("Enter the weights and values: ");
	for(i=0;i<n;i++){
		printf("item-%d,weight: ",i+1);
		scanf("%d",&weight[i]);
		printf("item-%d,value: ",i+1);
		scanf("%d",&value[i]);
		ratio[i]=(float)value[i]/weight[i];
	}
	printf("Enter the capacity of kanpsack: ");
	scanf("%d",&capacity);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(ratio[i]<ratio[j]){
			int temp_ratio=ratio[i];
			ratio[i]=ratio[j];
			ratio[j]=temp_ratio;
			int temp_weight=weight[i];
			weight[i]=weight[j];
			weight[j]=temp_weight;
			int temp_value=value[i];
			value[i]=value[j];
			value[j]=temp_value;
		}
	}
}
for(i=0;i<n;i++){
	if(weight[i]<=capacity){
		total_value+=value[i];
		capacity-=weight[i];
	}else{
		total_value+=value[i]*(capacity/weight[i]);
		break;
	}
}
printf("max value is:%.2f\n",total_value);
return 0;
}

