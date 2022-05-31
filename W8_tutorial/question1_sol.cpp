#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

//Qa
class Book
{
    private:
        string title;
        int availableCopies;
        vector<string> namesOfBorrowers;
    
    public:
        //Constructors
        Book(){}
        Book(string title, int availableCopies, vector<string> namesOfBorrowers)
        {
            this->title = title;
            this->availableCopies = availableCopies;
            this->namesOfBorrowers = namesOfBorrowers; //we can assign vectors directly
        }

        void showInfo()
        {
            cout << "title = " << title
                 << ",availableCopies = " << availableCopies
                 << ", name of borrowers = ";
            
            for(string name: namesOfBorrowers)
            {
                cout << name << " ";
            }
            cout << "\n";
        } 

    friend class User; //grant acess to private attribute for User
};

//Qb
class User
{
    public:
        string name;
        vector<Book*> borrowedBooks; //all elements store address of Book objects --> can automatic update 

        User(){}
        User(string name,  vector<Book*> borrowedBooks)
        {
            this->name = name;
            this->borrowedBooks = borrowedBooks;
        }

        //To borrow a book from the library
        virtual bool doBorrow(Book &abook)
        {
            if(abook.availableCopies <= 0)
            {
                cout << "Not possible to borrow a book" << endl;
                return false;
            }
            //record the book in borrowedBooks
            borrowedBooks.push_back(&abook); //borrowedBooks is a vector of Book pointer

            //record borrower name in namesOfBorrowers of the book
            abook.namesOfBorrowers.push_back(name); // store value

            //reduce its availableCopies
            abook.availableCopies--;

            return true;
        }

        //To return a book 
        void doReturn(Book &abook)
        {
            //remove the book in borrowedBooks
            for(int i = 0; i < borrowedBooks.size(); i++)
            {
                if(borrowedBooks[i] == &abook) //borrowedBooks is a vector of Book pointer
                {
                    //erase at the element i if found 
                    borrowedBooks.erase(borrowedBooks.begin() + i);
                }
            }

            //remove borrower name in namesOfBorrowers of the book
            for(int i = 0; i < abook.namesOfBorrowers.size(); i++)
            {
                if(abook.namesOfBorrowers[i] == name)
                {
                    //erase at the element i if found 
                    abook.namesOfBorrowers.erase(abook.namesOfBorrowers.begin() + i);
                }
            }

            //increase its availableCopies
            abook.availableCopies ++;
        }

        //show information of the user
        void showInfo()
        {
            cout << "User name = " << name << endl;
            for(auto borrows: borrowedBooks)
            {
                cout << borrows->title << " ";
            }
            cout << endl;
        }


};

/*d)	Create another class namely SuperUser in which the doBorrow() function is overridden 
to allow the SuperUser borrow two books at a time.
    bool doBorrow(Book &book1, Book &book2):
    */
class SuperUser: public User
{
    public:
        SuperUser(){}

        SuperUser(string name, vector<Book*> borrowedBooks): User(name, borrowedBooks){}


        bool doBorrow(Book &book1, Book &book2)
        {
            if(User::doBorrow(book1) && User::doBorrow(book2))
            {
                return true;
            }
            return false;
        }
};


int main()
{
    //Book("Book 1", 5, vector<string> {"User1", "User2"});
    #if 0
    Book book1("Book 1", 5, vector<string> {});
    book1.showInfo();
    #endif

    /*Create a vector of three Book objects using dynamic memory allocation.
    Create two User objects and test all methods (with the created book objects).
    */
    vector<Book*> books = {
        new Book("Book 1", 5, vector<string> {}),
        new Book("Book 2", 10, vector<string> {}),
        new Book("Book 3", 20, vector<string> {})
    };

    User user1("User1Name", vector<Book*>{});
    User user2("User2Name", vector<Book*>{});

    user1.doBorrow(*books[0]);
    user1.doBorrow(*books[1]);
    user2.doBorrow(*books[0]);
    user2.doBorrow(*books[2]);

    books[0]->showInfo();

    user2.doReturn(*books[0]);
    books[0]->showInfo();

    user2.showInfo();

    cout << "\n\n,";
    cout << "d> ";
    SuperUser supUser1("User2Name", vector<Book*>{});
    supUser1.doBorrow(*books[0], *books[1]);
    supUser1.showInfo();

    return 0;
}