
#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MEUN
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};


int main()
{
    while (true)
    {


        system("cls");

        cout << "1. 지도" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 인벤토리" << endl;
        cout << "4. 나가기" << endl;
        cout << "용사여 원하는 게 무엇이냐?  ";

        int select;
        cin >> select;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(2000, '\n');
            continue;
        }
        if (select == MM_EXIT) break;
    }
}

