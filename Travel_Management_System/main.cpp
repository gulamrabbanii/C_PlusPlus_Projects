#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

void menu();

class ManageMenu
{
protected:
    std::string userName;

public:
    ManageMenu()
    {
        std::cout << "\n\n\n\n\tEnter Your Name to Continue as an Admin: ";
        std::cin >> userName;
        system("CLS");
        menu();
    }
    ~ManageMenu() {}
};

class Customers
{
public:
    std::string name, gender, address;
    int age, mobileNo;
    static int cusID;
    char all[999];

    void getDetails()
    {

        std::ofstream out("old-customers.txt", std::ios::app);
        {
            std::cout << "Enter Customer ID: ";
            std::cin >> cusID;
            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << "Enter age: ";
            std::cin >> age;
            std::cout << "Enter Mobile Number: ";
            std::cin >> mobileNo;
            std::cout << "Enter Address: ";
            std::cin >> address;
            std::cout << "Enter Gender: ";
            std::cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress" << address << "\nGender: " << gender << std::endl;
        out.close();

        std::cout << "\nSAVED \nNOTE: We save your details record for future purposes\n"
                  << std::endl;
    }

    void showDetails()
    {
        std::ifstream in("old-customers.txt");
        {
            if (!in)
                std::cout << "File Error!" << std::endl;
            while (!(in.eof()))
            {
                in.getline(all, 999);
                std::cout << all << std::endl;
            }
            in.close();
        }
    }
};

int Customers::cusID;
class Cabs
{
public:
    int cabChoice, kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {
        std::cout << "We collaborated with fastest, safest, and smartest cab services arround the country" << std::endl;
        std::cout << "------------------ABC Cabs------------------" << std::endl;
        std::cout << "1. Rent a Standard Cab - Rs.15/KM" << std::endl;
        std::cout << "2. Rent a Luxury Cab - Rs.25/KM" << std::endl;
        std::cout << "\nTo calculate the cost for your journey" << std::endl;
        std::cout << "Enter which kind of cab you need: ";
        std::cin >> cabChoice;
        std::cout << "Enter Kilometers you have to travel: ";
        std::cin >> kilometers;

        int hireCab;
        switch (cabChoice)
        {
        case 1:
            cabCost = kilometers * 15;
            std::cout << "\nYour tour cost " << cabCost << " rupees for a standard cab" << std::endl;
            std::cout << "Press 1 to hire this cab or" << std::endl;
            std::cout << "Press 2 to select another cab: ";
            std::cin >> hireCab;
            system("CLS");

            switch (hireCab)
            {
            case 1:
                lastCabCost = cabCost;
                std::cout << "\nYou have successfully hired a Standard Cab" << std::endl;
                std::cout << "Goto Menu and take the receipt" << std::endl;
                break;
            case 2:
                cabDetails();
                break;
            default:
                std::cout << "Invalid Input! Redirecting to previous menu \nPlease Wait " << std::endl;
                Sleep(999);
                system("CLS");
                cabDetails();
                break;
            }
            break;
        case 2:
            cabCost = kilometers * 25;
            std::cout << "\nYour tour cost " << cabCost << " rupees for a standard cab" << std::endl;
            std::cout << "Press 1 to hire this cab or" << std::endl;
            std::cout << "Press 2 to select another cab: ";
            std::cin >> hireCab;
            system("CLS");

            switch (hireCab)
            {
            case 1:
                lastCabCost = cabCost;
                std::cout << "\nYou have successfully hired a Luxury Cab" << std::endl;
                std::cout << "Goto Menu and take the receipt" << std::endl;
                break;
            case 2:
                cabDetails();
                break;
            default:
                std::cout << "Invalid Input! Redirecting to previous menu \nPlease Wait " << std::endl;
                Sleep(999);
                system("CLS");
                cabDetails();
                break;
            }
            break;

        default:
            std::cout << "Invalid Input! Redirecting to Main menu \nPlease Wait " << std::endl;
            Sleep(1100);
            system("CLS");
            menu();
            break;
        }
        std::cout << "\nPress 1 to Redirect Main menu: " << std::endl;
        std::cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
            menu();
        else
            menu();
    }
};

float Cabs::lastCabCost;
class Booking
{
public:
    int chooseHotel, choosePack;
    static float hotelCost;

    void hotelDetails(int hotelChoice)
    {
        std::string hotelName;
        if (hotelChoice == 1)
            hotelName = "Avendra";
        else if (hotelChoice == 2)
            hotelName = "ChoiceYou";
        else
            hotelName = "Elephant Bay";

        std::cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << std::endl;
        std::cout << "Package offered by " << hotelName << ":" << std::endl;
        std::cout << "1. Standard Pack" << std::endl;
        std::cout << "\tAll basic facilities you need just for Rs.5000.00" << std::endl;
        std::cout << "2. Premium Pack" << std::endl;
        std::cout << "\tEnjoy Premium: Rs .10000.00 " << std::endl;
        std::cout << "3. Luxury Pack" << std::endl;
        std::cout << "\tLive a Luxury at " << hotelName << ": Rs.15000.00" << std::endl;

        std::cout << "\nPress another key to go back or\nEnter package number you want to book: ";
        std::cin >> choosePack;
        switch (choosePack)
        {
        case 1:
            hotelCost = 5000.00;
            std::cout << "\nYou have successfully booked Standard Pack at " << hotelName << std::endl;
            std::cout << "Goto Menu and take the receipt" << std::endl;
            break;
        case 2:
            hotelCost = 10000.00;
            std::cout << "\nYou have successfully booked Premium Pack at " << hotelName << std::endl;
            std::cout << "Goto Menu and take the receipt" << std::endl;
            break;
        case 3:
            hotelCost = 15000.00;
            std::cout << "\nYou have successfully booked Luxury Pack at " << hotelName << std::endl;
            std::cout << "Goto Menu and take the receipt" << std::endl;
            break;
        default:
            std::cout << "Invalid Input! Redirecting to Previous Menu\nPlease Wait..." << std::endl;
            Sleep(1100);
            system("CLS");
            hotels();
            int gotomenu;
            std::cout << "Press 1 to Go to Main menu: ";
            std::cin >> gotomenu;
            if (gotomenu == 1)
                menu();
            else
                menu();
        }
    }
    void hotels()
    {
        std::string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        for (int i = 0; i < 3; ++i)
        {
            std::cout << (i + 1) << ". Hotel " << hotelNo[i] << std::endl;
        }
        std::cout << "\nCurrently we collaborate with above hotels!" << std::endl;
        std::cout << "Press any key to go back or\nEnter number of the hotel you want to book: ";
        std::cin >> chooseHotel;

        system("CLS");
        switch (chooseHotel)
        {
        case 1:
            std::cout << "------------------WELCOME TO HOTEL AVENDRA------------------" << std::endl;
            hotelDetails(chooseHotel);
            break;
        case 2:
            std::cout << "-----------------WELCOME TO HOTEL CHOICE_YOU----------------" << std::endl;
            hotelDetails(chooseHotel);
            break;
        case 3:
            std::cout << "----------------WELCOME TO HOTEL ELEPHANT_BAY---------------" << std::endl;
            hotelDetails(chooseHotel);
            break;
        default:
            std::cout << "Invalid Input! Redirecting to Previous Menu\nPlease Wait..." << std::endl;
            Sleep(1100);
            system("CLS");
            hotels();
            break;
        }
        int gotomenu;
        std::cout << "Press 1 to Go to Main menu: ";
        std::cin >> gotomenu;
        if (gotomenu == 1)
            menu();
        else
            menu();
    }
};

float Booking::hotelCost;
class Charges : public Booking, Cabs, Customers
{
public:
    void printBill()
    {
        std::ofstream outf("receipt.txt");
        {
            outf << "------------------ABC Travel Agency------------------" << std::endl;
            outf << "-----------------------Receipt-----------------------" << std::endl;
            outf << "_____________________________________________________" << std::endl;
            outf << "Customer ID: " << Customers::cusID << std::endl
                 << std::endl;
            outf << "Description\t\t Total" << std::endl;
            outf << "Hotel cost:\t\t" << std::fixed << std::setprecision(2) << Booking::hotelCost << std::endl;
            outf << "Travel (cab) cost:\t" << std::fixed << std::setprecision(2) << Cabs::lastCabCost << std::endl;
            outf << "_____________________________________________________" << std::endl;
            outf << "Total Charge:\t\t" << std::fixed << std::setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << std::endl;
            outf << "_____________________________________________________" << std::endl;
            outf << "----------------------Thank You----------------------" << std::endl;
        }
        outf.close();
    }
    void showBill()
    {
        std::ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                std::cout << "File opening error!" << std::endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                std::cout << all << std::endl;
            }
        }
        inf.close();
    }
};

void menu()
{
    int menuChoice, gotoMenu, inChoice;

    std::cout << "\t\t\t* ABC Travels *\n"
              << std::endl;
    std::cout << "------------------------Main Menu------------------------" << std::endl;
    std::cout << "\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;
    std::cout << "\t|\t\t\t\t|" << std::endl;
    std::cout << "\t|Customer Management -> 1\t|" << std::endl;
    std::cout << "\t|Cabs Management     -> 2\t|" << std::endl;
    std::cout << "\t|Booking Mangement   -> 3\t|" << std::endl;
    std::cout << "\t|Charges & Bills     -> 4\t|" << std::endl;
    std::cout << "\t|Exit                -> 5\t|" << std::endl;
    std::cout << "\t|\t\t\t\t|" << std::endl;
    std::cout << "\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << std::endl;

    std::cout << "\nEnter Your Choice: ";
    std::cin >> menuChoice;
    system("CLS");
    Customers customer;
    Cabs cab;
    Booking book;
    Charges charge;

    switch (menuChoice)
    {
    case 1:
        std::cout << "---------Customers---------\n"
                  << std::endl;
        std::cout << "1. Enter New Customer" << std::endl;
        std::cout << "2. See Old Customers" << std::endl;
        std::cin >> inChoice;
        system("CLS");
        if (inChoice == 1)
            customer.getDetails();
        else if (inChoice == 2)
            customer.showDetails();
        else
        {
            std::cout << "Invalid Input! Redirecting to Previous Menu\nPlease Wait..." << std::endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        std::cout << "\nPress 1 to Redirect main menu: " << std::endl;
        std::cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
            menu();
        else
            menu();
        break;

    case 2:
        cab.cabDetails();
        break;
    case 3:
        std::cout << "--> Book a luxury Hotel using the system <--" << std::endl;
        book.hotels();
        break;
    case 4:
        std::cout << "--> Get Your Receipt <--" << std::endl;
        charge.printBill();
        std::cout << "Your receipt is already printed. You can get it from file path\n"
                  << std::endl;
        std::cout << "To display your receipt in the screen, Enter 1 or\nEnter another key to go back to main menu: ";
        std::cin >> gotoMenu;

        if (gotoMenu == 1)
        {
            system("CLS");
            charge.showBill();
            std::cout << "\n Press 1 to redirect main menu: ";
            std::cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
                menu();
            else
                menu();
        }
        else
        {
            system("CLS");
            menu();
        }
        break;
    case 5:
        std::cout << "------------GOOD-BYE------------" << std::endl;
        Sleep(1999);
        exit(0);
        break;
    default:
        std::cout << "Invalid Input! Redirecting to Previous Menu\nPlease Wait..." << std::endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu start;

    return 0;
}