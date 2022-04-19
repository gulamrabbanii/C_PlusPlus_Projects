#include <iostream>
#include <windows.h>

int main()
{
    int quant, choice;
    // Quantity
    int Qrooms{}, Qpasta{}, Qburger{}, Qnoodles{}, Qshake{}, Qchicken{};
    // Food items sold
    int Srooms{}, Spasta{}, Sburger{}, Snoodles{}, Sshake{}, Schicken{};
    // Total price of items
    int Total_rooms{}, Total_pasta{}, Total_burger{}, Total_noodles{}, Total_shake{}, Total_chicken{};

    std::cout << "\n\tQuantity of things we've," << std::endl;
    std::cout << "\tNumber of Rooms: ";
    std::cin >> Qrooms;
    std::cout << "\tQuantity of Pasta: ";
    std::cin >> Qpasta;
    std::cout << "\tQuantity of Burger: ";
    std::cin >> Qburger;
    std::cout << "\tQuantity of Noodles: ";
    std::cin >> Qnoodles;
    std::cout << "\tQuantity of Shake: ";
    std::cin >> Qshake;
    std::cout << "\tQuantity of Chicke-rool: ";
    std::cin >> Qchicken;

    std::cout << "\n\n\tPlease select from the menu options " << std::endl;
    std::cout << "\t1) Rooms" << std::endl;
    std::cout << "\t2) Pasta" << std::endl;
    std::cout << "\t3) Burger" << std::endl;
    std::cout << "\t4) Noodles" << std::endl;
    std::cout << "\t5) Shake" << std::endl;
    std::cout << "\t6) Chicken-roll" << std::endl;
    std::cout << "\t7) Information regarding sales and collection" << std::endl;
    std::cout << "\t8) Exit" << std::endl;

    std::cout << "\n\tPlease Enter your choice: ";
    std::cin >> choice;
    system("CLS");
    Sleep(999);

    switch (choice)
    {
    case 1:
        std::cout << "\tEnter the number of rooms you want: ";
        std::cin >> quant;
        break;
    defaul:
        std::cout << "invalid";
    }

    return 0;
}