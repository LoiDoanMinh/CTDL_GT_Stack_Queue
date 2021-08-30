#include <iostream>
using namespace std;
struct stack
{
	int a[100];
	int t;
};
void KhoiTaoStack(stack& s)
{
	s.t = -1;
}
int IsEmpty(stack s)
{
	if (s.t == -1)
		return 1;
	else
		return 0;
}
int IsFull(stack s)
{
	if (s.t >= 100)
		return 1;
	return 0;
}
int Push(stack& s, int x)
{
	if (IsFull(s))
		return 0;
	else
	{
		s.t++;
		s.a[s.t] = x;
		return 1;
	}
}
int Pop(stack& s, int& x)
{
	if (IsEmpty(s) == 1)
		return 0;
	else
	{
		x = s.a[s.t];
		s.t--;
	}
	return 1;
}
int DemSoPhanTu(stack &s)
{
	if (IsEmpty(s))
		return 0;
	else
		return s.t+1;
}
int XoaALL(stack& s)
{
	if (IsEmpty(s))
		return 0;
	else
	{
		for (s.t; s.t != -1;)
			s.t--;
	}
	return 1;
}
void menu(stack& s)
{
	int luachon;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t=========MENU=========";
		cout << "\n\t1.Push(them node vao stack)";
		cout << "\n\t2.Pop";
		cout << "\n\t3.Kiem tra Rong";
		cout << "\n\t4.Dem so luong phan tu";
		cout << "\n\t5.Xoa Tat ca phan tu";
		cout << "\n\t0.Thoat";
		cout << "\n\n\t\t=========END=========";
		cout << "\nNhap lua chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "Nhap x = ";
			cin >> x;
			if (Push(s, x) == 0)
				cout << "so luong phan tu qua gioi han";
		}
		else if (luachon == 2)
		{
			int tv;
			if (Pop(s, tv) == 0)
				cout << "stack rong !";
			else
				cout << "Gia tri lay duoc tu stack : " << tv;
			system("pause");
		}
		else if (luachon == 3)
		{
			if (IsEmpty(s))
				cout << " stack rong !";
			else
				cout << " stack khong rong !";
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "So phan tu trong stack : " << DemSoPhanTu(s);
			system("pause");
		}
		else if (luachon == 5)
		{
			if (XoaALL(s) == 0)
				cout << "stack rong!";
			else
				cout << " xoa thanh cong ";
			system("pause");
		}
		else
			break;
	}
}
int main()
{
	stack s;
	KhoiTaoStack(s);
	menu(s);
}