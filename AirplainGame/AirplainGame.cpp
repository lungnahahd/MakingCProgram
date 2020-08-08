#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Evan.h"

#define Max 30

//연관성 있는 변수를 함께 관리해 줄 구조체
struct OBJECT
{
	int x = 0;
	int y = 0;
	bool Bcheck = false;
};

OBJECT Enemy[Max];

OBJECT Player;

int score = 0;

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
			printf("*");
			Enemy[i].y++;
			if (Enemy[i].y > 28) {
				Enemy[i].Bcheck = false;
				score++;

			}
		}
	}
}

int crush() {
	for (int i = 0; i < Max; i++) {
		if (Enemy[i].Bcheck && Enemy[i].x == Player.x && Enemy[i].y == Player.y) {
			GotoXY(Player.x, Player.y);
			printf("점수 : %d \n", score);
			system("pause");
			return 0;
		}
	}
}

int main(void)
{

	

	
	int x = 15, y = 28;
	boolean bullet = false;
	boolean onoff = false;
	
	//콘솔창의 크기를 (30,30)으로 조정하는 Evan헤더의 함수
	SetConsoleSize(30, 30);
	int bX = 0;
	int bY = 0;


	srand(time(NULL));

	while (true)
	{
		//별 그림의 잔상을 지워주는 역할 수행
		Clear();

		//별을 만드는 함수
		makeStar();

		//별을 보여주는 함수
		showStar();
		

		//입력을 받아서 해당 커서의 위치를 이동시키는 부분, &0x8000을 통해서 꾹 누르던지 한번 누르던지 모두 입력을 받을 수 있다.
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { 
			x--;
			if (x < 0) {
				x = 0;
			}
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			y--;
			if (y < 0) {
				y = 0;
			}
			
		}
		if(GetAsyncKeyState(VK_DOWN) & 0x8000) {
			y++;
			if (y > 28) {
				y =28;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { 
			x++;
			if (x > 28) {
				x = 28;
			}
		}
		//총알 발사 Ver 2
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			if (!bullet) {
				bX = x;
				bY = y;
				bullet = true;
				onoff = true;
			}	
		}
		

		
		//충돌 시 동작 함수
		crush();

		

		if (onoff) {
			bY--;
			GotoXY(bX, bY);
			printf("º");
			if (bY < 0) {
				onoff = false;
				bullet = false;
			}
		}
		

		




		//커서의 위치를 변경하고 해당 위치에서 출력 동작 실행
		GotoXY(x, y);
		printf("☆");
		//커서가 while문을 돌면서 너무 빠르게 동작하는 것을 막기 위해 사용되는 코드
		Sleep(50);

		
		//총알 발사 기능 구현 Ver 1
		/**if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			int bulX = x;
			int bulY = y;
			while (bulY != 0)
			{	
				Clear();
				bulY--;
				GotoXY(bulX, bulY);
				printf("^");
				if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
					x--;
					if (x < 0) {
						x = 0;
					}
				}
				if (GetAsyncKeyState(VK_UP) & 0x8000) {
					y--;
					if (y < 0) {
						y = 0;
					}

				}
				if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
					y++;
					if (y > 28) {
						y = 28;
					}
				}
				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					x++;
					if (x > 28) {
						x = 28;
					}
				}
				GotoXY(x, y);
				printf("☆");
				//Sleep(20);
			}
		}**/
	}
	
	system("pause");
	return 0;
}