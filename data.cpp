#pragma once
#include <iostream>
#include <fstream>
#include <vector>
// #include "Date.h"

using namespace std;




struct request 
{
    string IDrequest;
    int Accept;
};

class hocsinh
{
private:
	string usename;
	string passWord;
	string cccd;
	
public:
	vector<string> borrowStatus; // Vector trạng thái của từng cuốn sách mượn
	string hoten;
	
	string borrow;
	string dayBorrow;
	string day, month, year;
	void setUserName(string usename)
	{
		this->usename = usename;
	}
	string getUserName()
	{
		return usename;
	}
	void setPassword(string passWord)
	{
		this->passWord = passWord;
	}
	string getPassword()
	{
		return passWord;
	}

	void setCCCD(string cccd)
	{
		this -> cccd = cccd;
	}

	string getCCCD()
	{
		return cccd;
	}


};
struct hs2
{
	string hoten;
	int sl;
	string username;
};


