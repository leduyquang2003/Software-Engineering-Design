/*a)	Defines a class namely Book with following private attributes and public methods (also provide constructor for it):
o	title (string)
o	availableCopies (integer) which is the number of copies of the book which are available to borrow. 
o	namesOfBorrowers (vector of strings) which are names of the book’s borrowers.
*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
class Book
{
    private:
        std::string title;
        int availableCopies;
        std::vector<std::string> namesofBorrowers;
    
    public:
        Book(){};
        Book(std::string title_val, int availableCopies_val, std::vector<std::string> namesofBorrowers_val)
        {
            this->title = title_val;
            this->availableCopies = availableCopies_val;
            this->namesofBorrowers = namesofBorrowers_val;
        }

        void show_info_Book()
        {
            std::cout << "Title of the book: " << title << std::endl;
            std::cout << "Number of available Copies: " << availableCopies << std::endl;
            std::cout << "Name of Borrowers: " << std::endl;
            for(std::string &names: namesofBorrowers)
            {
                std::cout << names << ", ";
            }
            std::cout << std::endl;
        } 

        int reduce()
        {
            availableCopies = availableCopies - 1;
            return availableCopies;
        }

        int return_book()
        {
            availableCopies = availableCopies + 1;
            return availableCopies;
        }

        
};

/*b)	Define another class namely User with following attributes and public methods (also provide constructor for it):
o	name (string)
o	borrowedBooks (vector of pointers of Book objects).
o	bool doBorrow(Book &abook): to borrow a book from the library (must record the book in borrowedBooks, borrower name in namesOfBorrowers of the book and reduce its availableCopies). 
o	void doReturn(Book &abook):  to return a book to the library (reverse the activities above).
Create a vector of three Book objects using dynamic memory allocation.
Create two User objects and test all methods (with the created book objects).
*/

bool T = true;
bool F = false;

class User
{
    public:
        std::string name;
        std::vector<Book*> borrowedBooks;

        User(){}
        User(std::string name_val)
        {
            this->name = name_val;
        }

        bool doBorrow(Book &abook)
        {
            borrowedBooks.push_back(&abook);
            return T;
        }

        /*o	void doReturn(Book &abook):  to return a book to the library (reverse the activities above).*/
        void doReturn(Book &abook)
        {
            std::cout << "Book is returned successfully" << std::endl;
            if(T)
            {
                for(Book *books: borrowedBooks)
                {
                    books->return_book();
                }
            }
        }

        void show_info_User()
        {
            // std::cout << "User name: " << name << std::endl;
            // std::cout << "Name of borrowers: " << std::endl;
            for(Book *books: borrowedBooks)
            {
                books->reduce();
                books->show_info_Book();
            }
        }

};

/*d)	Create another class namely SuperUser in which the doBorrow() function is overridden 
to allow the SuperUser borrow two books at a time.
    bool doBorrow(Book &book1, Book &book2):
    */
class SuperUser: public User
{
    public:
        bool doBorrow(Book &book1, Book &book2)
        {
            borrowedBooks.push_back(&book1);
            borrowedBooks.push_back(&book2);
            return true;
        }
};

int main()
{
    std::cout << "a) " << std::endl;
    Book book1("Jungle", 20, {"Nguyen Tuong Khang", "Jacey"});
    book1.show_info_Book();

    std::cout << "\n\n";
    std::cout << "b) " << std::endl;
    User user1("David");
    user1.doBorrow(book1);
    user1.doReturn(book1);
    user1.doReturn(book1);
    user1.show_info_User();

    /*Create a vector of three Book objects using dynamic memory allocation.*/
    std::cout << "\n\n";
    std::cout << "Create a vector of three Book objects using dynamic memory allocation: " << std::endl;
    std::vector<Book*> book_objs = {new Book("Life of Pi", 30, {"Duy"}),
        new Book("Myback", 2, {"Sophia", "John"}), new Book("The Knife", 5, {"Jeff"})};
    for(Book *books: book_objs)
    {
        books->show_info_Book();
    }    

    std::cout << "\n\n";
    std::cout << "Test book_obj call in user" << std::endl;
    User user2("Kai");
    user2.doBorrow(*book_objs[1]);
    user2.show_info_User();

    /*c)	What is the relationship type between Book and User classes? Draw class diagram for the above program.*/
    // passing objects of class Book as arguments to methods of class User
    //--> class User depends on class Book
    

    /*d)	Create another class namely SuperUser in which the doBorrow() function is overridden 
    to allow the SuperUser borrow two books at a time.
        bool doBorrow(Book &book1, Book &book2):
        */
    std::cout << "d)	Create another class namely SuperUser in which the doBorrow() function is overridden to allow the SuperUser borrow two books at a time." << std::endl;
    SuperUser user3;
    user3.doBorrow(*(book_objs[0]), *(book_objs[1]));
    user3.show_info_User();    

    return 0;
}
