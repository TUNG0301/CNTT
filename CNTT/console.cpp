#include "console.h"
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void gotoXY(int x, int y)
{
	COORD a;
	a.X = x;
	a.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void box(int x, int y, int w, int h,
    int t_color, int b_color, string nd)
{
    textcolor(b_color);
    for (int iy = y + 1; iy <= y + h - 1; iy++)
    {
        for (int ix = x + 1; ix <= x + w - 1; ix++)
        {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << nd;

    //==========ve vien=========
    textcolor(1);
    SetColor(t_color);
    if (h <= 1 || w <= 1)
    {
        // trong o phai co dong o giua
        return;
    }

    // chieu dai
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoXY(ix, y);
        cout << char(196); // ma ascii
        gotoXY(ix, y + h);
        cout << char(196);
    }

    // chieu rong
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoXY(x, iy);
        cout << char(179); // ma ascii
        gotoXY(x + w, iy);
        cout << char(179);
    }

    // sua cac goc
    gotoXY(x, y);
    cout << char(218);
    gotoXY(x + w, y);
    cout << char(191);
    gotoXY(x, y + h);
    cout << char(192);
    gotoXY(x + w, y + h);
    cout << char(217);
}

void sua_cot(int x, int y, int so_hang)
{
    for (int i = 1; i < so_hang; i++)
    {
        gotoXY(x, y + (i * 2));
        cout << char(195);
        gotoXY(x + 20, y + (i * 2));
        cout << char(180);
    }
}

void khung_so_luong(int Size) {
	SetColor(8);
	gotoXY(5, 3);
	printf("%c", 201);
	for (int i = 1; i < 108; i++)
		cout << char(205);
	printf("%c\n", 187);

	for (int i = 4; i < 5 + 2 * Size; i++)
	{
		gotoXY(5, i);
		printf("%c%108c\n", 186, 186);
	}

	gotoXY(5, 5 + 2 * Size);
	printf("%c", 200);
	for (int i = 1; i < 108; i++)
		cout << char(205);
	printf("%c\n", 188);
	/***********************************************************************/

	/** ve khung ghi cac loai thong tin *************************************/
	gotoXY(5, 5);
	printf("%c", 204);
	for (int i = 1; i < 108; i++)
		cout << char(205);
	printf("%c\n", 185);
	gotoXY(20, 3);
	cout << char(203);
	gotoXY(38, 3);
	cout << char(203);
	gotoXY(68, 3);
	cout << char(203);
	gotoXY(93, 3);
	cout << char(203);
	gotoXY(20, 4);
	printf("%c%18c%30c%25c", 186, 186, 186, 186); // cout << char(186);
	gotoXY(20, 5);
	cout << char(202);
	gotoXY(38, 5);
	cout << char(202);
	gotoXY(68, 5);
	cout << char(202);
	gotoXY(93, 5);
	cout << char(202);

	SetColor(14);
	gotoXY(7, 4);
	cout << "SO SV";
	gotoXY(7, 6);
	cout << "SO LUONG";
	gotoXY(7, 8);
	cout << "TI LE";
	gotoXY(26, 4);
	cout << "CNTT1";
	gotoXY(47, 4);
	cout << "CNTT2";
	gotoXY(76, 4);
	cout << "BDATTT";
	gotoXY(96, 4);
	cout << "ANHTTT";
	SetColor(7);
	/********************************************************************/

	/** Ve khung don ben trong ******************************************/
	SetColor(8);
	int row = 7;
	/* ve cac dong ngang don trong khung */
	for (int i = 1; i < Size; i++)
	{
		gotoXY(5, row);
		cout << char(199);
		for (int i = 1; i < 108; i++)
			printf("%c", 196);
		cout << char(182);
		row = row + 2;
	}
	/* Ve cac duong doc don trong khung */
	row = 6;
	for (int i = 1; i <= Size; i++)
	{
		gotoXY(20, row);
		printf("%c%18c%30c%25c", 179, 179, 179, 179);
		row = row + 1;
		gotoXY(20, row);
		cout << char(197);
		gotoXY(38, row);
		cout << char(197);
		gotoXY(68, row);
		cout << char(197);
		gotoXY(93, row);
		cout << char(197);
		row = row + 1;
	}
	row = row - 1;
	gotoXY(20, row);
	cout << char(207);
	gotoXY(38, row);
	cout << char(207);
	gotoXY(68, row);
	cout << char(207);
	gotoXY(93, row);
	cout << char(207);
	SetColor(7);
	gotoXY(103, 2);
	cout << "(ESC) Exit";
	while (true) {
		char c = _getch();
		if (c == 13)
			return;
	}
}

void khung_hoc_luc(int Size) {
	SetColor(8);
	gotoXY(5, 3);
	printf("%c", 201);
	for (int i = 1; i < 108; i++)
		cout << char(205);
	printf("%c\n", 187);

	for (int i = 4; i < 5 + 2 * Size; i++)
	{
		gotoXY(5, i);
		printf("%c%108c\n", 186, 186);
	}

	gotoXY(5, 5 + 2 * Size);
	printf("%c", 200);
	for (int i = 1; i < 108; i++)
		cout << char(205);
	printf("%c\n", 188);
	/***********************************************************************/

	/** ve khung ghi cac loai thong tin *************************************/
	gotoXY(5, 5);
	printf("%c", 204);
	for (int i = 1; i < 108; i++)
		cout << char(205);
	printf("%c\n", 185);
	gotoXY(20, 3);
	cout << char(203);
	gotoXY(38, 3);
	cout << char(203);
	gotoXY(68, 3);
	cout << char(203);
	gotoXY(93, 3);
	cout << char(203);
	gotoXY(20, 4);
	printf("%c%18c%30c%25c", 186, 186, 186, 186); // cout << char(186);
	gotoXY(20, 5);
	cout << char(202);
	gotoXY(38, 5);
	cout << char(202);
	gotoXY(68, 5);
	cout << char(202);
	gotoXY(93, 5);
	cout << char(202);

	SetColor(14);
	gotoXY(7, 4);
	cout << "HOC LUC";
	gotoXY(7, 6);
	cout << "SO LUONG";
	gotoXY(7, 8);
	cout << "TI LE";
	gotoXY(26, 4);
	cout << "GIOI";
	gotoXY(47, 4);
	cout << "KHA";
	gotoXY(76, 4);
	cout << "TB";
	gotoXY(96, 4);
	cout << "YEU";
	SetColor(7);
	/********************************************************************/

	/** Ve khung don ben trong ******************************************/
	SetColor(8);
	int row = 7;
	/* ve cac dong ngang don trong khung */
	for (int i = 1; i < Size; i++)
	{
		gotoXY(5, row);
		cout << char(199);
		for (int i = 1; i < 108; i++)
			printf("%c", 196);
		cout << char(182);
		row = row + 2;
	}
	/* Ve cac duong doc don trong khung */
	row = 6;
	for (int i = 1; i <= Size; i++)
	{
		gotoXY(20, row);
		printf("%c%18c%30c%25c", 179, 179, 179, 179);
		row = row + 1;
		gotoXY(20, row);
		cout << char(197);
		gotoXY(38, row);
		cout << char(197);
		gotoXY(68, row);
		cout << char(197);
		gotoXY(93, row);
		cout << char(197);
		row = row + 1;
	}
	row = row - 1;
	gotoXY(20, row);
	cout << char(207);
	gotoXY(38, row);
	cout << char(207);
	gotoXY(68, row);
	cout << char(207);
	gotoXY(93, row);
	cout << char(207);
	SetColor(7);
	gotoXY(103, 2);
	cout << "(ESC) Exit";
	while (true) {
		char c = _getch();
		if (c == 13)
			return;
	}
}