#include <iostream>
#include <string>
using namespace std;

// Define the Book class
class Book {
public:
    // Attributes
    string title;
    string author;
    double price;
    int stock;

    // Constructor
    Book(string title, string author, double price, int stock) {
        this->title = title;
        this->author = author;
        this->price = price;
        this->stock = stock;
    }

    // Member function to display book details
    void displayDetails() {
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Price: $" << this->price << endl;
        cout << "Stock: " << this->stock << " copies" << endl;
    }

    // Member function to update stock
    void updateStock(int stock) {
        this->stock = stock;
        cout << "Stock updated to " << this->stock << " copies" << endl;
    }
};

// Define the User class
class User {
public:
    string username;
    string email;

    // Constructor
    User(string username, string email) {
        this->username = username;
        this->email = email;
    }

    // Member function to display user information
    void displayInfo() {
        cout << "Username: " << this->username << endl;
        cout << "Email: " << this->email << endl;
    }

    // Member function to update email
    void updateEmail(string email) {
        this->email = email;
        cout << "Email updated to " << this->email << endl;
    }
};

int main() {
    // Instantiate Book objects
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 10.99, 5);
    Book book2("1984", "George Orwell", 8.99, 12);

    // Display details and update stock
    book1.displayDetails();
    book1.updateStock(7);

    book2.displayDetails();
    book2.updateStock(15);

    // Instantiate User objects
    User user1("Alice", "alice@gmail.com");
    User user2("Bob", "bob@gmail.com");

    // Display information and update email
    user1.displayInfo();
    user1.updateEmail("alicegirl@email.com");

    user2.displayInfo();
    user2.updateEmail("bobboy@email.com");

    return 0;
}
