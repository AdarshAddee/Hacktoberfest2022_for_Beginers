#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class Employee {
    public:
    string first_name;
    string last_name;
    string name;
    long int code;
    string designation;
    int exp;
    int age;

    void add_entry(string name) {
        ofstream out(name);
        out.open(name);
        cout << "Enter code :" << endl;
        cin >> code;
        cout << "Enter designation of the employee :" << endl;
        cin >> designation;
        cout << "Enter experience :" << endl;
        cin >> exp;
        cout << "Enter age :" << endl;
        cin >> age;
        out << first_name << endl;
        out << last_name << endl;
        out << code << endl;
        out << designation << endl;
        out << exp << endl;
        out << age << endl;
        out.close();
    }

    void delete_entry() {
        cout << "Enter the name of record to be deleted :" << endl;
        string name_del;
        cin >> name_del;
        remove(name_del.c_str());
        cout << "Entry deleted successfully" << endl;
    }

    void search_entry() {
        cout << "Enter the name of the employee :" << endl;
        string name_search;
        cin >> name_search;
        ifstream in;
        in.open(name_search + ".txt");
        string age_s;
        string code_s;
        string exp_s;
        if (in.is_open()) {
            getline(in, first_name);
            getline(in, last_name);
            getline(in, code_s);
            getline(in, designation);
            getline(in, exp_s);
            getline(in, age_s);

            cout << "First Name : " << first_name << endl;
            cout << "Last Name : " << last_name << endl;
            cout << "Code : " << code_s << endl;
            cout << "Designation : " << designation << endl;
            cout << "Experience : " << exp_s << " Years" << endl;
            cout << "Age : " << age_s << " Years" << endl;
         }
    }
};

int main() {
    Employee em;
    cout << "Please select from the given options :" << endl << endl;
    cout << "Add a new entry---------(1)" << endl;
    cout << "Delete an entry---------(2)" << endl;
    cout << "Search for an entry-----(3)" << endl;
    int select;
    cin >> select;
    if(select == 1) {
        cout << "Enter first name :" << endl;
        cin >> em.first_name;
        cout << "Enter last name :" << endl;
        cin >> em.last_name;
        em.name = em.first_name + " " + em.last_name + ".txt";
        em.add_entry(em.name);
    }
    if(select == 2) {
        em.delete_entry();
    }
    if(select == 3) {
        em.search_entry();
    }
}