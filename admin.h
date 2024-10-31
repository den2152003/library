#ifndef ADMIN_CPP
#define ADMIN_CPP
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

void timKiemThongTinSV(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach);

//---------*tong so sach dang duoc muon*-----------------//
void sachBorrow(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach);

//---------*muonsach*-----------------//
void muonSach(vector<hocsinh>& HOCSINH, long sohs, vector<book>& sach, long sosach) ;

//---------*trasach*-----------------//
void traSach(vector<hocsinh>& HOCSINH, long sohs, vector<book>& sach, long sosach) ;

//---------*quan ly sach*-----------------//
void quanLySach(vector<book> sach, long sosach);

//---------*them sach*-----------------//
void themSach(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach);


//---------*menu-book*-----------------//
int menudongBook(int xp,int yp,int xcu,int ycu,bool kt) ;

//---------*menu-sinhvien*-----------------//
int menudongSV(int xp,int yp,int xcu,int ycu,bool kt) ;

//---------*menu-admin*-----------------//
int menudongmain(int xp,int yp,int xcu,int ycu,bool kt) ;

//---------*admin-sinhvien*------------//
void adminSV(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach);

//---------*admin-book*------------//
void adminBook(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach);

//---------*admin*------------//
void admin(vector<hocsinh> &HOCSINH, long &sohs, vector<book> &sach, long &sosach);


#endif