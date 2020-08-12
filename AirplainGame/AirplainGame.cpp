#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Evan.h"
#define Max 30
#define BackColor 15

//연관성 있는 변수를 함께 관리해 줄 구조체
struct OBJECT
{
	int x = 0;
	int y = 0;
	bool Bcheck = false;
};


OBJECT Enemy[Max];

OBJECT Player;

OBJECT Bullet;

int score = 0;
bool endgame = true;
bool onoff = true;

void shot() {
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (!Bullet.Bcheck) {
			Bullet.x = Player.x;
			Bullet.y = Player.y;
			Bullet.Bcheck = true;
			onoff = true;
		}
	}
	if (onoff) {
		Bullet.y--;
		GotoXY(Bullet.x, Bullet.y);
		printf("↑");
		if (Bullet.y < 0) {
			onoff = false;
			Bullet.Bcheck = false;
		}
	}
}


void startSet() {
	OBJECT begin[Max];
	for (int i = 0; i < Max; i++) {
		Enemy[i].Bcheck = begin[i].Bcheck;
	}
	
}


void makeStar() {
	
	for (int i = 0; i < Max; i++) {
		if (!Enemy[i].Bcheck) {
			Enemy[i].x = rand() % 15 * 2;
			Enemy[i].y = 0;
			Enemy[i].Bcheck = true;
			break;
		}
	}
}

void showStar() {
	for (int i = 0; i < Max; i++) {
		if (Enemy[i].Bcheck) {
			GotoXY(Enemy[i].x, Enemy[i].y);
			printf("◆");
			Enemy[i].y++;
			if (Enemy[i].y > 28) 
			{
				Enemy[i].Bcheck = false;
				score++;
			}
			
		
		}
	}
}

void crush() {
	for (int i = 0; i < Max; i++) {
		if (Enemy[i].Bcheck && Enemy[i].x == Player.x && Enemy[i].y == Player.y) {
			endgame = false;
			GotoXY(Player.x, Player.y);
			printf("점수 : %d \n", score);	
		}
	}
}
void boom() 
{
	for (int i = 0; i < Max; i++) {
		if (Enemy[i].x == Bullet.x && Enemy[i].y == Bullet.y) {
			GotoXY(Bullet.x, Bullet.y);
			printf("▒");
			Enemy[i].Bcheck = false;
			onoff = false;
			Bullet.Bcheck = false;
		}
	}
}
void moveplayer() {
	
	// 입력을 받아서 해당 커서의 위치를 이동시키는 부분, & 0x8000을 통해서 꾹 누르던지 한번 누르던지 모두 입력을 받을 수 있다.
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			Player.x = Player.x - 2;
			if (Player.x < 0) {
				Player.x = 0;
			}
		}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		Player.y = Player.y - 2;
		if (Player.y < 0) {
			Player.y = 0;
		}

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		Player.y = Player.y + 2;
		if (Player.y > 28) {
			Player.y = 28;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		Player.x = Player.x + 2;
		if (Player.x > 28) {
			Player.x = 28;
		}
	}
}

void StartMenu() 
{
	while (_kbhit())
	{
		//입력은 받는데 화면에 보이지는 않는 함수
		//즉 여기서는 기존 입력을 모두 처리해서 없애주는 역할을 수행
		_getch();
	}
	while (true)
	{	
		score = 0;
		Clear();
		GotoXY(6, 10);
		printf("재밌는 비행기 게임");
		GotoXY(7, 20);
		printf("Press any Key...");
		GotoXY(13, 25);
		printf("Made By LUNGNAHA");

		//아무 버튼이나 누르면 게임을 시작하는 if문
		if (_kbhit()) {
			break;
		}
		Sleep(50);
	}
}

bool ContinueSelect()
{
	Clear();
	bool selectBut = true;
	while (selectBut) {
		GotoXY(6, 10);
		printf("SCORE : %d", score);
		GotoXY(6, 15);
		printf("한번 더?");
		GotoXY(6, 17);
		printf("Press Y / N");
		if (GetAsyncKeyState('Y') & 0x8000) {
			endgame = true;
			break;
		}
		else if (GetAsyncKeyState('N') & 0x8000) {
			endgame = false;
			break;
		}
		Sleep(50);
	}
	return endgame;

}

int main(void)
{
	Player.x = 14;
	Player.y = 28;
	boolean bullet = false;
	boolean onoff = false;
	
	//콘솔창의 크기를 (30,30)으로 조정하는 Evan헤더의 함수
	SetConsoleSize(30, 30);
	int bX = 0;
	int bY = 0;
	//제목을 설정해주는 함수
	SetTitle("비행기 게임");
	//배경색을 변경시켜주는 함수
	SetColor(BackColor, 0);

	StartMenu();
	Clear();
	

	srand(time(NULL));

	while (endgame)
	{
		//잔상을 지워주는 함수
		Clear();
		GotoXY(0, 0);
		printf("SCORE : %d", score);
		//적기를 만드는 함수
		makeStar();
		//적기를 보여주는 함수
		showStar();
		//플레이어를 움직이게 해주는 함수
		moveplayer();
		//충돌 시 동작 함수
		crush();
		if (!endgame) {
			ContinueSelect();
			if (!endgame) {
				system("pause");
				return 0;
			}
			else if (endgame) {
				Clear();
				Sleep(100);
				startSet();
				main();
			}
		}
		//총알이 발사되는 함수
		shot();
		//적을 격파하는 함수
		boom();
		

		//커서의 위치를 변경하고 해당 위치에서 출력 동작 실행
		GotoXY(Player.x, Player.y);
		printf("☆");
		//커서가 while문을 돌면서 너무 빠르게 동작하는 것을 막기 위해 사용되는 코드
		Sleep(50);

		
		
	}
	
	system("pause");
	return 0;
}