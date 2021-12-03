#pragma once
#include "console.h"
#include "SinhVien.h"
#include <vector>

using std::vector;

void swap(SinhVien& sv1, SinhVien& sv2);
int Stoi(int i, int n, char arr[]);
void divideDate(int& day, int& month, int& year, char ns[]);



int comparative_maLop(SinhVien sv1, SinhVien sv2);
int comparative_maSV(SinhVien sv1, SinhVien sv2);
int comparative_hoTen(SinhVien sv1, SinhVien sv2);
int comparative_ngaySinh(char* ns1, char* ns2);
int comparative_DTB(SinhVien sv1, SinhVien sv2);

void selectionSort(vector<SinhVien> &sv1, int selection);

void insertionSort(vector<SinhVien>& sv1, int selection);

void bubbleSort(vector<SinhVien>& sv1, int selection);
void quickSort(vector<SinhVien>& sv, int h, int l, int selection);

void showKieuSapXep(int x, int y, int w, int h, int t_color, int b_color);
void showLoaiSapXep(int x, int y, int w, int h, int t_color, int b_color);
