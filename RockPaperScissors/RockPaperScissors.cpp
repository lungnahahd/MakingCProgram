#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Evan.h"



int g_playerscore = 0;
int g_comscore = 0;

//main함수 위에다 만들지 않으면 식별자 인식 못하는 오류 발생
void PlayGameVer1()
{
	int presult = 0;
	int cresult = 0;


	while (true) {
		printf("\n");
		printf("가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요! \n");
		Sleep(50);
		int player = 0;
		int com = 0;

		srand(time(NULL));
		com = rand() % 3 + 1;
		_getch();
		if (GetAsyncKeyState('1') & 0x8000) {
			player = 1;

		}
		else if (GetAsyncKeyState('2') & 0x8000) {
			player = 2;
		}
		else if (GetAsyncKeyState('3') & 0x8000) {
			player = 3;
		}
		else {
			player = 0;
		}
		if (player == 0) {
			srand(time(NULL));
			player = rand() % 3 + 1;
		}
		if (player == 1) {
			const char *showplayer = "가위";
			printf("플레이어 : %s \n", showplayer);
		}
		else if (player == 2) {
			const char *showplayer = "바위";
			printf("플레이어 : %s \n", showplayer);
		}
		else if (player == 3) {
			const char *showplayer = "보";
			printf("플레이어 : %s \n", showplayer);
		}
		if (com == 1) {
			const char *showcom = "가위";
			printf("컴퓨터 : %s \n", showcom);
		}
		else if (com == 2) {
			const char *showcom = "바위";
			printf("컴퓨터 : %s \n", showcom);
		}
		else if (com == 3) {
			const char* showcom = "보";
			printf("컴퓨터 : %s \n", showcom);
		}

		if (player == com) {
			printf("비겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
		}
		else if (player > com ) {
			if (player == 3 && com == 1) {
				cresult++;
				printf("졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
			else {
				presult++;
				printf("이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
		
		}
		else {
			if (player == 1 && com == 3) {
				presult++;
				printf("이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
			else {
				cresult++;
				printf("졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
			}
		}

		if (presult == 3) {
			printf("승리하셨습니다. (%d : %d) \n", presult, cresult);
			break;
		}
		else if (cresult == 3) {
			printf("패배하셨습니다. (%d : %d) \n", presult, cresult);
			break;
		}


	}
}

//배열을 이용한 가위바위보 알고리즘
void PlayGameVer2() {
	char result[3][3] = { {0,1,2},{2,0,1},{1,2,0} };
	char showresult[3][10] = { "무","패","승" };
	int player = 0;
	int com = 0;
	int fresult = 0;
	srand(time(NULL));
	while (true) {
		printf("가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요! \n");
		com = rand() % 3 + 1;
		_getch();
		if (GetAsyncKeyState('1') & 0x8000) {
			player = 1;

		}
		else if (GetAsyncKeyState('2') & 0x8000) {
			player = 2;
		}
		else if (GetAsyncKeyState('3') & 0x8000) {
			player = 3;
		}
		else {
			player = 0;
		}
		if (player == 0) {
			srand(time(NULL));
			player = rand() % 3 + 1;
		}
		fresult = result[player][com];
		printf("결과 : %s \n", showresult[fresult]);
	}

}
char showvs[5][30] =
{"□□□□■■",
 "□□□■□□",
 "■□■□■□",
 "■□■□□■",
 "□■□■■□"};




//가위, 바위, 보를 보여주는 3차식 배열
char hand[][10][50] = 
{
	
	{"□□□□□□□□□□",
	 "□□■■□■■□□□",
	 "□□■■□■■□□□",
	 "□□■■□■■□□□",
	 "□□■■■■■□□□",
	 "□□■■■■■■□□",
	 "□□■■■■■■□□",
	 "□□■■■■■■□□",
	 "□□□■■■■□□□",
	 "□□□■■■■□□□"},

	{"□□□□□□□□□□",
	 "□■■■■■■■□□",
	 "□■■■■■■■□□",
	 "□■■■■■■■□□",
	 "□■■■■■■■■□",
	 "□■■■■■■■■□",
	 "□■■■■■■■■□",
	 "□■■■■■■■■□",
	 "□□□■■■■□□□",
	 "□□□■■■■□□□"},
	
	{"□□□□□□□□□□",
	 "□□■□■□■□■□",
	 "□□■□■□■□■□",
	 "□□■□■□■□■□",
	 "□□■■■■■■■□",
	 "□□■■■■■■■□",
	 "□■■■■■■■■□",
	 "□■■■■■■■■□",
	 "□□□■■■■□□□",
	 "□□□■■■■□□□"},

	{"□□□□■■",
	 "□□□■□□",
	 "■□■□■□",
	 "■□■□□■",
	 "□■□■■□"}
};


//특정한 위치에 원하는 text를 출력하는 함수
void wantprint(int _x, int _y, const char* _text) 
{
	GotoXY(_x, _y);
	printf(_text);
}

//해당 위치에 가위, 바위, 보를 출력하는 함수
void showhand(int _x, int _y, int _xsize, int _ysize, char* _text)
{
	char* show = _text;

	for (int y = 0; y < _ysize; y++)
	{
		wantprint(_x, _y+y, show);
		show = show + _xsize;
	}
}





//게임 시작 화면
void GameStart()
{
	int user = 0;
	int com = 0;
	int blink = 1;
	
	while (true)
	{	
		Clear();
		wantprint(30, 5, "재미있는 컴퓨터와의 가위, 바위, 보 게임!!!");
		user = rand() % 3 + 1;
		com = rand() % 3 + 1;
		SetColor(0, 9);
		showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[user - 1]);
		SetColor(0, 12);
		showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
		SetColor(0, 2);
		if(blink == 1)
		{
			wantprint(40, 20, "PRESS ANY KEY...");
			blink = 2;
		}
		else
		{
			wantprint(40, 20, "                    ");
			blink = 1;
		}
		if(_kbhit())
		{
			_getch();
			break;
		}
		


		Sleep(500);
	}
}
//게임 화면 
void StartGame()
{
	int user = 0;
	int com = 0;
	int blink = 1;

	while (true)
	{
		Clear();
		wantprint(30, 5, "가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요!");
		user = rand() % 3 + 1;
		com = rand() % 3 + 1;
		SetColor(0, 9);
		showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[user - 1]);
		SetColor(0, 12);
		showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
		SetColor(0, 6);
		showhand(45, 15, sizeof(hand[3][0]), sizeof(hand[3]) / sizeof(hand[3][0]), (char*)hand[3]);
		
		SetColor(0, 15);
	
		if (_kbhit())
		{
			if (GetAsyncKeyState('1') & 0x8000) {
				user = 1;
				wantprint(20, 20, "가위");
				showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[0]);
			}
			else if (GetAsyncKeyState('2') & 0x8000) {
				user = 2;
				wantprint(20, 20, "바위");
				showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[1]);
			}
			else if (GetAsyncKeyState('3') & 0x8000) {
				user = 3;
				wantprint(20, 20, "보");
				showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[2]);
			}
			if (com == 1) {
				wantprint(80, 20, "가위");
				showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[0]);
			}
			else if (com == 2) {
				wantprint(80, 20, "바위");
				showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[1]);
			}
			else if (com == 3) {
				wantprint(80, 20, "보");
				showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[2]);
			}
			if (user == com) {
				GotoXY(40, 25);
				printf("이번 판은 비겼습니다.");
				showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[user - 1]);
				showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
				Sleep(1000);
				break;
			}
			else if (user > com) {
				if (user == 3 && com == 1) {
					g_comscore++;
					GotoXY(40, 25);
					printf("이번 판은 졌습니다.");
					showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[user - 1]);
					showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
					Sleep(1000);
					break;
				}
				else {
					g_playerscore++;
					GotoXY(40, 25);
					printf("이번 판은 이겼습니다.");
					showhand(15, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[user - 1]);
					showhand(65, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
					Sleep(1000);
					break;
				}

			}
			else {
				if (user == 1 && com == 3) {
					g_playerscore++;
					GotoXY(40, 25);
					printf("이번 판은 이겼습니다.");
					Sleep(1000);
					break;
				}
				else {
					g_comscore++;
					GotoXY(40, 25);
					printf("이번 판은 졌습니다.");
					Sleep(1000);
					break;
				}
			}
			
			if (_kbhit()) 
			{
				_getch();
			}
		}
		Sleep(500);
	}
}

void EndPage(int _player, int _computer)
{
	Clear();
	if (_kbhit())
	{
		_getch();
	}
	GotoXY(40, 20);
	printf("플레이어 : %d          VS           컴퓨터 : %d", _player, _computer);
	Sleep(500);
}




int main(void)
//구성 : 메인 화면 + 게임 화면 + 결과 화면
{
	GameStart();
	while (g_playerscore != 3 && g_comscore != 3)
	{
		StartGame();
		EndPage(g_playerscore,g_comscore);
	}
	GotoXY(40, 10);
	if (g_playerscore == 3) {
		printf("당신이 이겼습니다. 축하드립니다.\n");
	}
	else
	{
		printf("당신이 졌습니다. ㅋㅋㅋ \n");
	}

	system("pause");
	return 0;
}

