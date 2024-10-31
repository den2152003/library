#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include <sstream>
#include "update.cpp"
// #include "inkhung.cpp"
#include <algorithm>
#include "book.h"

void docfile(vector<hocsinh> &HOCSINH,long &sohs, vector<book> &sach,long &sosach)
{
  int line = -1;
  ifstream ip("data.csv");
  string username;
  string password;
  string borroww;
  string hotenn;
  string cccd;
  string dayBorrow;
  string day, month, year;
  while (ip.peek()!=EOF)
  {
    line++; // LINE = 0
    getline(ip,username,',');
    getline(ip,password,',');
    getline(ip,hotenn,',');
    getline(ip,cccd,',');
    getline(ip,borroww,'~');
    getline(ip,day,'/');
    getline(ip,month,'/');
    getline(ip,year,'\n');

    hocsinh hs;
    hs.setUserName(username);
    hs.setPassword(password);
    hs.hoten = hotenn;
    hs.setCCCD(cccd);
    hs.borrow = borroww;
    hs.day = day;
    hs.month = month;
    hs.year = year;
   
    HOCSINH.push_back(hs);
  }

  sohs = line;
  ip.close();

  ifstream ip2("danhsachsach.csv");
  line = -1;
  while (ip2.peek()!=EOF)
  {
    line++;
    book ta;
    string code;
    string bookname;
    string category;
    string amount;
    string author;
    getline(ip2,code,',');
    getline(ip2,bookname,',');
    getline(ip2,category,',');
    getline(ip2,author,',');
    getline(ip2,amount,'\n');
    

    ta.setCode(code); ta.setBookname(bookname); ta.setCategory(category); 
    ta.setAuthor(author); ta.setAmount(amount);
    sach.push_back(ta);
  }
  sosach = line;
  ip2.close();
}
