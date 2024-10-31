#include "truycap.h"

using namespace std;

string mk;
string tk;
long sohs;
long sosach;
vector <hocsinh> HOCSINH;
vector<book> sach;
bool kkt = false; //admin
char ch;
void dangky()
{
	system("cls");
	ShowCur(true);
	


    string lmk = " ";
	string fullname;
    string cccd;
    SetColor(11);

    // Vẽ khung lớn
    draw(50, 6, 118, 28);

    // Vẽ khung nhỏ chứa tiêu đề "DANG NHAP TAI KHOAN"
    SetColor(11);
    draw(74, 9, 100, 11); 
    GoTo(83, 10);
    SetColor(7);
    cout << "DANG KY";

    // Vẽ khung nhỏ chứa tên đăng nhập và mật khẩu
    SetColor(11);
	box(73,12,28,4,11,1);
	
    // draw(74, 17, 100, 21); 
    GoTo(54, 14);
    cout << "Nhap tai khoan: ";
	
	
	box(73,16,28,4,11,1);
    // draw(74, 21, 100, 25); 
	

    GoTo(54, 18);
    cout << "Nhap mat khau: ";
	GoTo(73,16);cout << char(195);
	GoTo(101,16); cout << char (180);

    draw(74, 20, 100, 24); 
	GoTo(73,20); cout << char(195);
	GoTo(101,20); cout << char(180);

    GoTo(54, 22);
    cout << "Nhap lai mat khau: ";



	while (mk != lmk)
	{
        SetColor(11);
		
        GoTo(75, 14); //nhap tk
        cout << "            ";
        GoTo(75, 18); //nhap mk
        cout << "            ";
		bool kk = true;
        GoTo(75, 22); 
        cout << "            ";
		GoTo(75, 14); 
        cin >> tk;
		
		while (kk == true)
		{
			for (int i = 0; i <= sohs; i++)
				if (tk == HOCSINH[i].getUserName()) 
				{
                    GoTo (68,26);
					cout << "                                      ";
                    GoTo(76, 26);
            		SetColor(4);

					cout << "Tai khoan da ton tai" << endl;
					kk = true;
					break;
				}
				else
					kk = false;
			if (kk == true)
			{
                GoTo(75, 14);
				cout << "                     ";
                SetColor(11);
				GoTo(75, 14); 
				cin >> tk;
			}
		}

		GoTo(75, 18); 
		cin >> mk;

		GoTo(75, 22); 
		cin >> lmk;
		if (mk != lmk)
		{
			//	system("cls");
			
            SetColor(4);
			GoTo(68, 26); 
			cout << "Vui long dang ky lai theo dung yeu cau" << endl;
		}
	}
	GoTo(68, 26);
	cout << "                                           ";
	// GoTo(11, 8);
	SetColor(2);
	GoTo(76, 26);

	cout << "Dang ky thanh cong" << endl;
    cin.ignore();

    SetColor(11);

    // Vẽ khung lớn
    draw(50, 28, 118, 34);
	GoTo(49,28); cout << char(195);
	GoTo(119,28); cout << char(180);
	SetColor(11);
	// fflush(stdin);
	GoTo(54, 30);
	cout << "Nhap ho ten cua ban: ";
	getline(cin, fullname);

	GoTo(54, 32);
	cout << "Nhap CCCD cua ban: ";
	getline(cin, cccd);

	ShowCur(false);
	
    // Mở file để ghi
    ofstream outputFile("data.csv", ios::app); // là khi file đã có sẵn data thì dữ liệu sẽ được thêm vào cuối file.
	hocsinh hs;
    outputFile << tk << "," << mk << "," << fullname << "," << cccd << ",0;" << "~" << "0" << "/"<< "0" << "/" << "0" << endl;
    // outputFile << tk << "," << mk << "," << fullname  << ",0;" << endl;

	// fout.close();
	hs.setUserName(tk);
	hs.setPassword(mk);
	hs.hoten = fullname;
	hs.setCCCD(cccd);
	hs.day = "0";
	hs.month = "0";
	hs.year = "0";
	HOCSINH.push_back(hs);
	outputFile.close();
	// HOCSINH[0] ADMIN
	// HOCSINH[1] KHA
	sohs++;
    // docfile(HOCSINH, sohs, sach, sosach);
	
	ch = getch();
    if (ch == 13) 
	{
		admin(HOCSINH, sohs, sach, sosach);

	}
}

int tim(string fullname)
{
	for (int i = 0; i <= sohs; i++)
	{
		if ((fullname == HOCSINH[i].getUserName()) && (fullname == "admin"))
		{
			kkt = true;
			return i;
		}
		if (fullname == HOCSINH[i].getUserName())
			return i;
	}
	return -1;
}

void check(int i)
{
	if (i == -1)
	{
		//system("cls");
		SetColor(4);
		GoTo(66, 32);
		cout << "Khong co tai khoan hop le, nhap lai " << (char)30;
		SetColor(11);
		GoTo(69, 23);
		cout << "                    ";
		GoTo(69, 28);
		cout << "                    ";
		GoTo(69, 23);
		cin >> tk;
		GoTo(69, 28);
		cin >> mk;
		check(tim(tk));
	}
	else
	{
		//system("cls");

		if (HOCSINH[i].getPassword() == mk)
		{
			if (kkt != 0)
			{
				admin(HOCSINH, sohs, sach, sosach);
				kkt = false;
			}
			else
				user(HOCSINH, sohs, sach, sosach, i);
		}
		else
		{
			GoTo(66, 32);
			cout << "                                   ";
			SetColor(4);
			GoTo(75, 32);
			cout << (char)19 << " Mat khau sai";
			kkt = false;
			SetColor(11);
			GoTo(69, 28);
			cout << "                    ";
			GoTo(69, 28);
			cin >> mk;
			check(tim(tk)); //check(1)
		}
	};
}

void dangnhap()
{
    system("cls");
	ShowCur(true);
	bool kkt = false; //admin

    SetColor(11);

    // Vẽ khung lớn
    draw(48, 14, 111, 34);

    // Vẽ khung nhỏ chứa tiêu đề "DANG NHAP TAI KHOAN"
    SetColor(11);
    // box(67, 17, 32, 2, 11, 1, "     DANG NHAP TAI KHOAN"); 
    draw(68, 16, 98, 20); 

    GoTo(74, 18);
    SetColor(7);
    cout << "DANG NHAP TAI KHOAN";

    // Vẽ khung nhỏ chứa tên đăng nhập và mật khẩu
    SetColor(11);
    draw(68, 21, 98, 25); 
    GoTo(52, 23);
    cout << "Ten dang nhap: ";

    draw(68, 26, 98, 30); 
    GoTo(52, 28);
    cout << "Mat khau: ";

    // Nhập thông tin tài khoản và mật khẩu
    GoTo(69, 23); 
    cin >> tk;
    GoTo(69, 28); 
    cin >> mk;

	check(tim(tk));
}