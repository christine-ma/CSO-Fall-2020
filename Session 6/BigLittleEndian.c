//Christine Ma ID: cm4927
#include<stdio.h>
#include<string.h>

int is_little_endian(){
	int k = 0x01234567;
	//Big Endian = 01 23 45 67
	//Little Endian = 67 45 23 01
	char *start = (char *)&k;
	int n =sizeof(k);
	int i;
	printf("The stored address is: ");
	for (i = 0; i<n; i++){
		printf("%x", start[i]);
	}
	unsigned int j = 1;
	int result = 0;
	char *c = (char *)&j;
	if (*c){
		result = 1; //LittleEndian

	}
	else{
		result = 0; //BigEndian
	}
	return (result);
}
int main(){
	printf("Program 1: \n");
	printf("\n%s",is_little_endian()==1? "Your machine is LittleEndian":"Your machine is BigEndian");

}
