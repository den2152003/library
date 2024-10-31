#pragma once
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include "data.cpp"
// #include <stdlib.h>
#include "book.cpp"
// #include <sstream>
#include "goto_draw.cpp"
// #include "update.cpp"
#include "inkhung.cpp"
#include <algorithm>
#include "docfile.cpp"

void update(vector<hocsinh> &HOCSINH,long &sohs,vector<book> &sach,long &sosach, int h){
	// fstream fin, fout;
	// fin.open("data.csv", ios::in);
    ifstream fin("iostream.txt");
    ofstream fout("datanew.csv", ios::app); // là khi file đã có sẵn data thì dữ liệu sẽ được thêm vào cuối file.

	// fout.open("datanew.csv", ios::out);
	for (int i=0;i<=sohs;i++)
		{
			fout << HOCSINH[i].getUserName() << "," 
				 << HOCSINH[i].getPassword() << "," 
				 << HOCSINH[i].hoten << ","  
				 << HOCSINH[i].getCCCD() << "," 
				 << HOCSINH[i].borrow << "~" 
				 << HOCSINH[i].day << "/" << HOCSINH[i].month << "/" << HOCSINH[i].year << "\n";
		}
	fin.close();
	fout.close();

	// removing the existing file
	remove("data.csv");

	// renaming the updated file with the existing file name
	rename("datanew.csv", "data.csv");
	// SACH
//	fstream fin, fout;
	fin.open("danhsachsach.csv", ios::in);
	fout.open("danhsachsachnew.csv", ios::out);
	for (int i=0;i<=sosach;i++)
    {
        fout << sach[i].getCode() << "," <<  sach[i].getBookname() << "," << sach[i].getCategory() << "," << sach[i].getAuthor() << "," << sach[i].getAmount() << "\n";
    }
	fin.close();
	fout.close();

	// removing the existing file
	remove("danhsachsach.csv");

	// renaming the updated file with the existing file name
	rename("danhsachsachnew.csv", "danhsachsach.csv");
	
}