#include <stdio.h> /*Library I think.. includes printf function etc...*/
#include <stdlib.h>

int main() {  //int is a function that returns an integer

	struct student
	{
		char *strName[20];
		char *strSurname[20];
		char *strPPS[20];
		char *strNationality[20];	//	%c
		int *intMarried;    // 1 True; 0 False;
		int *intChildren;	//	%d
		char *strRegistration[20];
	};

	struct company
	{
		char strCompany[20];
		char strRegistration[20];
		int intSalary;
		int blnBenefits;
	};


	FILE *fileStudents = fopen("students.txt", "r");

	// if there was an error
	if (fileStudents == NULL) {
		perror("Error opening students file"); // print error
		return(-1);
	}
	// if there was no error
	else {

		struct student *pointer; //records each case of structure memory
		pointer = (struct student*) malloc(1000 * sizeof(struct student));

		int i;

		for (i = 0; i < 1000; ++i)
		{
			fscanf(fileStudents, "%s %s %s %s %d %d %s", &pointer[i].strName, &pointer[i].strSurname, &pointer[i].strPPS, &pointer[i].strNationality, &pointer[i].intMarried, pointer[i].intChildren, &pointer[i].strRegistration);
			printf("%s", pointer[i].strName);
		}



		return 0;

	}

	fclose(fileStudents); // close file

	return 0; //indicates successfull execution and build
}