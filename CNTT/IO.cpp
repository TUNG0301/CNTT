#include "IO.h"

vector<SinhVien>docTuFile(string tenFile)
{
	vector<SinhVien> v;
	string input;

	ifstream ifs(tenFile);
	if (ifs.fail())
	{
		cout << "Loi doc file!" << endl
			<< endl;
		return v;
	}

	while (getline(ifs, input))
	{
		if (input.empty())
			continue;
		SinhVien sv;

		string maLop;
		string maSV;
		string hoTen;
		string ngaySinh;
		string DTB;

		istringstream iss(input);
		getline(iss, maLop, ';');
		getline(iss, maSV, ';');
		getline(iss, hoTen, ';');
		getline(iss, ngaySinh, ';');
		getline(iss, DTB);
		// convert string to char*
		strcpy_s(sv.maLop, maLop.c_str());
		strcpy_s(sv.maSV, maSV.c_str());
		strcpy_s(sv.hoTen, hoTen.c_str());
		strcpy_s(sv.ngaySinh, ngaySinh.c_str());
		// convert string to float
		float fDTB = atof(DTB.c_str());
		sv.DTB = fDTB;

		v.push_back(sv);
	}

	ifs.close();
	return v;
}
void xuatRaFile(vector<SinhVien>& v, string tenFile)
{
	ofstream ofs(tenFile);
	string output;

	if (ofs.fail())
	{
		cout << "Loi mo file!" << endl;
		return;
	}

	for (SinhVien& sv : v)
	{
		ofs << sv.maLop << ";";
		ofs << sv.maSV << ";";
		ofs << sv.hoTen << ";";
		ofs << sv.ngaySinh << ";";
		ofs << sv.DTB << endl;
	}

	ofs.close();
}


void drawing_frame(int Size)
{
	// 200 : goc duoi ben trai
	// 188 : goc duoi ben phai
	// 201 : goc tren ben trai
	// 187 : goc tren ben phai
	// 205 : duong ngang kep
	// 186 : duong goc kep
	// int Size = 5;
	/** Ve khung cho "DANH SACH SINH VIEN" *******************/
	SetColor(8);
	gotoXY(38, 0);
	printf("%c", 218);
	for (int i = 0; i < 42; i++)
		printf("%c", 196);
	printf("%c\n", 191);
	gotoXY(38, 1);
	printf("%c%42c\n", 179, 179);
	gotoXY(38, 1);
	printf("%c", 195);
	for (int i = 0; i < 42; i++)
		printf("%c", 196);
	gotoXY(38, 1);
	printf("%c%43c\n", 179, 179);
	gotoXY(38, 2);
	printf("%c", 192);
	for (int i = 0; i < 42; i++)
		printf("%c", 196);
	printf("%c", 217);
	SetColor(7);
	/*********************************************************/

	gotoXY(103, 2);
	cout << "(ESC) Exit";
	SetColor(14);
	gotoXY(51, 1);
	cout << "DANH SACH SINH VIEN";
	SetColor(7);

	/** Ve khung kep ben ngoai**********************************************/
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
	cout << "MA SINH VIEN";
	gotoXY(26, 4);
	cout << "MA LOP";
	gotoXY(47, 4);
	cout << "TEN SINH VIEN";
	gotoXY(96, 4);
	cout << "DIEM TRUNG BINH";
	gotoXY(76, 4);
	cout << "NGAY SINH";
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
	/************************************************************************/

	// gotoXY(0,20);
	// for (int i = 100 ; i < 255; i++) cout << i << ":" << char(i) << "\t\t";
}
void show(vector<SinhVien>& student_list)
{
	// system("cls");
	SetColor(7);
	// Ve khung theo so luong sinh vien
	drawing_frame(student_list.size());
	SinhVien st;
	int row = 6;
	int Size = student_list.size();
	// In thong tin tung sinh vien
	for (int i = 0; i < Size; i++)
	{
		st = student_list.at(i);

		gotoXY(9, row);
		cout << st.maLop;
		;
		gotoXY(26, row);
		cout << st.maSV;
		gotoXY(42, row);
		cout << st.hoTen;
		gotoXY(102, row);
		cout << st.DTB;

		gotoXY(74, row);
		cout << st.ngaySinh;

		row = row + 2;
	}
}

void clear() {
	COORD origin = { 0, 0 };
	unsigned long len;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned long size;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);


	GetConsoleScreenBufferInfo(handle, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(handle, TEXT(' '), size, origin, &len);
	FillConsoleOutputAttribute(handle, csbi.wAttributes, size, origin, &len);
	SetConsoleCursorPosition(handle, origin);
}
