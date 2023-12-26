#include <iostream>
#include <fstream>
using namespace std;
class temp
{
    string username, email, password;
    string searchname, searchpass, searchemail;
    fstream file;

public:
    void login();
    void signup();
    void forget();

} obj;

int main()
{
    char choice;
    cout << "\n1-LOGIN";
    cout << "\n2-SIGN-UP";
    cout << "\n3-FORGET PASSWORD";

    cout << "\n4-EXIT";
    cout << "\n enter the choice:";
    cin >> choice;
    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signup();
        break;
    case '3':
        cin.ignore();
        obj.forget();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "invalid selection:";
    }
}
void temp::signup()
{
    cout << "\n enter your name ::";
    getline(cin, username);
    cout << "enter your email address::";
    getline(cin, email);
    cout << "enter your password::";
    getline(cin, password);
    file.open("loginData.txt", ios ::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();
}
void temp::login()
{
    cout << "----------LOGIN" << endl;
    cout << "enter your user name";
    getline(cin, searchname);
    cout << "enter ypur password ::" << endl;
    getline(cin, searchpass);

    file.open("loginData.txt", ios::in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (username == searchname)
        {
            if (password == searchpass)
            {
                cout << "\n Account login succesfull......!";
                cout << "\nusername  ::" << username << endl;
                cout << "\nemail ::" << email << endl;
            }
            else
            {
                cout << "password is incorrect";
            }
        }
        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    file.close();
}
void temp::forget()
{
    cout << "\n enter your user name";
    getline(cin, searchname);
    cout << "\n enter your email address ::";
    getline(cin, searchemail);

    file.open("logindata.txt", ios::in);
    getline(file, username, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (username == searchname)
        {
            if (email == searchemail)
            {
                cout << "\n Account found...." << endl;
                cout << "your password ::" << password << endl;
            }
            else
            {
                cout << "not found..\n";
            }
        }
        else
        {
            cout << "not found.....\n";
        }
        getline(file, username, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    file.close();
}
