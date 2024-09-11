#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

class Book{
    private:
        string title;
        string author;
        int yearPublished;
        bool available;

    public:
        //default constructor
        Book();

        //parametrized constructor
        Book(string title, string author, int yearPublished, bool available = "true");

        //Getter
        string getTitle() const;
        string getAuthor() const;
        int getYearPublished() const;
        bool isAvailable() const;

        //
        void checkout();
        void returnBook();
};


#endif //BOOK_H