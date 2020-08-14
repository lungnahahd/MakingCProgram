#include <windows.h>
#include <stdio.h>


//화면을 지우는 함수
void Clear(void)
{
	system("cls");
}

// 커서의 위치를 바꿔주는 함수(해당 위치에서 원하는 출력 등의 동작을 수행할 수 있다.
void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 콘솔 창의 제목을 변경하는 함수
void SetTitle(const char* _szConsoleName)
{
	SetConsoleTitle(_szConsoleName);
}

// 글자색, 배경색을 변경해주는 함수
//배경색 0 ~ 15, 글자색 0 ~ 15까지 16색 사용해서 변경하는 함수
void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	//배경색과 글자색을 동시에 설정하는 함수 - high 4bit:배경색, Low 4 bit : 글자색
	//0x00f0 이면 f은 흰색 배경 0은 검정 글씨
	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

//커서를 안보이게 하는 함수
void SetCursor(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	curInfor.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}
