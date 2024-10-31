#pragma once
#include <iostream>
#include "goto_draw.cpp"
#include <ctime>
#include "update.cpp"
#include "inkhung.cpp"

using namespace std;
int c;
time_t now = time(0);
tm *ltm = localtime(&now);

string get_time()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
}
string get_day()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
}
void intime()
{
	cout << " Thoi gian: " << get_time() << endl;
	cout << " Ngay: " << get_day() << endl;
}

string day()
{	
	time_t now = time(0);
tm *ltm = localtime(&now);
	return to_string(ltm->tm_mday);
}

string month()
{
	time_t now = time(0);
tm *ltm = localtime(&now);
	return to_string(1 + ltm->tm_mon);
}
string year()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return to_string(1900 + ltm->tm_year);
}