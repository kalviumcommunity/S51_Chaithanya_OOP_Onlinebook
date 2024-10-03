#include <iostream>
#include <string>
using namespace std;

// Abstract Base class: Book
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
    virtual ~Book() {
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
    virtual void displayBookInfo() {
        cout << "Title: " << getTitle() << endl;
        cout << "Price: Rs" << getPrice() << endl;
    }

    // Pure virtual function
    virtual void displayBookType() = 0; // Pure virtual function (abstract)

    // Static member function
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
    // Parameterized Constructor
    PrintedBook(string title, double price) : Book(title, price) {}

    void displayBookInfo() override {
        Book::displayBookInfo(); // Call base class function
        cout << "Book Type: Printed" << endl;
    }

    void displayBookType() override {
        cout << "This is a Printed Book." << endl;
    }
};

// Derived class: EBook (Single Inheritance)
class EBook : public Book {
private:
    double fileSize; // Size in MB
    string format;   // e.g., PDF, EPUB

public:
    // Parameterized Constructor
    EBook(string title, double price, double fileSize, string format)
        : Book(title, price), fileSize(fileSize), format(format) {}

    void displayBookInfo() override {
        Book::displayBookInfo(); // Call base class function
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }

    void displayBookType() override {
        cout << "This is an EBook." << endl;
    }
};

// Derived class: Library (Multilevel Inheritance)
class Library {
private:
    string libraryName;
    Book** books; // Using pointer to an array of pointers for polymorphism
    int totalBooks;

public:
    // Parameterized Constructor
    Library(string name, int totalBooks)
        : libraryName(name), totalBooks(totalBooks) {
        books = new Book*[totalBooks]; // Dynamic allocation for polymorphism
    }

    ~Library() {
        for (int i = 0; i < totalBooks; ++i) {
            delete books[i]; // Deleting dynamically allocated books
        }
        delete[] books;
        cout << "Library destructor called. Memory released for books." << endl;
    }

    // Input book details
    void inputBookDetails() {
        for (int i = 0; i < totalBooks; ++i) {
            string title;
            double price;
            char choice, bookType;
            cout << "Enter title of book " << i + 1 << ": ";
            getline(cin, title);

            cout << "Do you want to enter a price? (y/n): ";
            cin >> choice;
            cin.ignore();

            if (choice == 'y' || choice == 'Y') {
                cout << "Enter price for book " << i + 1 << ": Rs";
                cin >> price;
                cin.ignore();
            } else {
                price = 100.0; // Default price
            }

            cout << "Enter book type: 'P' for Printed, 'E' for EBook: ";
            cin >> bookType;
            cin.ignore();

            if (bookType == 'P' || bookType == 'p') {
                books[i] = new PrintedBook(title, price);
            } else if (bookType == 'E' || bookType == 'e') {
                double fileSize;
                string format;
                cout << "Enter file size (in MB): ";
                cin >> fileSize;
                cin.ignore();
                cout << "Enter format (PDF/EPUB): ";
                getline(cin, format);
                books[i] = new EBook(title, price, fileSize, format);
            }
        }
    }

    void displayLibraryInfo() {
        cout << "Library: " << libraryName << endl;
        cout << "Book Information:" << endl;
        for (int i = 0; i < totalBooks; ++i) {
            cout << "Book " << i + 1 << ":" << endl;
            books[i]->displayBookInfo(); // Polymorphic call
            books[i]->displayBookType();  // Polymorphic call
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
