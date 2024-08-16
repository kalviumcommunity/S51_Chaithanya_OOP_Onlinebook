#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define the Book class
class Book {
public:
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
    // Dynamic memory allocation for Book objects
    vector<Book*> books = {
        new Book("The Great Gatsby", "F. Scott Fitzgerald", 10.99, 5),
        new Book("1984", "George Orwell", 8.99, 12),
        new Book("To Kill a Mockingbird", "Harper Lee", 12.49, 7)
    };

    // Display details and update stock for each book
    for (Book* book : books) {
        book->displayDetails();
        book->updateStock(book->stock + 3);  // Increase stock by 3
        cout << endl;
    }

    // Dynamic memory allocation for User objects
    vector<User*> users = {
        new User("Alice", "alice@gmail.com"),
        new User("Bob", "bob@gmail.com"),
        new User("Charlie", "charlie@gmail.com")
    };

    // Display information and update email for each user
    for (User* user : users) {
        user->displayInfo();
        user->updateEmail("new_" + user->email);  // Prefix email with "new_"
        cout << endl;
    }

    // Deallocate memory
    for (Book* book : books) {
        delete book;
    }

    for (User* user : users) {
        delete user;
    }

    return 0;
}
