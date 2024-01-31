#include <iostream>	
#include <cmath>
using namespace std;
enum ResCode {
	Success,
	Error,
	Exit
};
enum Operation {
	Sum = 1,
	Subtract,
	Multiply,
	Divide,
	Pow,
	Sqrt,
	Percent,
	Factorial,
	Cancel
};
ResCode ProcessCalcuations(double* num1, double num2, Operation operaionToCalculate);
double FindFactorial(double num);
int main()
{
	setlocale(LC_ALL, "ru");
	bool isInitialized{ false };
	double num1, num2;
	int answer;
	ResCode res{ (ResCode)-1};
	Operation selectedOp;
	do
	{
		if (res == Success) {

			cout << "Current number: " << num1 << endl << "do you want to 1 - save or 2 - reset it" << endl;
			cin >> answer;
			switch (answer)
			{
			case 1:
				cout << "Input the second number" << endl;
				cin >> num2; break;
			case 2:
				cout << "Input two numbers to operate with" << endl;
				cin >> num1 >> num2;
			default:
				cout << "We don't have such option" << endl;
				break;
			}
		}
		else {
			cout << "Input two numbers to operate with" << endl;
			cin >> num1 >> num2;
		}
		cout << "Now, choose the operation to process:\n 1 - '+'\n 2 - '-'\n 3 - '*'\n 4 - '/'\n5 - 'power your num'\n6 - 'square root'\n7 - '1% of num'\n8 - !'(your first num)!'\n9 - 'exit the poor app'" << endl;
		cin >> answer;
		selectedOp = (Operation)answer;
		res = ProcessCalcuations(&num1, num2, selectedOp);
		if (res == Error)
		{
			cout << "there was problem while executing operation";
			return 0;
		}
		else if (res == Exit) { cout << "GoodBuy Comrade" << endl; return 0; }
		else cout << "Result: " << num1 << endl;
	} while (true);
}

ResCode ProcessCalcuations(double* num1, double num2, Operation operaionToCalculate) {
	switch (operaionToCalculate)
	{
	case Sum: 
		*num1 += num2;
		return Success;
	case Subtract: *num1 -= num2;
		return Success;
	case Multiply: *num1  *= num2;
		return Success;
	case Divide: if (num2 == 0) {
		cout << "Incorrect operator"; return Error;
	}
		  *num1 /= num2;
		  return Success;
	case Pow: *num1 = pow(*num1, num2);
		return Success;
	case Sqrt:  *num1 = sqrt(*num1);
	case Percent:  *num1 *= 0.01;
		return Success;
	case Factorial: if (*num1 <= 0) return Error;
		*num1 = FindFactorial(*num1);
		return Success;
	case 9: return Exit;
	default:
		cout << "We don't have such operation"<<endl;
		return Error;
	}
	return Exit;
}
double FindFactorial(double num) {
	double result = 1;
	for (size_t i =1; i <= num; i++)
	{
		result *= i;
	}
	return result;
}
