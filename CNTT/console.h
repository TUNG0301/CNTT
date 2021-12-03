#pragma once

#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include <iostream>


#define KEY_NONE -1

using namespace std;


int whereX();
int whereY();
void gotoXY(int x, int y);
void SetColor(WORD);
void ShowCur(bool);
int inputKey();
void textcolor(int x);

void box(int x, int y, int w, int h, int t_color, int b_color, string nd);
void sua_cot(int x, int y, int so_hang);
void khung_so_luong(int Size);
void khung_hoc_luc(int Size);