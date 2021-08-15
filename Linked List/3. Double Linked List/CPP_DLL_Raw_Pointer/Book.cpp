#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include "Book.h"

Book::Book() {
    author = "Not known";
    title = "Not known";
    price = 0U;

}

Book::Book(std::string title, std::string author, unsigned price) {
    this->title = title;
    this->author = author;
    this->price = price;
}

Book::Book(const Book& orig) {
    this->title = orig.title;
    this->author = orig.author;
    this->price = orig.price;
}

Book::~Book() {
    author.clear();
    title.clear();
    price = 0U;

}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getTitle() const {
    return title;
}

unsigned int Book::getPrice() const {
    return price;
}

bool Book::operator==(const Book& otherbook) {
    if (this->title != otherbook.title) {
        return false;
    }
    if (this->author != otherbook.author) {
        return false;
    }
    if (this->price != otherbook.price) {
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, Book& abook) {
    std::cout << std::setw(20)
        << std::setiosflags(std::ios::left)
        << "Title : " << std::setw(20) << abook.getTitle()
        << std::endl;
    std::cout << std::setw(20)
        << std::setiosflags(std::ios::left)
        << "Author : " << std::setw(20) << abook.getAuthor()
        << std::endl;
    std::cout << std::setw(20)
        << "Price       : " << std::setw(10) << std::setprecision(2)
        << std::setiosflags(std::ios::fixed)
        << abook.getPrice()
        << std::endl;
    std::cout << std::endl;
    return out;
}

