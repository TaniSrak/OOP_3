#include <iostream>
#include <string>

class Сassa
{
public:
	Сassa():hranenie_(0)
	{
		hranenie_ - 0;
	}
	int CurrentMoney() //сколько лежит денег в кассе
	{
		return hranenie_;
	}
	void CashIn(int money) //закидываем деньги в кассу
	{
		hranenie_ += money;
	}
	void CashOut(int money) //если денег в кассе меньше, чем нужно, то не начинаем работу
	{
		if (money > hranenie_)
		{
			std::cerr << "Денег не хватает.";
			return;
		}
		hranenie_ -= money;
	}
	int Exchenge(int ticket, int money) //если денег у киента и у кассы не хватает //чек - ticket
	{
		if (money < ticket)
		{
			std::cout << "Денег у покупателя не хватает.\n";
			return money;
		}
		if (hranenie_ < money - ticket )
		{
			std::cout << "Денег в кассе не хватает для сдачи.\n";
			return money;
		}
		hranenie_ += ticket; //если оба условия не выполняются, тогда сдаем сдачу
		return money - ticket;
	}

private: 
	long long hranenie_;
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	Сassa var1;
	Сassa var2;

	//сколько денег в кассе
	var1.CashIn(1000);
	std::cout << "Денег в кассе 1: " << var1.CurrentMoney() << "\n";
	std::cout << "Денег в кассе 2: " << var2.CurrentMoney() << "\n\n";

	std::cout << "==================\n";

	//берем деньги из кассы
	std::cout << "Берем деньги из кассы.\n";
	var1.CashOut(2000);
	std::cout << "имеется: " << var1.CurrentMoney() << "\n";
	var1.CashOut(200);
	std::cout << "имеется: " << var1.CurrentMoney() << "\n";
	var2.CashOut(200);
	std::cout << "имеется: " << var2.CurrentMoney() << "\n";
	var2.CashOut(0);
	std::cout << "имеется: " << var2.CurrentMoney() << "\n";
	std::cout << "==================\n";

	//сдаем сдачу
	int Var11 = 0;
	Var11 = var1.Exchenge(20, 40);
	std::cout << "Осталось после сдачи: " << var1.CurrentMoney() << "\n";
	int Var111 = 0;
	Var111 = var1.Exchenge(20, 30);
	std::cout << "Осталось после сдачи: " << var1.CurrentMoney() << "\n";
	int Var22 = 0;
	Var22 = var2.Exchenge(200, 1000);
	std::cout << "Осталось после сдачи: " << var2.CurrentMoney() << "\n";

	return 0;
}