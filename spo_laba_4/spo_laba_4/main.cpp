#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "������������ ������� �4\n\n";
	std::cout << "������� ��� *.txt ����� \n(���� ������ ������������� � ����� ����� � ����������)\n";
	std::string fname;
	std::cin >> fname;

	Lexer lexer;
	std::vector<token_pair> tokens = lexer.getTokens(fname);

	if (!tokens.empty())
	{
		std::cout << "\n������ �� ������ ������.";

		Parser parser;
		bool correct = parser.checkSyntax(tokens);
		if (correct)
		{
			std::cout << "\n������ �� ������ ������.\n";
		}
		else
		{
			std::cout << "\n������ ������ ������.\n";
		}
	}
	else
	{
		std::cout << "\n������ ������ ������.\n";
	}

	Interpreter interpreter;
	std::vector<std::string> rpn = interpreter.get_reverse_polish_notation(tokens);
	//interpreter.get_reverse_polish_notation(tokens);

	std::cout << "\n";
	for (int i = 0; i < rpn.size(); ++i)
	{
		std::cout << std::left << std::setw(3) << i + 1 << rpn[i] << "\n";
	}

	std::cout << "\n";
	system("pause");
	return 0;
}





/*std::cout << "\n\n��������� ������ �������:\n\n";
for (int i = 0; i < tokens.size(); ++i)
{
std::cout << std::left << std::setw(18) << tokens[i].name << " " << tokens[i].value << "\n";
}*/