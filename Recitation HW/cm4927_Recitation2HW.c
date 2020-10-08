#include <stdio.h>
struct studentGrade{
	char name[20], grade, subject[20];
	int marks1,marks2;
	float percentage;
}s1;
int main(){
	int choice = 1;
	do{
		struct studentGrade s1;
		printf("Enter the student name\n");
		scanf("%s", s1.name);
		printf("Enter the school subject\n");
		scanf("%s", s1.subject);
		printf("Enter the two grades\n");
		scanf("%d %d",&s1.marks1,&s1.marks2);
		int sumOfMarks = 200;
		s1.percentage = ((float)(s1.marks1 + s1.marks2))*100/(sumOfMarks);
		if (s1.percentage >= 75){
			s1.grade = 'A';
		}
		else if (s1.percentage>=50 && s1.percentage<75){
			s1.grade = 'B';
		}
		else if (s1.percentage>=35 && s1.percentage<50){
			s1.grade = 'C';
		}
		else{
			s1.grade = 'F';
		}
		printf("Student: %s, Subject: %s, Mark1: %d, Mark2: %d, Percentage: %.2f %%, Grade:%c\n", s1.name,s1.subject,s1.marks1,s1.marks2,s1.percentage,s1.grade);
		printf("Would you like to enter more information? Yes (1) / No (0)\n");
		scanf("%d", &choice);
	}while (choice == 1);
	return 0;
}
