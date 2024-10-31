#pragma once
#include "book.h"

// struct book
// {
// 	string code;
// 	string bookname;
// 	string category;
// 	string amount;
// 	int sl;
// 	//	string price;
// };



void book::setCode(string code) {
    this->code = code;
}

void book::setBookname(string bookname) {
    this->bookname = bookname;
}

void book::setCategory(string category) {
    this->category = category;
}


void book::setAmount(string amount) {
    this->amount = amount;
}

void book::setfixedAmount(int fixedAmount) 
{
    this->fixedAmount = fixedAmount;
}

void book::setAuthor(string author)
{
    this->author = author;
}
    
void book::setStatus(string status)
{
    this->status = status;
}



string book::getCode() {
    return code;
}

string book::getBookname() {
    return bookname;
}

string book::getCategory() {
    return category;
}


string book::getAmount() {
    return amount;
}

int book::getfixedAmount() 
{
    return fixedAmount;
}

string book::getAuthor()
{
    return author;
}

string book::getStatus()
{
    return status;
}

