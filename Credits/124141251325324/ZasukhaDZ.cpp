#include<iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");

	double CreditSum; //����� �������
	double PayCreditMonth; //C���� ������ �� �����
	double PerMonth; //���-�� ������� ��� ������ �������
	double SumForCredit; //����������� ������ �� �����
	double min_payment = 0;
	double max_payment = 0;

	cout << "����� �������: ";
	cin >> CreditSum; //������ ����� �������

	cout << "����� � ������: " << CreditSum << endl;

	SumForCredit = CreditSum * 5 / 100;
	PerMonth = CreditSum / SumForCredit;

	cout << "��� �� �������� ������ ����������� " << PerMonth <<" �������" << endl;

	cout << "����������� ����� ��� ������: " << SumForCredit << endl;

	for (int i = 0; i < PerMonth; i++)
	{
		if (CreditSum <= 0)
		{
			cout << "����������� ������: " << min_payment << endl;
			cout << "������������ ������: " << max_payment << endl;

			break;
		}

		cout << "��� �������� ��������� " << CreditSum << endl;

		SumForCredit = CreditSum * 5 / 100;
		PerMonth = CreditSum / SumForCredit;
	
		cout << "����������� ����� ��� ������: " << SumForCredit << endl;

		cout << "������� �� ������ ��������� �� " << i + 1 << " �����?" << endl;
		cin >> PayCreditMonth;


		if (PayCreditMonth>CreditSum)
		{
			cout << "���� �����: " << PayCreditMonth - CreditSum << endl;
		}

		CreditSum -= PayCreditMonth;

		if (PayCreditMonth < SumForCredit)
		{
			CreditSum = CreditSum + CreditSum * 0.05 / 100;
			SumForCredit = CreditSum * 5 / 100;

			cout << "�� �������� ������ 5-�� ���������,����� � ������ ������� ���������� ��: " << CreditSum << endl;
			cout << "����������� ����� �������: " << SumForCredit << endl;
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

/*������ 1 "������"
������ ����� ������ � ����� �� ���� � ���.
������� ����� ������ ������ ����� ���� �������� ��
���� ���������� �����������.�������� �����,
����������� ������, ��������� �� ����� 5 % �� ���������
���� �������.���� ������ ������ �����, �� ���� �������
���������� �� 0.05 % �� ������� �������.���������
�������� ������� ����������� �������� : �������� �
��������� �������� ���� �, �������� ������� ���� ������,
���� ������� �������� ������� ���� ��������� �������,
������ ����� �� ���������� ���������(��������� �����
	������� ����������� ��� ��, �� ���� ����������, ����
	������ ��������� ����� 5 % �� ��������� ���� �������).
	��������� :
	�� ������ ������ ������ ����� ��������� ������
	����� �� ���� ���������� �������
	����� �� ���� ������������� �������*/