#include "Book.h"
#include "Member.h"
#include "Library.h"
#include <iostream>
using namespace std;

int main(){
    Library store;

   //add books to library
    store.addBook(Book("Normal People", "Sally Rooney", 2018));
    store.addBook(Book("The Summer of Broken Rules", "K. L. Walther", 2021));
    store.addBook(Book("Love and Other Words", "Christina Lauren", 2018));
    store.addBook(Book("Little Women", "Louisa May Alcott", 1868));
    store.addBook(Book("A Thousand Boy Kisses", "Tillie Cole", 2016));
    store.addBook(Book("Better Than The Movies", "Lynn Painter", 2021));
    store.addBook(Book("Pride And Prejudice", "Jane Austen", 1813));
    

    //adding library members
    Member member1("Marriane Sheridan");
    Member member2("Poppy Litchfield");

    store.addMember(member1);
    store.addMember(member2);
    cout << endl;
    store.displayAvailableBooks();
    cout << endl;
    store.checkoutBook("Little Women", member1);

    
    cout << endl;
    
    member1.displayCheckedoutBooks();

    cout << endl; 

    store.displayAvailableBooks();
    
    cout << endl;
    
    member2.displayCheckedoutBooks();

    store.returnBook("Little Women", member1);
    cout << endl;
    store.displayAvailableBooks();






}