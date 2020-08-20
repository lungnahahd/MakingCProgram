
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
//몬스터 리스트
enum ENEMYLIST
{
    ENE_NONE,
    ENE_GOBLINE,
    ENE_GOLEM,
    ENE_DRAGON,
    ENE_COUNT
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
    int g_hp;
    int g_maxmp;
    int g_mp;
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
    int g_hp;
    int g_maxmp;
    int g_mp;
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
        g_MonsterInfo enemyinfo[ENE_COUNT];
        yourinfo.g_level = 1;
        yourinfo.g_exp = 0;
        yourinfo.g_money = 10000;
        cout << "★★★★★★★★★★★★★★★너에 대해 말해보거라★★★★★★★★★★★★★★★★★★★★" << endl;
        cout << "이름이 무엇이가요 용사님?" << endl;
        cin.getline(yourinfo.g_name, NAME_SIZE - 1);
        

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
            yourinfo.g_maxattack = 15;
            yourinfo.g_minattack = 5;
            yourinfo.g_maxdef = 20;
            yourinfo.g_mindef = 10;
            yourinfo.g_maxhp = 500;
            yourinfo.g_hp = 500;
            yourinfo.g_maxmp = 200;
            yourinfo.g_mp = 200;
            break;
        case 2 :
            strcpy_s(yourinfo.g_stringjob, "노련한 궁수");
            yourinfo.g_maxattack = 20;
            yourinfo.g_minattack = 10;
            yourinfo.g_maxdef = 15;
            yourinfo.g_mindef = 5;
            yourinfo.g_maxhp = 400;
            yourinfo.g_hp = 400;
            yourinfo.g_maxmp = 300;
            yourinfo.g_mp = 300;
        case 3 :
            strcpy_s(yourinfo.g_stringjob, "베일에 가려진 법사");
            yourinfo.g_maxattack = 30;
            yourinfo.g_minattack = 20;
            yourinfo.g_maxdef = 10;
            yourinfo.g_mindef = 5;
            yourinfo.g_maxhp = 300;
            yourinfo.g_hp = 300;
            yourinfo.g_maxmp = 400;
            yourinfo.g_mp = 400;
        default:
            break;
        }
        
        strcpy_s(enemyinfo[1].g_name, "더러운 고블린");
        enemyinfo[1].g_maxattack = 5;
        enemyinfo[1].g_minattack = 1;
        enemyinfo[1].g_maxdef = 5;
        enemyinfo[1].g_mindef = 1;
        enemyinfo[1].g_maxhp = 300;
        enemyinfo[1].g_hp = 300;
        enemyinfo[1].g_maxmp = 100;
        enemyinfo[1].g_mp = 100;
        enemyinfo[1].g_level = 5;
        enemyinfo[1].g_dropexp = 300;
        enemyinfo[1].g_dropmoney = 500;

        strcpy_s(enemyinfo[2].g_name, "문지기 골렘");
        enemyinfo[2].g_maxattack = 400;
        enemyinfo[2].g_minattack = 30;
        enemyinfo[2].g_maxdef = 500;
        enemyinfo[2].g_mindef = 400;
        enemyinfo[2].g_maxhp = 1000;
        enemyinfo[2].g_hp = 1000;
        enemyinfo[2].g_maxmp = 500;
        enemyinfo[2].g_mp = 500;
        enemyinfo[2].g_level = 20;
        enemyinfo[2].g_dropexp = 1000;
        enemyinfo[2].g_dropmoney = 15000;

        strcpy_s(enemyinfo[3].g_name, "지옥의 드래곤");
        enemyinfo[3].g_maxattack = 1000;
        enemyinfo[3].g_minattack = 800;
        enemyinfo[3].g_maxdef = 900;
        enemyinfo[3].g_mindef = 800;
        enemyinfo[3].g_maxhp = 5000;
        enemyinfo[3].g_hp = 5000;
        enemyinfo[3].g_maxmp = 5000;
        enemyinfo[3].g_mp = 5000;
        enemyinfo[3].g_level = 50;
        enemyinfo[3].g_dropexp = 100000;
        enemyinfo[3].g_dropmoney = 50000;

                



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

        int map_select;
        if (main_select == MAM_MAP)
        {
            while (true)
            {
                system("cls");
                cout << "★★★★★★★★★★★★★★★난이도 선정★★★★★★★★★★★★★★★★★★★★★" << endl;
                cout << "1. 평화의 숲" << endl;
                cout << "2. 보이지 않는 위험" << endl;
                cout << "3. 죽음의 늪" << endl;
                cout << "어느 시련은 경험할 것이냐?" << endl;

                cin >> map_select;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                if (map_select == MPM_EXIT) break;
                while (yourinfo.g_hp > 0 || enemyinfo[map_select].g_hp > 0)
                {
                    srand(time(NULL));
                    int player_attack;
                    int enemy_attack;
                    int player_def;
                    int enemy_def;
                    int fight_select;

                    system("cls");
                    cout << "★★★★★★★★★★★★★★★시련의 길★★★★★★★★★★★★★★★★★★★★★" << endl;
                    cout << "---------------------------------플레이어------------------------------------------" << endl;
                    cout << "이름 : " << yourinfo.g_name << '\t' << "직업 : " << yourinfo.g_stringjob << '\t' << "LEVEL : " << yourinfo.g_level << endl;
                    cout << "HP : " << yourinfo.g_hp << '\t' << "MP : " << yourinfo.g_mp << endl;
                    cout << "공격력 : " << yourinfo.g_minattack << " ~ " << yourinfo.g_maxattack << '\t' << "방어력 : " << yourinfo.g_mindef << " ~ " << yourinfo.g_maxattack << endl;
                    cout << "경험치 : " << yourinfo.g_exp << '\t' << "렁머니 : " << yourinfo.g_money << endl;
                    cout << "---------------------------------몬스터------------------------------------------" << endl;
                    cout << "종류 : " << enemyinfo[map_select].g_name << '\t' << "LEVEL : " << enemyinfo[map_select].g_level << endl;
                    cout << "HP : " << enemyinfo[map_select].g_hp << '\t' << "MP : " << enemyinfo[map_select].g_mp << endl;
                    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<너의 선택은?>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
                    cout << "1. 공격" << endl;
                    cout << "2. 도망가기" << endl;
                    cin >> fight_select;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    if (fight_select == 1)
                    {
                        player_def = yourinfo.g_mindef + (rand() % (yourinfo.g_maxdef + 1));
                        enemy_def = enemyinfo[map_select].g_mindef + (rand() % (enemyinfo[map_select].g_maxdef + 1));
                        player_attack = (yourinfo.g_minattack + (rand() % (yourinfo.g_maxattack + 1))) - enemy_def;
                        enemy_attack = (enemyinfo[map_select].g_minattack + (rand() % (enemyinfo[map_select].g_maxattack + 1))) - player_def;
                        enemyinfo[map_select].g_hp = enemyinfo[map_select].g_hp - player_attack;
                        yourinfo.g_hp = yourinfo.g_hp - enemy_attack;
                    }
                    else if (fight_select) break;

                }
            }
            
            
        }
        
    }

    
}

