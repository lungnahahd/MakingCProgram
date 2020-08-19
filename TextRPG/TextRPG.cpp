
#include <iostream>
#include <time.h>
#define NAME_SIZE  32

using namespace std;
//메인 메뉴 분류
enum MAIN_MEUN
{
    MAM_NONE,
    MAM_MAP,
    MAM_STORE,
    MAM_INVENTORY,
    MAM_EXIT
};
//난이도 분류
enum MAP_MENU
{
    MPM_NONE,
    MPM_EASY,
    MPM_NOMAL,
    MPM_HARD,
    MPM_EXIT
};
//직업 정보
enum JOB_LIST
{
    JOB_NONE,
    JOB_WARRIOR,
    JOB_ARCHER,
    JOB_MAGICION,
    JOB_EXIT
};
//플레이어에 대한 정보
struct g_PlayerInfo
{
    char g_name[NAME_SIZE];
    char g_stringjob[NAME_SIZE];
    int g_job;
    int g_maxattack;
    int g_minattack;
    int g_maxdef;
    int g_mindef;
    int g_maxhp;
    int g_minhp;
    int g_maxmp;
    int g_minmp;
    int g_exp;
    int g_level;
    int g_money;
};
//몬스터에 대한 정보
struct g_MonsterInfo
{
    char g_name[NAME_SIZE];
    int g_maxattack;
    int g_minattack;
    int g_maxdef;
    int g_mindef;
    int g_maxhp;
    int g_minhp;
    int g_maxmp;
    int g_minmp;
    int g_level;
    int g_dropmoney;
    int g_dropexp;
};


int main()
{
    
    while (true)
    {   
        system("cls");
        g_PlayerInfo yourinfo = {};
        cout << "★★★★★★★★★★★★★★★너에 대해 말해보거라★★★★★★★★★★★★★★★★★★★★" << endl;
        cout << "이름이 무엇이가요 용사님?" << endl;
        cin >> yourinfo.g_name;

        system("cls");
        cout << "★★★★★★★★★★★★★★★전생에 무슨 직업을 가지고 있었느냐?★★★★★★★★★★★★★★★★★★★★" << endl;
        cout << "1. 강인한 전사" << endl;
        cout << "2. 노련한 궁수" << endl;
        cout << "3. 베일에 가려진 법사" << endl;
        cout << "4. 이름 변경하기" << endl;
        cin >> yourinfo.g_job;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (yourinfo.g_job == 4) continue;
        
        switch (yourinfo.g_job)
        {
        case 1 :
            strcpy_s(yourinfo.g_stringjob, "강인한 기사");
            break;
        case 2 :
            strcpy_s(yourinfo.g_stringjob, "노련한 궁수");
        case 3 :
            strcpy_s(yourinfo.g_stringjob, "베일에 가려진 법사");
        default:
            break;
        }



        system("cls");
        cout << "★★★★★★★★★★★★★★★렁나하 게임★★★★★★★★★★★★★★★★★★★★" << endl;
        cout << "1. 지도" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 인벤토리" << endl;
        cout << "4. 나가기" << endl;
        cout << "용자여 원하는 게 무엇이냐?" << endl;


        int main_select;
        cin >> main_select;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (main_select == MAM_EXIT) break;

        if (main_select == MAM_MAP)
        {
            system("cls");
            cout << "★★★★★★★★★★★★★★★난이도 선정★★★★★★★★★★★★★★★★★★★★★" << endl;
            cout << "1. 평화의 숲" << endl;
            cout << "2. 보이지 않는 위험" << endl;
            cout << "3. 죽음의 늪" << endl;
            cout << "어느 시련은 경험할 것이냐?" << endl;

            int map_select;
            cin >> map_select;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (map_select == MPM_EXIT) break;

        }
    }

    
}

