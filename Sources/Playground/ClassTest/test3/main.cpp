#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class List
{
private:
	class Node
	{
	public:
		Node(Node* next=nullptr, T* value=nullptr) :
			value(value)
		{
			if(next != nullptr)
			{
				this->prev = next->prev;
				this->next = next;

				this->prev->next = this;
				this->next->prev = this;
			}
			else
			{
				this->prev = this;
				this->next = this;
			}
		}
		~Node()
		{
			if(this->next != this)
			{
				this->prev->next = this->next;
				this->next->prev = this->prev;
			}
		}

		Node* prev;
		Node* next;
		std::shared_ptr<T> value;
	};

public:
	List() : _first(nullptr) {}
	List(int count)
	{
		if(count <= 0)
		{
			_first = nullptr;
			return;
		}

		_first = new Node(nullptr, nullptr);

		while(--count > 0)
		{
			new Node(_first, nullptr);
		}
	}
	~List()
	{
		while(_first != nullptr)
		{
			pop_back();
		}
	}
	std::shared_ptr<T>* operator[](unsigned int index)
	{
		if(_first != nullptr)
		{
			Node* temp = _first;
			while(index--)
				temp = temp->next;

			return &(temp->value);
		}
		else
			return nullptr;
	}

	bool empty() const
	{
		return _first == nullptr;
	}

	void push_back(T* value)
	{
		if(_first != nullptr)
			new Node(_first, value);
		else
			_first = new Node(nullptr, value);
	}
	void push_front(T* value)
	{
		_first = new Node(_first, value);
	}
	void pop_back()
	{
		if(_first != nullptr)
		{
			if(_first->prev == _first)
			{
				delete _first;
				_first = nullptr;
			}
			else
				delete _first->prev;
		}
	}
	void pop_front()
	{
		if(_first != nullptr)
		{
			if(_first->next == _first)
			{
				delete _first;
				_first = nullptr;
			}
			else
			{
				Node* temp = _first;
				_first = _first->next;
				delete temp;
			}
		}
	}

	void print()
	{
		if(_first != nullptr)
		{
			Node* temp = _first;
			do
			{
				std::cout << *(temp->value) << ' ';
				temp = temp->next;
			} while (temp != _first);
			std::cout << std::endl;
		}
	}

private:
	Node* _first;
};

class Test
{
public:
	Test() : value() { std::cout << "Test Constructor " << value << std::endl; }
	Test(int val) : value(val) { std::cout << "Test Constructor2 " << value << std::endl; }
	~Test() { std::cout << "Test Destructor " << value << std::endl; }

	friend std::ostream& operator<<(std::ostream& cout, const Test& test)
	{
		return cout << test.value;
	}
	int value;
};

int main()
{
	List< Test > list;
	list.push_front(new Test(1));
	list.push_back(new Test(0));
	list.push_back(new Test(2));
	list.push_front(new Test(3));
	list.push_back(new Test(4));
	list.push_front(new Test(5));

	list.print();

	list.pop_back();
	list.pop_front();
	list.pop_front();
	list.pop_back();


	return 0;
}
