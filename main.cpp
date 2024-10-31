#include <bits/stdc++.h>
#include <windows.h>

#include "goto_draw.cpp"
#include "data.cpp"
#include "docfile.cpp"
#include "admin.cpp"
#include "user.cpp"
#include "update.cpp"
#include "book.cpp"
#include "truycap.cpp"

using namespace std;





void dangnhap();


void drawbook()
{
    system("cls");
	SetColor(8);
	GoTo(88, 18);
	cout << "_______________" << endl;
	for (int i = 0; i <= 6; i++)
	{
		GoTo(88, 19 + i);
		cout << "| |            |" << endl;
	}
	GoTo(92, 25);
	cout << "___________" << endl;
	GoTo(93, 21);
	cout << "Manage";
	GoTo(94, 22);
	cout << "Library";
	SetColor(7);
	draw(48, 16, 112, 27);
	GoTo(78, 28);
	for (int i = 0; i <= 5; i++)
		cout << (char)219;
}







bool menu () 
{
	while(true)
	{
		
		int null=0;
		int k= 22;
		
		
		GoTo(53,22); cout << "->";
		GoTo(53,23); cout << " ";
		
		while (true)
		{
		//	setposition(90,16); cout << ;
		
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k==22)
				{
					GoTo(53,k); cout << "  ";
					k++;
					GoTo(53,k); cout << "->";
					null++;	
				}
				else if (k==23)
				{
					GoTo(53,k); cout << "  ";
					k--;
					GoTo(53,k); cout << "->";
					null--;	
				}
				continue;
			}
			
			
			if (GetAsyncKeyState(VK_UP))
			{
				if (k == 23)
				{
					GoTo(53,k); cout << "  ";
					k--;
					GoTo(53,k); cout << "->";
					null--;
				}
				else if (k == 22)
				{
					GoTo(53,k); cout << "  ";
					k++;
					GoTo(53,k); cout << "->";
					null++;
				}
				continue;
			}
			
			if (GetAsyncKeyState(VK_RETURN))
			{
				if (null==0)
				{
					dangnhap();
					break;
				}
				if (null==1)
				{
					GoTo(20,20);
					break;
				}
				
			}
		}
		break;
	}
	return true;
}


int main () {
    docfile(HOCSINH, sohs, sach, sosach);
	ShowCur(0);
    const char* title = "Quan ly thu vien";
    wchar_t wideTitle[256];
    MultiByteToWideChar(CP_ACP, 0, title, -1, wideTitle, 256);
    SetConsoleTitleW(wideTitle);
	//SetConsoleOutputCP(65001);


	drawbook();
	GoTo(53, 19);
	SetColor(11);


	cout << "QUAN LY THU VIEN" ;
   
	
	// SetConsoleOutputCP(65001);
    GoTo(55, 22);
	cout << " Dang nhap " << endl;
	GoTo(55, 23);
	cout << " Quay lai " << endl;
	SetColor(7);
	GoTo(55, 24);

	
	if (menu())
		return 0;
		
	

	return 0;


}