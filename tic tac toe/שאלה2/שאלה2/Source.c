#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int countStudents(FILE* fp, char* nameFile) { // סופרת כמה סטודנטים במערכת
	int count = 0;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		while (fgets(buff, 255, (FILE*)fp)) {
			count++;
		}
	}
	return count;
}

int AddClassRomArray(FILE* fp, char* nameFile) { // (hash)מכינה את המערך לספירת כיתות
	int power = 10;
	int max = INT_MIN;
	int newnum = 0, loc = 1, diff = 0, len;
	int* newarr = NULL;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		while (fgets(buff, 255, (FILE*)fp)) {
			len = strlen(buff);
			while (buff[len] < '0' || buff[len]>'9') {
				len--;

			}
			while (buff[len] >= '0' && buff[len] <= '9') {
				newnum += (buff[len] - '0') * loc;
				loc *= 10;
				len--;
			}
			while (buff[len] >= 'a' && buff[len] <= 'z') {
				diff = buff[len] - 96;
				len--;
			}
			if (max < ((power * power) * diff) + newnum) {
				max = ((power * power) * diff) + newnum;
			}
			newnum = 0;
			loc = 1;
		}
		newarr = calloc(max + 1, sizeof(int));

		return newarr;

	}
}
int countClassRoom(FILE* fp, char* nameFile) { // סופרת מספר כיתות
	int count = 0, i = 0, k = 0, j = 0;
	int newnum = 0, loc = 1, power = 10, diff = 0;
	int* arr = NULL;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		arr = AddClassRomArray(fp, nameFile);

		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		while (fgets(buff, 255, (FILE*)fp)) {

			int len = strlen(buff);
			while (buff[len] < '0' || buff[len]>'9') {
				len--;

			}
			while (buff[len] >= '0' && buff[len] <= '9') {
				newnum += (buff[len] - '0') * loc;
				loc *= 10;
				len--;
			}
			while (buff[len] >= 'a' && buff[len] <= 'z') {
				diff = buff[len] - 96;
				len--;
			}
			if (arr[((power * power) * diff) + newnum] == 0) {

				arr[((power * power) * diff) + newnum] = 1;
				count++;
			}
			newnum = 0;
			loc = 1;
			diff = 0;
		}

		return count;
	}
}
int amountStudentClass(FILE* fp, char* nameFile, char* class) { // סופרת כמה סטודנים בכיתה
	int* newarr = NULL;
	int newnum = 0, loc = 1;
	int power = 10, diff = 0, count = 0;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		newarr = AddClassRomArray(fp, nameFile);
		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		int len = strlen(class) - 1;
		while (class[len] >= '0' && class[len] <= '9') {
			newnum += (class[len] - '0') * loc;
			loc *= 10;
			len--;
		}
		diff = class[len] - 96;
		int index = ((power * power) * diff) + newnum;
		newnum = 0;
		loc = 1;
		diff = 0;
		while (fgets(buff, 255, (FILE*)fp)) {
			len = strlen(buff);
			while (buff[len] < '0' || buff[len]>'9') {
				len--;

			}
			while (buff[len] >= '0' && buff[len] <= '9') {
				newnum += (buff[len] - '0') * loc;
				loc *= 10;
				len--;
			}
			while (buff[len] >= 'a' && buff[len] <= 'z') {
				diff = buff[len] - 96;
				len--;
			}
			if ((((power * power) * diff) + newnum) == index) {
				count++;
			}
			newnum = 0;
			loc = 1;
			diff = 0;

		}

		return count;
	}
}
void printallStudent(FILE* fp, char* nameFile) { // מדפיסה את כל שמות הסטודנטים
	int j = 0;
	int power = 10, diff = 0, count = 1, len = 0;
	char* namestudent = NULL;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		while (fgets(buff, 255, (FILE*)fp)) {

			len = 0;
			while (buff[len] != '\t' && buff[len]) {
				namestudent = realloc(namestudent, sizeof(int) * count);
				namestudent[j] = buff[len];
				len++;
				j++;
				count++;
			}
			namestudent[j] = 0;
			printf("%s\n", namestudent);
			j = 0;
			count = 1;
		}

	}
}
void printallClass(FILE* fp, char* nameFile) { // מדפיסה את שמות כל הכיתןת
	int* arr = NULL, j = 0;
	int newnum = 0, loc = 1;
	int power = 10, diff = 0, count = 1;
	char* class = NULL;
	int len = 0, len2 = 0;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		arr = AddClassRomArray(fp, nameFile);
		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		while (fgets(buff, 255, (FILE*)fp)) {
			len = 0;
			len2 = strlen(buff);
			while (buff[len2] < '0' || buff[len2]>'9') {
				len2--;

			}
			while (buff[len2] >= '0' && buff[len2] <= '9') {
				newnum += (buff[len2] - '0') * loc;
				loc *= 10;
				len2--;
			}
			while (buff[len2] >= 'a' && buff[len2] <= 'z') {
				diff = buff[len2] - 96;
				len2--;
			}
			while (buff[len] != '\t' && buff[len]) {
				len++;
			}
			while (buff[len] == '\t' && buff[len])
				len++;
			while ((buff[len] >= 'a' && buff[len] <= 'z') && buff[len]) {
				class = realloc(class, sizeof(int) * count);
				class[j] = buff[len];
				len++;
				j++;
				count++;
			}
			class[j] = buff[len];
			j++;
			class[j] = 0;
			if (arr[((power * power) * diff) + newnum] == 0) {

				arr[((power * power) * diff) + newnum] = 1;
				printf("%s  ", class);
			}
			j = 0;
			count = 1;
			newnum = 0;
			loc = 1;
			diff = 0;
		}
		printf("\n");

	}

}
int printallstudentspclass(FILE* fp, char* nameFile, char* class) { // מספיסה את שמות הסטודנטים ולאיזה כיתה שייכים
	int* arr = NULL, j = 0;
	int newnum = 0, loc = 1;
	int power = 10, diff = 0, count = 1, count2 = 0;
	char* namestudent = NULL;
	int len = 0, len2 = 0;
	if (nameFile == NULL) {
		return -1;
	}
	else {
		char buff[255];
		arr = AddClassRomArray(fp, nameFile);
		fp = (fopen(nameFile, "r"));
		if (!fp)
		{
			printf("ERROR OPEN THe FILE\n");
			return 0;
		}
		len = strlen(class) - 1;
		while (class[len] >= '0' && class[len] <= '9') {
			newnum += (class[len] - '0') * loc;
			loc *= 10;
			len--;
		}
		diff = class[len] - 96;
		int index = ((power * power) * diff) + newnum;
		newnum = 0;
		loc = 1;
		diff = 0;
		while (fgets(buff, 255, (FILE*)fp)) {

			len = 0;
			len2 = strlen(buff);
			while (buff[len2] < '0' || buff[len2]>'9') {
				len2--;

			}
			while (buff[len2] >= '0' && buff[len2] <= '9') {
				newnum += (buff[len2] - '0') * loc;
				loc *= 10;
				len2--;
			}
			while (buff[len2] >= 'a' && buff[len2] <= 'z') {
				diff = buff[len2] - 96;
				len2--;
			}
			while (buff[len] != '\t' && buff[len]) {
				namestudent = realloc(namestudent, sizeof(int) * count);
				namestudent[j] = buff[len];
				len++;
				j++;
				count++;
			}
			namestudent[j] = 0;
			if ((((power * power) * diff) + newnum) == index) {
				count2++;
				if (count2 > 1)
					printf("%s\n", namestudent);
			}

			j = 0;
			count = 1;
			newnum = 0;
			loc = 1;
			diff = 0;
		}
		return count2;

	}
}
void list() { // מדפיסה את הרשימה
	printf("menu:\n");
	printf("\t\t\t1-amount of studnets\n");
	printf("\t\t\t2-amount of classrooms\n");
	printf("\t\t\t3-amount of students in specified classromm\n");
	printf("\t\t\t4-prints all students in the school\n");
	printf("\t\t\t5-prints all classrooms in the school\n");
	printf("\t\t\t6-prints all students of a specified classrooms\n");
	printf("\t\t\t7-quit\n");


}
int main() { // מחלקה ראשים
	FILE* fp;
	char buff[255];
	fp = (fopen("students.dat", "r"));
	if (!fp) exit(1);
	/*while (fgets(buff, 255, (FILE*)fp)) {
		printf("%s", buff);
	}
	*/
	/*printallClass(fp, "students.dat");*/
	/*printallstudentspclass(fp, "students.dat", "a3");*/
	/*printf("%d", amountStudentClass(fp, "students.dat","a1"));*/
	int quit = 0;
	int choose;
	char class[100];
	do {
		list();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("%d\n", countStudents(fp, "students.dat"));
			break;
		case 2:
			printf("%d\n", countClassRoom(fp, "students.dat"));
			break;
		case 3:
			scanf("%s", class);
			if (!amountStudentClass(fp, "students.dat", class)) {
				printf("the spcified classroom has no students.\n");
			}
			else {
				printf("%d \n", amountStudentClass(fp, "students.dat", class));
			}
			break;
		case 4:
			printallStudent(fp, "students.dat");
			break;
		case 5:
			printallClass(fp, "students.dat");
			break;
		case 6:
			scanf("%s", class);
			int count = printallstudentspclass(fp, "students.dat", class);
			if (count == 0) {
				printf("the spcified classroom has no students.\n");
			}
			break;
		case 7:
			quit = 1;
			break;
		default:
			printf("You cant choose this postion choose between 1-7\n");
			break;
		}
	} while (quit == 0);
	printf("Thank you for try this program\n");
	return 0;

}