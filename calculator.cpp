#include <memory>
#include <vector>
#include <string>
#include <iostream>



class Calculator
{
public:
	template<typename  T> //simple template example
	T addition(T a, T b) {
		return a + b;
	}

	int subtraction(int a, int b) {
		return a - b;
	}
};
template<typename T>
bool getValidUserInput(T& input)
{
	std::cin >> input;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}


int main()
{
	int userChoice = 3;
	double a = 0;
	double b = 0;
	
	Calculator calc;

	
	std::cout << "Please enter first number: " << std::endl;
	while (!getValidUserInput(a))
		std::cout << "Not valid input.\n";
	
	std::cout << "Please enter second number: " << std::endl;
	while (!getValidUserInput(b))
		std::cout << "Not valid input.\n";
		
	std::cout << "Would you like to add, press 1. Would you like to subtract, press 2. For exit press 0" << std::endl;
	while (!getValidUserInput(userChoice))
		std::cout << "Not valid input.\n";

		while(true){
			if (userChoice == 0) 
			{
				std::cout << "Exiting\n";
				break;
			}
			else if (userChoice == 1) {
				std::cout << "Result is: " << calc.addition(a, b) << std::endl;
				break;
			}
			else if (userChoice == 2) {
				std::cout << "Result is: " << calc.subtraction(a, b) << std::endl;
				break;
			}
			else
				std::cout << "Incorrect entry. Try again: \n";
		}
		
	std::cout << std::endl;
	system("pause");
	return 0;
}
