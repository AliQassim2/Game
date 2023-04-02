#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main2()
{
    // srand(time(NULL));
    int input = 100;
    do
    {
        int ranumb, c = 0;
        ranumb = rand() % 100;
        cout << " guess the number...";
        cout << endl;

        while (input != ranumb)
        {
            cin >> input;

            if (input > ranumb) cout << "less..";
            else if (input < ranumb) cout << "larger..";
            cout << endl;
            c++;
        }
        cout << "You expected the number .. :" << ranumb <<
            ": you got it in .." << c << "  times" << endl;
        cout << " if you want continue input any number or -1 to stop ... " << endl;
        cin >> input;
    } while (input != -1);

    return 0;
}