
#include <iostream>
#include <time.h>
#include <conio.h>
#define NAME_SIZE  32
#define DESCRIPTION 1024

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
//상점 리스트
enum STORELIST
{
    ST_NONE,
    ST_WEAPON,
    ST_ARMOR,
    ST_HPLIQUID,
    ST_MPLIQUID,
    ST_EXIT
};
enum WEAPON
{
    WP_NONE,
    WP_1,
    WP_2,
    WP_3,
    WP_EXIT
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
//상점 상품들에 대한 정보
struct g_GOODS
{
    char g_gname[NAME_SIZE];
    char g_gdes[DESCRIPTION];
    char g_geffect[DESCRIPTION];
    int g_money;
    
};


int main()
{
    
    while (true)
    {   
        system("cls");
        cout << "PRESS ENTER...";
        getchar();
        system("cls");
        g_PlayerInfo yourinfo = {};
        g_MonsterInfo enemyinfo[ENE_COUNT];
        yourinfo.g_level = 1;
        yourinfo.g_exp = 0;
        yourinfo.g_money = 10000;
        cout << "★★★★★★★★★★★★★★★★너에 대해 말해보거라★★★★★★★★★★★★★★★★★★★" << endl;
        cout << "이름이 무엇이가요 용사님?" << endl;
        cin.getline(yourinfo.g_name, NAME_SIZE - 1);
        

        system("cls");
        cout << "★★★★★★★★★★★★★★★★전생에 무슨 직업을 가지고 있었느냐?★★★★★★★★★★★★★★★★★★★" << endl;
        cout << "1. 강인한 전사" << endl;
        cout << "" << endl;
        cout << "2. 노련한 궁수" << endl;
        cout << "" << endl;
        cout << "3. 베일에 가려진 법사" << endl;
        cout << "" << endl;
        cout << "4. 이름 변경하기" << endl;
        cout << "" << endl;
        cout << "직업을 함 선택해 보거라" << endl;
        cin >> yourinfo.g_job;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (yourinfo.g_job == 4)
        {
           
            continue;
        }
        
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
        enemyinfo[1].g_maxattack = 10;
        enemyinfo[1].g_minattack = 5;
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
        enemyinfo[2].g_minattack = 300;
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

                

        while (true)
        {

            g_GOODS wgoods[ST_EXIT];
            g_GOODS agoods[ST_EXIT];
            g_GOODS hlgoods[ST_EXIT];
            g_GOODS mlgoods[ST_EXIT];
            strcpy_s(wgoods[1].g_gname, "초심자의 목검");
            strcpy_s(wgoods[1].g_gdes, "대충 만든 것처럼 보이지만 강인한 힘을 지녔다.");
            strcpy_s(wgoods[1].g_geffect, "공격력 + 10");
            wgoods[1].g_money = 30000;

            strcpy_s(wgoods[2].g_gname, "무거운 대리석 검");
            strcpy_s(wgoods[2].g_gdes, "들기는 힘들지만 엄청난 파괴력을 가졌다.");
            strcpy_s(wgoods[2].g_geffect, "공격력 + 30");
            wgoods[2].g_money = 50000;

            strcpy_s(wgoods[3].g_gname, "청룡의 검");
            strcpy_s(wgoods[3].g_gdes, "청룡의 힘을 지닌 절대 비기의 검");
            strcpy_s(wgoods[3].g_geffect, "공격력 + 50");
            wgoods[3].g_money = 70000;

            strcpy_s(agoods[1].g_gname, "야생동물의 가죽 옷");
            strcpy_s(agoods[1].g_gdes, "질긴 가죽으로 만들어 간단한 공격들을 흡수할 수 있다.");
            strcpy_s(agoods[1].g_geffect, "방어력 + 10");
            agoods[1].g_money = 30000;

            strcpy_s(agoods[2].g_gname, "단단한 청동 갑옷");
            strcpy_s(agoods[2].g_gdes, "청동으로 웬만한 공격들을 튕겨내 준다.");
            strcpy_s(agoods[2].g_geffect, "방어력 + 30");
            agoods[2].g_money = 50000;

            strcpy_s(agoods[3].g_gname, "현무의 등");
            strcpy_s(agoods[3].g_gdes, "현무의 힘을 지닌 절대 비기의 갑옷");
            strcpy_s(agoods[3].g_geffect, "방어력 + 50");
            agoods[3].g_money = 70000;

            strcpy_s(hlgoods[1].g_gname, "HP물약(소)");
            strcpy_s(hlgoods[1].g_gdes, "HP를 일정량 회복 시켜 준다.");
            strcpy_s(hlgoods[1].g_geffect, "HP + 50");
            hlgoods[1].g_money = 2000;
            
            strcpy_s(hlgoods[2].g_gname, "HP물약(대)");
            strcpy_s(hlgoods[2].g_gdes, "HP를 많이 회복 시켜 준다.");
            strcpy_s(hlgoods[2].g_geffect, "HP + 200");
            hlgoods[2].g_money = 5000;

            strcpy_s(hlgoods[3].g_gname, "주작의 축복");
            strcpy_s(hlgoods[3].g_gdes, "주작의 힘으로 HP를 전부 회복 시켜 준다.");
            strcpy_s(hlgoods[3].g_geffect, "MAX HP");
            hlgoods[3].g_money = 7000;

            strcpy_s(mlgoods[1].g_gname, "MP물약(소)");
            strcpy_s(mlgoods[1].g_gdes, "MP를 일정량 회복 시켜 준다.");
            strcpy_s(mlgoods[1].g_geffect, "MP + 50");
            mlgoods[1].g_money = 2000;

            strcpy_s(mlgoods[2].g_gname, "MP물약(대)");
            strcpy_s(mlgoods[2].g_gdes, "MP를 많이 회복 시켜 준다.");
            strcpy_s(mlgoods[2].g_geffect, "MP + 200");
            mlgoods[2].g_money = 5000;

            strcpy_s(mlgoods[3].g_gname, "백호의 축복");
            strcpy_s(mlgoods[3].g_gdes, "백호의 힘으로 MP를 전부 회복 시켜 준다.");
            strcpy_s(mlgoods[3].g_geffect, "MAX MP");
            mlgoods[3].g_money = 7000;

            system("cls");
            cout << "★★★★★★★★★★★★★★★★렁나하 게임★★★★★★★★★★★★★★★★★★★" << endl;
            cout << "1. 지도" << endl;
            cout << "" << endl;
            cout << "2. 상점" << endl;
            cout << "" << endl;
            cout << "3. 인벤토리" << endl;
            cout << "" << endl;
            cout << "4. 게임 처음부터 다시 시작하기" << endl;
            cout << "" << endl;
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
                    cout << "★★★★★★★★★★★★★★★★난이도 선정★★★★★★★★★★★★★★★★★★★★" << endl;
                    cout << "1. 평화의 숲" << endl;
                    cout << "" << endl;
                    cout << "2. 보이지 않는 위험" << endl;
                    cout << "" << endl;
                    cout << "3. 죽음의 늪" << endl;
                    cout << "" << endl;
                    cout << "4. 꼬리 내리고 도망가기" << endl;
                    cout << "" << endl;
                    cout << "어느 시련은 경험할 것이냐?" << endl;

                    cin >> map_select;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    if (map_select == MPM_EXIT) break;
                    while (yourinfo.g_hp > 0 && enemyinfo[map_select].g_hp > 0)
                    {
                        srand(time(NULL));
                        int player_attack;
                        int enemy_attack;
                        int player_def;
                        int enemy_def;
                        int fight_select;

                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★시련의 길★★★★★★★★★★★★★★★★★★★★" << endl;
                        cout << "---------------------------------플레이어------------------------------------------" << endl;
                        cout << "이름 : " << yourinfo.g_name << '\t' << "직업 : " << yourinfo.g_stringjob << '\t' << "LEVEL : " << yourinfo.g_level << endl;
                        cout << "HP : " << yourinfo.g_hp << '\t' << "MP : " << yourinfo.g_mp << endl;
                        cout << "공격력 : " << yourinfo.g_minattack << " ~ " << yourinfo.g_maxattack << '\t' << "방어력 : " << yourinfo.g_mindef << " ~ " << yourinfo.g_maxdef << endl;
                        cout << "경험치 : " << yourinfo.g_exp << '\t' << "렁머니 : " << yourinfo.g_money << endl;
                        cout << "" << endl;
                        cout << "---------------------------------몬스터------------------------------------------" << endl;
                        cout << "종류 : " << enemyinfo[map_select].g_name << '\t' << "LEVEL : " << enemyinfo[map_select].g_level << endl;
                        cout << "HP : " << enemyinfo[map_select].g_hp << '\t' << "MP : " << enemyinfo[map_select].g_mp << endl;
                        cout << "" << endl;
                        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<너의 선택은?>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
                        cout << "1. 공격" << endl;
                        cout << "" << endl;
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
                            if (player_attack <= 0) player_attack = 1;
                            if (enemy_attack <= 0) enemy_attack = 1;
                            enemyinfo[map_select].g_hp = enemyinfo[map_select].g_hp - player_attack;
                            yourinfo.g_hp = yourinfo.g_hp - enemy_attack;
                            cout << "" << endl;
                            cout << enemyinfo[map_select].g_name << "이 " << player_attack << "만큼 피해를 입었습니다." << endl;
                            cout << "" << endl;
                            cout << "당신이 " << enemy_attack << "만큼 피해를 입었습니다." << endl;
                            system("pause");
                        }
                        else if (fight_select) break;
                    }

                    system("cls");
                    cout << "★★★★★★★★★★★★★★★★전투 결과★★★★★★★★★★★★★★★★★★★★" << endl;
                    if (enemyinfo[map_select].g_hp < 0)
                    {
                        enemyinfo[map_select].g_hp = enemyinfo[map_select].g_maxhp;
                        yourinfo.g_exp = yourinfo.g_exp + enemyinfo[map_select].g_dropexp;
                        yourinfo.g_money = yourinfo.g_money + enemyinfo[map_select].g_dropmoney;
                        cout << enemyinfo[map_select].g_name << "을 처지했습니다." << endl;
                        cout << "" << endl;
                        cout << "당신이" << enemyinfo[map_select].g_dropmoney << " 렁머니와 " << enemyinfo[map_select].g_dropexp << " 경험치를 획득하였습니다." << endl;
                    }
                    else if (yourinfo.g_hp < 0)
                    {
                        yourinfo.g_hp = yourinfo.g_maxhp;
                        yourinfo.g_exp = yourinfo.g_exp - (yourinfo.g_exp / 10);
                        yourinfo.g_money = yourinfo.g_money - (yourinfo.g_money / 10);
                        if (yourinfo.g_exp < 0) yourinfo.g_exp = 0;
                        cout << "당신이 죽었습니다." << endl;
                        cout << "" << endl;
                        cout << (yourinfo.g_money / 10) << " 렁머니와 " << (yourinfo.g_exp) << " 경험치를 잃었습니다." << endl;
                    }
                    cout << "계속 모험하시겠습니까?" << endl;
                    cout << "" << endl;
                    cout << "1. 계속 모험을 이어나간다." << endl;
                    cout << "" << endl;
                    cout << "2. 나의 한계를 인정하고 그만한다." << endl;
                    int battle_after_select;
                    cin >> battle_after_select;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    if (battle_after_select != 1) break;


                }

            }
            if (main_select == MAM_STORE)
            {
                while (true)
                {   
                    system("cls");
                    cout << "★★★★★★★★★★★★★★★★비밀리에 숨겨진 상점★★★★★★★★★★★★★★★★★★★★" << endl;
                    cout << "1. 청룡의 무기 상점" << endl;
                    cout << "" << endl;
                    cout << "2. 현무의 방어구 상점" << endl;
                    cout << "" << endl;
                    cout << "3. 주작의 회복 상점" << endl;
                    cout << "" << endl;
                    cout << "4. 백호의 마나 상점" << endl;
                    cout << "" << endl;
                    cout << "5. 상점에서 나가기" << endl;
                    cout << "" << endl;
                    cout << "누구와 거래를 해볼 것이냐?" << endl;

                    int store_select;
                    cin >> store_select;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    if (store_select == ST_EXIT) break;
                    
                    
                    
                    switch (store_select)
                    {
                    case ST_WEAPON :
                        

                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                        cout << "" << endl;
                        cout << "1. " << wgoods[1].g_gname << endl;
                        cout << wgoods[1].g_gdes << endl;
                        cout << wgoods[1].g_geffect << endl;
                        cout << wgoods[1].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "2. " << wgoods[2].g_gname << endl;
                        cout << wgoods[2].g_gdes << endl;
                        cout << wgoods[2].g_geffect << endl;
                        cout << wgoods[2].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "3. " << wgoods[3].g_gname << endl;
                        cout << wgoods[3].g_gdes << endl;
                        cout << wgoods[3].g_geffect << endl;
                        cout << wgoods[3].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "4. 아니 어떤 것도 필요하지 않다. " << endl;
                        cout << "" << endl;
                        cout << "무슨 무기가 필요한가?" << endl;
                        int weapon_select;
                        cin >> weapon_select;
                        if (weapon_select == WP_EXIT) break;
                        
                        break;
                    case ST_ARMOR :
                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                        cout << "" << endl;
                        cout << "1. " << agoods[1].g_gname << endl;
                        cout << agoods[1].g_gdes << endl;
                        cout << agoods[1].g_geffect << endl;
                        cout << agoods[1].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "2. " << agoods[2].g_gname << endl;
                        cout << agoods[2].g_gdes << endl;
                        cout << agoods[2].g_geffect << endl;
                        cout << agoods[2].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "3. " << agoods[3].g_gname << endl;
                        cout << agoods[3].g_gdes << endl;
                        cout << agoods[3].g_geffect << endl;
                        cout << agoods[3].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "4. 아니 어떤 것도 필요하지 않다. " << endl;
                        cout << "" << endl;
                        cout << "무슨 방어를 얻고 싶은가?" << endl;
                        int armor_select;
                        cin >> armor_select;
                        if (armor_select == WP_EXIT) break;

                        break;
                    case ST_HPLIQUID :
                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                        cout << "" << endl;
                        cout << "1. " << hlgoods[1].g_gname << endl;
                        cout << hlgoods[1].g_gdes << endl;
                        cout << hlgoods[1].g_geffect << endl;
                        cout << hlgoods[1].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "2. " << hlgoods[2].g_gname << endl;
                        cout << hlgoods[2].g_gdes << endl;
                        cout << hlgoods[2].g_geffect << endl;
                        cout << hlgoods[2].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "3. " << hlgoods[3].g_gname << endl;
                        cout << hlgoods[3].g_gdes << endl;
                        cout << hlgoods[3].g_geffect << endl;
                        cout << hlgoods[3].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "4. 아니 어떤 것도 필요하지 않다. " << endl;
                        cout << "" << endl;
                        cout << "무슨 주작의 힘을 얻고 싶은가?" << endl;
                        int hp_select;
                        cin >> hp_select;
                        if (hp_select == WP_EXIT) break;
                        break;
                    case ST_MPLIQUID :
                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                        cout << "" << endl;
                        cout << "1. " << mlgoods[1].g_gname << endl;
                        cout << mlgoods[1].g_gdes << endl;
                        cout << mlgoods[1].g_geffect << endl;
                        cout << mlgoods[1].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "2. " << mlgoods[2].g_gname << endl;
                        cout << mlgoods[2].g_gdes << endl;
                        cout << mlgoods[2].g_geffect << endl;
                        cout << mlgoods[2].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "3. " << mlgoods[3].g_gname << endl;
                        cout << mlgoods[3].g_gdes << endl;
                        cout << mlgoods[3].g_geffect << endl;
                        cout << mlgoods[3].g_money << " 렁머니" << endl;
                        cout << "" << endl;
                        cout << "---------------------------------------------------------------------------------------------" << endl;
                        cout << "" << endl;
                        cout << "4. 아니 어떤 것도 필요하지 않다. " << endl;
                        cout << "" << endl;
                        cout << "무슨 백호의 힘을 얻고 싶은가?" << endl;
                        int mp_select;
                        cin >> mp_select;
                        if (mp_select == WP_EXIT) break;
                        break;
                    default:
                        break;
                    }

                }
            }

        }
        
    }

    
}

