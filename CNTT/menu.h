#pragma once

#include "IO.h"
#include "console.h"
#include "sapxep.h"
#include "timkiem.h"
#include "thongke.h"
#include "SinhVien.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <ctime> 
#include <stdio.h>


#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

// Phim
#define MAX 100
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13
#define SPACE -32

// Lua chon
#define FIRST 6
#define SECOND 8
#define THIRD 10
#define FOURTH 12
#define FIFTH 14
#define SIXTH 16

//file doc
#define PATH "sv.txt"
using std::vector;

class App
{
	int x ;
	int y ;
	int w ;
	int h ;
	int t_color;
	int b_color;
	int b_color_sang;
	int xp = x - 3;
	int yp = y + 1;
	int yp_limit ; // 6 o
	int xcu = xp;
	int ycu = yp;
	bool kt = true;

	vector<SinhVien> vsv;

public:
	App();
	void tieu_de(int x, int y, int b_color);
	void get_choice(int* choice);
	void main_menu();
	void them_moi_ho_so();
	//void drawing_frame(int Size); /*Ve Khung de hien thi cac thong tin sinh vien*/
	//void show(vector<SinhVien>& student_list); /* Ghi thong tin cac sinh vien vao khung */
	void in_danh_sach();
	void sap_xep(vector<SinhVien>& sv1);
	void tim_kiem();
	void thong_ke();
	void menu();
};

