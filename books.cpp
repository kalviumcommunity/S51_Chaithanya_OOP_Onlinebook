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

int main() {
    int totalBooks;
    cout << "Enter the total number of books: ";
    cin >> totalBooks;
    cin.ignore();
    Book* arr = new Book[totalBooks];

    // Input book details
    for (int i = 0; i < totalBooks; ++i) {
        string title;
        double price;
        cout << "Enter title of book " << i + 1 << ": ";
        getline(cin, title);
        cout << "Enter price for book " << i + 1 << ": Rs";
        cin >> price;
        cin.ignore();

        arr[i].setTitle(title);
        arr[i].setPrice(price);
    }

    // Display book information
    cout << endl << "Book Information:" << endl;
    for (int i = 0; i < totalBooks; ++i) {
        cout << "Book " << i + 1 << ":" << endl;
        arr[i].displayBookInfo();
        cout << endl;
    }

    // Display total number of books and the total price of all books
    Book::displayTotal();

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
