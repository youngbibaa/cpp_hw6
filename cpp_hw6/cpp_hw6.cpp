#include <iostream>
#include <conio.h>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction() {}

	Fraction(int numerator, int denominator) : numerator{ numerator }, denominator{ denominator } {}

	friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2) {
		return Fraction(fraction1.numerator * fraction2.numerator, fraction1.denominator * fraction2.denominator);;
	}

	friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2) {
		return Fraction(fraction1.numerator * fraction2.denominator, fraction1.denominator * fraction2.numerator);;
	}

	friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2) {
		int numerator = (fraction1.numerator * fraction2.denominator) + (fraction2.numerator * fraction1.denominator);
		int denominator = fraction1.denominator * fraction2.denominator;
		return Fraction(numerator, denominator);;
	}

	friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2) {
		int numerator = (fraction1.numerator * fraction2.denominator) - (fraction2.numerator * fraction1.denominator);
		int denominator = fraction1.denominator * fraction2.denominator;
		return Fraction(numerator, denominator);;
	}

	double getResult() {
		return (double)this->numerator / (double)this->denominator;
	}

	
};

int main()
{
	setlocale(LC_ALL, "rus");
	Fraction fraction1{ 1, 10 };
	Fraction fraction2{ 3, 5 };

	Fraction fraction3 = fraction1 + fraction2;
	Fraction fraction4 = fraction1 - fraction2;
	Fraction fraction5 = fraction1 * fraction2;
	Fraction fraction6 = fraction1 / fraction2;

	cout << "Сумма: " << fraction3.getResult() << endl;
	cout << "Разность: " << fraction4.getResult() << endl;
	cout << "Произведение: " << fraction5.getResult() << endl;
	cout << "Частное: " << fraction6.getResult() << endl;

}

