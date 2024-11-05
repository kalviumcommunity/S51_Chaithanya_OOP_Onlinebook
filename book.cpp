#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Base class: Book
class Book {
protected:
    string title;
    double price;
    static int bookCount;
    static double totalPrice;

public:
    // Constructor Overloading: Default, Parameterized, Default Price
    Book() : title(""), price(0.0) {}
    Book(string title, double price) : title(title), price(price) {
        bookCount++;
        totalPrice += price;
    }
    Book(string title) : title(title), price(100.0) {
        bookCount++;
        totalPrice += price;
    }
    virtual ~Book() { cout << "Destructor called for book: " << title << endl; }

    // Accessors and Mutators
    void setTitle(string title) { this->title = title; }
    string getTitle() const { return title; }
    void setPrice(double price) {
        totalPrice -= this->price;
        this->price = price;
        totalPrice += price;
    }
    double getPrice() const { return price; }

    virtual void displayBookInfo() const {
        cout << "Title: " << getTitle() << endl;
        cout << "Price: Rs" << getPrice() << endl;
    }
    virtual void displayBookType() const = 0;

    static void displayTotal() {
        cout << "Total number of books: " << bookCount << endl;
        cout << "Total price of all books: Rs" << totalPrice << endl;
    }
};

// Initialize static variables
int Book::bookCount = 0;
double Book::totalPrice = 0.0;

// Derived class: PrintedBook (Single Inheritance)
class PrintedBook : public Book {
public:
    PrintedBook(string title, double price) : Book(title, price) {}
    void displayBookInfo() const override {
        Book::displayBookInfo();
        cout << "Book Type: Printed" << endl;
    }
    void displayBookType() const override {
        cout << "This is a Printed Book." << endl;
    }
};

// Derived class: EBook (Single Inheritance)
class EBook : public Book {
private:
    double fileSize;
    string format;

public:
    EBook(string title, double price, double fileSize, string format)
        : Book(title, price), fileSize(fileSize), format(format) {}
    void displayBookInfo() const override {
        Book::displayBookInfo();
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }
    void displayBookType() const override {
        cout << "This is an EBook." << endl;
    }
};

// Interface: IBookDisplay (Supports DIP and SRP)
class IBookDisplay {
public:
    virtual void display(const Book* book) const = 0;
};

// Concrete class implementing IBookDisplay
class BookDisplay : public IBookDisplay {
public:
    void display(const Book* book) const override {
        book->displayBookInfo();
        book->displayBookType();
    }
};

// Library class (Updated for SRP and DIP)
class Library {
private:
    string libraryName;
    vector<Book*> books;
    IBookDisplay* bookDisplay;

public:
    Library(string name, IBookDisplay* displayService)
        : libraryName(name), bookDisplay(displayService) {}

    void addBook(Book* book) {
        books.push_back(book);
    }

    void displayLibraryInfo() const {
        cout << "Library: " << libraryName << endl;
        for (const auto& book : books) {
            bookDisplay->display(book);
            cout << endl;
        }
        Book::displayTotal();
    }

    ~Library() {
        for (auto book : books) {
            delete book;
        }
        cout << "Library destructor called. Memory released for books." << endl;
    }
};

int main() {
    IBookDisplay* bookDisplay = new BookDisplay;
    Library library("City Library", bookDisplay);

    // Add books
    library.addBook(new PrintedBook("The Great Gatsby", 300.0));
    library.addBook(new EBook("Learn C++", 150.0, 2.5, "PDF"));

    // Display library information
    library.displayLibraryInfo();

    delete bookDisplay; // Clean up dynamic memory for display
    return 0;
}
