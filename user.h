#ifndef USER_CPP
#define USER_CPP
#include <iostream>
#include "goto_draw.cpp"
#include <ctime>
#include "update.cpp"
#include "inkhung.cpp"

using namespace std;
void thanhcong()

void muon(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h);

int menudongrequest(int xp,int yp,int xcu,int ycu,bool kt) ;

void menurequest(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h);

void allBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h);

void nameBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h);

void cateBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h);

void authorBook(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h);

void changePassword(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h);

//---------------------*MENU*-------------------------//
int menudong1(int xp,int yp,int xcu,int ycu,bool kt) ;

//---------------------*USER*-------------------------//
void user (vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach, int h);


#endif