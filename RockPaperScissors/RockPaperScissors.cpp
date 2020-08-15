#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Evan.h"

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
	 "□□□■■■■□□□"}
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



void PlayGameVer3()
{
	int presult = 0;
	int cresult = 0;
	int user;
	int player = 0;
	int com;
	bool stop = true;
	srand(time(NULL));



	while (true) {
		Clear();
		
		user = rand() % 3 + 1;
		com = rand() % 3 + 1;
		GotoXY(35, 2);
		printf("가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요! \n");
		GotoXY(35, 3);
		printf("플레이어 = %d, 컴퓨터 = %d", presult, cresult);
		

		if (_kbhit())
		{
			
			
			GotoXY(35, 2);
			printf("가위 < 1 >, 바위 < 2 >, 보 < 3 > 중에 하나를 선택하세요! \n");
			wantprint(20, 10, "플레이어 ");
			wantprint(70, 10, "컴퓨터 ");
			//Sleep(500);
			//_getch();
			if (GetAsyncKeyState('1') & 0x8000) {
				player = 1;
			}
			else if (GetAsyncKeyState('2') & 0x8000) {
				player = 2;
			}
			else if (GetAsyncKeyState('3') & 0x8000) {
				player = 3;
			}
			if (player == 1) {
				wantprint(40, 10, "가위");
				showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[0]);
			}
			else if (player == 2) {
				wantprint(40, 10, "바위");
				showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[1]);
			}
			else if (player == 3) {
				wantprint(40, 10, "보");
				showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[2]);
			}
			if (com == 1) {
				wantprint(80, 10, "가위");
				showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[0]);
			}
			else if (com == 2) {
				wantprint(80, 10, "바위");
				showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[1]);
			}
			else if (com == 3) {
				wantprint(80, 10, "보");
				showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[2]);
			}
			if (player == com) {
				GotoXY(35, 5);
				printf("이번 판은 비겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
				showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[player-1]);
				showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com-1]);
			}
			else if (player > com) {
				if (player == 3 && com == 1) {
					cresult++;
					GotoXY(35, 5);
					printf("이번 판은 졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
					showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[player - 1]);
					showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
				}
				else {
					presult++;
					GotoXY(35, 5);
					printf("이번 판은 이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
					showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[player - 1]);
					showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
				}

			}
			else {
				if (player == 1 && com == 3) {
					presult++;
					GotoXY(35, 5);
					printf("이번 판은 이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
				}
				else {
					cresult++;
					GotoXY(35, 5);
					printf("이번 판은 졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
				}
			}
			Sleep(1000);
			
			if (presult == 3) {
				Clear();
				GotoXY(35, 5);
				printf("승리하셨습니다. (%d : %d) \n", presult, cresult);
				break;
			}
			else if (cresult == 3) {
				Clear();
				GotoXY(35, 5);
				printf("패배하셨습니다. (%d : %d) \n", presult, cresult);
				break;
				
			}
			
		}
		while (_kbhit()) {
			_getch();
		}
		SetColor(0, 9);
		showhand(20, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[user - 1]);
		SetColor(0, 12);
		showhand(70, 15, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[com - 1]);
		wantprint(20, 10, "플레이어 ");
		wantprint(70, 10, "컴퓨터 ");
		wantprint(40, 27, "준비!! 시작 !!");
		Sleep(500);
		

	}
}


//구성 : 메인 화면 + 게임 화면 + 결과 화면
int main(void)
{
	
	

	

	PlayGameVer3();

	//showhand(10, 10, sizeof(hand[0][0]), sizeof(hand[0]) / sizeof(hand[0][0]), (char*)hand[0]);
	
	//PlayGameVer1();

	//PlayGameVer2();

	system("pause");
	return 0;
}

