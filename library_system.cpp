#include<bits/stdc++.h>
#define sp " "
#define endl "\n"
#define ll long long
using namespace std;

struct book_info
{
    int id;
    string name;
    int quantity;
    int borrowed = 0;

};
vector<book_info> add;
void add_book()
{
    book_info x;
    cout << "Enter book info: id & name & quantity: ";
    cin >> x.id >> x.name >> x.quantity;
    add.push_back(x);
    cout << "Successful process." << "\n\n";
}


void search()
{
    cout << "Enter book name prefix: ";
    string name;
    cin >> name;
    int sz = name.size();
    bool found = false;
    for(int i = 0; i < add.size(); i++)
    {
        if(name == add[i].name.substr(0,sz))
        {
            cout << add[i].name << endl;
            found = true;
        }
    }
    if(!found)
        cout << "No books with such prefix." << endl;
    cout << endl;
}


bool comp_id(const book_info &a, const book_info &b)
{
    return a.id < b.id;
}
void print_by_id()
{
    sort(add.begin(), add.end(), comp_id);
    cout << endl;
    for(int i = 0; i < add.size(); i++)
    {
        cout << "ID: " << add[i].id << "  "; 
        cout << "Name: " << add[i].name << "  ";
        cout << "Quantity: " << add[i].quantity << "  ";
        cout << "Borrowed: " << add[i].borrowed << endl;
    }
    cout << endl;
}


bool comp_name(const book_info &a, const book_info &b)
{
    return a.name < b.name;
}
void print_by_name()
{
    sort(add.begin(), add.end(), comp_name);
    cout << endl;
    for(int i = 0; i < add.size(); i++)
    {
        cout << "ID: " << add[i].id << "  "; 
        cout << "Name: " << add[i].name << "  ";
        cout << "Quantity: " << add[i].quantity << "  ";
        cout << "Borrowed: " << add[i].borrowed << endl;
    }
    cout << endl;
}


struct user
{
    string name;
    ll id;
    vector<int> books;
};
vector<user> users;
void add_user()
{
    user x;
    cout << "Enter user name and national id: ";
    cin >> x.name >> x.id;
    users.push_back(x);
    cout << "Successful process." << "\n\n";
}


void user_borrow_book()
{
    cout << "Enter user name: ";
    string name;
    string book;
    cin >> name;
    bool found = false;
    int user_idx = 0;
    for(int i = 0; i < users.size(); i++)
    {
        if(name == users[i].name)
        {
            found = true;
            user_idx = i;
            break;
        }
    }
    if(!found)
    {
        cout << "This user is not registered in the system.";
        cout << "\n\n";
        return;
    }
    cout << "Enter the book name: ";
    cin >> book;
    bool book_found = false;
    for(int i = 0; i < add.size(); i++)
    {
        if(book == add[i].name)
        {
            book_found = true;
            if(add[i].quantity > add[i].borrowed)
            {
                add[i].borrowed++;
                users[user_idx].books.push_back(add[i].id);
                cout << "Successful process." << "\n\n";
            }
            else
            {
                cout << "This book is not avilable.";
                cout << "\n\n";
            }
            break;
        }
    }
    if(!book_found)
    {
        cout << "This book is not exist in the system." << "\n\n";
    }
}


void return_book()
{
    cout << "Enter user name and book name: ";
    string name;
    string book;
    cin >> name >> book;
    bool found = false;
    int user_idx = 0;
    for(int i = 0; i < users.size(); i++)
    {
        if(name == users[i].name)
        {
            found = true;
            user_idx = i;
            break;
        }
    }
    if(!found)
    {
        cout << "This user is not registered in the system." << "\n\n";
        return;
    }

    bool find_book = false;
    int book_id;
    for(int i = 0; i < add.size(); i++)
    {
        if(book == add[i].name)
        {
            find_book = true;
            book_id = add[i].id;
            break;
        }
    }
    if(!find_book)
    {
        cout << "This book is not exist in the system." << "\n\n";
        return;
    }
    bool is_user_borrowed_the_book = false;
    for(int i = 0; i < users[user_idx].books.size(); i++)
    {
        if(book_id == users[user_idx].books[i])
        {
            is_user_borrowed_the_book = true;;
            users[user_idx].books.erase(users[user_idx].books.begin() + i);
            add[i].borrowed--;
            cout << "Successful process." << "\n\n";
            break;
        }        
    }
    if(!is_user_borrowed_the_book)
        cout << "You have not borrowed this book." << "\n\n";
}


void who_borrowed_books_by_name()
{
    cout << "Enter the book name: ";
    string name;
    cin >> name;
    int book_id;
    bool found = false;
    for(int i = 0; i < add.size(); i++)
    {
        if(name == add[i].name)
        {
            book_id = add[i].id;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout << "This book is not exist in the system\n\n";
        return;
    }
    bool name_found = false;
    for(int i = 0; i < users.size(); i++)
    {
        for(int j = 0; j < users[i].books.size(); j++)
        {
            if(book_id == users[i].books[j])
            {
                name_found = true;
                cout << users[i].name << endl;
                continue;
            }
        }
    }
    if(!name_found)
    {
        cout << "Nobody borrowed this book." << endl;
    } 
    cout << endl;
}

bool comp_user_id(const user &a, const user &b)
{
    a.id < b.id;
}
void all_users()
{
    cout << endl;
    bool found = false;
    sort(users.begin(), users.end(), comp_user_id);
    for(int i = 0; i < users.size(); i++)
    {
        found = true;
        cout << "User: " << users[i].name << "  ";
        cout << "ID: " << users[i].id << "  ";
        cout << "Borrowed Books: ";
        sort(users[i].books.begin(), users[i].books.end());
        for(int j = 0; j < users[i].books.size(); j++)
        {
            cout << users[i].books[j] << sp;
        }
        cout << endl;
    }
    if(!found)
    {
        cout << "There are no users registered in the system." << endl;
    }
    cout << endl;
}


void library_menu()
{
    while(true)
    {
        cout << "Library Menu:" << endl;
        cout << "1) Add book" << endl;
        cout << "2) Search for books" << endl;
        cout << "3) Print who borrowed a book by name" << endl;
        cout << "4) Print library by ID" << endl;
        cout << "5) Print library by name" << endl;
        cout << "6) Add user" << endl;
        cout << "7) User borrow book" << endl;
        cout << "8) User return book" << endl;
        cout << "9) Print all users" << endl;
        cout << "10) Exit" << endl;
        cout << "Please select an option (1-10): ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            add_book();
        }
        else if(choice == 2)
        {
            search();
        }
        else if(choice == 3)
        {
            who_borrowed_books_by_name();
        }
        else if(choice == 4)
        {
            print_by_id();
        }
        else if(choice == 5)
        {
            print_by_name();
        }
        else if(choice == 6)
        {
            add_user();
        }
        else if(choice == 7)
        {
            user_borrow_book();
        }
        else if(choice == 8)
        {
            return_book();
        }
        else if(choice == 9)
        {
            all_users();
        }
        else if(choice == 10)
        {
            cout << "Exiting the library system." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << "\n\n";
        }
    }
}
int main()
{
    library_menu();
    return 0;
}