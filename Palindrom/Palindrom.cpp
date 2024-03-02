#include <iostream>
#include <string>

using namespace std;

bool is_palindrom(int n);
char n_to_char(short int n);

int main()
{
    setlocale(LC_ALL, "rus");

    while(true){
        int n = 0;

        wcout << L"\nВведите число:\n";
        cin >> n;
    
        wcout << L"Число " << n << " " << (is_palindrom(n) ? L"является палиндромом" : L"не является палиндромом") << endl;
    }
}

bool is_palindrom(int n) {
    string rnum = "";
    string lnum = "";

    while (n != 0) {
        rnum = rnum + n_to_char(n % 10);
        lnum = n_to_char(n % 10) + lnum;
     
        n = n / 10;
    }

    return rnum == lnum;
}

char n_to_char(short int n) {
    switch (n) {
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '0';
    }
}