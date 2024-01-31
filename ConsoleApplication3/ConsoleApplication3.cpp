#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class CircularQueue
{
	T* _arr;
	int _front;
	int _rear;
	int _max;
public:
	CircularQueue(int max)
	{
		SetMax(max);
		_front = -1;
		_rear = -1;
		_arr = new T[_max];
	}
	void SetMax(int max)
	{
		if (max <= 1 && max >= 1000) assert(!"maximum 1000 ve minimum 1 ola biler");
		_max = max;

	}

	//IsFull()
	bool IsFull()
	{
		//if (_front == 0 && _rear == _max - 1)
		//    return true;
		//if (_front == _rear + 1)
		//    return true;
		//return false;

		return _front == (_rear + 1) % _max;
	}
	//IsEmtpy()
	bool IsEmpty()
	{
		return _front == -1;
	}
	//Add()
	void Add(T item)
	{
		if (IsFull()) assert(!"Yer yoxdur");
		if (_front == -1) _front = 0;
		_rear = (_rear + 1) % _max;
		_arr[_rear] = item;
		//way 2
		//if (_rear == _max - 1) _rear = 0;
		//else _rear++;
	}
	//Remove()
	void Remove()
	{
		if (IsEmpty()) assert(!"Silinencek sey yoxdur");
		if (_front == _rear) _front = _rear = -1;
		_front = (_front + 1) % _max;
	}
	//GetFront()
	T GetFront()
	{
		if (IsEmpty()) assert(!"Queue bosdur");
		return _arr[_front];
	}
	//GetRear()
	T GetRear()
	{
		if (IsEmpty()) assert(!"Queue bosdur");
		return _arr[_rear];
	}
	//print
	void Print()
	{
		if (IsEmpty())
		{
			cout << "[]" << endl;
			return;
		}
		int i;
		cout << "[";
		for (i = _front; i != _rear; i = (i + 1) % _max)
			cout << _arr[i] << ", ";
		cout << _arr[i] << "]" << endl;
	}
	//Destructor
	~CircularQueue()
	{
		if (_arr != nullptr) delete[] _arr;
	}
};
template <typename T>
class DeQueue
{
	T* _arr;
	int _front;
	int _rear;
	int _max;
	int _count;
public:
	DeQueue(int max)
	{
		SetMax(max);
		_front = 0;
		_rear = 0;
		_count = 0;
		_arr = new T[_max];
	}
	void SetMax(int max)
	{
		if (max <= 1 && max >= 1000) assert(!"maximum 1000 ve minimum 1 ola biler");
		_max = max;

	}

	//isFull
	bool IsFull()
	{
		return _count == _max ;
	}
	//isEmpty
	bool IsEmpty()
	{
		return _count == 0;
	}
	//AddFront
	void AddFront(T item)
	{
		if (IsFull()) assert(!"Doludur");
		if (IsEmpty())
		{
			_arr[_front] = item;
			_count++;
			return;
		}
		_front = (_max +_front - 1) % _max ;
		_arr[_front] = item;
		_count++;
	}
	//AddRear
	void AddRear(T item)
	{
		if (IsFull()) assert(!"Doludur");
		if (IsEmpty())
		{
			_arr[_rear] = item;
			_count++;
			return;
		}
		_rear = (_rear + 1) % _max;
		_arr[_rear] = item;
		_count++;
	}
	//PopFront
	void PopFront()
	{
		if (IsEmpty()) assert(!"Silinecek bir sey yoxudr");
		_front = (_front + 1) % _max;
		_count--;
	}
	//PopRear
	void PopRear()
	{
		if (IsEmpty()) assert(!"Boshdur");
		_rear--;
		_count--;
	}
	//GetFront
	T GetFront()
	{
		if (IsEmpty()) assert(!"Boshdur");
		return _arr[_front];
	}
	//GetRear
	T GetRear()
	{
		if (IsEmpty()) assert(!"Boshdur");
		return _arr[_rear];
	}
	//Print
	void Print()
	{
		if (IsEmpty())
		{
			cout << "[]" << endl;
			return;
		}
		int i;
		cout << "[";
		for (i = _front; i != _rear; i = (i + 1) % _max)
			cout << _arr[i] << ", ";
		cout << _arr[i] << "]" << endl;
	}
	//Destructor
	~DeQueue()
	{
		if (_arr != nullptr) delete[] _arr;
	}

};
int main()
{
	//CircularQueue<int> a(5);

	//a.Print();
	//a.Add(1);
	//a.Add(1);
	//a.Add(1);
	//a.Add(1);
	//a.Print();
	//a.Remove();
	//a.Remove();
	//a.Remove();
	//a.Print();

	DeQueue<int> b(10);
	b.Print();
	b.AddFront(10);
	b.AddFront(10);
	b.Print();
	b.AddRear(43);
	b.AddRear(43);
	b.AddRear(43);
	b.AddRear(43);
	b.Print();
	b.PopFront();
	b.PopFront();
	b.PopRear();
	b.PopRear();
	b.PopRear();
	b.Print();




}
