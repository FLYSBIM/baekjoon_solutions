#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input, bomb;
    cin >> input >> bomb;

    stack<char> s;  // 문자를 저장할 스택

    for (int i = 0; i < input.size(); ++i) {
        s.push(input[i]);

        // 폭발 문자열의 끝과 스택의 top을 비교하여 폭발 여부 확인
        if (input[i] == bomb.back() && s.size() >= bomb.size()) {
            string temp;
            bool explosion = true;

            // 스택에서 폭발 문자열 크기만큼 꺼내서 비교
            for (int j = 0; j < bomb.size(); ++j) {
                temp = s.top() + temp;
                s.pop();
            }

            // 폭발 여부 확인
            if (temp != bomb) {
                explosion = false;
            }

            // 폭발하지 않았다면 다시 스택에 넣음
            if (!explosion) {
                for (char c : temp) {
                    s.push(c);
                }
            }
        }
    }

    // 스택의 내용을 출력 문자열로 만듦
    string result;
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }

    // 결과 출력
    if (result.empty()) {
        cout << "FRULA\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}

