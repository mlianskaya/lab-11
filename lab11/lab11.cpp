#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

void task1()
{
	cout << "Enter a list of 10 numbers: ";
	vector <int> numbers;
	int temp;
	// Считываем список целых чисел 
	for (int i = 0; i != 10; i++) {
		cin >> temp;
		numbers.push_back(temp);
	}

	int max = *max_element(numbers.begin(), numbers.end()); //Нахождение максимального числа в списке
	cout << "Max number: " << max << endl;

	int min = *min_element(numbers.begin(), numbers.end()); // Нахождение минимального числа в списке
	cout << "Min number: " << min << endl;

	sort(numbers.begin(), numbers.end()); // Сортировка списка целых чисел
	cout << "Sorted list of numbers: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void task2()
{
	vector <int> numbers;
	list<int> List;
	for (int i = 1; i <= 10; i++) {
		numbers.push_back(i);
	}
	cout << "Original vector elements: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Добавляем в вектор три элемента в конец
	fill_n(back_inserter(numbers), 3, 0);
	cout << "Vector after adding elements to the end: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Копируем элементы из вектора в список
	copy(numbers.begin(), numbers.end(), front_inserter(List));
	cout << "List items after copying: ";
	for (list<int>::iterator it = List.begin(); it != List.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Добавляем 3 элемента в начало списка
	fill_n(front_inserter(List), 3, 1);
	cout << "List after adding elements to the beginning: ";
	for (list<int>::iterator it = List.begin(); it != List.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	list<int>::iterator forlist = List.begin();
	advance(forlist, 10);

	//Добавляем 2 элемента в середину списка
	fill_n(inserter(List, forlist), 2, -1);
	cout << "List after adding elements to the middle: ";
	for (list<int>::iterator it = List.begin(); it != List.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void task3()
{
	//Чтение из файла
	vector <int> myVector;
	ifstream file("input.txt");
	copy(istream_iterator<int>(file), istream_iterator<int>(), back_inserter(myVector));
	file.close();
	cout << "Vector from file: ";
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//Запись в файл
	vector <int> myVector2 = { 89, 49, 28, 94, 483, 9};
	ofstream file2;
	file2.open("output.txt");
	copy(myVector2.begin(), myVector2.end(), ostream_iterator<int>(file2, " "));
	cout << "Program completed! Check the file" << endl;
	file2.close();
}

void task4()
{
	vector<int> Vector = { 1, 2, 3, 4, 5 };
	deque<int> Deque;

	copy(Vector.begin(), Vector.end(), back_inserter(Deque));

	cout << "Deque after copying elements: ";
	for (auto it = Deque.begin(); it != Deque.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void task5()
{
	cout << "Enter a list of 10 numbers: ";
	list<int> reverseNumbers;
	int temp;
	for (int i = 0; i != 10; i++) {
		cin >> temp;
		reverseNumbers.push_back(temp);
	}
	cout << "List of numbers in reverse order: ";
	copy(reverseNumbers.rbegin(), reverseNumbers.rend(), ostream_iterator<int>(cout, " "));
}

int main()
{
	cout << "Task 1" << endl;
	task1();
	cout << endl;
	cout <<"--------------------------"<< endl;
	cout << "Task 2" << endl;
	task2();
	cout << endl;
	cout << "--------------------------" << endl;
	cout << "Task 3" << endl;
	task3();
	cout << endl;
	cout << "--------------------------" << endl;
	cout << "Task 4" << endl;
	task4();
	cout << endl;
	cout << "--------------------------" << endl;
	cout << "Task 5" << endl;
	task5();
	cout << endl;
	cout << "--------------------------" << endl;
	
    

}
