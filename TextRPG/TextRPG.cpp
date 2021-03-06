﻿
#include <iostream>
#include <time.h>
#include <conio.h>
#define NAME_SIZE  32
#define DESCRIPTION 1024
#define BAG_SIZE 10
#define SWAP (a,b,type) do{type temp; temp = a; a = b; b = temp;} while(0)

using namespace std;
//메인 메뉴 분류
enum MAIN_MEUN
{
    MAM_NONE,
    MAM_MAP,
    MAM_STORE,
    MAM_INVENTORY,
    MAN_USING,
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
//상점 상품들에 대한 정보
struct g_GOODS
{
    char g_gname[NAME_SIZE];
    char g_gdes[DESCRIPTION];
    char g_geffect[DESCRIPTION];
    int g_money;
    int g_use;
    int g_realplus;
    bool g_put = false;

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
    int g_invencount;
    int g_liquidcount;
    struct g_GOODS g_bag[BAG_SIZE];
    g_GOODS g_liquid[BAG_SIZE];
    bool g_weapon = false;
    bool g_armor = false;
};
//플레이어 장비 착용 상태 내용
struct g_Wear
{
    g_GOODS g_weapon[BAG_SIZE];
    g_GOODS g_armor[BAG_SIZE];
    
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
        cout << "PRESS ENTER...";
        getchar();
        system("cls");
        g_PlayerInfo yourinfo = {};
        g_MonsterInfo enemyinfo[ENE_COUNT];
        g_Wear wearing = {};
        yourinfo.g_level = 1;
        yourinfo.g_exp = 0;
        yourinfo.g_money = 1000000;
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
            wgoods[1].g_use = 1;
            wgoods[1].g_realplus = 10;
            

            strcpy_s(wgoods[2].g_gname, "무거운 대리석 검");
            strcpy_s(wgoods[2].g_gdes, "들기는 힘들지만 엄청난 파괴력을 가졌다.");
            strcpy_s(wgoods[2].g_geffect, "공격력 + 30");
            wgoods[2].g_money = 50000;
            wgoods[2].g_use = 1;
            wgoods[2].g_realplus = 30;
            
            strcpy_s(wgoods[3].g_gname, "청룡의 검");
            strcpy_s(wgoods[3].g_gdes, "청룡의 힘을 지닌 절대 비기의 검");
            strcpy_s(wgoods[3].g_geffect, "공격력 + 50");
            wgoods[3].g_money = 70000;
            wgoods[3].g_use = 1;
            wgoods[3].g_realplus = 50;
            
            strcpy_s(agoods[1].g_gname, "야생동물의 가죽 옷");
            strcpy_s(agoods[1].g_gdes, "질긴 가죽으로 만들어 간단한 공격들을 흡수할 수 있다.");
            strcpy_s(agoods[1].g_geffect, "방어력 + 10");
            agoods[1].g_money = 30000;
            agoods[1].g_use = 2;
            agoods[1].g_realplus = 10;

            strcpy_s(agoods[2].g_gname, "단단한 청동 갑옷");
            strcpy_s(agoods[2].g_gdes, "청동으로 웬만한 공격들을 튕겨내 준다.");
            strcpy_s(agoods[2].g_geffect, "방어력 + 30");
            agoods[2].g_money = 50000;
            agoods[2].g_use = 2;
            agoods[2].g_realplus = 30;

            strcpy_s(agoods[3].g_gname, "현무의 등");
            strcpy_s(agoods[3].g_gdes, "현무의 힘을 지닌 절대 비기의 갑옷");
            strcpy_s(agoods[3].g_geffect, "방어력 + 50");
            agoods[3].g_money = 70000;
            agoods[3].g_use = 2;
            agoods[3].g_realplus = 50;

            strcpy_s(hlgoods[1].g_gname, "HP물약(소)");
            strcpy_s(hlgoods[1].g_gdes, "HP를 일정량 회복 시켜 준다.");
            strcpy_s(hlgoods[1].g_geffect, "HP + 50");
            hlgoods[1].g_money = 2000;
            hlgoods[1].g_use = 3;
            hlgoods[1].g_realplus = 50;


            strcpy_s(hlgoods[2].g_gname, "HP물약(대)");
            strcpy_s(hlgoods[2].g_gdes, "HP를 많이 회복 시켜 준다.");
            strcpy_s(hlgoods[2].g_geffect, "HP + 200");
            hlgoods[2].g_money = 5000;
            hlgoods[2].g_use = 3;
            hlgoods[2].g_realplus = 200;

            strcpy_s(hlgoods[3].g_gname, "주작의 축복");
            strcpy_s(hlgoods[3].g_gdes, "주작의 힘으로 HP를 전부 회복 시켜 준다.");
            strcpy_s(hlgoods[3].g_geffect, "MAX HP");
            hlgoods[3].g_money = 7000;
            hlgoods[3].g_use = 3;
            hlgoods[3].g_realplus = yourinfo.g_maxhp;

            strcpy_s(mlgoods[1].g_gname, "MP물약(소)");
            strcpy_s(mlgoods[1].g_gdes, "MP를 일정량 회복 시켜 준다.");
            strcpy_s(mlgoods[1].g_geffect, "MP + 50");
            mlgoods[1].g_money = 2000;
            mlgoods[1].g_use = 4;
            mlgoods[1].g_realplus = 50;

            strcpy_s(mlgoods[2].g_gname, "MP물약(대)");
            strcpy_s(mlgoods[2].g_gdes, "MP를 많이 회복 시켜 준다.");
            strcpy_s(mlgoods[2].g_geffect, "MP + 200");
            mlgoods[2].g_money = 5000;
            mlgoods[2].g_use = 4;
            mlgoods[2].g_realplus = 200;

            strcpy_s(mlgoods[3].g_gname, "백호의 축복");
            strcpy_s(mlgoods[3].g_gdes, "백호의 힘으로 MP를 전부 회복 시켜 준다.");
            strcpy_s(mlgoods[3].g_geffect, "MAX MP");
            mlgoods[3].g_money = 7000;
            mlgoods[3].g_use = 4;
            mlgoods[3].g_use = yourinfo.g_maxmp;

            system("cls");
            cout << "★★★★★★★★★★★★★★★★렁나하 게임★★★★★★★★★★★★★★★★★★★" << endl;
            cout << "1. 지도" << endl;
            cout << "" << endl;
            cout << "2. 상점" << endl;
            cout << "" << endl;
            cout << "3. 인벤토리" << endl;
            cout << "" << endl;
            cout << "4. 아이템 사용" << endl;
            cout << "" << endl;
            cout << "5. 게임 처음부터 다시 시작하기" << endl;
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
            if (main_select == MAN_USING)
            {
                while (true)
                {
                    system("cls");
                    cout << "★★★★★★★★★★★★★★★★너의 상태를 잘 살펴 보아리★★★★★★★★★★★★★★★★★★★★" << endl;
                    cout << "□□□□□□□■■■□□□□□□□□" << endl;
                    cout << "□□□□□□■■■■■□□□□□□□" << endl;
                    cout << "□□□□□■■■■■■■□□□□□□         1. 무기" << endl;
                    cout << "□□□□□□■■■■■□□□□□□□" << endl;
                    cout << "□□□□□□□■■■□□□□□□□□" << endl;
                    cout << "□□□□□□□□■□□□□□□□□□         2. 방어구" << endl;
                    cout << "□□■■■■■■■■■■■■■■□□" << endl;
                    cout << "□□■■■■■■■■■■■■■■□□" << endl;
                    cout << "□■□■■■■■■■■■■■■□■□         3. HP 물약" << endl;
                    cout << "□■□■■■■■■■■■■■■□■□" << endl;
                    cout << "□■□■■■■■■■■■■■■□■□" << endl;
                    cout << "□■□■■■■■■■■■■■■□■□         4. MP 물약" << endl;
                    cout << "□■□■■■■■■■■■■■■□■□" << endl;
                    cout << "□□□■■■■■■■■■■■■□□□" << endl;
                    cout << "□□□□□■□□□□□□■□□□□□         5.그만 하고 나가기!!! " << endl;
                    cout << "□□□□□■□□□□□□■□□□□□" << endl;
                    cout << "□□□■■■□□□□□□■■■□□□" << endl;
                    cout << "--------------------------------------------------------------------------------------" << endl;
                    cout << "확인하고 싶은 부분을 선택해주세요." << endl;
                    int select_body;
                    cin >> select_body;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    if (select_body == ST_EXIT) break;
                    if (select_body == ST_WEAPON) {
                        bool check_1 = false;
                        for (int i = 0; i < BAG_SIZE; i++) {
                            if (yourinfo.g_bag[i].g_use == 1 && yourinfo.g_bag[i].g_put == true) {
                                cout << "물건명 : " << yourinfo.g_bag[i].g_gname << endl;
                                cout << "효과 : " << yourinfo.g_bag[i].g_geffect << endl;
                                cout << "설명 : " << yourinfo.g_bag[i].g_gdes << endl;
                                cout << "---------------------------------------------------------------------------------------------" << endl;
                                cout << "1. 확인 완료!" << endl;
                                cout << "2. 장착 해제하기" << endl;
                                int select_choice_1;
                                cin >> select_choice_1;
                                if (select_choice_1 == 1) break;
                                if (select_choice_1 == 2) {
                                    yourinfo.g_bag[i].g_put = false;
                                    check_1 = true;
                                    break;
                                }
                            }
                        }
                        if (!check_1) {
                            cout << "현재 장착하고 있는 장비가 존재하지 않습니다." << endl;
                        } 
                        
                    }
                    if (select_body == ST_ARMOR) {
                        bool check_2 = false;
                        for (int i = 0; i < BAG_SIZE; i++) {
                            if (yourinfo.g_bag[i].g_use == 2 && yourinfo.g_bag[i].g_put == true) {
                                cout << "물건명 : " << yourinfo.g_bag[i].g_gname << endl;
                                cout << "효과 : " << yourinfo.g_bag[i].g_geffect << endl;
                                cout << "설명 : " << yourinfo.g_bag[i].g_gdes << endl;
                                cout << "---------------------------------------------------------------------------------------------" << endl;
                                cout << "1. 확인 완료!" << endl;
                                cout << "2. 장착 해제하기" << endl;
                                int select_choice_2;
                                cin >> select_choice_2;
                                if (select_choice_2 == 1) break;
                                if (select_choice_2 == 2) {
                                    yourinfo.g_bag[i].g_put = false;
                                    check_2 = true;
                                    break;
                                }
                            }
                        }
                        if (!check_2) {
                            cout << "현재 장착하고 있는 장비가 존재하지 않습니다." << endl;
                        }
                    }
                    if (select_body == ST_HPLIQUID) {
                        cout << "해당 장비는 소비용입니다. 장착하실 수 없습니다." << endl;

                    }
                    if (select_body == ST_MPLIQUID) {
                        cout << "해당 장비는 소비용입니다. 장착하실 수 없습니다." << endl;
                    }
                    system("pause");
                }
               
                

            }
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
                    if (enemyinfo[map_select].g_hp <= 0)
                    {
                        enemyinfo[map_select].g_hp = enemyinfo[map_select].g_maxhp;
                        yourinfo.g_exp = yourinfo.g_exp + enemyinfo[map_select].g_dropexp;
                        yourinfo.g_money = yourinfo.g_money + enemyinfo[map_select].g_dropmoney;
                        cout << enemyinfo[map_select].g_name << "을 처지했습니다." << endl;
                        cout << "" << endl;
                        cout << "당신이" << enemyinfo[map_select].g_dropmoney << " 렁머니와 " << enemyinfo[map_select].g_dropexp << " 경험치를 획득하였습니다." << endl;
                    }
                    else if (yourinfo.g_hp <= 0)
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
                    cout << "★★★★★★★★★★★★★★★★비밀리에 숨겨진 상점★★★★★★★★★★★★★★★★★★★★" << '\t' << "보유 렁머니:" << yourinfo.g_money << endl;
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
                        cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << '\t' << "보유 렁머니:" << yourinfo.g_money << endl;
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
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        switch (weapon_select)
                        {
                        case WP_1:
                            if (yourinfo.g_money < wgoods[1].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 무기 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "무기 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - wgoods[1].g_money;
                                yourinfo.g_bag[yourinfo.g_invencount] = wgoods[1];
                                yourinfo.g_invencount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << wgoods[1].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 무기 가방 상황 : " << yourinfo.g_invencount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_2:
                            if (yourinfo.g_money < wgoods[2].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 무기 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "무기 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - wgoods[2].g_money;
                                yourinfo.g_bag[yourinfo.g_invencount] = wgoods[2];
                                yourinfo.g_invencount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << wgoods[2].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 무기 가방 상황 : " << yourinfo.g_invencount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_3:
                            if (yourinfo.g_money < wgoods[3].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 무기 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "무기 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - wgoods[3].g_money;
                                yourinfo.g_bag[yourinfo.g_invencount] = wgoods[3];
                                yourinfo.g_invencount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★청룡의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << wgoods[3].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 무기 가방 상황 : " << yourinfo.g_invencount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        default:
                            break;
                        }
                        if (weapon_select == WP_EXIT) break;
                        break;
                    case ST_ARMOR :
                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << '\t' << "보유 렁머니:" << yourinfo.g_money << endl;
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
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        switch (armor_select)
                        {
                        case WP_1:
                            if (yourinfo.g_money < agoods[1].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 무기 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "무기 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - agoods[1].g_money;
                                yourinfo.g_bag[yourinfo.g_invencount] = agoods[1];
                                yourinfo.g_invencount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << agoods[1].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 무기 가방 상황 : " << yourinfo.g_invencount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_2:
                            if (yourinfo.g_money < agoods[2].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 무기 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "무기 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - agoods[2].g_money;
                                yourinfo.g_bag[yourinfo.g_invencount] = agoods[2];
                                yourinfo.g_invencount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << agoods[2].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 가방 상황 : " << yourinfo.g_invencount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_3:
                            if (yourinfo.g_money < agoods[3].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 무기 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "무기 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - agoods[3].g_money;
                                yourinfo.g_bag[yourinfo.g_invencount] = agoods[3];
                                yourinfo.g_invencount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★현무의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << agoods[3].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 무기 가방 상황 : " << yourinfo.g_invencount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        default:
                            break;
                        }
                        if (armor_select == WP_EXIT) break;
                        break;
                    case ST_HPLIQUID :
                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << '\t' << "보유 렁머니:" << yourinfo.g_money << endl;
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
                        cout << "무슨 주작의 기운을 얻고 싶은가?" << endl;
                        int hp_select;
                        cin >> hp_select;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        if (hp_select == WP_EXIT) break;
                        switch (hp_select)
                        {
                        case WP_1:
                            if (yourinfo.g_money < hlgoods[1].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_liquidcount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 물약 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "물약 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - hlgoods[1].g_money;
                                yourinfo.g_liquid[yourinfo.g_liquidcount] = hlgoods[1];
                                yourinfo.g_liquidcount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << hlgoods[1].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 물약 가방 상황 : " << yourinfo.g_liquidcount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_2:
                            if (yourinfo.g_money < hlgoods[2].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_liquidcount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 물약 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "물약 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - hlgoods[2].g_money;
                                yourinfo.g_liquid[yourinfo.g_liquidcount] = hlgoods[2];
                                yourinfo.g_liquidcount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << hlgoods[2].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 물약 가방 상황 : " << yourinfo.g_liquidcount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_3:
                            if (yourinfo.g_money < hlgoods[3].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_liquidcount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 물약 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "물약 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - hlgoods[3].g_money;
                                yourinfo.g_liquid[yourinfo.g_liquidcount] = hlgoods[3];
                                yourinfo.g_liquidcount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★주작의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << hlgoods[3].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 가방 상황 : " << yourinfo.g_liquidcount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        default:
                            break;
                        }
                        break;
                    case ST_MPLIQUID :
                        system("cls");
                        cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << '\t' << "보유 렁머니:" << yourinfo.g_money << endl;
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
                        cout << "무슨 백호의 기운을 얻고 싶은가?" << endl;
                        int mp_select;
                        cin >> mp_select;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        if (mp_select == WP_EXIT) break;
                        switch (mp_select)
                        {
                        case WP_1:
                            if (yourinfo.g_money < mlgoods[1].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_liquidcount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 물약 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "물약 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - mlgoods[1].g_money;
                                yourinfo.g_liquid[yourinfo.g_liquidcount] = mlgoods[1];
                                yourinfo.g_liquidcount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << mlgoods[1].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 물약 가방 상황 : " << yourinfo.g_liquidcount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_2:
                            if (yourinfo.g_money < mlgoods[2].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_liquidcount == 10)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 물약 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "물약 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - mlgoods[2].g_money;
                                yourinfo.g_liquid[yourinfo.g_liquidcount] = mlgoods[2];
                                yourinfo.g_liquidcount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << mlgoods[2].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 가방 상황 : " << yourinfo.g_liquidcount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        case WP_3:
                            if (yourinfo.g_money < mlgoods[3].g_money)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "현재 보유하신 렁머니로는 해당 물건을 구입할 수 없습니다." << endl;
                                cout << "전투를 통해 렁머니를 벌어서 다시 찾아주시기 바랍니다." << endl;
                            }
                            else if (yourinfo.g_invencount == 30)
                            {
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "안타깝지만 물약 가방에 크기가 가득차서 구매를 하실 수 없습니다." << endl;
                                cout << "물약 가방을 비워주시고 다시 찾아주시기 바랍니다." << endl;
                            }
                            else
                            {
                                yourinfo.g_money = yourinfo.g_money - mlgoods[3].g_money;
                                yourinfo.g_liquid[yourinfo.g_liquidcount] = mlgoods[3];
                                yourinfo.g_liquidcount++;
                                system("cls");
                                cout << "★★★★★★★★★★★★★★★★백호의 방★★★★★★★★★★★★★★★★★★★★" << endl;
                                cout << "문제 없이" << mlgoods[3].g_gname << "을 구입하였습니다." << endl;
                                cout << "현재 남은 잔액 : " << yourinfo.g_money << " 렁머니" << endl;
                                cout << "용사님의 물약 가방 상황 : " << yourinfo.g_liquidcount << " / 10" << endl;
                            }
                            system("pause");
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }

                }
            }
            if (main_select == MAM_INVENTORY)
            {
                while (true)
                {
                    system("cls");
                    cout << "★★★★★★★★★★★★★★★★용사님의 가방★★★★★★★★★★★★★★★★★★★★" << endl;
                    cout << "열어보고 싶은 가방을 선택해 주세요." << endl;
                    cout << "---------------------------------------------------------------------------------------------" << endl;
                    cout << "1. 무기 가방 ( " << yourinfo.g_invencount << " / 10 )" << endl;
                    cout << "2. 물약 가방 ( " << yourinfo.g_liquidcount << " / 10 )" << endl;
                    cout << "3. 나가기" << endl;
                    int select_kind;
                    cin >> select_kind;
                    cout << "" << endl;
                    if (select_kind == 3) break;

                    if (select_kind == 1) {
                        while (true)
                        {
                            int select_bag;
                            system("cls");
                            cout << "★★★★★★★★★★★★★★★★용사님의 무기 가방★★★★★★★★★★★★★★★★★★★★" << '\t' << "공간 :" << yourinfo.g_invencount << " / 10" << endl;
                            cout << "각 품목의 설명을 보려면 각 물건의 번호를 입력하시오." << endl;
                            cout << "가방을 그만 보려면 0번을 눌러 주세요." << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            cout << "01." << yourinfo.g_bag[0].g_gname << endl;
                            cout << "02." << yourinfo.g_bag[1].g_gname << endl;
                            cout << "03." << yourinfo.g_bag[2].g_gname << endl;
                            cout << "04." << yourinfo.g_bag[3].g_gname << endl;
                            cout << "05." << yourinfo.g_bag[4].g_gname << endl;
                            cout << "06." << yourinfo.g_bag[5].g_gname << endl;
                            cout << "07." << yourinfo.g_bag[6].g_gname << endl;
                            cout << "08." << yourinfo.g_bag[7].g_gname << endl;
                            cout << "09." << yourinfo.g_bag[8].g_gname << endl;
                            cout << "10." << yourinfo.g_bag[9].g_gname << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            cout << "확인하고 싶은 번호를 입력해주시기 바랍니다.(0번은 가방 닫기) : ";
                            cin >> select_bag;
                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1024, '\n');
                                continue;
                            }
                            select_bag--;
                            if (select_bag == -1) break;
                            else {
                                g_GOODS trash[BAG_SIZE] = {};
                                system("cls");
                                cout << "물건명 : " << yourinfo.g_bag[select_bag].g_gname << endl;
                                cout << "효과 : " << yourinfo.g_bag[select_bag].g_geffect << endl;
                                cout << "설명 : " << yourinfo.g_bag[select_bag].g_gdes << endl;
                                cout << "---------------------------------------------------------------------------------------------" << endl;
                                cout << "1. 나가기" << endl;
                                cout << "2. 물건 장착하기" << endl;
                                cout << "3. 물건 기부하기" << endl;
                                int select_item;
                                cin >> select_item;
                                if (cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1024, '\n');
                                    continue;
                                }
                                if (select_item == 1) continue;
                                else if (select_item == 2)
                                {
                                    switch (yourinfo.g_bag[select_bag].g_use)
                                    {
                                    case 1:
                                        if (yourinfo.g_weapon) {
                                            cout << "" << endl;
                                            cout << "---------------------------------------------------------------------------------------------" << endl;
                                            cout << "이미 착용중인 장비가 있습니다." << endl;
                                            cout << "1. 현재 장비로 바꾸기" << endl;
                                            cout << "2. 변경사항 없이 나가기" << endl;
                                            int select_w_weapon;
                                            cin >> select_w_weapon;
                                            if (select_w_weapon == 1) {
                                                yourinfo.g_maxattack = yourinfo.g_maxattack - wearing.g_weapon[1].g_realplus + yourinfo.g_bag[select_bag].g_realplus;
                                                yourinfo.g_minattack = yourinfo.g_minattack - wearing.g_weapon[1].g_realplus + yourinfo.g_bag[select_bag].g_realplus;
                                                cout << "변경이 완료되었습니다." << endl;
                                                cout << "공격력이 " << yourinfo.g_bag[select_bag].g_realplus - wearing.g_weapon[1].g_realplus << " 만큼 변경되었습니다." << endl;
                                                wearing.g_weapon[1] = yourinfo.g_bag[select_bag];
                                                system("pause");
                                                continue;
                                            }
                                            if (select_w_weapon == 2) continue;

                                        }
                                        else
                                        {
                                            yourinfo.g_weapon = true;
                                            wearing.g_weapon[1] = yourinfo.g_bag[select_bag];
                                            yourinfo.g_maxattack = yourinfo.g_maxattack + yourinfo.g_bag[select_bag].g_realplus;
                                            yourinfo.g_minattack = yourinfo.g_minattack + yourinfo.g_bag[select_bag].g_realplus;
                                            yourinfo.g_bag[select_bag].g_put = true;
                                            cout << "" << endl;
                                            cout << "---------------------------------------------------------------------------------------------" << endl;
                                            cout << "공격력이 " << yourinfo.g_bag[select_bag].g_realplus << " 만큼 상승했습니다." << endl;
                                            system("pause");
                                            continue;
                                        }
                                    case 2:
                                        if (yourinfo.g_armor) {
                                            cout << "" << endl;
                                            cout << "---------------------------------------------------------------------------------------------" << endl;
                                            cout << "이미 착용중인 장비가 있습니다." << endl;
                                            cout << "1. 현재 장비로 바꾸기" << endl;
                                            cout << "2. 변경사항 없이 나가기" << endl;
                                            int select_w_armor;
                                            cin >> select_w_armor;
                                            if (select_w_armor == 1) {
                                                yourinfo.g_maxdef = yourinfo.g_maxdef - wearing.g_armor[1].g_realplus + yourinfo.g_bag[select_bag].g_realplus;
                                                yourinfo.g_mindef = yourinfo.g_mindef - wearing.g_armor[1].g_realplus + yourinfo.g_bag[select_bag].g_realplus;
                                                cout << "변경이 완료되었습니다." << endl;
                                                cout << "방어력이 " << yourinfo.g_bag[select_bag].g_realplus - wearing.g_armor[1].g_realplus << " 만큼 변경되었습니다." << endl;
                                                wearing.g_armor[1] = yourinfo.g_bag[select_bag];
                                                system("pause");
                                                continue;
                                            }
                                            if (select_w_armor == 2) continue;

                                        }
                                        else
                                        {
                                            yourinfo.g_armor = true;
                                            wearing.g_armor[1] = yourinfo.g_bag[select_bag];
                                            yourinfo.g_maxdef = yourinfo.g_maxdef + yourinfo.g_bag[select_bag].g_realplus;
                                            yourinfo.g_mindef = yourinfo.g_mindef + yourinfo.g_bag[select_bag].g_realplus;
                                            yourinfo.g_bag[select_bag].g_put = true;
                                            cout << "" << endl;
                                            cout << "---------------------------------------------------------------------------------------------" << endl;
                                            cout << "방어력이 " << yourinfo.g_bag[select_bag].g_realplus << " 만큼 상승했습니다." << endl;
                                            system("pause");
                                            continue;
                                        }

                                    default:
                                        break;
                                    }
                                }
                                else if (select_item == 3) {
                                    yourinfo.g_bag[select_bag] = yourinfo.g_bag[yourinfo.g_invencount - 1];
                                    yourinfo.g_bag[yourinfo.g_invencount - 1] = trash[0];
                                    yourinfo.g_invencount--;
                                    continue;
                                }

                            }
                            system("pause");
                        }
                    }
                    if (select_kind == 2) {
                        while (true)
                        {
                            int select_bag;
                            system("cls");
                            cout << "★★★★★★★★★★★★★★★★용사님의 물약 가방★★★★★★★★★★★★★★★★★★★★" << '\t' << "공간 :" << yourinfo.g_liquidcount << " / 10" << endl;
                            cout << "각 품목의 설명을 보려면 각 물건의 번호를 입력하시오." << endl;
                            cout << "가방을 그만 보려면 0번을 눌러 주세요." << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            cout << "01." << yourinfo.g_liquid[0].g_gname << endl;
                            cout << "02." << yourinfo.g_liquid[1].g_gname << endl;
                            cout << "03." << yourinfo.g_liquid[2].g_gname << endl;
                            cout << "04." << yourinfo.g_liquid[3].g_gname << endl;
                            cout << "05." << yourinfo.g_liquid[4].g_gname << endl;
                            cout << "06." << yourinfo.g_liquid[5].g_gname << endl;
                            cout << "07." << yourinfo.g_liquid[6].g_gname << endl;
                            cout << "08." << yourinfo.g_liquid[7].g_gname << endl;
                            cout << "09." << yourinfo.g_liquid[8].g_gname << endl;
                            cout << "10." << yourinfo.g_liquid[9].g_gname << endl;
                            cout << "---------------------------------------------------------------------------------------------" << endl;
                            cout << "확인하고 싶은 번호를 입력해주시기 바랍니다.(0번은 가방 닫기) : ";
                            cin >> select_bag;
                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1024, '\n');
                                continue;
                            }
                            select_bag--;
                            if (select_bag == -1) break;
                            else {
                                g_GOODS trash[BAG_SIZE] = {};
                                system("cls");
                                cout << "물건명 : " << yourinfo.g_liquid[select_bag].g_gname << endl;
                                cout << "효과 : " << yourinfo.g_liquid[select_bag].g_geffect << endl;
                                cout << "설명 : " << yourinfo.g_liquid[select_bag].g_gdes << endl;
                                cout << "---------------------------------------------------------------------------------------------" << endl;
                                cout << "1. 나가기" << endl;
                                cout << "2. 물건 사용하기" << endl;
                                cout << "3. 물건 기부하기" << endl;
                                int select_item;
                                cin >> select_item;
                                if (cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1024, '\n');
                                    continue;
                                }
                                if (select_item == 1) continue;
                                else if (select_item == 2)
                                {
                                    switch (yourinfo.g_liquid[select_bag].g_use)
                                    {
                                    case 3:
                                        yourinfo.g_hp = yourinfo.g_hp + yourinfo.g_liquid[select_bag].g_realplus;
                                        if (yourinfo.g_hp > yourinfo.g_maxhp) yourinfo.g_hp = yourinfo.g_maxhp;
                                        cout << "" << endl;
                                        cout << "---------------------------------------------------------------------------------------------" << endl;
                                        cout << "HP가 " << yourinfo.g_liquid[select_bag].g_realplus << "만큼 상승했습니다." << endl;
                                        cout << "현재 HP : " << yourinfo.g_hp << endl;
                                        yourinfo.g_liquid[select_bag].g_realplus = 0;
                                        strcpy_s(yourinfo.g_liquid[select_bag].g_gname, "빈 병");
                                        strcpy_s(yourinfo.g_liquid[select_bag].g_geffect, "HP + 0");
                                        system("pause");
                                        continue;


                                    case 4:
                                        yourinfo.g_mp = yourinfo.g_mp + yourinfo.g_liquid[select_bag].g_realplus;
                                        if (yourinfo.g_mp > yourinfo.g_maxmp) yourinfo.g_mp = yourinfo.g_maxmp;
                                        cout << "" << endl;
                                        cout << "---------------------------------------------------------------------------------------------" << endl;
                                        cout << "MP가 " << yourinfo.g_liquid[select_bag].g_realplus << "만큼 상승했습니다." << endl;
                                        cout << "현재 MP : " << yourinfo.g_hp << endl;
                                        yourinfo.g_liquid[select_bag].g_realplus = 0;
                                        strcpy_s(yourinfo.g_liquid[select_bag].g_gname, "빈 병");
                                        strcpy_s(yourinfo.g_liquid[select_bag].g_geffect, "MP + 0");
                                        system("pause");
                                        continue;


                                    default:
                                        break;
                                    }
                                }
                                else if (select_item == 3) {
                                    yourinfo.g_liquid[select_bag] = yourinfo.g_liquid[yourinfo.g_liquidcount - 1];
                                    yourinfo.g_liquid[yourinfo.g_liquidcount - 1] = trash[0];
                                    yourinfo.g_liquidcount--;
                                    continue;
                                }
                                system("pause");
                        }
                        
                    }
                }
                
                
            }

        }
        
    }

}
}