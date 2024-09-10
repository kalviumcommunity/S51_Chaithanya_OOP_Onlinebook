#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    double price;
    static int bookCount;      
    static double totalPrice;   

public:
    // Constructor
    Book() : title(""), price(0.0) {}

    // Mutator (Setter) for title
    void setTitle(string title) {
        this->title = title;
    }

    // Accessor (Getter) for title
    string getTitle() {
        return title;
    }

    // Mutator (Setter) for price
    void setPrice(double price) {
        this->price = price;
        totalPrice += price;
        bookCount++;
    }

    // Accessor (Getter) for price
    double getPrice() {
        return price;
    }

    // Function to display the book's information
    void displayBookInfo() {
        cout << "Title: " << getTitle() << endl;
        cout << "Price: Rs" << getPrice() << endl;
    }

    // Static member function to display total number of books and total price
    static void displayTotal() {
        cout << "Total number of books: " << bookCount << endl;
        cout << "Total price of all books: Rs" << totalPrice << endl;
    }
};

// Initialize static variables outside the class
int Book::bookCount = 0;
double Book::totalPrice = 0.0;

class Library {
private:
    string libraryName;
    Book* books;
    int totalBooks;

public:
    // Constructor
    Library(string name, int totalBooks) : libraryName(name), totalBooks(totalBooks) {
        books = new Book[totalBooks];
    }

    // Destructor to free memory
    ~Library() {
        delete[] books;
    }

    // Function to input book details
    void inputBookDetails() {
        for (int i = 0; i < totalBooks; ++i) {
            string title;
            double price;
            cout << "Enter title of book " << i + 1 << ": ";
            getline(cin, title);
            cout << "Enter price for book " << i + 1 << ": Rs";
            cin >> price;
            cin.ignore();

            books[i].setTitle(title);
            books[i].setPrice(price);
        }
    }

    // Function to display library and book details
    void displayLibraryInfo() {
        cout << "Library: " << libraryName << endl;
        cout << endl << "Book Information:" << endl;
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
 