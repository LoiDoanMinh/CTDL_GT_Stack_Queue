#include <iostream>
using namespace std;
struct queue
{
	int A[100];
	int front;
	int rear;
};
void KhoiTaoQueue(queue& q)
{
	q.front = -1;
	q.rear = -1;
}
int Enqueue(queue& q, int x)
{
	int i, f, r;
	if ((q.rear - q.front + 1) == 100)
		return 0;
	else
	{
		if (q.front == -1)
		{
			q.front = q.rear = 0;
		}
		if (q.rear == 99)
		{
			f = q.front;
			r = q.rear;
			for (i = f; i < r; i++)
			{
				q.A[i - f] = q.A[i];
			}
			q.front = 0;
			q.rear = r - f;
		}
		q.A[q.rear] = x;
		q.rear++;
		return 1;
	}
}
int Dequeue(queue& q, int& x)
{
	if (q.front == -1)
	{
		cout << " queue rong ";
		return 0;
	}
	else
	{
		x = q.A[q.front];
		q.front++;
		if (q.front >= q.rear)
		{
			q.front = q.rear = -1;
		}
		return 1;
	}
}
int IsEmpty(queue q)
{
	if (q.front == -1)
		return 1;
	else
		return 0;
}
void DemSoPhanTu(queue q)
{
	int dem = q.rear - q.front;
	if (q.front == -1)
	{
		cout << "So Phan tu trong queue : 0 ";
	}
	else
		cout << "So Phan tu trong queue : " << dem;
}
int XoaALL(queue& q)
{
	if (q.front != -1)
	{
		q.front = q.rear = -1;
		return 1;
	}
	else
	{
		return 0;
	}
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
			cout << "Nhap x = ";
			cin >> x;
			if (Enqueue(q, x) == 0)
				cout << "Khong Them Thanh Cong";
		}
		else if (luachon == 2)
		{
			int x;
			Dequeue(q, x);
			cout << "Gia tri lay tra duoc tu queue : " << x;
			system("pause");
		}
		else if (luachon == 3)
		{
			if (IsEmpty(q) == 1)
				cout << "Queue rong !";
			else
				cout << "Queue khong rong ! ";
			system("pause");
		}
		else if (luachon == 4)
		{
			DemSoPhanTu(q);
			system("pause");
		}
		else if (luachon == 5)
		{
			if (XoaALL(q) == 0)
				cout << "queue rong!";
			else
				cout << "Xoa Thanh Cong!";
			system("pause");
		}
		else
			break;
	}
}

int main()
{
	queue q;
	KhoiTaoQueue(q);
	menu(q);
}
