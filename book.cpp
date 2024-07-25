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
    Book(string t, string a, double p, int s) : title(t), author(a), price(p), stock(s) {}

    // Member function to display book details
    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }

    // Member function to update stock
    void updateStock(int newStock) {
        stock = newStock;
        cout << "Stock updated to " << stock << " copies" << endl;
    }
};

// Define the User class
class User {
public:

    string username;
    string email;

    // Constructor
    User(string u, string e) : username(u), email(e) {}

    // Member function to display user information
    void displayInfo() {
        cout << "Username: " << username << endl;
        cout << "Email: " << email << endl;
    }

    // Member function to update email
    void updateEmail(string newEmail) {
        email = newEmail;
        cout << "Email updated to " << email << endl;
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
