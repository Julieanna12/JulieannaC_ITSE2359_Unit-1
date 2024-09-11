#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Member.h"

using namespace std;


class Library {
    private:
        vector<Book> inventory;
        vector<Member> Members;

    public:
        void addBook(const Bool& book);
        void addMember(const Member& member);

        void checkoutBook(const string& bookTitle, Member& member);
        void returnBook(const string& bookTitle, Member& member);

        void displayAvailableBooks() const;
};


#endif // LIBRARY_H