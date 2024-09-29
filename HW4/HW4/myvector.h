#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;         // 동적 배열
    int capacity;    // 배열의 용량
    int size;        // 현재 원소의 개수

    void resize();   // 배열 크기 늘리는 함수

public:
    MyVector();                     // 기본 생성자
    MyVector(const MyVector& other); // 복사 생성자
    ~MyVector();                    // 소멸자

    void push_back(const T& element);
    T at(int index);
    T operator[](int index);
    MyVector& operator=(const MyVector& other); // 복사 대입 연산자
    MyVector operator+(const MyVector& other); // 벡터 덧셈 연산자

    bool empty() const;
    int sizeGet() const;
    void erase(int index);
    void insert(int index, const T& element);

    T* begin();
    T* end();
};

// 기본 생성자
template <typename T>
MyVector<T>::MyVector() : data(nullptr), capacity(0), size(0) {}

// 복사 생성자
template <typename T>
MyVector<T>::MyVector(const MyVector& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    std::copy(other.data, other.data + size, data);
}

// 소멸자
template <typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

// 원소 추가
template <typename T>
void MyVector<T>::push_back(const T& element) {
    if (size == capacity) {
        resize();
    }
    data[size++] = element;
}

// 특정 인덱스의 원소 반환
template <typename T>
T MyVector<T>::at(int index) {
    return data[index];
}

// [] 연산자 오버로딩
template <typename T>
T MyVector<T>::operator[](int index) {
    return at(index);
}

// = 연산자 오버로딩
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this == &other) return *this;  // 자기 자신을 대입하는 경우, 그대로 반환

    delete[] data;  // 기존 데이터를 해제

    // 새로운 데이터 할당 및 크기 설정
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];

    // 다른 벡터의 데이터를 복사
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;  // 자기 자신 반환
}


// + 연산자 오버로딩 (두 벡터 더하기)
template <typename T>
MyVector<T> MyVector<T>::operator+(const MyVector& other) {
    MyVector<T> result;
    for (int i = 0; i < this->size; ++i) {
        result.push_back(this->data[i]); // 왼쪽 벡터의 원소 추가
    }
    for (int i = 0; i < other.size; ++i) {
        result.push_back(other.data[i]); // 오른쪽 벡터의 원소 추가
    }
    return result;
}

// 내부적으로 배열 크기 늘리기
template <typename T>
void MyVector<T>::resize() {
    int increaseAmount = 5; // 증가량 설정
    capacity += increaseAmount; // 현재 용량에 증가량 추가
    T* newData = new T[capacity]; // 새로운 배열 생성

    // 기존 데이터를 새 배열로 복사
    std::copy(data, data + size, newData);

    delete[] data; // 이전 배열 메모리 해제
    data = newData; // 새로운 배열로 데이터 포인터 업데이트
}

// 벡터가 비어있는지 확인
template <typename T>
bool MyVector<T>::empty() const {
    return size == 0;
}

// 벡터의 원소 개수 반환
template <typename T>
int MyVector<T>::sizeGet() const {
    return size;
}

// 특정 인덱스의 원소 삭제
template <typename T>
void MyVector<T>::erase(int index) {
    if (index < 0 || index >= size) return; // 인덱스 범위 체크 후 무시
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

// 특정 인덱스에 원소 삽입
template <typename T>
void MyVector<T>::insert(int index, const T& element) {
    if (index < 0 || index > size) return; // 인덱스 범위 체크 후 무시
    if (size == capacity) {
        resize();
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    size++;
}

// 시작 원소에 대한 포인터 반환
template <typename T>
T* MyVector<T>::begin() {
    return data; // 첫 번째 원소의 포인터 반환
}

// 끝 원소 다음에 대한 포인터 반환
template <typename T>
T* MyVector<T>::end() {
    return data + size; // 마지막 원소 다음의 포인터 반환
}

//#include "myvector.h"

#endif // MYVECTOR_H
