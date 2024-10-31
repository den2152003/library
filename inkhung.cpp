#pragma once
#include <iostream>
#include <iomanip>
#include "goto_draw.cpp"
using namespace std;
void inkhung()
{

	cout << "_________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(11);
	cout << setw(8) << left << "Ma sach";
	SetColor(7);
	cout << setw(11) << left << "|";
	SetColor(11);
	cout << setw(33) << left << "Ten sach";
	SetColor(7);
	cout << setw(5) << left << "|";
	SetColor(11);
	cout << setw(13) << left << "The loai";
	SetColor(7);
	cout << "|" << endl;

	SetColor(7);
	cout << "_________________________________________________________________________" << endl;
}

void inkhung4()
{
	// Vẽ ô chứa tiêu đề
	SetColor(7);
	draw(27, 1, 122, 5);
	SetColor(11);
	GoTo(27, 3); cout << "++++++++++++++++++++++++++++++ SO LUONG SACH HIEN CO TRONG THU VIEN ++++++++++++++++++++++++++++";
	SetColor(7);

	// Vẽ ô chứa dòng ngăn cách giữa tiêu đề và nội dung
	
	draw(27, 5, 122, 7);
	GoTo(26,5); cout << char(195);
    GoTo(123,5); cout << char(180);
	// Vẽ ô chứa nội dung sách
	SetColor(7);
	GoTo(30, 6);  cout << "Ma sach";
	GoTo(39, 6);  cout << char(179);
	GoTo(39,5); cout << char(194);
	GoTo(26,7); cout << char(195);
	GoTo(39,7); cout << char(197);


	

	GoTo(53, 6);  cout << "Ten sach";
	GoTo(74, 6); cout << char(179);
	GoTo(74,5); cout << char(194);
	GoTo(74,7); cout << char(197);

	
	GoTo(79, 6); cout << "The loai";
	GoTo(94, 6); cout << char(179);
	GoTo(94,5); cout << char(194);
	GoTo(94,7); cout << char(197);

	GoTo(99, 6); cout << "Tac gia";
	GoTo(111, 6); cout << char(179);
	GoTo(111,5); cout << char(194);
	GoTo(111,7); cout << char(197);


	GoTo(114, 6); cout << "So luong";
	GoTo(123,7); cout << char (180);


	// draw(33, 7, 116, 9);
	// // SetColor(7);
	// // GoTo(45,5); cout << char(218);
    // // GoTo(45,7); cout << char(191);

	
	GoTo(0,8);

}

void inkhungmuon()
{
	// Vẽ ô chứa tiêu đề
    box(10,15,140,4,7,11,"+++++++++++++++++++++++++++++++++++++ SO LUONG SACH HIEN CO TRONG THU VIEN +++++++++++++++++++++++++++++++++++");
	box(10,19,13,4,7,11,"Ma sach");
	GoTo(10,19); cout << char(195);
	box(23,19,50,4,7,11,"Ten sach");
	GoTo(23,19); cout << char(194);
	box(73,19,24,4,7,11,"The loai");
	GoTo(73,19); cout << char(194);
	box(97,19,20,4,7,11,"Tac gia");
	GoTo(97,19); cout << char(194);
	box(117,19,14,4,7,11,"So luong");
	GoTo(117,19); cout << char(194);
	box(131,19,19,4,7,11,"Trang thai");
	GoTo(131,19); cout << char(194);
	GoTo(150,19); cout << char(180);
	// SetColor(7);
	// draw(10, 16, 127, 20);
	// SetColor(11);
	// GoTo(12, 18); cout << "++++++++++++++++++++++++++++++ SO LUONG SACH HIEN CO TRONG THU VIEN ++++++++++++++++++++++++++++";
	// SetColor(7);

	// // Vẽ ô chứa dòng ngăn cách giữa tiêu đề và nội dung
	

	// draw(10, 20, 127, 22);
	// GoTo(9,20); cout << char(195);
    // GoTo(128,20); cout << char(180);
	// // Vẽ ô chứa nội dung sách
	// SetColor(7);
	// GoTo(13, 21);  cout << "Ma sach";
	// GoTo(22, 21);  cout << char(179);
	// GoTo(22,20); cout << char(194);
	// GoTo(22,22); cout << char(193);



	
    // GoTo(36, 21);  cout << "Ten sach";
	// GoTo(57, 21); cout << char(179);
	// GoTo(57,20); cout << char(194);
	// GoTo(57,22); cout << char(193);


	// GoTo(62, 21); cout << "The loai";
	// GoTo(77, 21); cout << char(179);
	// GoTo(77,20); cout << char(194);
	// GoTo(77,22); cout << char(193);


    // GoTo(82, 21); cout << "Tac gia";
	// GoTo(94, 21); cout << char(179);
	// GoTo(94,20); cout << char(194);
	// GoTo(94,22); cout << char(193);


    // GoTo(97, 21); cout << "So luong";
	// GoTo(109, 21); cout << char(179);
	// GoTo(109,20); cout << char(194);
	// GoTo(109,22); cout << char(193);

	// GoTo(114, 21); cout << "Trang thai";


}

void inkhungadmin_muon()
{
	SetColor(11);
	draw(27, 1, 122, 5);
	SetColor(11);
	GoTo(27, 3); cout << "++++++++++++++++++++++++++++++++++++++++++ CHO MUON SACH +++++++++++++++++++++++++++++++++++++++";
	SetColor(11);
}
void inkhungadmin_tra()
{
	SetColor(11);
	box(26,1,99,4,11,7);
	SetColor(11);
	GoTo(27, 3); cout << "++++++++++++++++++++++++++++++++++++++++++++ TRA SACH ++++++++++++++++++++++++++++++++++++++++++";
	SetColor(11);
	box(26,5,99,4,11,7, " Nhap CCCD: ");
	GoTo(26,5); cout << char(195);
	GoTo(125,5); cout << char(180);
	box(26,9,99,4,11,7, " Nhap ma so sach can tra: ");
	GoTo(26,9); cout << char(195);
	GoTo(125,9); cout << char(180);
}
