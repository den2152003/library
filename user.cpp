#pragma once
#include <iostream>
#include "goto_draw.cpp"
#include <ctime>
#include "data.cpp"
#include "book.cpp"

// #include "update.cpp"
#include "inkhung.cpp"
#include "truycap.h"

void dangnhap();
void user (vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h);
void menurequest(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h);



using namespace std;

void thanhcong()
{
	cout << "------------------" << endl;
	SetColor(9);
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	// intime();
	SetColor(7);
	cout << "------------------" << endl;
}


void muon(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	long k = 1;

	bool *kt = new bool[sosach + 1];
	for (int i = 1; i <= sosach; i++)
		kt[i] = false;
	string st = hs[h].borrow;
	string s;

	// for (int j = 0; j < 10; j++)
	// {			
	// 	cout << sach[ms1[j]].getCode();
	// }
	for (int i = 0; i <= st.length(); i++)
		if (st[i] == ';')
		{
			kt[stoi(s)] = true;
			s = "";
		}
		else
			s = s + st[i];
		box(42,4,66,4,11,7,"Nhap ma so sach yeu cau muon : ");
		SetColor(4);
		// cout << "LUU Y !!! Ban khong duoc muon 1 sach nhieu cuon hoac muon sach da het ( so luong = 0) " << endl;
		
		SetColor(7);

		GoTo(73,6);
		int ms;
		cout << " " << (char)16 << (char)16;
		cin >> ms;
		//while ((kt[ms] == true) || (sach[ms].amount == "0") || ms <= 0 || ms > sosach)
		while ((ms <= 0) || (kt[ms] == true) || (sach[ms].getAmount() == "0") || (ms > sosach))
		{
			GoTo(42,10);
			SetColor(4);
			cout << "Ban can nhap dung theo yeu cau, nhap lai ma: " ;
			GoTo(42,11);
			cout << "Cac sach ma sach ban dang muon: ";
			cout << hs[h].borrow << endl;
			SetColor(7);
			cout << " " << (char)16 << (char)16;
			GoTo(73,6);
			cout << "   ";
			GoTo(73,6);
			cin >> ms;
		}

		GoTo(42,10);
		cout << "                                             ";
		GoTo(42,11);
		cout << "                                                   ";
		//update
		GoTo(42,10);
		SetColor(2);
		cout << "Ban dang muon quyen " << sach[ms].getBookname() << endl;
		// sach[ms].setStatus("dang xet");
		
		SetColor(7);
		kt[ms] = true;
		
		if (hs[h].borrow == "0;")
			hs[h].borrow = "";
		hs[h].borrow = hs[h].borrow + to_string(ms) + "-" + " dang xet" + ";";
		update(hs, sohs, sach, sosach, h);

		
		
		// int t = stoi(sach[ms].getAmount()) - 1;
		// sach[ms].getAmount() = to_string(t);
		// thanhcong();


		char ch;
		ch = getch();
		if (ch == 13) 
		{
			menurequest(hs, sohs, sach, sosach, h);
		}
		
		
	
}


int menudongrequest(int xp,int yp,int xcu,int ycu,bool kt) 
{
    ShowCur(0);
    while(true) 
    {
        if(kt == true) 
        {
            GoTo(xcu,ycu);
            if(ycu == 6)  thanhsang(xcu,ycu,30,4,1,"      Yeu cau muon sach      ");
            if(ycu == 10) thanhsang(xcu,ycu,30,4,1,"           Quay lai          ");
            xcu = xp;
            ycu = yp;
            if(yp == 6)  thanhsang(xp,yp,30,4,75,"      Yeu cau muon sach      ");
            if(yp == 10) thanhsang(xp,yp,30,1,75,"           Quay lai          ");
            kt = false;
        }
        if(_kbhit()) 
        {
            char c = _getch();
            
            if(c == -32) 
            {
                c = _getch();
                if(c == 72 && yp != 6) 
                {
                    kt = true;
                    yp -= 4;
                } else if(c == 72 && yp == 6) 
                {
                    kt = true;
                    yp += 4;
                } else if(c == 80  && yp != 10)
                {
                    kt = true;
                    yp += 4;
                } else if(c == 80  && yp == 10)
                {
                    kt = true;
                    yp -= 4;
                } 
            }
            else if(c == 13 ) 
                {
                    kt = false;
                    return yp;
                }
        }   
    }
}

void menurequest(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h)
{       
	system("cls");
	int option, k;
	
	
	box(10,2,30,4,11,11,"=============MENU=============");
	// GoTo(1,2); cout << char(218);
	box(10,6,30,4,11,7,"      Yeu cau muon sach");
	GoTo(10,6); cout << char(195);
	GoTo(40,6); cout << char(180);
	box(10,10,30,4,11,7,"           Quay lai");
	GoTo(10,10); cout << char(195);
	GoTo(40,10); cout << char(180);

	
	box(40,2,70,12,11,7);
	GoTo(40,2); cout << char(194);
	GoTo(40,6); cout << char(180);
	GoTo(40,10); cout << char(180);
	GoTo(40,14); cout << char(193);
	
	// box(41,7,68,2,11,7);
	// box(41,11,68,2,11,7);
    
	inkhungmuon();
	int count1;
	string muonsach = HOCSINH[h].borrow;
	GoTo(0,23);
	size_t start_pos = 0;
	size_t end_pos = 0;
	while (end_pos != string::npos) {
			// Tìm vị trí của dấu ";"
			end_pos = muonsach.find(";", start_pos);

			// Trích xuất phần từ từ start_pos đến end_pos
			string ms_str = muonsach.substr(start_pos, end_pos - start_pos);

			// Tìm vị trí của dấu "-" trong ms_str
			size_t dash_pos = ms_str.find("-");

			if (dash_pos != string::npos) 
			{
				// Trích xuất số sách từ đầu đến dấu "-"
				int num;
				stringstream ss;
				ss << ms_str.substr(0, dash_pos);
				ss >> num;
				string status = ms_str.substr(dash_pos + 1);

	// box(10,19,13,4,7,11,"Ma sach");
	// box(23,19,50,4,7,11,"Ten sach");
	// box(73,19,24,4,7,11,"The loai");
	// box(97,19,20,4,7,11,"Tac gia");
	// box(117,19,14,4,7,11,"So luong");
	// box(131,19,19,4,7,11,"Trang thai");

				box(10,23+count1,13,4,7,7, "    " + sach[num].getCode());
				GoTo(10,23+count1); cout<< char(195);
				box(23,23+count1,50,4,7,7, "  " + sach[num].getBookname());
				GoTo(23,23+count1); cout<< char(197);
				GoTo(23,23+count1+4); cout<< char(193);
				box(73,23+count1,24,4,7,7, "  " + sach[num].getCategory());
				GoTo(73,23+count1); cout<< char(197);
			    GoTo(73,23+count1+4); cout<< char(193);
				box(97,23+count1,20,4,7,7, "  " + sach[num].getAuthor());
				GoTo(97,23+count1); cout<< char(197);
			    GoTo(97,23+count1+4); cout<< char(193);
				box(117,23+count1,14,4,7,7, "  " + sach[num].getAmount());
				GoTo(117,23+count1); cout<< char(197);
			    GoTo(117,23+count1+4); cout<< char(193);
				box(131,23+count1,19,4,7,7, " " + status);
			    GoTo(131,23+count1); cout<< char(197);
				GoTo(150,23+count1); cout<< char(180);
				GoTo(131,23+count1+4); cout<< char(193);

				count1 = count1 + 4;

			// 	cout << "         " << char(179) << " ";
			// 	if (stoi(sach[num].getCode(), 0) < 10)
			// 		cout << " ";
				
			// 	else if (stoi(sach[num].getCode(), 0) >= 100)
			// 		cout << "";
			// 	cout << "    "<< sach[num].getCode() << "     " << char(179) << " ";
				
			// 	cout << sach[num].getBookname();
			// 	for (int ii = sach[num].getBookname().length(); ii <= 36; ii++)
			// 	{
			// 		if (ii == 33)
			// 			cout << char (179);
			// 		else
			// 			cout << " ";
			// 	}
		

			// 	cout  << " " << sach[num].getCategory();
				
			// 	for (int ii = sach[num].getCategory().length(); ii <= 17; ii++)
			// 	{
			// 		if (ii == 15)
			// 			cout << char(179);
			// 		else
			// 			cout << " ";
			// 	}

			// 	cout << sach[num].getAuthor();
			// 	for (int ii = sach[num].getAuthor().length(); ii <= 17; ii++)
			// 	{
			// 		if (ii == 14)
			// 			cout << char(179);
			// 		else
			// 			cout << " ";
			// 	}
				
			// 	cout << sach[num].getAmount();
			// 	string ttsl = sach[num].getAmount();
			// 	for (int j = 1; j < 9 - ttsl.length(); j++)
			// 		cout << " ";
	
			// // Trích xuất trạng thái từ dấu "-" đến hết chuỗi
				

			// 	// In ra trạng thái
			// 	cout  << status << endl;
			}
			start_pos = end_pos + 1;
    }
			
			
		// }
		// cout << "                          " << char(192); for (int i=32;i<=43;i++) cout << char(196); 
		// cout << char(193); for (int i=40;i<=73;i++) cout << char(196); 
		// cout << char (193);for (int i=70;i<=88;i++) cout << char(196);
		// cout << char (193);for (int i=100;i<=127;i++) cout << char(196);
		// cout << char (217) << endl << endl;
		// SetColor(10);
		
		start_pos = end_pos + 1;
		// cout << "_________________________________________________________________________" << endl;
	
	option = menudongrequest(10,6,10,6,true);
	switch (option)
	{
		case 6:
			muon(HOCSINH, sohs, sach, sosach, h);
			
			
			break;
		case 10:
			user(HOCSINH, sohs, sach, sosach, h);
			break;
	}
}



void allBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
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



void nameBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{ 
	string nameSach = " ";
	int count = 0;
	system("cls");
	
	box(10,3,122,4,11,11, "======================================================TIM KIEM SACH THEO TEN=============================================");
	box(10,7,122,4,11,7, "  Nhap ten sach can tiem kiem: ");
	GoTo(10,7); cout << char(195);
	GoTo(132,7); cout << char(180);

	ShowCur(true);
	GoTo(42,9);
	SetColor(7);
	getline(cin, nameSach);


	for (int i = 1; i <= sosach; i++)
	{
		if (nameSach == sach[i].getBookname())
		{
			box(10,13,122,4,7,11, "====================================================SACH CAN TIM=========================================================");
			box(10,17,15,4,7,7,"   Ma sach"); 
			GoTo(10,17); cout << char(195);
			box(25,17,45,4,7,7,"                 Ten sach"); 
			GoTo(25,17); cout << char(194);
			box(70,17,22,4,7,7, "      The loai");
			GoTo(70,17); cout << char(194);
			box(92,17,22,4,7,7, "       Tac gia");
			GoTo(92,17); cout << char(194);
			box(114,17,18,4,7,7, "    So luong");
			GoTo(114,17); cout << char(194);
			GoTo(132,17); cout << char(180);

			box(10,21+count,15,4,7,7, " "+ sach[i].getCode());
			GoTo(10,21+count); cout << char(195);
			box(25,21+count,45,4,7,7, " "+ sach[i].getBookname()); 
			GoTo(25,21+count); cout << char(197);
			GoTo(25,21+count+4); cout << char(193);
			box(70,21+count,22,4,7,7, " "+ sach[i].getCategory()); 
			GoTo(70,21+count); cout << char(197);
			GoTo(70,21+count+4); cout << char(193);
			box(92,21+count,22,4,7,7, " "+ sach[i].getAuthor());
			GoTo(92,21+count); cout << char(197);
			GoTo(92,21+count+4); cout << char(193);
			box(114,21+count,18,4,7,7," "+ sach[i].getAmount());
			GoTo(114,21+count); cout << char(197);
			GoTo(132,21+count); cout << char(180);
			GoTo(114,21+count+4); cout << char(193);
			count += 4;
			

		}
	}
	
	SetColor(14);
	GoTo(70,9);
	ShowCur(false);
	cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
	char ch;
	ch = getch();
	if (ch == 13)
	{
		nameBook(hs,sohs,sach,sosach,h);
	}
	else if (ch == 8)
	{
		user(hs, sohs, sach, sosach, h);
	}
	
}

void cateBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{ 
	string nameSach = " ";
	int count = 0;
	system("cls");
	
	box(10,3,122,4,11,11, "===================================================TIM KIEM SACH THEO THE LOAI===========================================");
	box(10,7,122,4,11,7, "  Nhap the loai can tiem kiem: ");
	GoTo(10,7); cout << char(195);
	GoTo(132,7); cout << char(180);
	
	ShowCur(true);
	GoTo(42,9);
	SetColor(7);
	getline(cin, nameSach);

	for (int i = 1; i <= sosach; i++)
	{
		if (nameSach == sach[i].getCategory())
		{
			box(10,13,122,4,7,11, "====================================================SACH CAN TIM=========================================================");
			box(10,17,15,4,7,7,"   Ma sach"); 
			GoTo(10,17); cout << char(195);
			box(25,17,45,4,7,7,"                 Ten sach"); 
			GoTo(25,17); cout << char(194);
			box(70,17,22,4,7,7, "      The loai");
			GoTo(70,17); cout << char(194);
			box(92,17,22,4,7,7, "       Tac gia");
			GoTo(92,17); cout << char(194);
			box(114,17,18,4,7,7, "    So luong");
			GoTo(114,17); cout << char(194);
			GoTo(132,17); cout << char(180);

			box(10,21+count,15,4,7,7, " "+ sach[i].getCode());
			GoTo(10,21+count); cout << char(195);
			box(25,21+count,45,4,7,7, " "+ sach[i].getBookname()); 
			GoTo(25,21+count); cout << char(197);
			GoTo(25,21+count+4); cout << char(193);
			box(70,21+count,22,4,7,7, " "+ sach[i].getCategory()); 
			GoTo(70,21+count); cout << char(197);
			GoTo(70,21+count+4); cout << char(193);
			box(92,21+count,22,4,7,7, " "+ sach[i].getAuthor());
			GoTo(92,21+count); cout << char(197);
			GoTo(92,21+count+4); cout << char(193);
			box(114,21+count,18,4,7,7," "+ sach[i].getAmount());
			GoTo(114,21+count); cout << char(197);
			GoTo(132,21+count); cout << char(180);
			GoTo(114,21+count+4); cout << char(193);
			count += 4;
		}
	}
	
	SetColor(14);
	GoTo(70,9);
	ShowCur(false);
	cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
	char ch;
	ch = getch();
	if (ch == 13)
	{
		cateBook(hs,sohs,sach,sosach,h);
	}
	else if (ch == 8)
	{
		user(hs, sohs, sach, sosach, h);
	}
	
}

void authorBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{ 
	string nameSach = " ";
	int count = 0;
	system("cls");
	
	box(10,3,122,4,11,11, "===================================================TIM KIEM SACH THEO TAC GIA============================================");
	box(10,7,122,4,11,7, "  Nhap tac gia can tiem kiem: ");
	GoTo(10,7); cout << char(195);
	GoTo(132,7); cout << char(180);
	
	ShowCur(true);
	GoTo(42,9);
	SetColor(7);
	getline(cin, nameSach);

	for (int i = 1; i <= sosach; i++)
	{
		if (nameSach == sach[i].getAuthor())
		{
			box(10,13,122,4,7,11, "====================================================SACH CAN TIM=========================================================");
			box(10,17,15,4,7,7,"   Ma sach"); 
			GoTo(10,17); cout << char(195);
			box(25,17,45,4,7,7,"                 Ten sach"); 
			GoTo(25,17); cout << char(194);
			box(70,17,22,4,7,7, "      The loai");
			GoTo(70,17); cout << char(194);
			box(92,17,22,4,7,7, "       Tac gia");
			GoTo(92,17); cout << char(194);
			box(114,17,18,4,7,7, "    So luong");
			GoTo(114,17); cout << char(194);
			GoTo(132,17); cout << char(180);

			box(10,21+count,15,4,7,7, " "+ sach[i].getCode());
			GoTo(10,21+count); cout << char(195);
			box(25,21+count,45,4,7,7, " "+ sach[i].getBookname()); 
			GoTo(25,21+count); cout << char(197);
			GoTo(25,21+count+4); cout << char(193);
			box(70,21+count,22,4,7,7, " "+ sach[i].getCategory()); 
			GoTo(70,21+count); cout << char(197);
			GoTo(70,21+count+4); cout << char(193);
			box(92,21+count,22,4,7,7, " "+ sach[i].getAuthor());
			GoTo(92,21+count); cout << char(197);
			GoTo(92,21+count+4); cout << char(193);
			box(114,21+count,18,4,7,7," "+ sach[i].getAmount());
			GoTo(114,21+count); cout << char(197);
			GoTo(132,21+count); cout << char(180);
			GoTo(114,21+count+4); cout << char(193);
			count += 4;
		}
	}
	
	SetColor(14);
	GoTo(70,9);
	ShowCur(false);
	cout << "Nhan [BACKSPACE] de thoat, nhan [ENTER] de tiep tuc...!!!";
	char ch;
	ch = getch();
	if (ch == 13)
	{
		authorBook(hs,sohs,sach,sosach,h);
	}
	else if (ch == 8)
	{
		user(hs, sohs, sach, sosach, h);
	}
	
}


void changePassword(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h)
{
	string mk, lmk;
	char ch;
	system("cls");
	ShowCur(true);
	// Vẽ khung lớn
    SetColor(11);

    draw(48, 14, 111, 34);

    SetColor(11);
    draw(69, 16, 99, 20); 

    GoTo(74, 18);
    SetColor(7);
    cout << "DOI MAT KHAU";

    SetColor(11);
    draw(69, 21, 99, 25); 
    GoTo(49, 23);
    cout << "Nhap mat khau: ";

    draw(69, 26, 99, 30); 
    GoTo(49, 28);
    cout << "Nhap lai mat khau: ";

	GoTo(70,23);
	cin >> mk;
	while (mk == HOCSINH[h].getPassword())
	{
		SetColor(4);
		GoTo(71, 32);
		cout << (char)19 << "Ban da nhap mat khau cu" << endl;
		GoTo(70,23);
		cout <<"          ";

		SetColor(11);
		GoTo(70,23);
		cin >> mk;
	}
	
	SetColor(11);
	GoTo(70,28);
	cin >> lmk;
	while (mk != lmk)
	{
		SetColor(4);
		GoTo(71, 32);
		cout << (char)19 << "Mat khau khong trung khop" << endl;
		GoTo(70,23);
		cout <<"          ";
		GoTo(70,28);
		cout <<"          ";

		SetColor(11);
		GoTo(70,23);
		cin >> mk;

		SetColor(11);
		GoTo(70,28);
		cin >> lmk;
	}
	SetColor(10);
	GoTo(71, 32);
	cout <<"                                    ";
	GoTo(71, 32);
	cout << (char)19 << "Doi mat khau thanh cong" << endl;
	ShowCur(0);
	HOCSINH[h].setPassword(mk);
	update(HOCSINH, sohs, sach, sosach, h);
	ch = getch();
    if (ch == 13) 
	{
		dangnhap();
	}	
}

int menudong1(int xp,int yp,int xcu,int ycu,bool kt) 
{
    ShowCur(0);
    while(true) 
    {
        if(kt == true) 
        {
            GoTo(xcu,ycu);
            if(ycu == 11) thanhsang(xcu,ycu,35,4,1,"     Xem cac sach thu vien co     ");
            if(ycu == 15) thanhsang(xcu,ycu,35,4,1,"        Yeu cau muon sach         ");
            if(ycu == 19) thanhsang(xcu,ycu,35,4,1,"      Tim kiem sach theo ten      ");
			if(ycu == 23) thanhsang(xcu,ycu,35,4,1,"      Loc sach theo the loai      ");
			if(ycu == 27) thanhsang(xcu,ycu,35,4,1,"    Tim kiem sach theo tac gia    ");
			if(ycu == 31) thanhsang(xcu,ycu,35,4,1,"           Doi mat khau           ");
			if(ycu == 35) thanhsang(xcu,ycu,35,4,1,"             Quay lai             ");
            xcu = xp;
            ycu = yp;
            if(yp == 11) thanhsang(xp,yp,35,4,75,"     Xem cac sach thu vien co     ");
            if(yp == 15) thanhsang(xp,yp,35,4,75,"        Yeu cau muon sach         ");
            if(yp == 19) thanhsang(xp,yp,35,4,75,"      Tim kiem sach theo ten      ");
			if(yp == 23) thanhsang(xp,yp,35,4,75,"      Loc sach theo the loai      ");
			if(yp == 27) thanhsang(xp,yp,35,4,75,"    Tim kiem sach theo tac gia    ");
			if(yp == 31) thanhsang(xp,yp,35,4,75,"           Doi mat khau           ");
			if(yp == 35) thanhsang(xp,yp,35,4,75,"             Quay lai             ");
            kt = false;
        }
        if(_kbhit()) 
        {
			int null=0;

            char c = _getch();
            
            if(c == -32) 
            {
                c = _getch();
                if(c == 80 && yp == 35) // 80 xuong
                {
                    kt = true;
                    yp -= 24;
                } else if(c == 80 && yp != 35) 
                {
                    kt = true;
                    yp += 4;
                } else if(c == 72 && yp != 11) // 72 len
                {
                    kt = true;
                    yp -= 4;
                } else if(c == 72 && yp == 11)
                {
                    kt = true;
                    yp += 24;

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

void user (vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h)
{ // dang dang nhap hoc sinh h
	system("cls");

	//-----------------*MENU*----------------------------//
	box(60,7,35,4,11,11,"===============MENU================");

    box(60,11,35,4,11,7,"     Xem cac sach thu vien co"); 
	GoTo(60,11); cout << char(195);
    GoTo(95,11); cout << char(180);

	box(60,15,35,4,11,7,"        Yeu cau muon sach"); 
	GoTo(60,15); cout << char(195);
    GoTo(95,15); cout << char(180);

	box(60,19,35,4,11,7,"      Tim kiem sach theo ten"); 
	GoTo(60,19); cout << char(195);
    GoTo(95,19); cout << char(180);

	box(60,23,35,4,11,7,"      Loc sach theo the loai"); 
	GoTo(60,23); cout << char(195);
    GoTo(95,23); cout << char(180);

	box(60,27,35,4,11,7,"    Tim kiem sach theo tac gia"); 
	GoTo(60,27); cout << char(195);
    GoTo(95,27); cout << char(180);

	box(60,31,35,4,11,7,"           Doi mat khau"); 
	GoTo(60,31); cout << char(195);
    GoTo(95,31); cout << char(180);

	box(60,35,35,4,11,7,"             Quay lai"); 
	GoTo(60,35); cout << char(195);
    GoTo(95,35); cout << char(180);

	int check = menudong1(60,11,60,11,true);
	int lenh;
	switch (check)
	{
		case 11:
			allBook(HOCSINH, sohs, sach, sosach, h);
			SetColor(14);
		
			cout << "Nhan backspace de tro ve man hinh chon " << endl;
		    char ch;
			ch = getch();
            if (ch==8) {
               system("cls");
			   user(HOCSINH, sohs, sach, sosach, h);
			}
			break;
		case 15:
			menurequest(HOCSINH, sohs, sach, sosach, h);
			//muon(HOCSINH, sohs, sach, sosach, h);
			break;

        case 19:
			nameBook(HOCSINH, sohs, sach, sosach, h);
			break;

		case 23:
			cateBook(HOCSINH, sohs, sach, sosach, h);
			break;

		case 27:
			authorBook(HOCSINH, sohs, sach, sosach, h);
			break;
		
		case 31:
			changePassword(HOCSINH, sohs, sach, sosach, h);
			break;

		case 35:
			dangnhap();
			break;
	}

}