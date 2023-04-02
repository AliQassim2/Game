#include<iostream>
#include <ctime>
#include <conio.h>
#include<Windows.h>
using namespace std;
enum Dir { Top=1,Down, Right,Left};
struct Map { int Widht, Height, FruitX, FruitY; };
struct Snake { int HeadX, HeadY, Tail_N; Dir dir; };
struct Player { int Score; bool Lose; };
Map map1; Snake snake1; Player player1;
void Generate() {
	srand(time(NULL));
	map1.FruitX = rand() % (map1.Widht - 2) + 1;
	map1.FruitY = rand() % (map1.Height - 2) + 1;
}
void setup() {

	map1.Widht = 50;
	map1.Height = 15;

	Generate();

	snake1.HeadX = map1.Widht /2;
	snake1.HeadY = map1.Height/2;
	snake1.Tail_N = 0;
	player1.Score = 0;
	player1.Lose = false;
} 
void Dear() {
	system("cls");
	int i,j;
	for (i = 0; i < map1.Height; i++) {
		for (j = 0; j < map1.Widht; j++) {
			if (i == 0 || i == map1.Height - 1)cout << "*";
			else if (j == 0 || j == map1.Widht - 1)cout << "*";
			else if (j == snake1.HeadX && i == snake1.HeadY)cout << "O";
			else if (j == map1.FruitX && i == map1.FruitY)cout << "$";
			else cout << " ";

		}
		cout << endl;
	}
	cout << "Player Score : " << player1.Score << endl;
}
void input(char x[4],char p) {
	if (_kbhit()) {

		
		char c = _getch();
		if (p == c)system("pause");
		if(c==x[0])snake1.dir = Top;
		if(c==x[1])snake1.dir = Right;
		if(c==x[2])snake1.dir = Down;
		if (c == x[3])snake1.dir = Left;
		/*switch (c)
		{
		case 'w':snake1.dir = Top;
			//break;
		case 'd':snake1.dir = Right; 
			break;
		case 's':snake1.dir = Down; 
			break;
		case 'a':snake1.dir = Left; 
			break;

		case 'x':exit(0);
		}*/
	}
}
void Move() {
	
	switch (snake1.dir)
	{
	case Top: snake1.HeadY--; break;
	case Left: snake1.HeadX--; break;
	case Down: snake1.HeadY++; break;
	case Right: snake1.HeadX++; break;
	}
	if (snake1.HeadY > map1.Height-2 || snake1.HeadY <= 0 ||
		snake1.HeadX > map1.Widht-2 || snake1.HeadX <= 0)
		player1.Lose = true;

	if (snake1.HeadY == map1.FruitY && snake1.HeadX == map1.FruitX) {
		Generate();
		player1.Score += 1;
		snake1.Tail_N++;
	}
}


int main() {
	char x[4]{},p;
	cin >> x[0] >> x[1] >> x[2] >> x[3];
	cin >> p;

	setup();
	while (!player1.Lose)
	{
	
	Dear();
	input(x,p);
	Move();
	Sleep(40);
	}
	system("pause");
	return 0;

}
