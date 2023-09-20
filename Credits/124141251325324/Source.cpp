#include<iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");

	double CreditSum; //Сумма кредита
	double PayCreditMonth; //Cумма оплаты за месяц
	double PerMonth; //Кол-во месяцев для оплаты кредита
	double SumForCredit; //Минимальная оплата за месяц
	double min_payment = 0;
	double max_payment = 0;

	cout << "Сумма кредита: ";
	cin >> CreditSum; //Ввести сумма кредита

	cout << "Сумма к оплате: " << CreditSum << endl;

	SumForCredit = CreditSum * 5 / 100;
	PerMonth = CreditSum / SumForCredit;

	cout << "Что бы оплатить кредит понадобится " << PerMonth <<" месяцев" << endl;

	cout << "Минимальная сумма для оплаты: " << SumForCredit << endl;

	for (int i = 0; i < PerMonth; i++)
	{
		if (CreditSum <= 0)
		{
			cout << "Минимальный платеж: " << min_payment << endl;
			cout << "Максимальний платеж: " << max_payment << endl;

			break;
		}

		cout << "Вам осталось заплатить " << CreditSum << endl;

		SumForCredit = CreditSum * 5 / 100;
		PerMonth = CreditSum / SumForCredit;
	
		cout << "Минимальная сумма для оплаты: " << SumForCredit << endl;

		cout << "Сколько вы хотите заплатить за " << i + 1 << " месяц?" << endl;
		cin >> PayCreditMonth;


		if (PayCreditMonth>CreditSum)
		{
			cout << "Ваша сдача: " << PayCreditMonth - CreditSum << endl;
		}

		CreditSum -= PayCreditMonth;

		if (PayCreditMonth < SumForCredit)
		{
			CreditSum = CreditSum + CreditSum * 0.05 / 100;
			SumForCredit = CreditSum * 5 / 100;

			cout << "Вы оплатили меньше 5-ти процентов,сумма к оплате кредита изменилась на: " << CreditSum << endl;
			cout << "Минимальная сумма платежа: " << SumForCredit << endl;
		}

		if (min_payment == 0 || PayCreditMonth < min_payment)
		{
			min_payment = PayCreditMonth;
		}
		if (PayCreditMonth > max_payment) 
		{
			max_payment = PayCreditMonth;
		}

		if (CreditSum < SumForCredit)
		{
			SumForCredit = CreditSum;
		}	
	}
}

/*Задача 1 "Кредит"
Людина взяла кредит у банку на суму Х грн.
Кожного місяця людина сплачує деяку суму виходячи із
своїх фінансових можливостей.Щомісячна плата,
встановлена банком, становить не менше 5 % від залишкової
суми кредиту.Якщо людина сплачує менше, то сума кредиту
збільшується на 0.05 % від залишку кредиту.Інтерфейс
програми повинен передбачати наступне : введення з
клавіатури загальної суми Х, введення чергової суми виплат,
після кожного введення чергової суми необхідно вивести,
скільки людині ще залишилося виплатити(додатково можна
	вивести повідомлення про те, що сума збільшилася, якщо
	людина заплатила менше 5 % від залишкової суми кредиту).
	Визначити :
	За скільки місяців людина зможе виплатити кредит
	Номер та суму мінімального платежа
	Номер та суму максимального платежа*/