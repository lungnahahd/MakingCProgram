#include <stdio.h>
#include <stdlib.h>
#include "Evan.h"

int main(void)
{
	int x = 15, y = 28;
	//콘솔창의 크기를 (30,30)으로 조정하는 Evan헤더의 함수
	SetConsoleSize(30, 30);

	while (true)
	{
		//별 그림의 잔상을 지워주는 역할 수행
		Clear();

		//왼,오른쪽 방향키의 입력을 받아서 해당 커서의 위치를 이동시키는 부분, &0x8000을 통해서 꾹 누르던지 한번 누르던지 모두 입력을 받을 수 있다.
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




		//커서의 위치를 변경하고 해당 위치에서 출력 동작 실행
		GotoXY(x, y);
		printf("☆");
		//커서가 while문을 돌면서 너무 빠르게 동작하는 것을 막기 위해 사용되는 코드
		Sleep(50);
	}

	system("pause");
	return 0;
}