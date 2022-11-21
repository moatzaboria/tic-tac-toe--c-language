#include<stdio.h>
#include<stdlib.h>
#define N 3
char** board;
void intro() {
	printf("**********************************************\n");
	printf("Welcome My project this game is tic tac toe\n");
	printf("***********************************************\n");
	printf("\n");
}

void initEntries() { // גודל של לוח משחק וגם משלימה רווחים
	board = (char*)malloc(sizeof(int) * N);
	if (board == NULL)
	{
		printf("Error Allocate Memory\n");
		free(board);
		return;
	}
	for (int i = 0; i < N; i++) {
		board[i] = (char*)malloc(sizeof(int) * N);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = ' ';
		}
	}
}
void draw() { // מציירת המשחק
	int count = 1;
	char ch = 'A';
	for (int i = 0; i < N; i++) {
		if (i == 0)
			printf("  |");
		else
			printf("|");
		printf("%d", count);
		count++;
	}
	printf("|");
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%c ", ch);
		for (int j = 0; j < N; j++) {
			printf("|");
			printf("%c", board[i][j]);
		}
		printf("|");
		printf("\n");
		ch += 1;
	}
}
int winX() { // פונקציה בודקת אם אקס ניצח
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'X')
			{
				flag = 1;
			}
		}
		if (flag == 0)
			return 1;
		flag = 0;
	}
	flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[j][i] != 'X')
			{
				flag = 1;
			}
		}
		if (flag == 0)
			return 1;
		flag = 0;
	}
	flag = 0;
	for (int i = 0; i < N; i++) {
		if (board[i][i] != 'X')
			flag = 1;
	}
	if (flag == 0)
		return 1;
	flag = 0;
	for (int i = 0; i < N; i++) {
		if (board[i][N - i - 1] != 'X')
			flag = 1;
	}
	if (flag == 0)
		return 1;
	return 0;
}
int winO() { // פונקציה בודקת אם אוו ניצח
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 'O')
			{
				flag = 1;
			}
		}
		if (flag == 0)
			return 1;
		flag = 0;
	}
	flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[j][i] != 'O')
			{
				flag = 1;
			}
		}
		if (flag == 0)
			return 1;
		flag = 0;
	}
	flag = 0;
	for (int i = 0; i < N; i++) {
		if (board[i][i] != 'O')
			flag = 1;
	}
	if (flag == 0)
		return 1;
	flag = 0;
	for (int i = 0; i < N; i++) {
		if (board[i][N - i - 1] != 'O')
			flag = 1;
	}
	if (flag == 0)
		return 1;
	return 0;
}
int changeDirChar(char ch) { // מחליפה התווים לאינדקסים
	switch (ch)
	{
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	default:
		return -1;
		break;
	}
}
int CheckChar(char ch) { // בודקת אם התו נכון
	if (ch < 'A' || ch > 'C')
		return 0;
	return 1;
}
int Checknum(int num) { // בודקת שאין חריגה באינדקס
	if (num < 1 || num>3)
		return 0;
	return 1;
}
void Gameplay() { // פןנקציה קולטת מהמשתמש מיקום ומסמנת את האיקס או ה אוו
	int counter = 0;
	int flag = 0;
	int count = 0;
	do {
		draw();
		printf("Enter the Place \n");
		int num;
		char ch;
		flag = 0;
		scanf_s(" %c", &ch);
		scanf_s("%d", &num);
		if (CheckChar(ch) == 0)
			flag = 1;
		if (Checknum(num) == 0)
			flag = 1;
		if (flag == 1)
			printf("You Cant Choose this Place \n");
		if (flag == 0) {
			if (board[changeDirChar(ch)][num - 1] == ' ') {
				if (count % 2 == 0) {
					board[changeDirChar(ch)][num - 1] = 'X';
					count++;
					counter++;

				}
				else {
					board[changeDirChar(ch)][num - 1] = 'O';
					count++;
					counter++;
				}
			}
			else {
				printf("Invlaid input\n");
			}

		}
		if (winX() == 1) { // בודקת אם איקס ניצח
			counter--;
			draw();
			printf("The player X is win\n");
			break;
		}
		if (winO() == 1) { // בודקת אם או ניצח
			counter--;
			draw();
			printf("The player O is win\n");
			break;
		}
		
	} while (counter < N * N); // בודקת אם יש שוויון
	if (counter >= N * N) {
		printf("Tie\n");
	}
}
int main() {
	intro();
	initEntries();
	Gameplay();
	return 0;
}