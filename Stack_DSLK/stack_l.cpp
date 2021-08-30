#include <iostream>
using namespace std;
struct node
{
	int data;
	node* pNext;
};
struct stack
{
	node* phead;
};
node* KhoiTaoNode(int x);
void KhoiTaoStack(stack& s);
void Push(stack& s, node* p);
int IsEmpty(stack s);
int Pop(stack& s, int& x);
int DemSoPhanTu(stack s);
bool XoaALL(stack& s);
void menu(stack& s);
int main()
{
	stack s;
	KhoiTaoStack(s);
	menu(s);
	
}
node* KhoiTaoNode(int x)
{
	node* p = new node();
	if (p == NULL)
	{
		cout << "Cap phat khong thanh cong ";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void KhoiTaoStack(stack& s)
{
	s.phead = NULL;
}
void Push(stack& s, node* p)
{
	if (s.phead == NULL)
	{
		s.phead = p;
	}
	else
	{
		p->pNext = s.phead;
		s.phead = p;
	}
}
int IsEmpty(stack s)
{
	if (s.phead == NULL)
		return 1;
	else
		return 0;
}
int Pop(stack& s, int& x)
{
	if (IsEmpty(s))
		return 0;
	else
	{
		node* p = s.phead;
		x = p->data;
		s.phead = s.phead->pNext;
		delete p;
	}
	return 1;
}
int DemSoPhanTu(stack s)
{
	node* p;
	int dem = 0;
	for (p = s.phead; p != NULL; p = p->pNext)
		dem++;
	return dem;
}
bool XoaALL(stack& s)
{
	node* p;
	if (s.phead == NULL)
		return false;
	while (!IsEmpty(s))
	{
		p = s.phead;
		s.phead = s.phead->pNext;
		delete p;
	}
	return true;
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
		cout << "\nNhap Lua Chon : ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "Nhap gia tri can them x = ";
			cin >> x;
			node* p = KhoiTaoNode(x);
			Push(s, p);
		}
		else if (luachon == 2)
		{
			int x;
			if (Pop(s, x) == 0)
				cout << "stack rong";
			else
				cout << " gia gtri lay duoc trong stack : " << x;
			system("pause");
		}
		else if (luachon == 3)
		{
			if (IsEmpty(s) == 1)
				cout << "stack rong";
			else
				cout << " stack khong rong";
			system("pause");
		}
		else if (luachon == 4)
		{
			int x;
			x = DemSoPhanTu(s);
			cout << "\n So luong phan tu : " << x;
			system("pause");
		}
		else if (luachon == 5)
		{
			if (XoaALL(s) == 0)
				cout << "stack chua co phan tu";
			else
				cout << "xoa thanh cong ";
			system("pause");
		}
		else
			break;

	}
}