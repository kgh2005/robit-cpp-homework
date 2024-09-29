#include "myvector.h"
#include <iostream>

using namespace std;


int main() {
    MyVector<int> v;

    int number;

    while (1) {
        // 기능을 선택하기 위해 어떤 기능이 있는지 보여준다.
        std::cout << "1. push_back()" << std::endl;
        std::cout << "2. erase()" << std::endl;
        std::cout << "3. insert()" << std::endl;
        std::cout << "4. show" << std::endl;
        std::cout << "5. empty()" << std::endl;
        std::cout << "6. size()" << std::endl;
        std::cout << "7. exit" << std::endl;

        // 기능을 선택한다.
        std::cin >> number;
        std::cout << std::endl;

        int num;
        int index;

        // 7이 입력 되었을 때 프로그램은 종료 된다.
        if (number == 7) break;

        // 스위치문을 통해서 선택한 기능을 실행시킨다.
        switch (number) {
            case 1: {

                std::cout << "저장할 숫자를 입력하세요." << std::endl;
                std::cin >> num;
                v.push_back(num);
                std::cout << std::endl;
                break;
            }
            case 2: {

                std::cout << "지울 index를 입력하세요." << std::endl;
                std::cin >> index;
                v.erase(index);
                std::cout << std::endl;
                break;
            }
            case 3: {
                std::cout << "index를 입력하세요." << std::endl;
                std::cin >> index;
                std::cout << "숫자를 입력하세요." << std::endl;
                std::cin >> num;

                v.insert(index, num);

                std::cout << std::endl;

                break;
            }
            case 4: {
                if (v.empty()) std::cout << "비어있습니다." << std::endl;
                else {
                    for (int i = 0; i < v.sizeGet(); i++) {
                        std::cout << v.at(i) << std::endl;
                    }

                }

                std::cout << std::endl;

                break;
            }
            case 5: {
                if (v.empty()) std::cout << "비어있습니다." << std::endl;
                else std::cout << "비어있지 않습니다." << std::endl;
                std::cout << std::endl;
                break;
            }
            case 6: {
                std::cout << v.sizeGet() << std::endl;
                std::cout << std::endl;

                break;
            }
            // 잘못된 숫자가 들어왔을 경우 다시 입력하게 한다.
            default: {
                std::cout << "다시 입력하세요" << std::endl;
                std::cout << std::endl;
                break;
            }
        }
    }
    return 0;
}
