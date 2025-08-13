#include <iostream>
#include <cstring>
#include <locale>

void getHelp(char* argv[])
{
	const char* locale = std::setlocale(LC_MESSAGES, "");
	
	if (locale[0] == 'e' && locale[1] == 'n')
	{
		std::cout << "Usage: " << argv[0] << " [left_operand] [operator] [right_operand]" << std::endl
			<< "Left and right operands should be number of integer and/or double type" << std::endl
			<< "Supported operands: \n\t Addition: +\n\t Subtraction: - \n\t Multiplication: x (english keyboard layout)\n\t Division: /\n";
	}
	if (locale[0] == 'r' && locale[1] == 'u')
	{
		std::cout << "Используйте: " << argv[0] << " [левый операнд] [оператор] [правый операнд]" << std::endl
			<< "Левый и правый операнды должны быть целым и/или десятичными числами" << std::endl
			<< "Поддерживаемые операнды:  \n\t Сложение: +\n\t Вычитание: -\n\t Умножение: x (в английской раскладке в нижнем регистре)\n\t Деление: /\n";
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " [left_operand] [operator] [right_operand]" << std::endl
			<< "Left and right operands should be number of integer and/or double type" << std::endl
			<< "Supported operands: \n\t Addition: +\n\t Subtraction: - \n\t Multiplication: x (english keyboard layout at the lowercase\n\t Division: /\n";
	}
}

double calc(int argc, char* argv[])
{
	double a = 0.0, b = 0.0;

	for (int i = 0; argv[1][i] != '\0'; i++)
	{
		a = a * 10 + (argv[1][i]- '0');
	}
	for (int i = 0; argv[3][i] != '\0'; i++)
	{
		b = b * 10 + (argv[3][i] - '0');
	}

	switch(argv[2][0])
	{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case 'x':
			return a * b;
			break;
		case '/':
			return a / b;
			break;		
		default:
			std::cerr << "Error! Unknown argument(s). Exit code: ";
			return 1;
	}
}	

int main(int argc, char* argv[])
{
	if ((strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
	{
		getHelp(argv);
		return 0;
	}
	else if (argc > 3)
	{
		std::cout << calc(argc, argv) << std::endl;
	}
	else
	{
		std::cout << "Unknown Error!" << std::endl;
	}

	return 0;
}
