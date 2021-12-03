#pragma once
#include "menu.h"
#include "SinhVien.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using std::vector; 
using std::string;

vector<SinhVien>docTuFile(string tenFile);
void xuatRaFile(vector<SinhVien>& v, string tenFile);
void drawing_frame(int Size);
void show(vector<SinhVien>& student_list);
void clear();

