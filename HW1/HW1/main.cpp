#include "boolstack.h"
#include "boolqueue.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    BoolStack stack; // 객체 설정
    BoolQueue queue; // 객체 설정


    int number = 0;
    int stackNumber; // 기능선택 변수
    int queueNumber; // 기능 선택 변수
    int pushNumber; // 스택에 추가할 원소 변수
    int enqueueNumber; // 큐에 추가할 원소 변수

    while (1) {

        switch (number) {
            case 0: { // 스택 or 큐 선택
                std::cout << std::endl;
                std::cout << "1.Stack 2.Queue" << std::endl;
                std::cout << "원하는 기능의 번호를 입력하세요 : ";
                std::cin >> number;
                std::cout << std::endl;
                break;
            }
            case 1: { // 스택에서 원하는 기능 선택
                std::cout << std::endl;
                std::cout << "1.push 2.pop 3.top 4.empty 5.getSize 6.exit" << std::endl;
                std::cout << "원하는 기능의 번호를 입력하세요 : ";
                std::cin >> stackNumber;
                std::cout << std::endl;

                switch (stackNumber) { // 선택한 기능 작동
                    case 1: // push
                        std::cout << "몇을 입력 할 것 인가요? (0, 1 이외 모든 숫자는 1로 처리)";
                        std::cin >> pushNumber;
                        stack.push(pushNumber);
                        break;
                    case 2: // pop
                        std::cout << stack.pop() << std::endl;
                        break;
                    case 3: //top
                        std::cout << stack.top() << std::endl;
                        break;
                    case 4: // empty
                        if (stack.isEmpty())
                            std::cout << "비어있습니다." << std::endl;
                        else
                            std::cout << "비어있지 않습니다." << std::endl;
                        break;
                    case 5: // getSize
                        std::cout << stack.getSize() << std::endl;
                        break;
                    case 6: // exit
                        std::cout << "exit" << std::endl;
                        number = 0;
                        break;
                }
                break;
            }
            case 2: { // 원하는 기능 선택
                std::cout << std::endl;
                std::cout << "1.enqueue 2.dequeue 3.front 4.empty 5.getSize 6.exit" << std::endl;
                std::cout << "원하는 기능의 번호를 입력하세요 : ";
                std::cin >> queueNumber;
                std::cout << std::endl;

                switch (queueNumber) {
                    case 1: // enqueue
                        std::cout << "몇을 입력 할 것 인가요? (0, 1 이외 모든 숫자는 1로 처리)";
                        std::cin >> enqueueNumber;
                        queue.enqueue(enqueueNumber);
                        break;
                    case 2: // dequeue
                        std::cout << queue.dequeue() << std::endl;
                        break;
                    case 3: // front
                        std::cout << queue.front() << std::endl;
                        break;
                    case 4: // empty
                        if (queue.isEmpty())
                            std::cout << "비어있습니다." << std::endl;
                        else
                            std::cout << "비어있지 않습니다." << std::endl;
                        break;
                    case 5: // getSize
                        std::cout << queue.getSize() << std::endl;
                        break;
                    case 6: // exit
                        std::cout << "exit" << std::endl;
                        number = 0;
                        break;
                }
                break;
            }

        }

    }

    return 0;
}
