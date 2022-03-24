#include <iostream>
#include <fstream>

using namespace std;

class Shopping
{
private:
    int p_code;
    float price, dis;
    string p_name;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void Shopping::menu()
{
m:
    int choice;
    string email, passwd;
    cout << "\t\t\t\t|-------------------------------------------|\n";
    cout << "\t\t\t\t|                                           |\n";
    cout << "\t\t\t\t|         Super Market Main Menu            |\n";
    cout << "\t\t\t\t|                                           |\n";
    cout << "\t\t\t\t|-------------------------------------------|\n\n";
    cout << "\t\t\t\t   1) Administrator     \n";
    cout << endl;
    cout << "\t\t\t\t   2) Buyer             \n";
    cout << endl;
    cout << "\t\t\t\t   3) Exit              \n";
    cout << endl;
    cout << "\t\t\t\t Please select:    ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t Please Login" << endl;
        cout << "\t\t\t\t Enter Email:  ";
        cin >> email;
        cout << "\t\t\t\t Enter Password:   ";
        cin >> passwd;
        if (email == "user@market.com" && passwd == "pass")
        {
            administrator();
        }
        else
            cout << "Invalid email/password" << endl;
        break;
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Please select from the given option" << endl;
        break;
    }
    goto m;
}

void Shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Administrato menu";
    cout << "\n\t\t\t|      1) Add the product      |";
    cout << "\n\t\t\t|      2) Modify the product   |";
    cout << "\n\t\t\t|      3) Delete the product   |";
    cout << "\n\t\t\t|      4) Back to main menu    |";
    cout << "\n\t\t\t       Enter your choice:  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    goto m;
}

void Shopping::buyer()
{
m:
    int choice;
    cout << "\n\t\t\t       Buyer:              ";
    cout << "\n\t\t\t       1) Buy the product  ";
    cout << "\n\t\t\t       2) Go back          ";
    cout << "\n\t\t\t       Enter your choice:  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Invalid choice" << endl;
    }
    goto m;
}

void Shopping::add()
{
m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    std::cout << "\n\n\t\tAdd new product" << endl;
    std::cout << "\t\tProduct code of the product:    ";
    cin >> p_code;
    std::cout << "\t\tName of the product:    ";
    cin >> p_name;
    cout << "\t\tPrice of the product:   ";
    cin >> price;
    std::cout << "\t\tDiscount on the product:    ";
    cin >> dis;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::out);
        data << p_code << "        " << p_name << "        " << price << "        " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == p_code)
                token++;
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token >= 1)
    {
        cout << "Code already exist. Please Enter unique code" << endl;
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << p_code << "        " << p_name << "        " << price << "        " << dis << endl;
        data.close();
    }
    cout << "\n\t\tRecord inserted" << endl;
}

void Shopping::edit()
{
    fstream data, data1;
    int p_key, token = 0, c;
    float p, d;
    string n;

    cout << "\n\t\t\tModify the record";
    cout << "\n\t\t\tProduct code: ";
    cin >> p_key;

    data.open("database.txt", ios::in);
    if (!data)
        cout << "\n\t\t\tFile does not exist!" << endl;
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> p_code >> p_name >> price >> dis;
        while (!data.eof())
        {
            if (p_key == p_code)
            {
                cout << "\n\t\t\tProduct New Code:   ";
                cin >> c;
                cout << "\t\t\tName of the product:    ";
                cin >> n;
                cout << "\t\t\tPrice:  ";
                cin >> p;
                cout << "\t\t\tDiscount:    ";
                cin >> d;
                data1 << c << "        " << n << "        " << p << "        " << d << endl;
                cout << "\n\t\t\tRecord edited   " << endl;
                token++;
            }
            else
            {
                data1 << p_code << "        " << p_name << "        " << price << "        " << dis << endl;
            }
            data >> p_code >> p_name >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
            cout << "Sorry! Record could not found." << endl;
    }
}

void Shopping::rem()
{
    fstream data, data1;
    int p_key, token = 0;
    cout << "\n\t\t\tDelete product";
    cout << "\n\t\t\tProduct code: ";
    cin >> p_key;
    data.open("database.txt", ios::in);
    if (!data)
        cout << "File does not exist" << endl;
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> p_code >> p_name >> price >> dis;
        while (!data.eof())
        {
            if (p_code == p_key)
            {
                cout << "\n\t\t\tProduct deleted successfully";
                token++;
            }
            else
                data1 << p_code << "        " << p_name << "        " << price << "        " << dis;
            data >> p_code >> p_name >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
            cout << "\n\t\t\t Sorry! Record could not found" << endl;
    }
}

void Shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n\t|------------------------------------------------------------------------|" << endl;
    cout << "\t|                                                                        |";
    cout << "\n\t|Product Code\t\tProduct Name\t\tPrice\t\tDiscount |";
    cout << "\n\t|                                                                        |";
    cout << "\n\t|------------------------------------------------------------------------|" << endl;
    data >> p_code >> p_name >> price >> dis;
    while (!data.eof())
    {
        cout << "\t|\t" << p_code << "\t\t" << p_name << "\t\t\t" << price << "\t\t" << dis << "\t |";
        data >> p_code >> p_name >> price >> dis;
    }
    data.close();
}

void Shopping::receipt()
{
m:
    fstream data;
    int arr_code[100], arr_qty[100];
    char choice;
    int c = 0;
    float amount = 0, dis = 0, total = 0;

    cout << "\n\t\t\tReceipt " << endl;
    data.open("database.txt", ios::in);
    if (!data)
        cout << "Empty database" << endl;
    else
    {
        data.close();
        list();
        cout << "\n\t|---------------------------------------------|" << endl;
        cout << "\t|         Please Place the order              |" << endl;
        cout << "\t|---------------------------------------------|" << endl;
        do
        {
            cout << "\n\t\tEnter Product Code: ";
            cin >> arr_code[c];
            cout << "\t\tEnter the product quantity: ";
            cin >> arr_qty[c];
            for (int i{}; i < c; ++i)
            {
                if (arr_code[c] == arr_code[i])
                {
                    cout << "\t\tDuplicate Product Code. Please Try again." << endl;
                    goto m;
                }
            }
            c++;
            cout << "\n\t\tDo you want to buy another product? Press 'y' or 'n':    ";
            cin >> choice;
        } while (choice == 'y');
        cout << "\n\n\t\t______________________________________RECEIPT______________________________________" << endl;
        cout << "\t\tProduct_No.\tProduct_Name\tQauntity\tPrice\tAmount\tAmount_with_discount" << endl;

        for (int i{}; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> p_code >> p_name >> price >> dis;
            while (!data.eof())
            {
                if (p_code == arr_code[i])
                {
                    amount = price * arr_qty[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n\t\t" << p_code << "\t\t" << p_name << "\t\t" << arr_qty[i] << "\t\t" << price << "\t" << amount << "\t" << dis << endl;
                }
                data >> p_code >> p_name >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\t\t___________________________________________________________________________________" << endl;
    cout << "\n\t\tTotal Amount:    " << total << endl;
}

int main()
{
    Shopping s;
    s.menu();

    return 0;
}