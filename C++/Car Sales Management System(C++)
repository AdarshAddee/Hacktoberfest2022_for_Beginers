#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <set>

using namespace std;

int num1 = 224550; //Car identification number -->unique for every car.
int num2 = 20000;  //user ID number -->unique for every user.
int num3 = 30000;  //temperory ID used by users for resale of cars.
int numShowrooms = 30 + rand() % 21;      // 30-50

void unique()
{
    int data;
    set<int> s1;
    set<int>::iterator itr;
    ifstream infile;
    infile.open("sales.txt");
    while (!infile.eof())
    {
        infile >> data;
        s1.insert(data);
    }
    infile.close();

    ofstream outfile;
    outfile.open("temp.txt");
    for (itr = s1.begin(); itr != s1.end(); itr++)
        outfile << *itr << " ";

    outfile.close();
    remove("sales.txt");
    rename("temp.txt", "sales.txt");
}

void printOutline()
{
    cout << "+---------+---------------+------------+---------+-----------------------+---------+-----------+-----+--------+---------+\n";
}

void printHeader()
{
    printOutline();
    cout << setw(8) << "| Car ID" << setw(15) << "| Engine Type" << setw(16) << " | Horsepower " << setw(4) << "| Mileage |" << setw(20) << "   Engine Model " << setw(4) << "|" << setw(6) << "   Seats" << setw(12) << "|  Category" << setw(7) << "| Fuel" << setw(8) << "| Colour |" << setw(4) << "  Price" << setw(3) << "|" << endl;
    printOutline();
}

class Showroom
{
public:
    int showroom_ID;     //showroom ID.

    int setID()
    {
        //creating max no.of showrooms. //nearly 30-50 showrooms are created.
        int j = 10000 + 1 + rand() % (numShowrooms); //randomly assigning a showroom ID.
        showroom_ID = j;
        return showroom_ID;
    }
};

class Cars : public Showroom
{
public:
    int engine;                //1-4.
    int hp;                    //180-200.
    int mileage;               //40-60.
    string engineName;         //name of the engine.
    int numSeats;              //2-8.
    int category;              //1-4.
    float fuelCapacity;        //tank capacity. (5-30lts)
    int color;                 //8 colors.
    int num;                   //unique identification number for every car.
    int price;                 //price of the car.
    int accessories[10] = {0}; //array used to represent 10 different accessories. //Initially initiated to zero.
    bool book = 0;

    string setEngineName() //setting the engine name. //edit this method for more names.
    {
        int i = 0 + rand() % 10;
        string names[10] = {"Supercharged DOHC V-6", "Turbocharged DOHC I-6", "Turbocharged DOHC I-4",
                            "Pentastar DOHC V-6", "DOHC V-8       ", "DOHC I-4 Drive Motor", "Tau DOHC V-8   ", "TDCI        ",
                            "IDTEC        ", "Turbo Diesel modifica"};
        return names[i];
    }

    void setAccessories() //setting the various accessories.
    {
        for (int i = 0; i < 10; i++)
        {
            int x = 0 + rand() % 1;
            accessories[i] = x;
        }
    }

    void createCars() //creating a car.
    {
        engine = 1 + rand() % 4;
        hp = 180 + rand() % 21;
        mileage = 40 + rand() % 21;
        engineName = setEngineName();
        numSeats = 2 + rand() % 7;
        category = 1 + rand() % 4;
        fuelCapacity = 5 + rand() % 25 + 1 / 123456789;
        color = 1 + rand() % 8;
        num = num1;
        price = 2000000 + rand() % (5000000 - 2000000 + 1);
        num1++;
    }

    void printDetails() //printing the details.
    {

        string temp1; //type of engine.
        if (engine == 1)
            temp1 = "Petrol";
        else if (engine == 2)
            temp1 = "Diesel";
        else if (engine == 3)
            temp1 = "Electric";
        else
            temp1 = "Hybrid";

        string temp2; //category of car.
        if (category == 1)
            temp2 = "SUV  ";
        else if (category == 2)
            temp2 = "Sedan ";
        else if (category == 3)
            temp2 = "Fleet ";
        else
            temp2 = "Hatchback";

        string temp3; //colour of car body.
        if (color == 1)
            temp3 = "Red  ";
        else if (color == 2)
            temp3 = "Orange";
        else if (color == 3)
            temp3 = "White";
        else if (color == 4)
            temp3 = "Black";
        else if (color == 5)
            temp3 = "Yellow";
        else if (color == 6)
            temp3 = "Maroon";
        else if (color == 7)
            temp3 = "Violet";
        else
            temp3 = "Brown";
        cout << "|" << setw(7) << num << setw(3) << "|" << setw(10) << temp1 << setw(6) << "|" << setw(8) << hp
             << setw(5) << "|" << setw(6) << mileage << setw(4) << "|" << setw(22) << engineName << setw(2) << "|"
             << setw(6) << numSeats << setw(4) << "|" << setw(10) << temp2 << setw(2) << "|" << setw(4) << fuelCapacity << setw(2)
             << "|" << setw(7) << temp3 << " | " << setw(6) << price << setw(2) << "|" << endl;
    }
};
class Sales : public Cars
{
public:
    void addCar(int sid, int num, Cars car[], int size) //adding a car to sales.
    {
        for (int i = 0; i < size; i++)
        {

            if (car[i].showroom_ID == sid)
            {

                ofstream f;
                f.open("sales.txt", ios::app); //sales.txt file contains all the car IDs' that are on sale.
                f << num << " ";
                f.close();
                break;
            }
        }
    }

    void deleteCar(int sid, int num, Cars car[], int size) //removing a car from sales.
    {
        for (int i = 0; i < size; i++)
        {
            if (car[i].showroom_ID == sid)
            {
                int data;
                ifstream readfile;
                readfile.open("sales.txt", ios::in);
                ofstream writefile;
                writefile.open("temp.txt", ios::out);
                while (!readfile.eof())
                {
                    readfile >> data;
                    if (data != num)
                    {
                        writefile << data << " ";
                    }
                }
                readfile.close();
                writefile.close();
                cout << "Car: " << car[i].num << " is removed from the sales.\n";
                remove("sales.txt");
                rename("temp.txt", "sales.txt"); //performing file handling to edit sales.txt file.
                break;
            }
        }
        unique();
    }

    void setPrice(int sid, int num, Cars car[], int size) //setting price manually.
    {
        int i; //used for reading from the file.
        int flag = 0;
        ifstream input_file("sales.txt");
        if (!input_file.is_open())
        {
            cerr << "Error!";
        }

        while (!input_file.eof())
        {
            input_file >> i;
            for (int j = 0; j < size; j++)
            {
                if (((car[j].num == i)) && ((car[j].showroom_ID) == sid))
                {
                    flag = 1;
                    int temp = car[j].price;
                    car[j].price = 2000000 + rand() % 7000001; //price range: (20,00,000-50,00,000).
                    cout << "\n\nCar ID: " << car[j].num << endl;
                    cout << "Price is successfully set.\n";
                    cout << "+----------------------------------+\n";
                    cout << "| Previous Price " << setw(2) << "|" << setw(2) << " Modified Price |" << endl;
                    cout << "+----------------------------------+\n";
                    cout << "|    " << temp << "      |     " << car[j].price << "    |" << endl;
                    cout << "+----------------------------------+\n";
                    cout << "\nModified Car Details:\n";
                    printHeader();
                    car[j].printDetails();
                    printOutline();
                    break;
                }
            }
            if (flag == 1)
                break;
        }

        input_file.close();
    }

    void modifySpecs(int num, int sid, Cars car[], int size, int options)    //setting other specifications of the car manually.
    {                                                                        //for demonstration purposes the inputs are generated randomly.
        int i, flag = 0;
        ifstream input_file("sales.txt");
        if (!input_file.is_open())
        {
            cerr << "Error!";
        }

        while (input_file >> i)
        {
            for (int j = 0; j < size; j++)
            {
                if (car[j].num == i && car[j].showroom_ID == sid)
                {
                    cout << "Details of car before modification:\n";
                    printHeader();
                    car[j].printDetails();
                    printOutline();

                    switch (options)
                    {
                    case 1:
                        car[j].engine = 1 + rand() % 4;
                        break;
                    case 2:
                        car[j].hp = 180 + rand() % 21;
                        break;
                    case 3:
                        car[j].mileage = 40 + rand() % 21;
                        break;
                    case 4:
                        car[j].engineName = setEngineName();
                        break;
                    case 5:
                        car[j].numSeats = 2 + rand() % 7;
                        break;
                    case 6:
                        car[j].category = 1 + rand() % 4;
                        break;
                    case 7:
                        car[j].fuelCapacity = 5 + rand() % 25 + 1 / 123456789;
                        break;
                    case 8:
                        car[j].color = 1 + rand() % 8;
                        break;
                    default:
                        cout << "Enter proper credentials.\n";
                        break;
                    }
                    flag = 1;
                    string temp[8] = {"Engine", "HorsePower", "Mileage", "Engine Name", "Number of Seats", "Category", "Fuel Capacity", "Color"};
                    cout << "Change in :" << temp[options - 1] << endl;
                    cout << "Details of the Car: " << car[j].num << " after modifications:\n";
                    printHeader();
                    car[j].printDetails();
                    printOutline();
                    break;
                }
            }
            if (flag == 1)
                break;
        }

        input_file.close();
    }
};

class User : public Cars
{
    int userID;
    int coupons;
    int total;
    string name;
    long phone;
    float tax;
    int booked;             //car ID which is booked by the user.
    int wishList[10] = {0}; //maximum of 10 cars can be added to wishlist.

public:
    string setName() //900 different names can be generated.
    {
        int i, j;
        i = 0 + rand() % 30;
        j = 0 + rand() % 30;
        string str1[30] = {"Liam ", "Olivia ", "Noah ", "Emma ", "Oliver ", "Ava ", "William ", "Sophia ", "Elijah ", "Isabella ", "James ", "Charlotte ", "Benjamin ", "Amelia ",
                           "Lucas ", "Mia ", "Mason ", "Harper ", "Ethan ", "Evelyn ", "Zion ", "Kai ", "Maeve ", "Luca ", "Nova ", "Mila ", "Quinn ", "Eliana ", "Amara ", "Lilibet "};
        string str2[30] = {"Aaran", "Aaren", "Aarez", "Aarman", "Aaron", "Aaron-James", "Aarron", "Aaryan", "Aaryn", "Aayan", "Aazaan", "Abaan", "Abbas",
                           "Abdallah", "Abdalroof", "Abdihakim", "Abdirahman", "Abdisalam",
                           "Abdul", "Abdul-Aziz", "River", "Xavier", "Isla", "Lyla", "Remi", "Rohan", "Shia", "Cecilia", "Finn", "Jesse"};
        return str1[i] + str2[j];
    }

    void createUserDetails()              //creating user details.
    {
        userID = num2;
        name = setName();
        phone = 9804560000 + rand() % (9999999999 - 9804560000 + 1); //setting up phone number.
        num2++;
    }
    void carsAvailable(Cars c[], int size) //shows the user all the available cars and their details that are on sale.
    {
        int i, num;
        ifstream input_file("sales.txt");
        if (!input_file.is_open())
        {
            cerr << "Error!";
        }
        while (input_file >> i)
        {
            for (int j = 0; j < size; j++)
            {
                if (c[j].num == i)
                {
                    c[j].printDetails();
                    break;
                }
            }
        }
        input_file.close();
    };
    void addToWishList(int x, int userid, User users[], int size)      //adding a car to wishlist.
    {
        int i;
        int flag1 = 0, flag2 = 0;

        ifstream input_file("sales.txt");
        if (!input_file.is_open())
        {
            cerr << "Error!";
        }
        while (input_file >> i)
        {
            for (int j = 0; j < size; j++)
            {
                if (x == i && userid == users[j].userID)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        if (users[j].wishList[k] == 0)
                        { //putting the car ID in the wishlist array.
                            users[j].wishList[k] = x;
                            flag1 = 1;
                            break;
                        }
                    }
                    if (flag1 == 1)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 1)
                    break;
            }
        }
        input_file.close();
    }

    void removeFromWishList(int x, int userid, User users[], int size) //removing a car from wishlist of a user.
    {
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (users[i].userID == userid)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (users[i].wishList[j] == x)
                    {
                        for (int k = j; k < 10; k++)
                        {
                            users[i].wishList[k] = users[i].wishList[k + 1];
                        }
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    users[i].accessories[9] = 0;
                    break;
                }
            }
        }
    }
    void filterPrice(int min, int max, Cars car[], int size) //printing details of the car based on price of the car.
    {
        User c;
        int key;
        ifstream input_file("sales.txt");
        if (!input_file.is_open())
        {
            cerr << "Error!";
        }
        while (input_file >> key)
        {
            for (int i = 0; i < size; i++)
            {

                if ((car[i].num == key) && ((car[i].price >= min) && (car[i].price <= max)))
                { //checking the condition and printing the car details.
                    car[i].printDetails();
                }
            }
        }
        input_file.close();
    }
    void filterSpecs(int specs[], Cars car[], int size) //printing details of all available cars based on the specifications given by user. //the specifications array is randomly generated in the main function.
    {
        Cars c;
        int key;
        int count = 0;
        ifstream input_file("sales.txt");
        if (!input_file.is_open())
        {
            cerr << "Error!";
        }
        while (input_file >> key)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (specs[j] == car[i].accessories[j])       //checking if all the accessories are same as expected by the user.
                        count++;
                }
                if (count == 10)
                    car[i].printDetails();
            }
        }
    }

    void compareInWishList(Cars car[], int size)          //prints all the details of the cars in the wishlist of a user.
    {
        int i = 0;
        Cars c;
        while (wishList[i] != 0 && i < 10)
        {
            for (int j = 0; j < size; j++)
            {
                if (wishList[i] == car[j].num)
                {
                    car[j].printDetails();
                    break;
                }
            }
            i++;
        }
    }

    void couponGenerator()
    { //generating coupons.
        ofstream file;
        file.open("coupons.txt");
        int x = 45998080 + rand() % (25998080 - 89567908) + 1;
        for (int i = 0; i < 1000; i++)
            file << x << " ";
        file.close();
        
    }

    int checkCoupon()                                          //checking if the applied coupon is valid and return the percentage of discount on car only.
    {                                                          //NO discount on accessories.
        int y = 45998080 + rand() % (25998080 - 89567908) + 1; //random input of coupon by USER.
        ifstream file;
        int key, z = 0;
        file.open("coupons.txt");
        if (!file.is_open())
        {
            cerr << "Error!";
        }
        while (file >> key)
        {
            if (y == key)
            {
                z = 10 + rand() % (40 - 10 + 1); //10-40% discount.
                break;
            }
        }
        file.close();
        return z;
    }
    void addAccessories(Cars c) //this method is to set accessories of a car by the user.
    {                           //here it is done randomly so the setAccessories() method is called.
        c.setAccessories();
    }
    int estimateTaxes(Cars c)
    {
        //GST-28%
        //Road Tax-12%
        //VAT-16%
        return (c.price * 0.28) + (c.price * 0.12) + (c.price * 0.16);
    }
    int finalPrice(Cars c, int discount)
    {
        int x = 100 - discount;
        int temp = c.accessories[0] * 2000 + c.accessories[1] * 3500 + c.accessories[2] * 750 + c.accessories[3] * 6500 + c.accessories[4] * 450 + c.accessories[5] * 950 +
                   c.accessories[6] * 3400 + c.accessories[7] * 599 + c.accessories[8] * 699 + c.accessories[9] * 1500; //setting up prices for various accessories selected for a car.
        int price = ((c.price + temp + estimateTaxes(c)) * x) / 100;
        return price;
    }
    void printBill()
    {
        cout << "------ BILL ------" << endl;
        cout << "User ID:" << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Phone. " << phone << endl;
    }

    void bookCar(int userID, int num, Cars car[], int size, User users[], int size1)
    {
        Sales s;
        int val;

        //removing the car from sale.

        for (int i = 0; i < size; i++)
        {
            if (car[i].num == num)
            {
                car[i].book = 1;
                val = i;
                s.deleteCar(car[i].showroom_ID, num, car, size);
                break;
            }
        }

        //removing the booked car from all the wishlists of all the other users.
        for (int j = 0; j < size1; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (users[j].wishList[k] == num)
                {
                    users[j].wishList[k] = 0;
                    for (int p = k; p < 10; p++)
                    {
                        users[j].wishList[p] = users[j].wishList[p + 1];
                    }
                    users[j].wishList[10] = {0};
                    break;
                }
            }
        }

        for (int s = 0; s < size1; s++)
        {
            if (users[s].userID == userID)
            {
                booked = car[val].num;
                int discount;
                cout << "\n\n";
                users[s].printBill();
                cout << "\n Price before Additional Taxes:\n";
                printHeader();
                car[val].printDetails();
                printOutline();
                discount = users[s].checkCoupon();
                cout << "Discount: " << discount << "%" <<endl;
                car[val].price = finalPrice(car[val], discount);
                cout << "\n Price after Additional Taxes and Discount:\n";
                printHeader();
                car[val].printDetails();
                printOutline();
                break;
            }
        }
    }
};

class Resale : public User, public Sales
{
    int use;    //no. of years the car is old.
    int engine; //on a scale of 0-5 engines' rating.
    int price;  //price after replacement.

public:
    int tempID;
    Cars setDetails() //setting details of a resale car.
    {
        Cars c;
        c.Cars::createCars();
        tempID = num3;
        c.showroom_ID = tempID;
        num3++;
        return c;
    }
    void addToSale(int tempid, Cars car) //adding a resale car to sale.
    {
        if (car.showroom_ID == tempid)
        {
            ofstream f;
            f.open("sales.txt", ios::app);    //sales.txt file contains all the car IDs' that are on sale.
            f << car.num;
            f.close();
        }
    }
    void modifySaleInfo(int num, Cars car, int options) //modifying the information about the resale cars.
    {
        if (car.num == num)
        {
            cout << "Details of car before modification:\n";
            printHeader();
            car.printDetails();
            printOutline();
            cout << "\n";

            switch (options)
            {
            case 1:
                car.engine = 1 + rand() % 4;
                break;
            case 2:
                car.hp = 180 + rand() % 21;
                break;
            case 3:
                car.mileage = 40 + rand() % 21;
                break;
            case 4:
                car.engineName = car.setEngineName();
                break;
            case 5:
                car.numSeats = 2 + rand() % 7;
                break;
            case 6:
                car.category = 1 + rand() % 4;
                break;
            case 7:
                car.fuelCapacity = 5 + rand() % 25 + 1 / 123456789;
                break;
            case 8:
                car.color = 1 + rand() % 8;
                break;
            default:
                cout << "Enter proper credentials.\n";
                break;
            }
            string temp[8] = {"Engine", "HorsePower", "Mileage", "Engine Model", "Number of Seats", "Category", "Fuel Capacity", "Color"};
            cout << "Change in :" << temp[options - 1] << endl;
            cout << "Details of the Car: " << car.num << " after modifications:\n";
            printHeader();
            car.printDetails();
            printOutline();
        }
    }
    void deleteSales(int tempid, Cars car) //deletes a resale car that is on sale.
    {
        if (car.showroom_ID == tempid)
        {
            int data;
            ifstream readfile;
            readfile.open("sales.txt", ios::in);
            ofstream writefile;
            writefile.open("temp.txt", ios::out);
            while (!readfile.eof())
            {
                readfile >> data;
                if (data != car.num)
                {
                    writefile << data << " ";
                }
            }
            readfile.close();
            writefile.close();
            cout << "Car: " << car.num << " is removed from the sales.\n";
            remove("sales.txt");
            rename("temp.txt", "sales.txt"); //performing file handling to edit sales.txt file.
            unique();
        }
    }

    int priceSetter(int tempID, Cars c)    //sets a price for the resale cars.
    {
        if (c.showroom_ID == tempID) //checking if the details entered are correct.
        {
            int x = 1000000 + rand() % (3000000 - 1000000 + 1);
            use = 1 + rand() % (15 - 1 + 1);
            engine = 0 + rand() % (5 - 1 + 1);
            price = ((float)x / use) * engine;
            return price;
        }
        else
            return 0;
    }
    void requestReplacement(int tempID, Cars c1, Cars c2, Cars car[], int size, User user[], int size2) //Exchanging old car and buying new car at a reduced price.
    {                                                                                                   //c1->New Car
        //c2->Old Car
        Resale r;
        if (c2.showroom_ID = tempID)
        {
            price = c1.price - priceSetter(tempID, c2);
            r.bookCar(tempID, c1.num, car, size, user, size2);
            r.deleteCar(c2.showroom_ID, c2.num, car, size);
        }
    }
};

int main()
{
    int i;
    int temp1, temp2;
    srand((unsigned)time(NULL));

    //Creating cars.
    int num_cars = 100 + rand() % (400 - 100 + 1); //No.of cars.
    cout << "List of Cars and their Details:\n";
    cout << "Number of cars in Inventory: " << num_cars << endl;
    Cars car[num_cars];

    //printing all the cars' details.
    printHeader();
    for (i = 0; i < num_cars; i++)
    {
        car[i].createCars();
        car[i].setID();
        car[i].printDetails();
    }
    printOutline();

    //creating a new file that contains all the car IDs' on sale named as "sales.txt".
    fstream f;
    f.open("sales.txt", ios::out);
    f.close();

    User customer;
    customer.couponGenerator();

    //Adding cars on sale.
    //Only the showroom owner can add the car to sale.
    Sales sale;
    for (i = 0; i < num_cars; i++)
    {
        sale.addCar(car[i].showroom_ID, i + 224550, car, num_cars); //all the cars are added to sale. //Only for showing the result.
    }

    //Deleting cars that are on sale.
    //Only showroom owner can delete a car that is on sale.
    cout << "\n\nREMOVING CAR FROM FROM SALE:\n";
    sale.deleteCar(car[4].showroom_ID, 4 + 224550, car, num_cars); //we are removing the first 10 cars that are on sale. //Only for showing the result.

    cout << "\n\nSETTING THE PRICE MANUALLY:";
    //Manually altering the price of a car by the showroom owner.
    sale.setPrice(car[3].showroom_ID, car[3].num, car, num_cars); //here price is set randomly for showong the result.

    //Modifying the accessories of a car.
    //here option is the input from user which determines what specifications to be altered by the showroom owner  of the car.
    int option = 1 + rand() % 8;
    cout << "\n\nMODIFYING DETAILS OF THE CARS:\n\n";
    sale.modifySpecs(car[5].num, car[5].showroom_ID, car, num_cars, option);

    //creating an Users list.
    int num_users = 100 + rand() % 401; //No.of users.
    User users[num_users];

    for (i = 0; i < num_users; i++)
    {
        users[i].createUserDetails(); //creating user details.
    }

    //showing the list of all the cars that are on sale.
    cout << "\n\nLIST OF ALL THE CARS THAT ARE ON SALE:\n";
    printHeader();
    customer.carsAvailable(car, num_cars);
    printOutline();

    //Adding cars to wishlist of a user.
    customer.addToWishList(224550, 20000, users, num_users);
    customer.addToWishList(224551, 20000, users, num_users);
    customer.addToWishList(224552, 20000, users, num_users);
    customer.addToWishList(224553, 20000, users, num_users);

    //printing details of cars that are in wishlist of a user.
    cout << "\n\nPrinting the details of the Cars in a users' Wishlist.\n";
    printHeader();
    users[0].compareInWishList(car, num_cars);
    printOutline();

    //removing a car from a wishlist of a user.
    customer.removeFromWishList(224551, 20000, users, num_users);
    cout << "\n\nPrinting the details of the Cars in a users' Wishlist after removing a car from the wishlist.\n";
    printHeader();
    users[0].compareInWishList(car, num_cars);
    printOutline();

    //printing details of cars that are in wishlist of a user after removing a car.
    cout << "\n\nLIST OF CARS THAT ARE ON SALE IN THE PRICE RANGE OF 20,00,000-20,16,000.\n";
    printHeader();
    customer.filterPrice(2000000, 2016000, car, num_cars);
    printOutline();

    //Adding cars to wishlist of users.
    for (int i = 0; i < 2000; i++)
    {
        temp1 = 1 + rand() % num_users + 20000;
        temp2 = 1 + rand() % num_cars + 224550;
        customer.addToWishList(temp1, temp2, users, num_users);
    }

    //Removing cars from wishlist of users.
    for (i = 0; i < 100; i++)
    {
        temp1 = 1 + rand() % num_users + 20000;
        temp2 = 1 + rand() % num_cars + 224550;
        customer.removeFromWishList(temp2, temp1, users, num_users);
    }

    //Printing Details of Cars that satisfy the required conditions of the user.
    int specs[10]; //these contain the 10 accessories that are available for every car.
    for (int i = 0; i < 10; i++)
    {
        specs[i] = 0 + rand() % 2;
    }
    cout << "\n\nPrinting the details of the Cars that satisfy users' specifications:\n";
    printHeader();
    customer.filterSpecs(specs, car, num_cars);
    printOutline();

    cout << "\n\nBILL FOR BOOKING A CAR FOR THE USER:\n";
    customer.bookCar(20000, 224552, car, num_cars, users, num_users); //booking a car by the user.
    customer.addAccessories(car[3]);                                  //setting the accessories manually.

    //Resale Cars section. //only for showing the result.
    Resale resaler;
    Cars car1;
    Cars car2;
    car1 = resaler.setDetails();
    car2 = resaler.setDetails();
    resaler.addToSale(30000, car1);
    resaler.addToSale(30001, car2);
    resaler.modifySaleInfo(car1.num, car1, option);
    resaler.priceSetter(30000, car1);
    cout << "\n\n Deleting a Resale Car:\n";
    resaler.deleteSales(30000, car1);

    cout << "\nSelling Car by Replacement with Old Car:\n";
    resaler.requestReplacement(30001, car[6], car2, car, num_cars, users, num_users);

    return 0;
}
