#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main3() {

    string name[3];
    int s[3] = { 8,9,6 }, i = 0, x = 0, o;

    srand(time(NULL));
    o = time(NULL) % 3;

    for (int k = 0; k < 3; k++)
        cin >> name[k];


    while (i < 3)
    {
        srand(time(NULL));
        s[i] = time(NULL) % 3;

        cout << "o =" << o << " s=" << s[i] << endl;
        system("pause");
        cout << name[x] << endl;
        system("pause");
        if (s[0] == s[1])s[1];
        else if (s[0] != s[1] && (s[1] == s[2] || s[1] == s[0])) s[2];
        if (x == o)cout << "hunter \n";
        else cout << " servavel \n";
        s[i] = x;
        cout << s[i] << endl;
        i++;
        cout << "o =" << o << " s=" << s[i] << endl;


    }
    return 0;

}