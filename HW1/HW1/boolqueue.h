#ifndef BOOLQUEUE_H
#define BOOLQUEUE_H

class BoolQueue {
private:
    struct Node {
        bool data;       // 데이터 저장
        Node* next;      // 다음 노드를 가리키는 포인터
        Node(bool item) : data(item), next(nullptr) {}
    };

    Node* frontNode;      // 큐의 앞쪽 노드를 가리킴
    Node* rearNode;       // 큐의 뒤쪽 노드를 가리킴
    int size;             // 큐의 크기

public:
    BoolQueue();          // 생성자
    ~BoolQueue();         // 소멸자

    void enqueue(bool item);  // 항목 삽입
    bool dequeue();           // 항목 제거 및 반환
    bool front() const;       // 가장 앞 항목 반환
    bool isEmpty() const;     // 큐가 비어있는지 확인
    int getSize() const;      // 큐의 크기 반환
};
#endif // BOOLQUEUE_H

