#include "menu.h"

App::App() {


	this->vsv = docTuFile(PATH);

	this->x = 50;
	this->y = 5;
	this->w = 20;
	this->h = 2;
	this->t_color = LIGHTCYAN;
	this->b_color = BLUE;
	this->b_color_sang = 75;
	this->yp_limit = 11;
	this->xp = this->x - 3;
	this->yp = this->y + 1;
	this->xcu = this->xp;
	this->ycu = this->yp;
	this->kt = true;
}

void App::tieu_de(int x, int y, int b_color)
{
	textcolor(b_color);
	gotoXY(35, 2);
	cout << "           Chuong trinh quan ly sinh vien            ";
}

void App::get_choice(int* choice)
{
	while (true)
	{
		if (kt == true)
		{
			// xoa dong khi di chuyen
			gotoXY(xcu, ycu);
			cout << "  ";
			xcu = xp;
			ycu = yp;
			gotoXY(xp, yp);
			cout << "->";
			kt = false; // chua nhay ki tu
		}

		if (_kbhit())
		{
			// bat phim
			char c = _getch();

			//-32 la nut cach
			if (c == SPACE)
			{
				kt = true;
				c = _getch();
				switch (c)
				{
				case UP:
					if (yp > y + 1)
						// Tang vi tri con tro
						yp -= 2;
					else
						// Dua vi tri con tro ve cuoi hang
						yp = y + yp_limit;
					break;
				case DOWN:
					if (yp < y + yp_limit)
						// Giam vi tri con tro
						yp += 2;
					else
						// Dua vi tri con tro ve dau hang
						yp = y + 1;
					break;
				}
				// di chuyen len xuong trong khoang (1 + (so hang - 1) * 2) o
			}

			if (c == ENTER)
			{
				gotoXY(xp, yp);
				*choice = yp;
				break;
			}
		}
	}
}

void App::main_menu()
{
	this->yp_limit = 11;

	tieu_de(x, y, b_color);
	box(x, y, w, h, t_color, b_color, "Them moi ho so");
	box(x, y + h, w, h, t_color, b_color, "In danh sach");
	box(x, y + 2 * h, w, h, t_color, b_color, "Sap xep");
	box(x, y + 3 * h, w, h, t_color, b_color, "Tim kiem");
	box(x, y + 4 * h, w, h, t_color, b_color, "Thong ke");
	box(x, y + 5 * h, w, h, t_color, b_color, "Thoat");
	sua_cot(x, y, 6);
}

void App::them_moi_ho_so()
{
	string maLop;
	string maSV;
	string hoTen;
	string ngaySinh;
	string DTB;
	int choice;

	this->yp_limit = 11; // 6 o

	box(x, y, w, h, t_color, 0, "Nhap ma lop");
	cout << endl;
	sua_cot(x, y, 1);
	gotoXY(x + 1, y + 1.5 * h);
	getline(cin, maLop);

	box(x, y + 2 * h, w, h, t_color, 0, "Ma SV");
	sua_cot(x, y + 2 * h, 1);
	gotoXY(x + 1, y + 3.5 * h);
	getline(cin, maSV);

	box(x, y + 4 * h, w, h, t_color, 0, "Ho va ten");
	sua_cot(x, y + 4 * h, 1);
	gotoXY(x + 1, y + 5.5 * h);
	getline(cin, hoTen);

	box(x, y + 6 * h, w, h, t_color, 0, "Ngay sinh");
	sua_cot(x, y + 6 * h, 1);
	gotoXY(x + 1, y + 7.5 * h);
	getline(cin, ngaySinh);

	box(x, y + 8 * h, w, h, t_color, 0, "Diem TB tich luy");
	sua_cot(x, y + 8 * h, 1);
	gotoXY(x + 1, y + 9.5 * h);
	getline(cin, DTB);

	xuatRaFile(this->vsv, PATH);
	SinhVien sv;
	// convert string to char*
	strcpy_s(sv.maLop, maLop.c_str());
	strcpy_s(sv.maSV, maSV.c_str());
	strcpy_s(sv.hoTen, hoTen.c_str());
	strcpy_s(sv.ngaySinh, ngaySinh.c_str());
	// convert string to float
	float fDTB = atof(DTB.c_str());
	sv.DTB = fDTB;
	this->vsv.push_back(sv);

	gotoXY(x - 10, y + 10.5 * h);
	cout << "Nhap thanh cong, enter de quay lai menu chinh";

	cin.get();
}





void App::in_danh_sach()
{
	//this->yp_limit = 1 + this->vsv.size() * 2;
	//int last_pos, choice;
	//int i;
	show(vsv);

	// for (i = 0; i < this->vsv.size(); i++)
	// {
	// 	string output;
	// 	box(x, y + i * h, w, h, t_color, b_color, output);
	// }

	// box(x, y + i * h, w, h, t_color, b_color, "Quay lai");
	// sua_cot(x, y, this->vsv.size() + 1);
	// last_pos = 4 + 2 * (i + 1);

	// do
	// {
	// 	get_choice(&choice);
	// 	if (choice == last_pos)
	// 	{
	// 		system("cls");
	// 		main_menu();
	// 	}
	// } while (choice != last_pos);

}

void App::sap_xep(vector<SinhVien>& sv1)
{
	int choice1 = 0;
	int choice2 = 0;
	showKieuSapXep(x, y, w, h, t_color, b_color);
	get_choice(&choice1);
	showLoaiSapXep(x, y, w, h, t_color, b_color);
	get_choice(&choice2);
	switch (choice1) {
	case FIRST: selectionSort(sv1, choice2); 
		show(sv1);
		break;
	case SECOND: 
		insertionSort(sv1, choice2);
		show(sv1);
		break;
	case THIRD: bubbleSort(sv1, choice2);
		show(vsv);
		break;
	case FOURTH: //vector<SinhVien> sv = sv1;
		quickSort(sv1, 0, sv1.size() - 1, choice2);
		show(vsv);
		//	outPut_comparative(sv1, sv, pointer_2_0);
		break;
	case FIFTH:
		clear();
		sap_xep(sv1);
		break;
	}

		
}

void App::tim_kiem() {

}
void App::thong_ke() {

}

void App::menu()
{
	ShowCur(0);

	main_menu();

	while (true)
	{
		int choice;
		get_choice(&choice);

		switch (choice)
		{
		case FIRST:
			system("cls");
			them_moi_ho_so();
			break;
		case SECOND:
			system("cls");
			in_danh_sach();
			break;
		case THIRD:
			system("cls");
			sap_xep(vsv);
			break;	
		case FOURTH:
			system("cls");
			tim_kiem();
			break;
		case FIFTH:
			system("cls");
			thong_ke();
			break;
		case SIXTH:
			exit(0);
			break;
		}
	}
}