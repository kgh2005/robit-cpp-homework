#ifndef BOOLSTACK_H
#define BOOLSTACK_H


class BoolStack {
private:
    struct Node {
        bool data;
        Node* next;
        Node(bool item) : data(item), next(nullptr) {} //bool: 1바이트 크기의 참/거짓 자료형
    };

    Node* topNode;    // 스택의 최상단 노드를 가리킴
    int size;         // 스택의 크기

public:
    BoolStack();      // 생성자
    ~BoolStack();     // 소멸자

    void push(bool item);  // 항목 삽입
    bool pop();            // 항목 제거 및 반환
    bool top() const;      // 최상단 항목 반환
    bool isEmpty() const;  // 스택이 비어있는지 확인
    int getSize() const;   // 스택의 크기 반환
};
#endif // BOOLSTACK_H

