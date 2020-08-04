#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//LowHigh 게임을 통한 c언어 연습
//(컴퓨터가 1~100까지의 숫자를 정하고 이를 플레이어가 맞추는 게임)

//build과정
//1. 컴퓨터가 임의의 숫자를 선정
//2. 플레이어가 숫자 입력을 주면 해당 숫자보다 낮으면 "Low", 크면 "High"를 맞추면 "Okay"를 출력
//3. 숫자를 맞췄을 때, 몇 번의 시도만에 맞추었는지 표시

int main(void) {
	int num; //컴퓨터의 임의의 숫자
	int player; //플레이어의 선정 숫자
	int count = 0; // 몇 번의 시도를 했는지 카운트 해주는 변수

	printf(" < 1 ~ 100 > 까지의 숫자 중 원하는 숫자를 입력해 주세요! \n");


	//srand와 rand 함수를 이용해서 임의의 숫자를 받는 과정(범위 : 1 ~ 100)
	srand(time(NULL));
	num = rand() % 100 + 1;

	scanf("%d", &player);

	while (player != num)
	{
		if (num > player) {
			printf("정답은 더 커요. 다시 입력해주세요! \n");
			count = count + 1;
			scanf("%d", &player);
		}
		else if (num < player) {
			printf("정답은 더 작아요. 다시 입력해주세요! \n");
			count = count + 1;
			scanf("%d", &player);
		}
	}
	count = count + 1;
	printf("정답입니다. 해당 숫자는 %d 이고 시도 횟수는 %d 입니다. \n", num, count);


	system("pause");
	return 0;
}