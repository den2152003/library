#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void draw(int a,int b,int c, int d){ //(33 1) (97 10)
    //(a,b) (c,d)
    //canh tren hcn (a,b) do dai c
    GoTo(a,b);for (int i=a;i<=c;i++) cout << char(196); 
    //canh duoi hcn (a,d) do dai c
    GoTo(a,d);for (int i=a;i<=c;i++) cout << char(196);
    //b + i la ve tu tren xuong
    for (int i=1;i<=d-b;i++) {GoTo(a-1,b+i);cout << char(179) << endl;}
    for (int i=1;i<=d-b;i++) {GoTo(c+1,b+i);cout << char(179) << endl;}
    GoTo(a-1,b); cout << char(218);
    GoTo(c+1,b); cout << char(191);
    GoTo(a-1,d); cout << char(192);
    GoTo(c+1,d); cout << char(217);
}

void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void thanhsang(int x, int y, int w, int h, int b_color,string nd) 
{
    TextColor(b_color);
    for(int iy = x+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            GoTo(ix,iy); cout << " ";
        }
    }
    SetColor(7);
    GoTo(x+1,y+2);
    cout << nd;
    TextColor(1);
}

void box(int x, int y, int w, int h, int t_color, int b_color,string nd) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            GoTo(ix,iy); cout << " ";
        }
    }
    SetColor(7);
    TextColor(b_color);
    GoTo(x+1,y+2);
    cout << nd;
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        GoTo(ix,y);
        cout << char(196);
        GoTo(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        GoTo(x,iy);
        cout << char(179);
        GoTo(x+w,iy);
        cout << char(179);
    }
    GoTo(x,y); cout << char(218);
    GoTo(x+w,y); cout << char(191);
    GoTo(x,y+h); cout << char(192);
    GoTo(x+w,y+h); cout << char(217);
}

void box(int x, int y, int w, int h, int t_color, int b_color) 
{
    TextColor(b_color);
    for(int iy = y+1; iy <= y+h-1; iy++) 
    {
        for(int ix = x+1; ix <= x+w-1; ix++) 
        {
            GoTo(ix,iy); cout << " ";
        }
    }
    TextColor(1);
    SetColor(t_color);
    if(h <= 1 || w <= 1) return ;
    for(int ix = x; ix <= x + w; ix++) 
    {
        GoTo(ix,y);
        cout << char(196);
        GoTo(ix,y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++) 
    {
        GoTo(x,iy);
        cout << char(179);
        GoTo(x+w,iy);
        cout << char(179);
    }
    GoTo(x,y); cout << char(218); //trai tren
    GoTo(x+w,y); cout << char(191);
    GoTo(x,y+h); cout << char(192);//trai duoi
    GoTo(x+w,y+h); cout << char(217);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}