#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
class queue
{
private:
	int* arr;
	int mCur;
	int front;
	int rear;
public:
    queue(int size = 10) :
		mCur(size)
		,front(0)
		,rear(0)
	{
		if (size < 2)
		{
			throw std::invalid_argument("size must be >= 2");
		}
		arr = new int[size];
	}
	// copy constructor
	queue(const queue& other) : arr(nullptr), mCur(other.mCur), front(other.front), rear(other.rear)
	{
		arr = new int[mCur];
		for (int i = 0; i < mCur; ++i) arr[i] = other.arr[i];
	}
	// copy assignment
	queue& operator=(const queue& other)
	{
		if (this == &other) return *this;
		int* newArr = new int[other.mCur];
		for (int i = 0; i < other.mCur; ++i) newArr[i] = other.arr[i];
		delete[] arr;
		arr = newArr;
		mCur = other.mCur;
		front = other.front;
		rear = other.rear;
		return *this;
	}
	// move constructor
	queue(queue&& other) noexcept : arr(other.arr), mCur(other.mCur), front(other.front), rear(other.rear)
	{
		other.arr = nullptr;
		other.mCur = 0;
		other.front = other.rear = 0;
	}
	// move assignment
	queue& operator=(queue&& other) noexcept
	{
		if (this == &other) return *this;
		delete[] arr;
		arr = other.arr;
		mCur = other.mCur;
		front = other.front;
		rear = other.rear;
		other.arr = nullptr;
		other.mCur = 0;
		other.front = other.rear = 0;
		return *this;
	}
	~queue() 
	{
		delete[] arr;
		arr = nullptr;
	}
	void push(int val)
	{
        if((rear+1)%mCur==front)
		{
			throw std::overflow_error("队列已满");
		}
		arr[rear] = val;
		rear = (rear + 1) % mCur;
	}
	void pop()
	{
      if (rear == front)
		{
			throw std::underflow_error("队列为空");
		}
		front = (front + 1) % mCur;
	}
    bool empty() const
	{
		if (rear == front)
		{
			return true;
		}
		return false;
	}
 bool full() const
	{
		if ((rear + 1) % mCur == front)
		{
			return true;
		}
		return false;
	}
  bool find(int val) const
	{
      if (rear == front)
		{
			return false;
		}
		for (int i = front; i != rear; i = (i + 1) % mCur)
		{
			if (arr[i] == val) return true;
		}
		return false;
	}
 int frontValue() const
	{
		if (rear == front)
		{
			throw std::underflow_error("队列为空");
		}
		return arr[front];
	}
	int backValue() const
	{
		if (rear == front)
		{
			throw std::underflow_error("队列为空");
		}
		return arr[(rear - 1 + mCur) % mCur];
	}
	void show()
	{
		if (rear == front)
		{
			throw std::underflow_error("队列为空");
		}
		for (int i = front;i != rear;i = (i + 1) % mCur)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
};

int main()
{
	queue MyQueue;
	MyQueue.push(100);
	MyQueue.show();
	MyQueue.pop();
}