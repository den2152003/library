#pragma once
#include <iostream>
#include <iomanip>
#include <map>
#include <conio.h>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include "book.cpp"
#include <sstream>
#include "goto_draw.cpp"
#include "update.cpp"
#include "inkhung.cpp"
#include <algorithm>
#include "docfile.cpp"
#include "truycap.h"
#include "date.cpp"


void admin(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach);
void adminSV(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach);

// Hàm để kiểm tra xem một dòng có chứa thông tin cần xóa hay không
bool shouldDeleteRow(const string& row, const string& infoToDelete) {
    // Ví dụ: kiểm tra xem dòng có chứa thông tin cần xóa hay không
    return (row.find(infoToDelete) != string::npos);
}
void xoaTaiKhoan(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
	string cccd;
	string taikhoan;
	ifstream inFile("data.csv");
	vector<string> lines;
    string line;
	while (getline(inFile, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
	inFile.close();
	
	system("cls");
	box(20,5,100,4,11,11, "===========================================XOA TAI KHOAN===========================================");
	box(20,9,100,4,11,11, "Nhap cccd can xoa tai khoan:");
	GoTo(20,9); cout << char(195);
	GoTo(120,9); cout << char(195);
	box(20,13,100,4,11,11);
	GoTo(20,13); cout << char(195);
	GoTo(120,13); cout << char(195);
	GoTo(50,11);
	cin >> cccd;
	string infoToDelete = cccd;
	// Tìm và xóa dòng chứa thông tin cần xóa
    vector<string> newLines;
    for (const auto& row : lines) {
        if (!shouldDeleteRow(row, infoToDelete)) {
            newLines.push_back(row);
        }
    }
	ofstream outFile("data.csv");
	for (const auto& row : newLines) {
        outFile << row << endl;
    }

    outFile.close();

	SetColor(10);
	GoTo(23,15);
	cout << "Da xoa tai khoan thanh cong !!!";
	SetColor(11);
	GoTo(63,15);
	ShowCur(false);
	cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
	char ch;
	ch = getch();
	if (ch == 13)
	{
		xoaTaiKhoan(hs,sohs,sach,sosach);
	}
	else if (ch == 8)
	{
		adminSV(hs, sohs, sach, sosach);

	}
	
}

void timKiemThongTinSV(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
	system("cls");
	box(18,2,112,4,11,11, "=========================================TIM KIEM THONG TIN NGUOI DUNG=======================================");
	box(18,6,112,4,11,7, "Nhap cccd can xem thong tin: ");
	GoTo(18,6); cout << char(195);
	GoTo(130,6); cout << char(180);
	long k = 1;

	string st;
	
	SetColor(11);
	GoTo(48,8);
	cin >> st;
	bool chay = false;
	SetColor(7);
	for (int i = 1; i <= sohs; i++)
		if (st == hs[i].getCCCD())
		{
			chay = true;
			box(18,10,30,4,11,7, "     HO TEN NGUOI DUNG");
            GoTo(18,10); cout << char(195);
			box(48,10,30,4,11,7, "      CCCD NGUOI DUNG");
			GoTo(48,10); cout << char(194);
			box(78,10,26,4,11,7, "       TAI KHOAN");
			GoTo(78,10); cout << char(194);
			box(104,10,26,4,11,7, "        MAT KHAU");
			GoTo(104,10); cout << char(194);
            GoTo(130,10); cout << char(180);

			box(18,14,30,4,11,7, "   " + hs[i].hoten);
			// GoTo(18,14); cout << char(195);
			box(48,14,30,4,11,7, "   " + hs[i].getCCCD());
			// GoTo(48,14); cout << char(197);
			box(78,14,26,4,11,7, "   " +  hs[i].getUserName());
			// GoTo(78,14); cout << char(197);
			box(104,14,26,4,11,7, "   " + hs[i].getPassword());
			// GoTo(104,14); cout << char(197);
            // GoTo(130,14); cout << char(180);
			
			SetColor(7);
			if (hs[i].borrow == "0;")
			{
				SetColor(4);
				GoTo(48,8);
				cout << " !!! Chua muon sach" << endl;
				GoTo(70,8);
				SetColor(11);
				cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
				char kitu;
				kitu = getch();
				if (kitu == 13)
				{
					timKiemThongTinSV(hs, sohs, sach, sosach);
				}
				else if (kitu == 8)
				{
					adminSV(hs, sohs, sach, sosach);
				}
			}
			else
			{
				box(18,14,30,4,11,7, " " + hs[i].hoten);
				GoTo(18,14); cout << char(195);
				box(48,14,30,4,11,7, " " + hs[i].getCCCD());
				GoTo(48,14); cout << char(197);
				GoTo(48,18); cout << char(193);
				box(78,14,26,4,11,7, " " + hs[i].getUserName());
				GoTo(78,14); cout << char(197);
				GoTo(78,18); cout << char(193);
				box(104,14,26,4,11,7, " " + hs[i].getPassword());
				GoTo(104,14); cout << char(197);
                GoTo(130,14); cout << char(180);
				GoTo(104,18); cout << char(193);
				box(18,20,112,4,7,11, "==============================================TOAN BO SACH DANG MUON===========================================");
				box(18,24,30,4,7,7, "        MA SO SACH");
				GoTo(18,24); cout << char(195);
				box(48,24,30,4,7,7, "          TEN SACH");
				GoTo(48,24); cout << char(194);
				box(78,24,26,4,7,7, "         TAC GIA");
				GoTo(78,24); cout << char(194);
				box(104,24,26,4,7,7, "       NGAY MUON");
				GoTo(104,24); cout << char(194);
				GoTo(130,24); cout << char(180);
				string dayBorrow = hs[i].day + "/" + hs[i].month + "/" + hs[i].year;

				int count = 0;
				string trasach = hs[i].borrow;
                size_t start_pos = 0;
                size_t end_pos = 0;
                while (end_pos != string::npos) 
				{
                    // Tìm vị trí của dấu ";"
                    end_pos = trasach.find(";", start_pos);

                    // Trích xuất phần từ từ start_pos đến end_pos
                    string ms_str = trasach.substr(start_pos, end_pos - start_pos);
                    // Tìm vị trí của dấu "-" trong ms_str
                    size_t dash_pos = ms_str.find("-");
					// cout << dash_pos;

                    if (dash_pos != string::npos) 
					{
                        // Trích xuất số sách từ đầu đến dấu "-"
                        int num;
                        stringstream ss;
                        ss << ms_str.substr(0, dash_pos);
                        ss >> num;
						string status = ms_str.substr(dash_pos + 1);
						if (status == "chap nhan")
						{
							
							box(18,28+count,30,4,7,7, " "+ sach[num].getCode());
							GoTo(18,28+count); cout << char(195);
							box(48,28+count,30,4,7,7, " "+  sach[num].getBookname());
							GoTo(48,28+count); cout << char(197);
							GoTo(48,28+count+4); cout << char(193);
							box(78,28+count,26,4,7,7," "+ sach[num].getAuthor());
							GoTo(78,28+count); cout << char(197);
							GoTo(78,28+count+4); cout << char(193);
							box(104,28+count,26,4,7,7, " "+  dayBorrow);
							GoTo(104,28+count); cout << char(197);
							GoTo(130,28+count); cout << char(180);
							GoTo(104,28+count+4); cout << char(193);
							count = count + 4;	
							
                        } 
						
					}
					
					start_pos = end_pos + 1;							                             
                }
				
				GoTo(70,8);
				SetColor(11);
				cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
				char kitu;
				kitu = getch();
				if (kitu == 13)
				{
					timKiemThongTinSV(hs, sohs, sach, sosach);
				}
				else if (kitu == 8)
				{
					adminSV(hs, sohs, sach, sosach);
				}
            }
				
			}
		
	if (chay == false)
	{
		GoTo(48,8);
		SetColor(4);
		cout << "Username khong ton tai" ;
		SetColor(11);
		GoTo(73,8);
		cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
		char ch;
		ch = getch();
		if (ch == 13)
		{
			timKiemThongTinSV(hs, sohs, sach, sosach);
		} else if (ch == 8)
		{
			adminSV(hs, sohs, sach, sosach);
		}
	}
}


void sachBorrow(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
	int sl[sosach + 1];
	int T = 0;
	int count = 0;
	string trasach = "";
	for (int i = 1; i <= sosach; i++)
	{
		sl[i] = 0;
	}
	system("cls");
	box(18,2,115,4,11,11, "============================================SO LUONG SACH DANG DUOC MUON=========================================");
	box(18,6,15,4,11,7, "   Ma sach");
	GoTo(18,6); cout << char(195);
	box(33,6,40,4,11,7, "                Ten sach");
	GoTo(33,6); cout << char(194);
	box(73,6,20,4,11,7, "      The loai");
	GoTo(73,6); cout << char(194);
	box(93,6,25,4,11,7, "        Tac gia");
	GoTo(93,6); cout << char(194);
	box(118,6,15,4,11,7, "   So luong");
	GoTo(118,6); cout << char(194);
	GoTo(133,6); cout << char(180);
	for (int i = 1; i <= sohs; i++)
	{
		trasach = trasach + hs[i].borrow;
	};
	
	size_t start_pos = 0;
	size_t end_pos = 0;
	while (end_pos != string::npos) 
	{
		// Tìm vị trí của dấu ";"
		end_pos = trasach.find(";", start_pos);

		// Trích xuất phần từ từ start_pos đến end_pos
		string ms_str = trasach.substr(start_pos, end_pos - start_pos);
		// Tìm vị trí của dấu "-" trong ms_str
		size_t dash_pos = ms_str.find("-");
		// cout << dash_pos;

		if (dash_pos != string::npos) {
			// Trích xuất số sách từ đầu đến dấu "-"
			int num;
			stringstream ss;
			ss << ms_str.substr(0, dash_pos);
			ss >> num;
			string status = ms_str.substr(dash_pos + 1);
			if (status == "chap nhan")
			{
				sl[num] = sl[num] + 1;		
			} 

		}
		start_pos = end_pos + 1;
		
	}
	for (int j = 1; j <= sosach; j++)
	{
		if (sl[j] != 0)
		{
			box(18,10+count,15,4,7,7, "      "+sach[j].getCode());
			GoTo(18,10+count); cout << char(195);
			box(33,10+count,40,4,7,7, " "+sach[j].getBookname());
			GoTo(33,10+count); cout << char(197);
			// GoTo(48,10+count+4); cout << char(197);
			box(73,10+count,20,4,7,7, " "+sach[j].getCategory());
			GoTo(73,10+count); cout << char(197);
			box(93,10+count,25,4,7,7, " "+sach[j].getAuthor());
			GoTo(93,10+count); cout << char(197);
			box(118,10+count,15,4,7,7,"       "+ to_string(sl[j]));
			GoTo(118,10+count); cout << char(197);
			GoTo(133,10+count); cout << char(180);
			T = T + sl[j];
			count = count + 4;
		}
	}
	box(18,10+count,55,4,7,11, "                     Tong cong");
	GoTo(18,10+count); cout << char(195);
	GoTo(33,10+count); cout << char(193);
	box(73,10+count,60,4,7,11, "                               " + to_string(T));
	GoTo(73,10+count); cout << char(197);
	GoTo(93,10+count); cout << char(193);
	GoTo(118,10+count); cout << char(193);
	GoTo(133,10+count); cout << char(180);
	GoTo(73,10+count+4); cout << char(193);
	char ch;
	ch = getch();
	if (ch == 8)
	{
		adminSV(hs, sohs, sach, sosach);
	}
	
	
}

void muonSach(vector<hocsinh>& HOCSINH, long sohs, vector<book>& sach, long sosach) {
    system("cls");
	inkhungadmin_muon();
	
	ShowCur(true);
	box(26,5,35,4,11,7," Nhap CCCD: "); 
	GoTo(26,5); cout <<char(195);
	box(61,5,27,4,11,7," Ma sach yeu cau: ");
	GoTo(61,5); cout <<char(194);
	box(88,5,35,4,11,7," Chap nhan/Tu choi (A/R): "); 
	GoTo(88,5); cout <<char(194);
	GoTo(123,5); cout <<char(180);
	box(26,9,97,4,11,7, " ");
	GoTo(26,9); cout <<char(195);
	GoTo(61,9); cout <<char(193);
	GoTo(88,9); cout <<char(193);
	GoTo(123,9); cout <<char(180);

    long k = 1;
	vector<string> listBorrow;
	vector<int> ms;
	int codeBook;
    string taikhoan;
	string cccd;
    
    SetColor(11);
	GoTo(39,7);
    cin >> cccd;
    bool chay = false;
    SetColor(7);
    for (int i = 1; i <= sohs; i++)
        if (cccd == HOCSINH[i].getCCCD()) 
		{
			// jmp:
			ShowCur(false);
			int count = 0;
			int count1 = 0;
            chay = true;
            
            SetColor(7);
            if (HOCSINH[i].borrow == "0;") {
                SetColor(4);
				GoTo(28,11);
                cout << " !!! Hoc sinh nay chua muon sach cua thu vien" << endl;
            }
            else 
			{
				
				box(26,16,15,4,7,11,"   Ma sach"); 
				box(41,16,45,4,7,11,"                 Ten sach"); 
				GoTo(41,16); cout << char(194);
				box(86,16,22,4,7,11, "      Tac gia");
				GoTo(86,16); cout << char(194);
				box(108,16,15,4,7,11,"  Trang thai"); 
				GoTo(108,16); cout << char(194);

                SetColor(7);
				
                string muonsach = HOCSINH[i].borrow;
                size_t start_pos = 0;
                size_t end_pos = 0;
                while (end_pos != string::npos) 
				{
                    // Tìm vị trí của dấu ";"
                    end_pos = muonsach.find(";", start_pos);

                    // Trích xuất phần từ từ start_pos đến end_pos
                    string ms_str = muonsach.substr(start_pos, end_pos - start_pos);
					listBorrow.push_back(ms_str);
					count++;
                    // Tìm vị trí của dấu "-" trong ms_str
                    size_t dash_pos = ms_str.find("-");
					// cout << dash_pos;

                    if (dash_pos != string::npos) 
					{
                        // Trích xuất số sách từ đầu đến dấu "-"
                        int num;
                        stringstream ss;
                        ss << ms_str.substr(0, dash_pos);
                        ss >> num;
						string status = ms_str.substr(dash_pos + 1);
						
						box(26,20+count1,15,4,7,7, "      " + sach[num].getCode());
						GoTo(26,20+count1); cout<< char(195);
						box(41,20+count1,45,4,7,7, "  " + sach[num].getBookname());
						GoTo(41,20+count1); cout<< char(197);
						GoTo(41,20+count1+4); cout<< char(193);
						box(86,20+count1,22,4,7,7, "  " + sach[num].getAuthor());
						GoTo(86,20+count1); cout<< char(197);
						GoTo(86,20+count1+4); cout<< char(193);
						box(108,20+count1,15,4,7,7, " " + status);
						GoTo(108,20+count1); cout<< char(197);
						GoTo(123,20+count1); cout<< char(180);
						GoTo(108,20+count1+4); cout<< char(193);

						count1 = count1 + 4;
					}
					start_pos = end_pos + 1;

                }
			
				SetColor(14);
				// cout << endl;
				GoTo(70,11);
				cout << "Nhan [Enter] de tiep tuc!";
				cout << "Nhan [Backspace] de tro lai!";
				char ch;
				ch = getch();
				if (ch==13) {
					
					HOCSINH[i].borrow = "";
					update(HOCSINH, sohs, sach, sosach, i);
					
				} else if (ch == 8)
				{
					system("cls");
					admin(HOCSINH, sohs, sach, sosach);
					break;
				}

				// cout << "nhap ma sach: ";
				// cin >> codeBook;
				char choice;
				int countChapNhan = 0;

				do {
					int codeBook;
					GoTo(28,11);
					cout << "                                    ";
					GoTo(115,7);
					cout << "   ";
					GoTo(80,7);
					cout << "  ";

					SetColor(11);
					ShowCur(true);
					GoTo(80,7);
					cin >> codeBook;


					// Duyệt qua các mượn sách trong listBorrow
					for (int j = 0; j < count - 1; j++) {
						string muonsach = listBorrow[j];
						
						size_t dash_pos = muonsach.find("-");
						if (dash_pos != string::npos) {
							// Trích xuất số sách từ đầu đến dấu "-"
							int num;
							stringstream ss;
							ss << muonsach.substr(0, dash_pos);
							ss >> num;
							string status = muonsach.substr(dash_pos + 1);
							if (codeBook == num) 
							{
								GoTo(115,7);
								cout << "   ";
								GoTo(115,7);
								cin >> choice;
								switch(choice) 
								{
									case 'A':
									case 'a':
										{
											// sach[codeBook].getAmount() = sach[codeBook].getAmount() - 1;
											int t = stoi(sach[num].getAmount()) - 1;
											sach[num].setAmount(to_string(t));
											HOCSINH[i].borrow += to_string(num) + "-" + "chap nhan" + ";";
											ms.push_back(num);
											countChapNhan++;

											update(HOCSINH, sohs, sach, sosach, i);
											break;
										}
										
									case 'R':
									case 'r':
										// Xử lý khi từ chối mượn sách
										break;
									default:
										// Xử lý trường hợp lựa chọn không hợp lệ
										break;
								}
							} 
						}
					}
					GoTo(28,11);
					cout << "Tiep tuc? (Nhan Y de tiep tuc): ";
					cin >> choice;
				} while (choice == 'Y' || choice == 'y');

				// cout << "\n\n\n\n\n\n\n\n\n";
				// int lc2;
				char kytu;
				GoTo(28,11);
                cout << "                                                                                               " << endl;
				GoTo(28,11);
				SetColor(10);
				cout << "Ban co muon in phieu muon sach khong? ";
				cout << "Nhan [Enter] de in phieu" ;
				// cout << "	1. In phieu muon" << endl;
				// cout << "	2. Khong in" << endl;
				// cout << ms[0] << " " << ms[1] << " " << ms[2] << " " << count;
				// cin >> lc2;
			    kytu = getch();
				//	cout <<"Ma sach muon: "<< hs[h].borrow<<endl;;
				if (kytu == 13)
				{
					ofstream phieumuon("phieumuon.txt");
					phieumuon << "Phieu muon sach" << endl;
					phieumuon << "=============================" << endl;
					phieumuon << "Ho ten: " << HOCSINH[i].hoten << endl;
					phieumuon << "CCCD: " << HOCSINH[i].getCCCD() << endl; 

					phieumuon << "Ma so sach: "
							<< "   ";

					phieumuon << "Ten sach: " << endl;
					for (int j = 0; j < countChapNhan; j++)
					{
						phieumuon << sach[ms[j]].getCode();
						for (int l = sach[ms[j]].getCode().length(); l < 15; l++)
						{
							phieumuon << " ";
						}
						phieumuon << sach[ms[j]].getBookname() << endl;
						
					}
					// phieumuon << "Ngay muon: " << get_day() << endl;
					phieumuon << "Ngay muon: " << get_day() << endl;
					HOCSINH[i].dayBorrow = get_day();
					HOCSINH[i].day = day();
					HOCSINH[i].month = month();
					HOCSINH[i].year = year();
					phieumuon << "                             " << endl;
					phieumuon << "=============================" << endl;
					phieumuon << "Nguoi muon ky va ghi ro ho ten" << endl;
					
				}
				if (kytu == 13)
				{
					GoTo(28,11);
                    cout << "                                                                                               " << endl;
				    GoTo(28,11);
					SetColor(10);
					cout << "In phieu thanh cong!";
					cout << "Hoan tat muon sach!";
					cout << "Ngay" <<HOCSINH[i].day << "/" << HOCSINH[i].month;
					SetColor(7);
				}
				update(HOCSINH, sohs, sach, sosach, i);
            }
			

        }
    if (chay == false) {
        system("cls");
        cout << "Username khong ton tai" << endl;
        muonSach(HOCSINH, sohs, sach, sosach);
    }

}


void traSach(vector<hocsinh>& HOCSINH, long sohs, vector<book>& sach, long sosach) 
{
	system("cls");
	bool *kt = new bool[sosach + 1];
	for (int i = 1; i <= sosach; i++)
		kt[i] = false;

	inkhungadmin_tra();
	
	string cccd;
    vector<int> listTra;
    SetColor(11);
	GoTo(39,7);
	ShowCur(true);
    cin >> cccd;
	bool chay = false;
    SetColor(7);
    for (int i = 1; i <= sohs; i++)
        if (cccd == HOCSINH[i].getCCCD()) 
		{
			
			ShowCur(false);
			int count = 0;
            int count2 = 0;
            chay = true;
            
            SetColor(7);
			if (HOCSINH[i].borrow == "0;") {
				GoTo(70,7);
                SetColor(4);
                cout << " !!! Hien tai hoc sinh nay chua muon sach cua thu vien" << endl;
				SetColor(14);
			    GoTo(59,11);
			    cout << "Nhan [Backspace] de tro ve man hinh chon hoac [Enter] de tiep tuc!" << endl;
			    SetColor(7);
			    cout << " " << (char)16 << (char)16;
			    char kytu1;
			    kytu1 = getch();
                if (kytu1==8) {
				    system("cls");
				    admin(HOCSINH, sohs, sach, sosach);
                }
			    else if (kytu1==13) {
				    traSach(HOCSINH, sohs, sach, sosach);
                }         
            }
            else 
			{
				box(26,16,15,4,7,11,"   Ma sach"); 
				box(41,16,45,4,7,11,"                 Ten sach"); 
				GoTo(41,16); cout << char(194);
				box(86,16,22,4,7,11, "      Tac gia");
				GoTo(86,16); cout << char(194);
				box(108,16,17,4,7,11,"   Ngay muon"); 
				GoTo(108,16); cout << char(194);
				string dayBorrow = HOCSINH[i].day + "/" + HOCSINH[i].month + "/" + HOCSINH[i].year;
				string trasach = HOCSINH[i].borrow;
                size_t start_pos = 0;
                size_t end_pos = 0;
                while (end_pos != string::npos) 
				{
                    // Tìm vị trí của dấu ";"
                    end_pos = trasach.find(";", start_pos);

                    // Trích xuất phần từ từ start_pos đến end_pos
                    string ms_str = trasach.substr(start_pos, end_pos - start_pos);
                    // Tìm vị trí của dấu "-" trong ms_str
                    size_t dash_pos = ms_str.find("-");
					// cout << dash_pos;

                    if (dash_pos != string::npos) {
                        // Trích xuất số sách từ đầu đến dấu "-"

                        int num;
                        stringstream ss;
                        ss << ms_str.substr(0, dash_pos);
                        ss >> num;
						kt[num] = true;
						listTra.push_back(num);
						count++;
						string status = ms_str.substr(dash_pos + 1);
						if (status == "chap nhan")
						{
						    

                            box(26,20+count2,15,4,7,7, "      " + sach[num].getCode());
						    GoTo(26,20+count2); cout<< char(195);
						    box(41,20+count2,45,4,7,7, "  " + sach[num].getBookname());
						    GoTo(41,20+count2); cout<< char(197);
						    GoTo(41,20+count2+4); cout<< char(193);
						    box(86,20+count2,22,4,7,7, "  " + sach[num].getAuthor());
						    GoTo(86,20+count2); cout<< char(197);
						    GoTo(86,20+count2+4); cout<< char(193);
						    box(108,20+count2,17,4,7,7, "   " + dayBorrow);
						    GoTo(108,20+count2); cout<< char(197);
						    GoTo(125,20+count2); cout<< char(180);
						    GoTo(108,20+count2+4); cout<< char(193); 

							count2 = count2 + 4;
						
							
						} else
						{
							system("cls");
							inkhungadmin_tra();
							GoTo(91,7);
                            SetColor(4);
							cout << "Hien nguoi nay khong muon sach!!!";
                            SetColor(14);
			                GoTo(59,11);
			                cout << "Nhan [Backspace] de tro ve man hinh chon hoac [Enter] de tiep tuc!" << endl;
			                SetColor(7);
			                cout << " " << (char)16 << (char)16;
			                char kytu1;
			                kytu1 = getch();
                            if (kytu1==8) {
				               system("cls");
				               admin(HOCSINH, sohs, sach, sosach);
                            }
			                else if (kytu1==13) {
				               traSach(HOCSINH, sohs, sach, sosach);
                            }                                           
							
						}
							
						                      
            
                    }
                    start_pos = end_pos + 1;
					
                }
				
					
					int codeBook;
					string sst;
					string ms_str = "";
					int countTra = count;

					// Duyệt qua các mượn sách trong listBorrow
					for (int j = 0; j < count; j++) 
					{	
						ShowCur(true);
						GoTo(52,11);
						cout << "      ";

						GoTo(52,11);
						SetColor(11);
						cin >> codeBook;

						while (kt[codeBook] == false) 
						{
							GoTo(27,11);
							SetColor(14);
							cout << " Nguoi dung khong muon cuon sach nay!!!";
							cout <<"   Nhan [Enter] de nhap lai ma sach";
							ShowCur(false);
							char l;
							l = getch();
							if (l == 13)
							{
								GoTo(27,11);
								cout << "                                                                           ";
								GoTo(52,11);   
								cout << "      ";
								GoTo(27,11);
								SetColor(7);
								cout << "Nhap ma so sach can tra:";
								ShowCur(true);
								GoTo(52,11);
								SetColor(11);
								cin >> codeBook;
							}
							
						}
						if ( ((stoi(year()) == stoi(HOCSINH[i].year)) && (stoi(month()) == stoi(HOCSINH[i].month)) && ((stoi(day()) - stoi(HOCSINH[i].day)) < 15)) 
							|| ( (stoi(year()) == stoi(HOCSINH[i].year)) && ((stoi(month()) - stoi(HOCSINH[i].month)) == 1)&& ( stoi(day()) + (30 - stoi(HOCSINH[i].day)) < 15 ))
							)
						{
							GoTo(60,7);
							SetColor(10);
							cout << "Tra sach dung han!";
							cout << "Ban da tra thanh cong cuon " << sach[codeBook].getBookname() <<"!";
							int t = stoi(sach[codeBook].getAmount()) + 1;
							sach[codeBook].setAmount(to_string(t));
							SetColor(14);
			                GoTo(59,11);
			                cout << "Nhan [Backspace] de tro ve man hinh chon hoac [Enter] de tiep tuc!" << endl;
			                  

							for (int g = 0; g < countTra; g++) 
							{
								if (codeBook == listTra[g])
								{
									if(to_string(codeBook).length() == 2)
										trasach = trasach.erase(13*g,12);
									trasach = trasach.erase(12*g,12);
									break;
								}
							}
							
							
							
							if (trasach == "")
							{
								trasach = "0;";
								HOCSINH[i].day = "0";
								HOCSINH[i].month = "0";
								HOCSINH[i].year = "0";
							}
							break;
							

						} 
						else 
						    GoTo(106,7);
						    SetColor(4);
							ShowCur(false);
							cout << "Tra sach tre han!!!";
							int t = stoi(sach[codeBook].getAmount()) + 1;
							sach[codeBook].setAmount(to_string(t));
			                SetColor(14);
			                GoTo(59,11);
			                cout << "Nhan [Backspace] de tro ve man hinh chon hoac [Enter] de tiep tuc!" << endl;
							for (int g = 0; g < countTra; g++) 
							{
								if (codeBook == listTra[g])
								{
									if(to_string(codeBook).length() == 2)
										trasach = trasach.erase(13*g,12);
									trasach = trasach.erase(12*g,12);
									break;
								}
							}
							if (trasach == "")
							{
								trasach = "0;";
								HOCSINH[i].day = "0";
								HOCSINH[i].month = "0";
								HOCSINH[i].year = "0";
							}
							break;
			                                                                           
								
					}
					
					
				
				if (HOCSINH[i].borrow == "")
				{
					HOCSINH[i].borrow = "0;";
					
				}
				else
					HOCSINH[i].borrow = trasach;
				update(HOCSINH, sohs, sach, sosach, i);

			}
		}
}

void quanLySach(vector<book> sach, long sosach)
{
	system("cls");
	inkhung4();

	// kk = 0;

	// tam = new book2[sosach + 1];
	
	// GoTo(32,7); cout << char(195);
	
	for (int i = 1; i < sosach + 1; i++)
	{
		// kk++;
		cout << "                          " << char(179) << " ";
		if (stoi(sach[i].getCode(), 0) < 10)
			cout << " ";
		
		else if (stoi(sach[i].getCode(), 0) >= 100)
			cout << "";
		cout << "    "<< sach[i].getCode() << "     " << char(179) << " ";
		
		cout << sach[i].getBookname();
		for (int ii = sach[i].getBookname().length(); ii <= 36; ii++)
		{
			if (ii == 33)
				cout << char (179);
			else
				cout << " ";
		}
		

		cout  << " " << sach[i].getCategory();
		
		for (int ii = sach[i].getCategory().length(); ii <= 17; ii++)
		{
			if (ii == 15)
				cout << char(179);
			else
				cout << " ";
		}

		cout << sach[i].getAuthor();
		for (int ii = sach[i].getAuthor().length(); ii <= 17; ii++)
		{
			if (ii == 14)
				cout << char(179);
			else
				cout << " ";
		}
		
		cout << sach[i].getAmount();
		string ttsl = sach[i].getAmount();
		for (int j = 1; j < 9 - ttsl.length(); j++)
			cout << " ";
		cout << char (179) << endl;
	}
    cout << "                          " << char(192); for (int i=32;i<=43;i++) cout << char(196); 
	cout << char(193); for (int i=40;i<=73;i++) cout << char(196); 
	cout << char (193);for (int i=70;i<=88;i++) cout << char(196);
	cout << char (193);for (int i=100;i<=127;i++) cout << char(196);
	cout << char (217) << endl << endl;
	SetColor(10);
	
}


void themSach(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach)
{   
	system("cls");
	string ten;
	string theloai;
	string sl;
	string author;
	box(0,2,35,2,7,11);
	GoTo(1,3);
	TextColor(11);
	cout << "=============THEM SACH============";
	// GoTo(35,2); cout << char(180);
	box(0,0,148,2,7,7);
	GoTo(0,2); cout << char(195);
	// GoTo(35,2); cout << char(194);
	GoTo(47,1);
	cout << "Ban muon nhap them bao nhieu sach:	";
	int n;
	GoTo(82,1);
	cin >> n; 
	cin.ignore();
    int x= 0;

	for (int i = 1; i <= n; i++)
	{   
		
		box(0,4+x,35,2,7,7);
	    GoTo(2,5+x);
		cout << "Nhap thong tin ma sach thu " << i << ":" << endl;
		GoTo(0,4+x); cout << char(195);
	    // GoTo(35,4+x); cout << char(217);
		

		string ten;
		string theloai;
		string sl;
		fflush(stdin);

		box(35,2,40,2,7,7);
		GoTo(35,2+x); cout << char(194);

	    GoTo(47,3);
		cout << "Nhap ten sach";


		box(35,4+x,40,2,7,7); 
		
		GoTo(35,4+x); cout << char(197);
		// GoTo(35,4+x); cout << char(197);
		// GoTo(75,4+x); cout << char(180);
		// GoTo(75,2+x); cout << char(194);
		// GoTo(35,6+x); cout << char(193);
		GoTo(38,5+x);
		getline(cin, ten);
		fflush(stdin);

		box(75,2,30,2,7,7);
		GoTo(75,2); cout << char(194);
	    GoTo(82,3);
		cout<< "Nhap the loai";
		box(75,4+x,30,2,7,7);
		// GoTo(75,2+x); cout << char(194);
		// GoTo(75,2+x); cout << char(197);
		GoTo(75,4+x); cout << char(197);
		// GoTo(75,6+x); cout << char(193);
		// GoTo(105,2+x); cout << char(194);
		// GoTo(105,4+x); cout << char(180);
		GoTo(78,5+x);
		getline(cin, theloai);
		fflush(stdin);

		box(105,2,25,2,7,7);
		GoTo(105,2); cout << char(194);
	    GoTo(110,3);
		cout <<"Nhap tac gia";
		box(105,4+x,25,2,7,7);
		// GoTo(105,2+x); cout << char(194);
		// GoTo(105,2+x); cout << char(197);
		GoTo(105,4+x); cout << char(197);
        // GoTo(105,6+x); cout << char(193);
		// GoTo(130,2+x); cout << char(180);
		// GoTo(130,4+x); cout << char(180);
		
		GoTo(108,5+x);
		getline(cin, author);

		box(130,2,18,2,7,7);
		GoTo(130,2); cout << char(194);
		GoTo(148,2); cout << char(180);
		GoTo(133,3);
		cout <<"Nhap so luong";
		box(130,4+x,18,2,7,7);
		// GoTo(130,2+x); cout << char(194);
		// GoTo(130,2+x); cout << char(197);
		GoTo(130,4+x); cout << char(197);
		GoTo(148,4+x); cout << char(180);
        // GoTo(130,6+x); cout << char(193);
		// // GoTo(130,2+x); cout << char(180);
		// // GoTo(130,4+x); cout << char(180);
		
		GoTo(138,5+x);
		getline(cin, sl);

		x+=2;

		stringstream ss2;
		ss2 << sosach + i; //1
		string masach = ss2.str(); // CHUYEN SO SANG XAU - 2
		
		book tam;
		tam.setCode(masach);
		tam.setBookname(ten);
		tam.setCategory(theloai);
		tam.setAuthor(author);
		tam.setAmount(sl) ;
		sach.push_back(tam);
	}
	sosach = sosach + n; 
		
	update(HOCSINH, sohs, sach, sosach, 0);
	SetColor(10);
	GoTo(1,6+x);
	cout << "Nhap them sach thanh cong!" << endl;
	SetColor(7);
}

int menudongBook(int xp,int yp,int xcu,int ycu,bool kt) 
{
    ShowCur(0);
    while(true) 
    {
        if(kt == true) 
        {
            GoTo(xcu,ycu);
            if(ycu == 13) thanhsang(xcu,ycu,35,4,1, "             Muon sach            ");
            if(ycu == 17) thanhsang(xcu,ycu,35,4,1,"             Tra sach             ");
            if(ycu == 21) thanhsang(xcu,ycu,35,4,1,"           Quan ly sach           ");
			if(ycu == 25) thanhsang(xcu,ycu,35,4,1,"             Them sach            ");
			if(ycu == 29) thanhsang(xcu,ycu,35,4,1,"             Quay lai             ");
            xcu = xp;
            ycu = yp;
            if(yp == 13) thanhsang(xp,yp,35,4,75, "             Muon sach            ");
            if(yp == 17) thanhsang(xp,yp,35,4,75,"             Tra sach             ");
            if(yp == 21) thanhsang(xp,yp,35,4,75,"           Quan ly sach           ");
			if(yp == 25) thanhsang(xp,yp,35,4,75,"             Them sach            ");
			if(yp == 29) thanhsang(xp,yp,35,4,75,"             Quay lai             ");

            kt = false;
        }
        if(_kbhit()) 
        {
			int null=0;

            char c = _getch();
            
            if(c == -32) 
            {
                c = _getch();
                if(c == 80 && yp == 29) // 80 xuong
                {
                    kt = true;
                    yp -= 16;
                } else if(c == 80 && yp != 29) 
                {
                    kt = true;
                    yp += 4;
                } else if(c == 72 && yp != 13) // 72 len
                {
                    kt = true;
                    yp -= 4;
                } else if(c == 72 && yp == 13)
                {
                    kt = true;
                    yp += 16;

                } 
            }
            else if(c == 13 ) // 13 enter
                {
                    kt = false;
                    return yp;
                }
        }   
    }
}

int menudongSV(int xp,int yp,int xcu,int ycu,bool kt) 
{
    ShowCur(0);
    while(true) 
    {
        if(kt == true) 
        {
            GoTo(xcu,ycu);
            if(ycu == 13) thanhsang(xcu,ycu,35,4,1,"   Tim kiem thong tin sinh vien   ");
            if(ycu == 17) thanhsang(xcu,ycu,35,4,1,"    Quan ly sach sinh vien muon   ");
            if(ycu == 21) thanhsang(xcu,ycu,35,4,1,"    Dang ky tai khoan sinh vien   ");
			if(ycu == 25) thanhsang(xcu,ycu,35,4,1,"     Xoa tai khoan sinh vien      ");
			if(ycu == 29) thanhsang(xcu,ycu,35,4,1,"             Quay lai             ");
            xcu = xp;
            ycu = yp;
            if(yp == 13) thanhsang(xp,yp,35,4,75,"   Tim kiem thong tin sinh vien   ");
            if(yp == 17) thanhsang(xp,yp,35,4,75,"    Quan ly sach sinh vien muon   ");
            if(yp == 21) thanhsang(xp,yp,35,4,75,"    Dang ky tai khoan sinh vien   ");
			if(yp == 25) thanhsang(xp,yp,35,4,75,"     Xoa tai khoan sinh vien      ");
			if(yp == 29) thanhsang(xp,yp,35,4,75,"             Quay lai             ");

            kt = false;
        }
        if(_kbhit()) 
        {
			int null=0;

            char c = _getch();
            
            if(c == -32) 
            {
                c = _getch();
                if(c == 80 && yp == 29) // 80 xuong
                {
                    kt = true;
                    yp -= 16;
                } else if(c == 80 && yp != 29) 
                {
                    kt = true;
                    yp += 4;
                } else if(c == 72 && yp != 13) // 72 len
                {
                    kt = true;
                    yp -= 4;
                } else if(c == 72 && yp == 13)
                {
                    kt = true;
                    yp += 16;

                } 
            }
            else if(c == 13 ) // 13 enter
                {
                    kt = false;
                    return yp;
                }
        }   
    }
}

int menudongmain(int xp,int yp,int xcu,int ycu,bool kt) 
{
    ShowCur(0);
    while(true) 
    {
        if(kt == true) 
        {
            GoTo(xcu,ycu);
            if(ycu == 17) thanhsang(xcu,ycu,35,4,1,"         Quan ly sinh vien        ");
            if(ycu == 21) thanhsang(xcu,ycu,35,4,1,"           Quan ly sach           ");
            if(ycu == 25) thanhsang(xcu,ycu,35,4,1,"             Quay lai             ");
            xcu = xp;
            ycu = yp;
            if(yp == 17) thanhsang(xp,yp,35,4,75,"         Quan ly sinh vien        ");
            if(yp == 21) thanhsang(xp,yp,35,4,75,"           Quan ly sach           ");
            if(yp == 25) thanhsang(xp,yp,35,4,75,"             Quay lai             ");

            kt = false;
        }
        if(_kbhit()) 
        {
			int null=0;

            char c = _getch();
            
            if(c == -32) 
            {
                c = _getch();
                if(c == 80 && yp == 25) // 80 xuong
                {
                    kt = true;
                    yp -= 8;
                } else if(c == 80 && yp != 25) 
                {
                    kt = true;
                    yp += 4;
                } else if(c == 72 && yp != 17) // 72 len
                {
                    kt = true;
                    yp -= 4;
                } else if(c == 72 && yp == 17)
                {
                    kt = true;
                    yp += 8;

                } 
            }
            else if(c == 13 ) // 13 enter
                {
                    kt = false;
                    return yp;
                }
        }   
    }
}

void adminSV(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach)
{
    system("cls");
	//-----------------*MENU*----------------------------//
	
	box(60,9,35,4,11,11,"=========QUAN LY SINH VIEN=========");

    box(60,13,35,4,11,7,"   Tim kiem thong tin sinh vien"); 
	GoTo(60,13); cout << char(195);
    GoTo(95,13); cout << char(180);

	box(60,17,35,4,11,7,"    Quan ly sach sinh vien muon"); 
	GoTo(60,17); cout << char(195);
    GoTo(95,17); cout << char(180);

	box(60,21,35,4,11,7,"    Dang ky tai khoan sinh vien"); 
	GoTo(60,21); cout << char(195);
    GoTo(95,21); cout << char(180);

	box(60,25,35,4,11,7,"     Xoa tai khoan sinh vien"); 
	GoTo(60,25); cout << char(195);
    GoTo(95,25); cout << char(180);

	box(60,29,35,4,11,7,"             Quay lai"); 
	GoTo(60,29); cout << char(195);
    GoTo(95,29); cout << char(180);

	int check = menudongSV(60,13,60,13,true);
	//-----------*menu1: tim kiem thong tin sinh vien*----------------//
	int lenh;
	switch (check)
	{
	    case 13:
			timKiemThongTinSV(HOCSINH, sohs, sach, sosach);
	        break;

		case 17:
			sachBorrow(HOCSINH, sohs, sach, sosach);
			break;

		case 21:
			dangky();
			break;

		case 25:
			xoaTaiKhoan(HOCSINH, sohs, sach, sosach);
			break;
		
		case 29:
			admin(HOCSINH, sohs, sach, sosach);
			break;
	}

}

void adminBook(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach)
{
    system("cls");
	//-----------------*MENU*----------------------------//
	
	box(60,9,35,4,11,11,"============QUAN LY SACH===========");

    box(60,13,35,4,11,7,"             Muon sach"); 
	GoTo(60,13); cout << char(195);
    GoTo(95,13); cout << char(180);

	box(60,17,35,4,11,7,"             Tra sach"); 
	GoTo(60,17); cout << char(195);
    GoTo(95,17); cout << char(180);

	box(60,21,35,4,11,7,"           Quan ly sach"); 
	GoTo(60,21); cout << char(195);
    GoTo(95,21); cout << char(180);

	box(60,25,35,4,11,7,"             Them sach"); 
	GoTo(60,25); cout << char(195);
    GoTo(95,25); cout << char(180);

	box(60,29,35,4,11,7,"             Quay lai"); 
	GoTo(60,29); cout << char(195);
    GoTo(95,29); cout << char(180);

	int check = menudongBook(60,13,60,13,true);
	//-----------*menu1: tim kiem thong tin sinh vien*----------------//
	int lenh;
	switch (check)
	{
		case 13:
			muonSach(HOCSINH, sohs, sach, sosach);
			GoTo(82,11);
	        SetColor(14);
	        cout << "Nhan [Backspace] de tro ve man hinh chon " ;
		    char ch;
			ch = getch();
            if (ch==8) {
               system("cls");
			   adminBook(HOCSINH, sohs, sach, sosach);
			}
			break;

		case 17:
			jmp:
			traSach(HOCSINH, sohs, sach, sosach);
			
			char kytu;
			kytu = getch();
            if (kytu==8) {
				system("cls");
				admin(HOCSINH, sohs, sach, sosach);
            }
			else if (kytu==13) {
				goto jmp;
            }
			break;

		case 21:
			quanLySach(sach, sosach);
			SetColor(14);
			cout << "Nhan backspace de tro ve man hinh chon " << endl;
			ch = getch();
            if (ch==8) {
               system("cls");
			   adminBook(HOCSINH, sohs, sach, sosach);
			}
			break;

		case 25:
			themSach(HOCSINH, sohs, sach, sosach);
			SetColor(14);
			cout << "Nhan backspace de tro ve man hinh chon " << endl;
			ch = getch();
            if (ch==8) {
               system("cls");
			   adminBook(HOCSINH, sohs, sach, sosach);
			}
			break;
		
		case 29:
			admin(HOCSINH, sohs, sach, sosach);
			break;
	}


}
//*************************ADMIN****************************//
void admin(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach)
{
    system("cls");
	//-----------------*MENU*----------------------------//
	
	box(60,13,35,4,11,11,"===============MENU================");

    box(60,17,35,4,11,7,"        Quan ly sinh vien"); 
	GoTo(60,17); cout << char(195);
    GoTo(95,17); cout << char(180);

	box(60,21,35,4,11,7,"           Quan ly sach"); 
	GoTo(60,21); cout << char(195);
    GoTo(95,21); cout << char(180);

	box(60,25,35,4,11,7,"             Quay lai"); 
	GoTo(60,25); cout << char(195);
    GoTo(95,25); cout << char(180);

	int check = menudongmain(60,17,60,17,true);
	//-----------*menu1: tim kiem thong tin sinh vien*----------------//
	int lenh;
	switch (check)
	{
		case 17:
		    adminSV(HOCSINH, sohs, sach, sosach);
	        break;

		case 21:
			adminBook(HOCSINH, sohs, sach, sosach);
			break;
		
		case 25:
			dangnhap();
			break;
	}

}




