#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct CharIntConstruct {
    int type;  // 0 == 숫자, 1 == 연산자
    int number;
    char symbol;
};

// 우선순위 정하는 함수
int precedence(char item) {
    if (item == '+' || item == '-') return 1;
    if (item == '*' || item == '/') return 2;
    if (item == '^') return 3;
    return 0;
}

// 후위 표기법 변환 함수
vector<CharIntConstruct> make_postfix(const string& input) {
    vector<CharIntConstruct> postfix; // 후위 표기법을 저장할 벡터
    stack<char> item; // 연산자를 저장할 스택

    size_t i = 0; // 문자열 인덱스 초기화

    while (i < input.size()) {
        // 공백을 건너뛰기
        while (i < input.size() && input[i] == ' ') {
            i++;
        }

        if (i >= input.size()) break;

        // 숫자를 처리
        if (isdigit(input[i])) {
            int number = 0;
            // 숫자를 계속 읽음
            while (i < input.size() && isdigit(input[i])) {
                number = number * 10 + (input[i] - '0'); // 각 자릿수 계산
                i++;
            }
            postfix.push_back({0, number, ' '}); // 숫자 추가
        }
        // 여는 괄호 처리
        else if (input[i] == '(') {
            item.push('(');
            i++;
        }
        // 닫는 괄호 처리
        else if (input[i] == ')') {
            while (!item.empty() && item.top() != '(') {
                postfix.push_back({1, 0, item.top()}); // 스택에서 연산자 꺼내기
                item.pop();
            }
            if (item.empty()) return {}; // 괄호 불일치 오류
            item.pop(); // 여는 괄호 제거
            i++;
        }
        // 연산자 처리
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '^') {
            char op = input[i];
            while (!item.empty() && precedence(item.top()) >= precedence(op)) {
                postfix.push_back({1, 0, item.top()}); // 스택에서 연산자 꺼내기
                item.pop();
            }
            item.push(op); // 연산자 스택에 추가
            i++;
        }
        // 잘못된 입력 처리
        else {
            return {}; // 잘못된 입력
        }
    }

    // 남아 있는 연산자를 모두 처리
    while (!item.empty()) {
        if (item.top() == '(') return {}; // 괄호 불일치 오류
        postfix.push_back({1, 0, item.top()}); // 스택에서 연산자 꺼내기
        item.pop();
    }

    return postfix;
}

bool evaluate_stack(stack<int>& numbers, const char symbol) {
    // 스택에 숫자 2개 이상이라고 가정
    if (numbers.size() < 2) return 0;

    int value2 = numbers.top();
    numbers.pop();
    int value1 = numbers.top();
    numbers.pop();

    int result; // 결과 저장할 변수
    switch (symbol) {
        case '+': result = value1 + value2; break;
        case '-': result = value1 - value2; break;
        case '*': result = value1 * value2; break;
        case '/':
            if (value2 == 0) return 0; // 0으로 나누기 방지
            result = value1 / value2;
            break;
        case '^':
            result = 1; // 제곱을 위한 초기값
            for (int i = 0; i < value2; ++i) result *= value1;
            break;
        default: return 0;
    }

    numbers.push(result);
    return 1;
}

int evaluate_postfix(const vector<CharIntConstruct>& postfix) {
    if (postfix.empty()) return -1;

    stack<int> numbers;
    for (const auto& token : postfix) {
        if (token.type == 0) {
            numbers.push(token.number);
        } else {
            if (!evaluate_stack(numbers, token.symbol)) {
                return -1; // 계산 오류
            }
        }
    }

    if (numbers.size() != 1) {
        return -1; // 오류: 결과가 하나가 아님
    }

    return numbers.top();
}

int main() {
    cout << "수식을 입력하세요." << endl;
    cout << "'EOI'를 입력하면 결과를 출력합니다." << endl;

    vector<string> expressions; // 수식 저장할 벡터
    string input; // 입력을 저장할 변수

    while (true) {
        cout << "> ";
        getline(cin, input);

        // EOI가 입력 되었다면 계산 시작
        if (input == "EOI") {
            for (const auto& expr : expressions) {
                vector<CharIntConstruct> postfix = make_postfix(expr); // 후위 표기법으로 변환
                int result = evaluate_postfix(postfix); // 수식 계

                cout << "결과: ";
                if (result == -1) { // 계산 중 오류 출력
                    cout << "오류" << endl;
                } else {
                    cout << result << endl;
                }
            }
            break;
        }

        expressions.push_back(input);
    }

    return 0;
}
