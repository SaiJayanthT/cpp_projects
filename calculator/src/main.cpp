#include <iostream>
#include "calculator.h"
#define EXIT 9

enum ARITHMETIC_OPERATIONS {
    ADD = 1,
    SUB = 2,
    MUL = 3,
    DIV = 4
};


int main(){
    int num1, num2;
    int operation = 0;
    std::cout << "###############################################################" << std::endl;
    std::cout << "################### WELCOME TO CALCULATOR #####################" << std::endl;
    std::cout << "###############################################################" << std::endl;
    std::cout << std::endl;


    do 
    {

        std::cout << "======================== INPUT WINDOW =========================" << std::endl;
        std::cout << "++++++++++++++++++++++++ CALCULATOR OPTIONS +++++++++++++++++++" << std::endl;
        std::cout << "1 - ADDITION" << std::endl;
        std::cout << "2 - SUBTRACT" << std::endl; 
        std::cout << "3 - MULTIPLICATION" << std::endl; 
        std::cout << "4 - DIVISION" << std::endl;
        std::cout << "9 - EXIT" << std::endl;
        std::cout << "Enter Option: ";
        std::cin >> operation;

        if (operation == EXIT)
        {
            std::cout << std::endl;
            std::cout << "###############################################################" << std::endl;
            std::cout << "######################### EXIT ################################" << std::endl;
            std::cout << "################# THANK YOU. VISIT AGAIN ######################" << std::endl;
            std::cout << "###############################################################" << std::endl;
        }
        else
        {
            if ((operation > 0) && (operation < 5))
            {
                std::cout << "++++++++++++++++++++++++ ENTER NUMBERS ++++++++++++++++++++++++" << std::endl;
                std::cout << "Enter The First Number: ";
                std::cin >> num1;
                std::cout << "Enter The Second Number: ";
                std::cin >> num2;
                std::cout << "===============================================================" << std::endl;
                std::cout << std::endl;

                std::cout << "======================== OUTPUT WINDOW ========================" << std::endl;
                switch (operation)
                {
                    case ADD:
                        std::cout << num1 << " + " << num2 << " = " << dev::add(num1, num2) << std::endl;
                        break;
                    case SUB:
                        std::cout << num1 << " - " << num2 << " = " << dev::sub(num1, num2) << std::endl;
                        break;
                    case MUL:
                        std::cout << num1 << " * " << num2 << " = " << dev::mul(num1, num2) << std::endl;
                        break;
                    default:
                        try{
                            double res = dev::div(num1, num2);
                            std::cout << num1 << " / " << num2 << " = " <<  res << std::endl;
                        }catch (const char* msg){
                            std::cout << "Error: " << msg << std::endl;
                            std::cout << "Divider shouldn't be 0. Please try again."<< std::endl;
                        } 
                }
                std::cout << "===============================================================" << std::endl;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "!!!!!!!!!!! Invalid Option Choosen. Please Try Again !!!!!!!!!!" << std::endl;
            }
            
        }
        std::cout << std::endl;

        

    }
    while (operation != EXIT);

    
}