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
    void setValues(string title, double price) {
        this->title = title;
        this->price = price;
        bookCount++;
        totalPrice += price;      
    }

    void displayBookInfo() {
        cout << "Title: " << title << endl;
        cout << "Price: Rs" << price << endl;
    }

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

    for (int i = 0; i < totalBooks; ++i) {
        string title;
        double price;
        cout << "Enter title of book " << i + 1 << ": ";
        getline(cin, title);
        cout << "Enter price for book " << i + 1 << ": Rs";
        cin >> price;
        cin.ignore();

        arr[i].setValues(title, price);
    }

    cout << endl << "Book Information in arr:" << endl;
    for (int i = 0; i < totalBooks; ++i) {
        cout << "Book " << i + 1 << ":" << endl;
        arr[i].displayBookInfo();
        cout << endl;
    }

    // Display total number of books and the total price of all books
    Book::displayTotal();

    delete[] arr;

    return 0;
}
