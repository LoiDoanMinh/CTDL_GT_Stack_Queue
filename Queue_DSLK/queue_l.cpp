#include <iostream>
using namespace std;
struct node
{
	int data;
	node* pNext;
};
struct queue
{
	node* phead;
	node* ptail;
};
node* KhoiTaoNode(int x);
void KhoiTaoQueue(queue& q);
int IsEmpty(queue& q);
void EnQueue(queue& q, node* p);
int Dequeue(queue& q, int& x);
int DemSoPhanTu(queue q);
int XoaALL(queue& q);
void menu(queue& q);
int main()
{
	queue q;
	KhoiTaoQueue(q);
	menu(q);
}
node* KhoiTaoNode(int x)
{
	node* p = new node();
	if (p == NULL)
		return NULL;
	else
		p->data = x;
	p->pNext = NULL;
	return p;
}
void KhoiTaoQueue(queue& q)
{
	q.phead = q.ptail = NULL;
}
int IsEmpty(queue& q)
{
	if (q.phead == NULL)
		return 1;
	return 0;
}
void EnQueue(queue& q, node* p)
{
	if (IsEmpty(q))
		q.phead = q.ptail = p;
	else
	{
		q.ptail->pNext = p;
		q.ptail = p;
	}
}
int Dequeue(queue& q, int& x)
{
	if (IsEmpty(q) == 1)
		return 0;
	else
	{
		node* p = q.phead;
		x = p->data;
		q.phead = q.phead->pNext;
		delete p;
	}
	return 1;
}
int DemSoPhanTu(queue q)
{
	int dem = 0;
	for (node* p = q.phead; p != NULL; p = p->pNext)
		dem++;
	return dem;
}
int XoaALL(queue& q)
{
	node* p;
	if (IsEmpty(q))
		return 0;
	else
	{
		while (!IsEmpty(q))
		{
			p = q.phead;
			q.phead = q.phead->pNext;
			delete p;
		}
	}
	return 1;
}
void menu(queue& q)
{
	int luachon;
	while (1)
	{
		system("cls");
		cout << "\n\n\t\t=========MENU=========";
		cout << "\n\t1.EnQueue";
		cout << "\n\t2.DeQueue";
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
			cout << "Nhap gia tri x : ";
			cin >> x;
			node* p = KhoiTaoNode(x);
			EnQueue(q, p);
		}
		else if (luachon == 2)
		{
			int tv;
			if (Dequeue(q, tv) == 0)
				cout << "Queue rong ";
			else
			{
				cout << "gia tri lay duoc tu queue :" << tv;
			}
			system("pause");
		}
		else if (luachon == 3)
		{
			if (IsEmpty(q))
				cout << "Queue rong!";
			else
				cout << "Queue khong rong!";
			system("pause");
		}
		else if (luachon == 4)
		{
			int dem;
			dem = DemSoPhanTu(q);
			cout << " so phan tu trong queue : " << dem;
			system("pause");
		}
		else if (luachon == 5)
		{
			if (XoaALL(q) == 0)
				cout << "queue rong !";
			else
				cout << " xoa thanh cong !";
			system("pause");
		}
		else
			break;
	}
}