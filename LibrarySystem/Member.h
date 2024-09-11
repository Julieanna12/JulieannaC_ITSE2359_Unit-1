#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Movie.h"

using namespace std;

class Member {
    private:
        string name;
        vector<Book> checkedoutBooks;

    public:
        Member();
        Member(string name);

        string getName() const;
        void checkoutBook(Book& book);
        void returnBook(Book& book);

        void displayCheckedoutBooks() const;
};

#endif // MEMBER_H