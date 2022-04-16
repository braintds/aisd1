#include <iostream>
#include <windows.h>

const int mySize = 3, matrixRow1 = 0, matrixRow2 = 2, stackSize = 10, sizeArray = 10, sizeArrayQueue = 5;

using namespace std;


struct MyList
{
	int data;
	MyList* next = nullptr;
	MyList(int data) : data{ data }
	{
	}

	MyList(int data, MyList* next) : data{ data }, next{ next }
	{}
};

//1
void arrayMatrix()
{
	int matrix[mySize][mySize];
	int temp{ 0 };

	for (int i = 0; i < mySize; i++)
	{
		for (int j = 0; j < mySize; j++)
		{
			matrix[i][j] = rand() % 100 + 1;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	for (int j = 0; j < mySize; j++) //арифметическая реализация перестановки строк
	{
		matrix[matrixRow1][j] = matrix[matrixRow1][j] - matrix[matrixRow2][j];
		matrix[matrixRow2][j] = matrix[matrixRow1][j] + matrix[matrixRow2][j];
		matrix[matrixRow1][j] = matrix[matrixRow2][j] - matrix[matrixRow1][j];
	}

	cout << endl;

	for (int i = 0; i < mySize; i++) //вывод после перестановки
	{
		for (int j = 0; j < mySize; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int j = 0; j < mySize; j++) //реализация перестановки строк с помощью доп переменной
	{
		temp = matrix[1][j];
		matrix[1][j] = matrix[matrixRow2][j];
		matrix[matrixRow2][j] = temp;
	}

	cout << endl;

	for (int i = 0; i < mySize; i++) //вывод после перестановки
	{
		for (int j = 0; j < mySize; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

}


void pointerMatrix()
{
	int** pointerArray = new int* [mySize];
	int* temp;

	for (int i = 0; i < mySize; i++)
	{
		pointerArray[i] = new int[mySize];
		for (int j = 0; j < mySize; j++)
		{
			pointerArray[i][j] = rand() % 100 + 1;
			cout << pointerArray[i][j] << " ";
		}
		cout << endl;
	}

	temp = pointerArray[matrixRow1];
	pointerArray[matrixRow1] = pointerArray[matrixRow2];
	pointerArray[matrixRow2] = temp;

	cout << endl;

	for (int i = 0; i < mySize; i++)
	{
		for (int j = 0; j < mySize; j++)
			cout << pointerArray[i][j] << " ";
		cout << endl;
	}


}

//2
void MyPushBack(int a[], int New, int& top)
{
	if (top == 0)
		a[top] = New;

	top++;
	a[top] = New;
}


void printStack(int a[], const int top)
{
	for (int i = 0; i <= top; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


void extractElement(int a[], int& top) //извлечение
{
	cout << "extract: " << a[top] << endl;
	top--;
}


bool isEmpty(const int top)
{
	if (top == 0) return true;
	return false;
}


void purificationStack(int& top) //очистка стека
{
	top = 0;
	cout << "stack clear!" << endl;
}


void stackArray()
{
	int stack[stackSize];
	int top{ 0 };

	cout << "is empty? " << isEmpty(top) << endl;
	for (int i = 0; i < 4; i++)
		MyPushBack(stack, (rand() % 100), top);

	cout << "is empty? " << isEmpty(top) << endl;
	printStack(stack, top);
	MyPushBack(stack, 228, top);
	printStack(stack, top);

	extractElement(stack, top);
	printStack(stack, top);
	purificationStack(top);

	cout << "is empty? " << isEmpty(top) << endl;
}


bool isEmpty(MyList* list)
{
	if (!list) return true;
	return false;
}


MyList* MyPush(MyList* list, int data)
{
	MyList* l = new MyList(data),

		* temp = list;
	l->next = list;
	list = l;
	return list;
}


void printStack(MyList* list)
{
	while (list != nullptr)
	{
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}


MyList* extractElement(MyList* list)
{
	if (isEmpty(list))
		return list;

	cout << list->data << endl;
	list = list->next;
	return list;
}


MyList* initStack(MyList* list, int data)
{
	if (!list)
		list = new MyList(data);
	return list;
}


MyList* purificationStack()
{
	return nullptr;
}


void stackList()
{
	MyList* stack = nullptr;
	int data = 10;

	initStack(stack, data);

	for (int i = 0; i < 5; i++)
		stack = MyPush(stack, rand() % 100);

	printStack(stack);
	stack = extractElement(stack);
	printStack(stack);

	stack = purificationStack();

	cout << "is empty? " << isEmpty(stack) << endl;
}

//3 от сюда нужно доделать

class queue
{
private:
	int queueArray[sizeArrayQueue];
	int first = -1;
	int last = -1;
public:
	void print()
	{
		for (int i = first; i < last; i++)
		{
			cout << queueArray[i] << " ";
		}
		cout << endl;
	}
	void add(const int element)
	{
		if ((first = 0) && (last < sizeArrayQueue))
			cout << "Очередь заполнена!";
		else
		{
			if (first == -1) first = 0;
			last++;
			queueArray[last] = element;
		}
	}
	int get()
	{
		if (isEmpty())
		{
			first = -1;
			last = -1;
			return -1;
		}
		else
		{
			int item;
			item = queueArray[first];
			first++;
			return (item);
		}
	}
	bool isEmpty()
	{
		return last == first;
	}
	void cleanStack()
	{
		while (get() != -1)
			get();
		first = -1;
		last = -1;
	}
};


void addElement(int array[], int& first, int& last, const int element)
{
	//if (queueIsFull(first, last))
	//{
	//	cout << "queue is full!" << endl;
	//	return;
	//}

	if (first == -1)
	{
		++last; ++first;
		array[last] = element;
	}
	++last;
	if (last <= sizeArray)
	{
		array[last = element];
	}
	if (last > sizeArray || last < first)
	{

	}
}


void queueArray()//функция где происходит весь кипиш(типа мейна)
{
	queue MyQueueArray;

	cout << MyQueueArray.isEmpty() << endl;

	MyQueueArray.add(5);
	MyQueueArray.add(6);
	MyQueueArray.add(7);
	MyQueueArray.add(9);

	MyQueueArray.print();

	MyQueueArray.get();

	MyQueueArray.add(19);
	MyQueueArray.add(29);

	MyQueueArray.print();

	cout << MyQueueArray.isEmpty() << " f" << endl;

	MyQueueArray.cleanStack();

	cout << MyQueueArray.isEmpty() << endl;
}
// до сюда

//queue List
struct queueList
{
	int data;
	queueList* next = nullptr;
	queueList* prev = nullptr;

	queueList(int element)
	{
		this->data = element;
	}
};


queueList* initQueueList(const int element)
{
	queueList* newList = new queueList(element);
	newList->next = newList;
	newList->prev = newList;
	/*
	queueList* head = new queueList(element);
	head->next = head;
	head->prev = head;*/

	return newList;
}


queueList* addInQueue(queueList* head, const int element)
{
	queueList* temp = new queueList(element), * pointer;

	pointer = head->prev;

	temp->next = head;
	temp->prev = pointer;
	pointer->next = temp;
	head->prev = temp;

	return head;
}


queueList* extractFromQueue(queueList* head)
{
	queueList* pointer = head->next;
	queueList* pointer1 = head->prev;

	pointer1->next = pointer;
	head = pointer;
	pointer->prev = pointer1;
	return head;
}


void printQueueList(queueList* head)
{
	queueList* tempHead = head;

	do
	{
		cout << tempHead->data << " ";
		tempHead = tempHead->next;
	} while (tempHead != head);
	cout << endl;
}


queueList* deleteQueueList(queueList* head)
{
	queueList* tmp = head, * pointer;
	do
	{
		pointer = tmp->next;
		tmp = nullptr;
		tmp = pointer;
	} while (tmp != head);

	return nullptr;
}


bool isEmpty(queueList* head)
{
	if (head == nullptr || head->next == nullptr)	return true;
	return false;
}


void checkStatus(queueList* head)
{
	if (isEmpty(head))
	{
		cout << "queue is empty!" << endl;
		return;
	}
	cout << "queue is not empty!" << endl;
}


void queueExList()
{
	queueList* head = new queueList(9);
	head = initQueueList(228);

	head = addInQueue(head, 12);
	head = addInQueue(head, 13);
	head = addInQueue(head, 14);
	head = addInQueue(head, 15);
	head = addInQueue(head, 16);

	printQueueList(head);

	head = extractFromQueue(head);
	head = addInQueue(head, 1337);

	printQueueList(head);
	checkStatus(head);

	head = deleteQueueList(head);
	checkStatus(head);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//arrayMatrix();    //part 1
	//pointerMatrix();    

	//stackArray();     //part 2
	//stackList();      

	queueArray();		//part 3
	//queueExList();
	return 0;
}