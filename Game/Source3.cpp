#include<iostream>
#include<Windows.h>
using namespace std;
char matrixTop[3][3] = { {'a','b','c'}
,{'d','e','f'}
,{'g','h','i'}
};
char matrixMid[2][3] = { 
{'j','k','l'}
,{'m','n','o'}
};
char matrixBot[3][3] = { 

{'p','q','r'}
,{'s','t','u'}
,{'v','w','x'}
};
char FirstPlayer = 'X';
int x = 0;
void printmatrixTop() {
	for (int i = 0; i < 3; i++) {
		
		cout << "\t";
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k <= i && j==0; k++) cout << "    ";
			for (int k = 3; k> i && j == 1; k--) cout << "    ";
			for (int k = 2; k >= i && j == 2; k--) cout << "    ";

			cout << matrixTop[i][j];
			
			
		} cout << endl;

	}
}
void printmatrixMid() {cout << "\t    ";
	for (int i = 0; i < 2; i++) {
		
		for (int j = 0; j < 3; j++) {
			
			
			cout << matrixMid[i][j] << "   ";
		}
		if (i == 0)cout << "      ";
		else cout << endl;
	}
}
void printmatrixBot() {
	for (int i = 0; i < 3; i++) {
		cout << "\t";
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k <= i && j == 2; k++) cout << "    ";
			for (int k = 0; k <= i && j == 1; k++) cout << "    ";
			for (int k = 2; k >= i && j == 0; k--) cout << "    ";
			cout << matrixBot[i][j] ;
		}cout << endl;

	}
}
void printmatrixNew() {
	system("cls");

	printmatrixTop();
	printmatrixMid();
	printmatrixBot();
	
}
void Start() {

	char pos;
	
		cout << "choose your position - player ( " << FirstPlayer << " ) :";
		cin >> pos;
		x++;
		// Top 

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)

				if (matrixTop[i][j] == pos) {

					matrixTop[i][j] = FirstPlayer;

					if (FirstPlayer == 'X') {
						FirstPlayer = 'O';
					}
					else {
						FirstPlayer = 'X';
					}
				}

		//Mid 

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)

				if (matrixMid[i][j] == pos) {

					matrixMid[i][j] = FirstPlayer;

					if (FirstPlayer == 'X') {
						FirstPlayer = 'O';
					}
					else {
						FirstPlayer = 'X';
					}
				}

		// Bot 

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)

				if (matrixBot[i][j] == pos) {

					matrixBot[i][j] = FirstPlayer;

					if (FirstPlayer == 'X') {
						FirstPlayer = 'O';
					}
					else {
						FirstPlayer = 'X';
					}
				}
				
	
}

void Move33() {
	cout << " choose you p want move ";
	int cmp;
	cin >> cmp;

	cout << " where you want move :";
		int wmp;
	cin >> wmp;


}
int main5() {
	while (true) {
		printmatrixNew();
		if (x < 6)
			Start();
		else Move33();
			 
		
	}
	return 0;
}