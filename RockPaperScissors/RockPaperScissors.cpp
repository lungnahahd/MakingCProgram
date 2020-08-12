#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//main함수 위에다 만들지 않으면 식별자 인식 못하는 오류 발생
void PlayGameVer1()
{
	int presult = 0;
	int cresult = 0;


	while (true) {
		printf("가위(1), 바위(2), 보(3) 중에 하나를 선택하세요! \n");
		Sleep(50);
		int player = 0;
		int com = 0;
		/*int presult = 0;
		int cresult = 0;*/
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

		if (player == com) {
			printf("비겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
		}
		else if (player > com) {
			presult++;
			printf("이겼습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
		}
		else {
			cresult++;
			printf("졌습니다. 플레이어 = %d, 컴퓨터 = %d \n", presult, cresult);
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

//구성 : 메인 화면 + 게임 화면 + 결과 화면
int main(void)
{
	
	
	PlayGameVer1();

	system("pause");
	return 0;
}

