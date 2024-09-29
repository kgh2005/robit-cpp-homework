//#include "myvector.h"

//template <typename T>
//MyVector<T>::MyVector() : data(nullptr), capacity(0), size(0) {}

//template <typename T>
//MyVector<T>::MyVector(const MyVector& other) : capacity(other.capacity), size(other.size) {
//    data = new T[capacity];
//    std::copy(other.data, other.data + size, data);
//}

//template <typename T>
//MyVector<T>::~MyVector() {
//    delete[] data;
//}

//template <typename T>
//void MyVector<T>::push_back(const T& element) {
//    if (size == capacity) {
//        resize();
//    }
//    data[size++] = element;
//}

//template <typename T>
//T MyVector<T>::at(int index) {
//    return data[index];
//}

//template <typename T>
//T MyVector<T>::operator[](int index) {
//    return at(index);
//}

//template <typename T>
//MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
//    if (this == &other) return *this;

//    delete[] data;

//    size = other.size;
//    capacity = other.capacity;
//    data = new T[capacity];

//    for (int i = 0; i < size; i++) {
//        data[i] = other.data[i];
//    }

//    return *this;
//}


//template <typename T>
//MyVector<T> MyVector<T>::operator+(const MyVector& other) {
//    MyVector<T> result;
//    for (int i = 0; i < this->size; ++i) {
//        result.push_back(this->data[i]);
//    }
//    for (int i = 0; i < other.size; ++i) {
//        result.push_back(other.data[i]);
//    }
//    return result;
//}

//template <typename T>
//void MyVector<T>::resize() {
//    int increaseAmount = 5;
//    capacity += increaseAmount;
//    T* newData = new T[capacity];

//    std::copy(data, data + size, newData);

//    delete[] data;
//    data = newData;
//}

//template <typename T>
//bool MyVector<T>::empty() const {
//    return size == 0;
//}

//template <typename T>
//int MyVector<T>::sizeGet() const {
//    return size;
//}

//template <typename T>
//void MyVector<T>::erase(int index) {
//    if (index < 0 || index >= size) return;
//    for (int i = index; i < size - 1; i++) {
//        data[i] = data[i + 1];
//    }
//    size--;
//}

//template <typename T>
//void MyVector<T>::insert(int index, const T& element) {
//    if (index < 0 || index > size) return;
//    if (size == capacity) {
//        resize();
//    }
//    for (int i = size; i > index; i--) {
//        data[i] = data[i - 1];
//    }
//    data[index] = element;
//    size++;
//}

//template <typename T>
//T* MyVector<T>::begin() {
//    return data;
//}

//template <typename T>
//T* MyVector<T>::end() {
//    return data + size;
//}
