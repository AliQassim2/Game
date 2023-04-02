#include<iostream>
#include<Windows.h>
using namespace std;
char matrix[4][4] = { '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
char player = 'X';

void printmatrix() {
	system("cls");

	for (int i = 0; i < 4; i++) {
		cout << endl;

		for (int j = 0; j < 4; j++) { 
			cout << "\t";
			if ( matrix[i][j] != 'O' && matrix[i][j] != 'X') {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 7);
				cout << matrix[i][j] << " "; }
			else if ( matrix[i][j] != 'O' && matrix[i][j] == 'X') {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 4);
				cout <<  matrix[i][j] << " ";
			}
			else if ( matrix[i][j] == 'O' && matrix[i][j] != 'X') {
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(h, 6);
				cout << matrix[i][j] << " ";
			}
		}
		cout << endl;

	}
	cout << endl;
}
void play() {

	char pos;
	cout << "choose your position - player ( " << player << " ) :";
	cin >> pos;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)

			if (matrix[i][j] == pos) {
				
				matrix[i][j] = player;

				if (player == 'X') {
					player = 'O';
				}
				else {
					player = 'X';
				}
			}

}
char check_if(int counter) {
//rectangle [1] 

	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')return 'X';
	else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 'O';
	
	if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')return 'X';
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') return 'O';

	//rectangle [2]
	if (matrix[0][1] == 'X' && matrix[1][2] == 'X' && matrix[2][3] == 'X')return 'X';
	else if (matrix[0][1] == 'O' && matrix[1][2] == 'O' && matrix[2][3] == 'O') return 'O';

	if (matrix[0][3] == 'X' && matrix[1][2] == 'X' && matrix[2][1] == 'X')return 'X';
	else if (matrix[0][3] == 'O' && matrix[1][2] == 'O' && matrix[2][1] == 'O') return 'O';

	//rectangle [3]
	if (matrix[1][0] == 'X' && matrix[2][1] == 'X' && matrix[3][2] == 'X')return 'X';
	else if (matrix[1][0] == 'O' && matrix[2][1] == 'O' && matrix[3][2] == 'O') return 'O';

	if (matrix[0][3] == 'X' && matrix[1][2] == 'X' && matrix[2][1] == 'X')return 'X';
	else if (matrix[3][0] == 'O' && matrix[2][1] == 'O' && matrix[1][2] == 'O') return 'O';

	////rectangle [4]
	if (matrix[1][1] == 'X' && matrix[2][2] == 'X' && matrix[3][3] == 'X')return 'X';
	else if (matrix[1][1] == 'O' && matrix[2][2] == 'O' && matrix[3][3] == 'O') return 'O';

	if (matrix[1][3] == 'X' && matrix[2][2] == 'X' && matrix[3][1] == 'X')return 'X';
	else if (matrix[1][3] == 'O' && matrix[2][2] == 'O' && matrix[3][1] == 'O') return 'O';

	
	if (counter == 0)return 'Z';

	return '.';
}
char check_for_vertical() {
		int Xc = 0;
		int Oc = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[j][i] == 'X')Xc++;
			else if (matrix[j][i] == 'O')Oc++;
			if (Xc == 3 || Oc == 3) {
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0;
		Oc = 0;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 3; j++) {
			if (matrix[j][i] == 'X')Xc++;
			else if (matrix[j][i] == 'O')Oc++;
			if (Xc == 3 || Oc == 3) {
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0;
		Oc = 0;
	}

}
char check_for_Horizontal(int &counter) {
	int Xc = 0;
	int Oc = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] == 'X')Xc++;
			else if (matrix[i][j] == 'O')Oc++; 
			else counter++;
			if (Xc == 3 || Oc == 3) {
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0;
		Oc = 0;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 3; j++) {
			if (matrix[i][j] == 'X')Xc++;
			else if (matrix[i][j] == 'O')Oc++; 
			else counter++;
			if (Xc == 3 || Oc == 3) {
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0;
		Oc = 0;
	}
}
char whowin() {
	int  counter = 0 ;

	if (check_for_vertical() == 'X' || check_for_Horizontal(counter) == 'X') {
				return 'X';
			}
	if (check_for_vertical() == 'O' || check_for_Horizontal(counter) == 'O') {
		return 'O';
	}


	return check_if(counter);
	
}
void rester() {
	char matrix2[4][4] = { '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
				matrix[i][j] = matrix2[i][j];
			}
int main4() {
	int i=1,j=0;
	do {
		if (j % 2 == 0)player = 'X';
				else player = 'O';
		while (whowin() == '.') {
			printmatrix();
			play();
		}
		if (whowin() == 'Z')	cout << " Draw";
		else
			cout << "The Winner is Player (" << whowin() << ")";
		cout << "\n if want continuation enter positve number:";
		cin >> i;
		rester();
		j++;
	} while (i >= 0);

	return 0;
}