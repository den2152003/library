#ifndef BOOK_H
#define BOOK_H
#include<string>
#include<iostream>
using namespace std;

class book 
{
private:
    string code;
	string bookname;
	string category;
	string amount;
    string author;
    int fixedAmount;
    string status;
public:
    

    void setCode(string code);
    void setBookname(string bookname);
    void setCategory(string category);
    void setAmount(string amount);
    void setAuthor(string author);
    void setfixedAmount(int);
    void setStatus(string status);

    string getCode();
    string getBookname();
    string getCategory();
    string getAmount();
    string getAuthor();

    int getfixedAmount();

    string getStatus();
};

struct book2
{
	string code;
	string bookname;
	int sl;
	string category;
};

#endif