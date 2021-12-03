#pragma once

typedef struct{
	char maLop[30];
	char maSV[30];
	char hoTen[30];
	char ngaySinh[30];
	float DTB;
} SinhVien;

inline void constructor(SinhVien& sv)
{
	for (int i = 0; i < 30; i++)
	{
		sv.hoTen[i] = ' ';
		sv.maLop[i] = ' ';
		sv.maSV[i] = ' ';
		sv.ngaySinh[i] = ' ';
	}
	sv.hoTen[29] = '\0';
	sv.maLop[29] = '\0';
	sv.maSV[29] = '\0';
	sv.ngaySinh[29] = '\0';
	sv.DTB = 0;
}
inline bool Empty(SinhVien sv)
{
	int ten = 0, lop = 0, ns = 0;
	for (int i = 0; i < 30; i++)
	{

		if (sv.hoTen[i] != ' ') ten = 1;
		if (sv.maLop[i] != ' ') lop = 1;
		if (sv.ngaySinh[i] != ' ') ns = 1;
	}
	if (ten == 1 || lop == 1 || ns == 1 || sv.DTB == 0) {
		return 1;
	}
	return 0;
}
