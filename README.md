# MakingCGame&Program
------------
## 제작 동기
> C언어 공부를 하는데 틀에 박혀 있는 코드를 공부하는 것보다 예전 부터 해보고 싶었던 콘솔창을 이용한 게임들을 만들어보면서 C언어 관련 부족한 부분을 공부하고 코딩 실력도 키워보고자
C언어 콘솔 게임 제작을 시작하게 되었습니다.
------------
## Low_High_Game
> 게임 설명
  + 게임 시작과 동시에 컴퓨터가 1~100 사이에 임의의 숫자를 선정하게됩니다.
  + 게임 플레이어가 1~100 사이에 숫자를 입력하면 컴퓨터가 임의의 숫자가 사용자 입력 숫자보다 큰지 작은지를 화면에 출력해 줍니다.
  + 게임 플레이어는 컴퓨터가 주는 힌트를 보고 컴퓨터가 정한 임의의 숫자를 맞출때까지 게임은 동일한 방식으로 진행됩니다.
  + 게임 플레이어가 임의의 숫자를 맞추게 되면 몇 번의 시도 후에 성공했는지 알려주면서 게임은 종료하게 됩니다.
 ------------
 > 헤더 파일
  + #include <stdio.h>
  + #include <stdlib.h>
  + #include <time.h>
 ------------
 ------------
 ## Airplain_Game
 > 게임 설명
  + 게임을 시작하면 적군이 콘솔 창 위에서 부터 내려오게 됩니다.
  + 플레이어는 방향키를 이용해서 플레이어의 비행기를 움직일 수 있습니다.
  + 또한 Spacebar를 이용해서 총알을 발사해서 적군을 격파할 수 있습니다. 
  + 자신이 피한 적군의 수가 카운트 되고 플레이어의 비행기가 적군과 부딪힌 경우 게임이 종료됩니다.
  + 게임이 종료되면 플레이어의 점수가 화면에 나타나고 다시 플레이할지 종료할지 선택하게됩니다.
------------
 > 헤더 파일
  + #include <stdio.h>
  + #include <stdlib.h>
  + #include <time.h>
  + #include <conio.h>
  + #include "Evan.h"
------------
------------
## Rock_Paper_Scissors_Game
> 게임 설명
  + 게임을 시작하면 플레이어는 가위(1), 바위(2), 보(3) 중에 하나를 선택하게 됩니다.
  + 플레이어가 선택한 순간 미리 가위, 바위, 보 중에 하나를 임의로 선정해 놓았던 컴퓨터가 해당 선택 결과를 출력합니다.
  + 플레이어와 컴퓨터의 선택 들을 통해 결정된 승 또는 패 또는 무의 결과를 화면에 출력합니다.
  + 이긴 쪽은 +1를 획득하고 비기면 둘 다 +0을 얻게 됩니다.
  + 게임은 플레이어나 컴퓨터가 3점을 얻을 때까지 진행되고 전체 결과가 화면에 출력되고 게임이 종료됩니다.
------------
 > 헤더 파일
  + include <stdio.h>
  + include <stdlib.h>
  + #include <time.h>
  + #include <windows.h>
  + #include <conio.h>
  + #include "Evan.h"
------------
------------
## Text_RPG_Game
> 게임 설명
  + 게임을 시작하면 먼저 이름과 원하는 직업을 선택하게 됩니다.
  + 플레이어 설정이 되면 메인 메뉴를 선택하게 됩니다.
  + 메인 메뉴 중 지도를 선택하면 거기서 난이도를 선택하고, 그에 맞는 몬스터들과 전투를 하게 되고, 전투에서 이길 시에는 돈과 경험치를 얻게 되고 반대로 질 경우는 돈과 경험치를 잃게 됩니다.
  + 메인 메뉴 중 상점을 선택하면 거기서 무기, 방어구, HP 물약, MP 물약을 구매 할 수 있게 됩니다.
  + 메인 메뉴 중 인벤토리를 선택하면 무기 가방과 물약 가방 중 하나를 선택하게 되고, 무기 가방에서는 상점에서 구입한 무기와 방어구를 확인할 수 있고 물약 가방에서는 HP와 MP 물약을 확인할 수 있으며 거기서 아이템 장착과 사용을 할 수 있으며 상세 설명도 확인할 수 있습니다.
  + 메인 메뉴 중 아이템 사용을 선택하면 현재 장착되어 있는 아이템을 직접 확인 할 수 있습니다.
  + 이런 식으로 계속 전투와 상점 등을 이용해 개인 캐릭터를 키우는 RPG게임 입니다.
------------
> 헤더 파일
  + #include <iostream>
  + #include <time.h>
  + #include <conio.h> 
------------
> 업데이트 예정
  + 일정 경험치가 축적되면 레벨업이 되면서 기본 능력치들의 증가를 구현 할 예정입니다.
  + 난이도 별 몬스터의 종류와 상점의 아이템 종류를 추가시킬 예정입니다.
  + 전투 중 기본 공격 외에도 각 직업군별 고유 스킬들을 구현시킬 예정입니다.
------------
------------
> #include "Evan.h"
  + 'Rock_Paper_Scissors_Game' 과 'Airplain_Game' 에서 공통적으로 사용하고 있는 사용자 정의 헤더 파일 설명
  + 해당 사용자 헤더 파일은 내부에 #include <windows.h> 와 #include <stdio.h> 두 가지 헤더 파일 사용하고 있습니다.
  
  + 화면을 지우는 함수
``` C++
    void Clear(void) 
    {
	    system("cls");
    }
```
+ 커서의 위치를 원하는 위치로 변경해서 동작할 수 있게 해주는 함수
``` C++
    void GotoXY(int x, int y)
    {
	    COORD pos = { x, y };
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }
```
+ 콘솔 창의 제목을 변경해주는 함수
``` C++
    void SetTitle(const char* _szConsoleName)
    {
	    SetConsoleTitle( _szConsoleName);
    }
```
+  글자색, 배경색 등을 변경할 수 있도록 도와주는 함수
    
``` C++
    void SetColor(unsigned char _BgColor, unsigned char _TextColor)
    {
	    if (_BgColor > 15 || _TextColor > 15) return;
	    unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
    }
```
+ 커서를 안 보이게 해주는 함수
``` C++
    void SetCursor(BOOL _bShow)
    {
	    CONSOLE_CURSOR_INFO curInfor;
	    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	    curInfor.bVisible = _bShow;
	    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
    }  
```
+ 콘솔 창의 크기를 원하는대로 수정할 수 있도록 해주는 함수
``` C++
    void SetConsoleSize(int _col, int _lines)
    { 
	    char setText[100];
	    sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	    system(setText);
    }
```
------------
------------     
## 느낀 점
> 책을 통해 얻는 것도 좋았지만, 실질적으로 여러 블로그나 유튜브 등을 통해서 필요한 부분에 정보를 얻고 스스로 찾아보면서 오히려 코딩에 대해서 더욱 친숙하게 접근할 수 있었던 계기가
되었던 것 같습니다. 또한 아주 간단하고 쉬운 게임이지만 실제로 게임을 만들어보는 과정을 거치면서 초기 계획 설정과 중간 문제점 수정, 제작 이후에 문제 관리나 기능 추가 등을 하면서
작게나마 프로젝트 과정을 잘 경험해 볼 수 있었던 것 같습니다. 또한 머리 속으로만 그려보면서 코딩했던 게임들이 눈 앞에 콘솔 창에서 구현되는 모습을 통해서 코딩의 재미를 더욱 느낄 수
 있었습니다. 그렇지만, 아는 것이 부족해 조금 더 크고 많은 기능을 담고 있는 게임을 구현해보지 못한 아쉬움도 많이 느꼈습니다.






