#include "sapxep.h"



void swap(SinhVien& sv1, SinhVien& sv2)
{
	SinhVien temp = sv1;
	sv1 = sv2;
	sv2 = temp;
}

int Stoi(int i, int n, char arr[]) {
	int x = 0;
	int k = 1;
	for (int j = n; j > i; j--) {
		x = x + (arr[j] - 48) * k;
		k = k * 10;
	}
	return x;
}

void divideDate(int& day, int& month, int& year, char ns[])
{
	int count = 0, j = 0;
	for (int i = strlen(ns) - 1; i >= 0; i--)
	{
		if (ns[i] == '/' || i == 0) {
			count++;
			if (count == 1) year = Stoi(i, strlen(ns) - 1, ns);
			else if (count == 2) month = Stoi(i, j, ns);
			else if (count == 3) {
				day = Stoi(-1, j, ns);
			}
			j = i - 1;
		}
	}
}

int comparative_maSV(SinhVien sv1, SinhVien sv2)
{
	return strcmp(sv1.maSV, sv2.maSV);
}
int comparative_maLop(SinhVien sv1, SinhVien sv2)
{
	return strcmp(sv1.maLop, sv2.maLop);
}

int comparative_hoTen(SinhVien sv1, SinhVien sv2)
{
	return strcmp(sv1.hoTen, sv2.hoTen);
}

int comparative_ngaySinh(char* ns1, char* ns2)
{
	int day1, month1, year1, day2, month2, year2, key = 0;
	divideDate(day1, month1, year1, ns1);
	divideDate(day2, month2, year2, ns2);
	if (year1 > year2) key = 1;
	else if (year1 < year2) key = -1;
	else {
		if (month1 > month2) key = 1;
		else if (month1 < month2) key = -1;
		else {
			if (day1 > day2) key = 1;
			else if (day1 < day2) key = -1;
			else key = 0;
		}
	}
	return key;
}

int comparative_DTB(SinhVien sv1, SinhVien sv2)
{
	if (sv1.DTB > sv2.DTB) return 1;
	else return -1;
}
/*
void outPut_comparative(vector<SinhVien>& sv1, vector<SinhVien>& sv, int pointer)
{
	clear();
	int page = 0;
	if (sv.size() == 0) listEmpty();
	else
	{
		int head = 0, end = 9;
		if (end > sv.size() - 1)
		{
			end = sv.size() - 1;
		}
		printListComparative(sv, head, end, page, pointer);
		while (1)
		{
			if (kbhit)
			{
				char c = getch();
				if (c == 77)
				{
					page++, head += 10; end += 10;
					if (end > sv.size() - 1)
					{
						if (head < sv.size()) end = sv.size() - 1;
						else {
							head = 0; end = 9; page = 0;
							if (end > sv.size() - 1) end = sv.size() - 1;// truong hop chi co mot trang

						}
					}
					printListComparative(sv, head, end, page, pointer);
				}
				else if (c == 75)
				{
					page--; head -= 10; end -= 10;
					if (head < 0)
					{
						end = sv.size() - 1;
						head = end - end % 10;
						page = (sv.size() - 1) / 10;
					}
					else if (end % 10 < 9)
					{
						end = (end / 10) * 10 + 9;
					}
					printListComparative(sv, head, end, page, pointer);
				}
				else if (c == 27)
				{
					clear();
					Menu(sv1);
				}
			}
		}
	}
}
*/
// sap xep chon 


void selectionSort(vector<SinhVien> &sv1,int selection)
{
	//vector<SinhVien> sv = sv1;
	for (int i = 0; i < sv1.size(); i++){
		for (int j = i + 1; j < sv1.size(); j++)
		{
			int key = 0;
			//App::get_choice(&choice);
			switch (selection) {
			case 6: key = comparative_maSV(sv1[i], sv1[j]); break;
			case 8: key = comparative_hoTen(sv1[i], sv1[j]); break;
			case 10: key = comparative_ngaySinh(sv1[i].ngaySinh, sv1[j].ngaySinh); break;
			case 12: key = comparative_DTB(sv1[i], sv1[j]); break;
			case 14: showKieuSapXep(50, 5, 20, 2, 11, 1);
			}
			if (key > 0) swap(sv1[i], sv1[j]);
		}
	}
	//outPut_comparative(sv1, sv, selection);
}

// sap xep noi bot 
void bubbleSort(vector<SinhVien>& sv, int selection)
{
	
	for (int i = sv.size() - 1; i > -1; i--)
		for (int j = 0; j < i; j++)
		{
			int key = 0;
			switch (selection)
			{
			case 6: key = comparative_maSV(sv[j], sv[j + 1]); break;
			case 8: key = comparative_hoTen(sv[j], sv[j + 1]); break;
			case 10: key = comparative_ngaySinh(sv[j].ngaySinh, sv[j + 1].ngaySinh); break;
			case 12: key = comparative_DTB(sv[j], sv[j + 1]); break;
			}
			if (key > 0)swap(sv[j], sv[j + 1]);


		}
	//outPut_comparative(sv1, sv, selection);
}

void insertionSort(vector<SinhVien>& sv, int selection)
{
	//vector<SinhVien> sv = sv1;
	for (int i = 0; i < sv.size(); i++)
		for (int j = i; j > 0; j--) {
			int key = 0;
			switch (selection)
			{
			case 6: key = comparative_maSV(sv[j - 1], sv[j]); break;
			case 8: key = comparative_hoTen(sv[j - 1], sv[j]); break;
			case 10: key = comparative_ngaySinh(sv[j - 1].ngaySinh, sv[j].ngaySinh); break;
			case 12: key = comparative_DTB(sv[j - 1], sv[j]); break;
			}
			if (key > 0) swap(sv[j - 1], sv[j]);
		}
	//outPut_comparative(sv1, sv, selection);
}

void quickSort(vector<SinhVien>& sv, int h, int l, int selection)
{
	if (h < l)
	{
		int i = h - 1;
		SinhVien k = sv[l];
		for (int j = h; j < l; j++)
		{
			switch (selection)
			{
			case 6: if (comparative_maSV(sv[j], k) < 0) {
				i++;
				swap(sv[i], sv[j]);
				break;
			}
			case 8: if (comparative_hoTen(sv[j], k) < 0) {
				i++;
				swap(sv[i], sv[j]);
				break;
			}
			case 10: if (comparative_ngaySinh(sv[j].ngaySinh, k.ngaySinh) < 0) {
				i++;
				swap(sv[i], sv[j]);
				break;
			}
			case 12: if (comparative_DTB(sv[j], k) < 0) {
				i++;
				swap(sv[i], sv[j]);
				break;
			}
			
			}
		}
		swap(sv[i + 1], sv[l]);
		int p = i + 1;
		quickSort(sv, h, p - 1, selection);
		quickSort(sv, p + 1, l, selection);
	}
}

void showKieuSapXep(int x,int y,int w, int h, int t_color, int b_color) {
	box(x, y, w, h, t_color, b_color, "Sap xep chon");
	box(x, y + h, w, h, t_color, b_color, "Sap xep chen");
	box(x, y + 2 * h, w, h, t_color, b_color, "Sap xep noi bot");
	box(x, y + 3 * h, w, h, t_color, b_color, "Quicksort");
	box(x, y + 4 * h, w, h, t_color, b_color, "Quay lai");
}

void showLoaiSapXep(int x, int y, int w, int h, int t_color, int b_color) {
	box(x, y , w, h, t_color, b_color, "Sap xep ma SV");
	box(x, y + h, w, h, t_color, b_color, "Sap xep ten");
	box(x, y + 2 * h, w, h, t_color, b_color, "Sap xep ngay sinh");
	box(x, y + 3 * h, w, h, t_color, b_color, "Sap xep diem TB");
	box(x, y + 4 * h, w, h, t_color, b_color, "Quay lai");
}
