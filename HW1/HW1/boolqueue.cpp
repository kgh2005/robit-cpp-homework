#include "boolqueue.h"
#include <stdexcept>

BoolQueue::BoolQueue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

BoolQueue::~BoolQueue() {
    while (!isEmpty()) {
        dequeue();  // 스택이 비어질 때까지 항목 제거
    }
}

void BoolQueue::enqueue(bool item) {
    Node* newNode = new Node(item);   // 새로운 노드 생성
    newNode->next = nullptr;          // 새 노드의 next를 기존 topNode로 설정

    if (isEmpty()) {
        frontNode = newNode;
        rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    size++;                           // 스택의 크기 증가
}

bool BoolQueue::dequeue() {
    if (isEmpty()) {
    // 큐가 비어있을 때 예외 처리
        throw std::out_of_range("Queue is empty.");

    }

    Node* tempNode = frontNode;        // 현재 최상단 노드를 임시로 저장
    bool poppedData = frontNode->data; // 최상단 노드의 데이터를 저장
    frontNode = frontNode->next;         // 최상단을 그 다음 노드로 변경

    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    delete tempNode;                 // 이전 최상단 노드 메모리 해제
    size--;                          // 스택 크기 감소

    return poppedData;               // 꺼낸 데이터 반환
}

bool BoolQueue::front() const {
    if (isEmpty())
        throw std::out_of_range("Queue is empty.");
    else
        return frontNode->data;
}

int BoolQueue::getSize() const {
    return size;
}

bool BoolQueue::isEmpty() const {
    return size == 0;
}
