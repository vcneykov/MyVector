#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
	T* list;
	int number_objects;
	int max_number_objects;
	int start;
	int end;

	void resize();
public:
	// Big 4
	Vector();
	Vector(const Vector& rhs);
	Vector& operator= (const Vector& rhs);
	~Vector();

	// Operators
	bool operator==(const Vector& rhs) const;
	T operator[](int position) const;

	// Functionalities
	void AddObject(const T& to_add);
	void RemoveObject(T to_remove);
	void SetElement(int position, T value);
	void PushBack(T value);
	void Print() const;

	// Getters
	T GetObject(int position) const;
	int GetObjectPosition(T object) const;
};

template<typename T>
void Vector<T>::resize()
{
	T* new_list = new T[this->max_number_objects * 2];

	for (int i = 0; i < this->number_objects; i++) {
		new_list[i] = this->list[i];
	}

	delete[] this->list;
	this->list = new_list;
	this->max_number_objects *= 2;
}

template<typename T>
Vector<T>::Vector()
{
	this->list = new T[1];
	this->number_objects = 0;
	this->max_number_objects = 1;
	this->start = 0;
	this->end = -1;
}

template<typename T>
Vector<T>::Vector(const Vector& rhs)
{
	this->max_number_objects = rhs.max_number_objects;
	this->number_objects = rhs.number_objects;
	this->start = rhs.start;
	this->end = rhs.end;

	this->list = new T[rhs.max_number_objects];

	for (int i = 0; i < number_objects; i++) {
		this->list[i] = rhs.list[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	if (this != &rhs) {
		delete[] this->list;

		this->max_number_objects = rhs.max_number_objects;
		this->number_objects = rhs.number_objects;
		this->start = rhs.start;
		this->end = rhs.end;

		this->list = new T[rhs.max_number_objects];

		for (int i = 0; i < number_objects; i++) {
			this->list[i] = rhs.list[i];
		}
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] this->list;
}

template<typename T>
inline bool Vector<T>::operator==(const Vector& rhs) const
{
	return this->list == rhs.list && this->number_objects == rhs.number_objects &&
		this->max_number_objects == rhs.max_number_objects && this->start == rhs.start && this->end == rhs.end;
}

template<typename T>
void Vector<T>::AddObject(const T& to_add)
{
	if (this->number_objects == this->max_number_objects) {
		this->resize();
	}

	this->end += 1;
	if (this->end == this->max_number_objects) {
		this->end = 0;
	}

	this->list[this->end] = to_add;
	this->number_objects++;
}

template<typename T>
void Vector<T>::SetElement(int position, T value)
{
	if (position <= number_objects && this->max_number_objects > this->number_objects + 1) {
		this->list[position] = value;
		this->number_objects++;
	}
	else {
		std::cout << "Invalid position \n";
	}
}

template<typename T>
void Vector<T>::PushBack(T value)
{
	if (this->max_number_objects == this->number_objects) {
		resize();
	}

	this->list[this->number_objects] = value;
	this->number_objects++;
}

template<typename T>
void Vector<T>::RemoveObject(T to_remove)
{
	for (int i = 0; i < max_number_objects; i++) {
		if (this->list[i] == to_remove) {
			for (int j = i; j < number_objects - 1; j++) {
				this->list[j] = this->list[j + 1];
			}
		}
	}

	this->number_objects--;
	this->end--;
}

template<typename T>
void Vector<T>::Print() const
{
	for (int i = 0; i < this->number_objects; i++) {
		this->list[i].Print();
	}
}

template<typename T>
T Vector<T>::GetObject(int position) const
{
	if (position < this->number_objects) {
		return this->list[position];
	}
	else {
		return T();
	}
}

template<typename T>
int Vector<T>::GetObjectPosition(T object) const
{
	for (int i = 0; i < this->number_objects; i++) {
		if (this->list[i] == object)
			return i;
	}
	return -1;
}

template<typename T>
T Vector<T>::operator[](int position) const
{
	if (position < this->number_objects) {
		return T();
	}
	else {
		return this->list[position];
	}
}
