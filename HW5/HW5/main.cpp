#include <iostream>
#include <string>

using namespace std;

// Animal 클래스 정의
class Animal {
public:
    string name; // 동물 이름
    int age; // 동물 나이
    virtual void makesound() = 0; // 순수 가상 함수
    Animal(); // 생성자 선언
};

// Animal 클래스의 생성자 구현
Animal::Animal(): name(""), age(0) {}

// Dog 클래스 정의
class Dog : public Animal {
public:
    Dog(); // 기본 생성자
    Dog(string n, int a);
    virtual void makesound() { cout << "Bark" << endl; }
};

// 생성자 구현
Dog::Dog() : Animal() {}

// Cat 클래스 정의
class Cat : public Animal {
public:
    Cat();
    Cat(string n, int a);
    virtual void makesound() { cout << "Meow" << endl; }
};

// 생성자 구현
Cat::Cat() : Animal() {}

// Bird 클래스 정의
class Bird : public Animal {
public:
    Bird();
    Bird(string n, int a);
    virtual void makesound() { cout << "Chirp" << endl; }
};

// 생성자 구현
Bird::Bird() : Animal() {}



int main()
{
    int choice; // 선택 저장 변수
    int animal_choice; // 동물 종류 선택 변수

    // 객체 생성
    Dog dog;
    Cat cat;
    Bird bird;

    while(1) {
        cout << "1. 동물 추가" << endl;
        cout << "2. 동물 검색" << endl;
        cin >> choice;

        switch (choice) {
            case 1: { // 동물 추가
                cout << "1. Dog" << endl;
                cout << "2. Cat" << endl;
                cout << "3. Bird" << endl;
                cin >> animal_choice;

                switch (animal_choice) {  // 선택한 동물 추가
                    case 1: {
                        cout << "이름: ";
                        cin >> dog.name;
                        cout << "나이: ";
                        cin >> dog.age;
                        break;
                    }
                    case 2: {
                        cout << "이름: ";
                        cin >> cat.name;
                        cout << "나이: ";
                        cin >> cat.age;
                        break;
                    }
                    case 3: {
                        cout << "이름: ";
                        cin >> bird.name;
                        cout << "나이: ";
                        cin >> bird.age;
                        break;
                    }
                }
                break;
            }
            case 2: { // 동뭉 검색
                cout << "어떤 동물을 검색하시겠습니까?" << endl;
                cout << "1. Dog" << endl;
                cout << "2. Cat" << endl;
                cout << "3. Bird" << endl;
                cin >> animal_choice;

                switch (animal_choice) { // 선택한 동물에 따라 정보 출력
                    case 1: {
                        if (dog.name != "") {
                            cout << "Dog의 이름: " << dog.name << endl;
                            cout << "Dog의 나이: " << dog.age << endl;
                            dog.makesound();
                        } else {
                            cout << "Dog 정보가 없습니다." << endl;
                        }
                        break;
                    }
                    case 2: {
                        if (cat.name != "") {
                            cout << "Cat의 이름: " << cat.name << endl;
                            cout << "Cat의 나이: " << cat.age << endl;
                            cat.makesound();
                        } else {
                            cout << "Cat 정보가 없습니다." << endl;
                        }
                        break;
                    }
                    case 3: {
                        if (bird.name != "") {
                            cout << "Bird의 이름: " << bird.name << endl;
                            cout << "Bird의 나이: " << bird.age << endl;
                            bird.makesound();
                        } else {
                            cout << "Bird 정보가 없습니다." << endl;
                        }
                        break;
                    }
                    default: {
                        cout << "잘못된 선택입니다." << endl;
                        break;
                    }
                }
                break;
            }
            default: {
                cout << "잘못된 선택입니다." << endl;
                break;
            }
        }

    }


    return 0;
}
