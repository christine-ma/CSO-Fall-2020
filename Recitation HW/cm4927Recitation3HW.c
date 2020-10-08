#include <stdio.h>
void swapByVal(int a,int b){
		printf("Swapping values %d, %d through call by Value\n",a,b);
		int temp;
		temp=a;
		a=b;
		b=temp;
		printf("After swap: %d, %d\n",a,b);
	}
void swapByRef(int *p1,int *p2){
	printf("Swapping values %d, %d through call by Reference\n",*p1,*p2);
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	printf("After swap: %d, %d\n",*p1,*p2);
}
int main(){
	int var1 = 1, var2 = 3;
	printf("Original values before swapping %d,%d\n",var1,var2);
	swapByVal(var1,var2);
	printf("Original values before swapping %d,%d\n",var1,var2);
	swapByRef(&var1,&var2);
	return 0;
}


