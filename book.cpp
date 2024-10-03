#include <iostream>
#include <string>
using namespace std;

// Base class: Book
class Book {
private:
    string title;
    double price;
    static int bookCount;
    static double totalPrice;

public:
    // Default Constructor
    Book() : title(""), price(0.0) {}

    // Parameterized Constructor
    Book(string title, double price) : title(title), price(price) {
        bookCount++;
        totalPrice += price;
    }

    // Constructor Overloading: Constructor with default price
    Book(string title) : title(title), price(100.0) { // Default price set to 100.0
        bookCount++;
        totalPrice += price;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called for book: " << title << endl;
    }

    // Mutators and Accessors
    void setTitle(string title) { this->title = title; }
    string getTitle() { return title; }
    void setPrice(double price) {
        totalPrice -= this->price; // Adjust total price before changing
        this->price = price;
        totalPrice += price;
    }
    double getPrice() { return price; }

    // Display book information
    void displayBookInfo() {
        cout << "Title: " << getTitle() << endl;
        cout << "Price: Rs" << getPrice() << endl;
    }

    // Static member function
    static void displayTotal() {
        cout << "Total number of books: " << bookCount << endl;
        cout << "Total price of all books: Rs" << totalPrice << endl;
    }
};

// Initialize static variables
int Book::bookCount = 0;
double Book::totalPrice = 0.0;

// Derived class: EBook (Single Inheritance)
class EBook : public Book {
private: 
    double fileSize; // Size in MB
    string format; // e.g., PDF, EPUB

public:
    // Parameterized Constructor
    EBook(string title, double price, double fileSize, string format)
        : Book(title, price), fileSize(fileSize), format(format) {}

    void displayBookInfo() {
        Book::displayBookInfo(); // Call base class function
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }
};

// Derived class: Library (Multilevel Inheritance)
class Library {
private:
    string libraryName;
    Book* books;
    int totalBooks;

public:
    // Parameterized Constructor
    Library(string name, int totalBooks)
        : libraryName(name), totalBooks(totalBooks) {
        books = new Book[totalBooks]; // Dynamic allocation
    }

    ~Library() {
        delete[] books;
        cout << "Library destructor called. Memory released for books." << endl;
    }

    // Input book details
    void inputBookDetails() {
        for (int i = 0; i < totalBooks; ++i) {
            string title;
            double price;
            char choice;
            cout << "Enter title of book " << i + 1 << ": ";
            getline(cin, title);

            cout << "Do you want to enter a price? (y/n): ";
            cin >> choice;
            cin.ignore(); 

            if (choice == 'y' || choice == 'Y') {
                cout << "Enter price for book " << i + 1 << ": Rs";
                cin >> price;
                cin.ignore(); 
                books[i] = Book(title, price);  
            } else {
                books[i] = Book(title); 
            }
        }
    }

    void displayLibraryInfo() {
        cout << "Library: " << libraryName << endl;
        cout << "Book Information:" << endl;
        for (int i = 0; i < totalBooks; ++i) {
            cout << "Book " << i + 1 << ":" << endl;
            books[i].displayBookInfo();
            cout << endl;
        }
        Book::displayTotal();
    }
};

int main() {
    string libraryName;
    int totalBooks;

    cout << "Enter the name of the library: ";
    getline(cin, libraryName);
    cout << "Enter the total number of books: ";
    cin >> totalBooks;
    cin.ignore();

    Library library(libraryName, totalBooks);

    // Input book details
    library.inputBookDetails();

    // Display library and book information
    library.displayLibraryInfo();

    return 0;
}
