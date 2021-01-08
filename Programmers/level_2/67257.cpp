#include <sstream>
#include <string>
#include <vector>

using namespace std;

void strtok_s(string str, string delimeter, vector<long long>& numbers, vector<char>& operands) {
    long long number;
    string num = "";
    for (char c : str) {
        bool is_delimit = false;
        for (char d : delimeter) {
            if (c == d) {
                operands.push_back(d);
                istringstream(num) >> number;
                numbers.push_back(number);
                num = "";
                is_delimit = true;
                break;
            }
        }
        if (!is_delimit) num += c;
    }
    istringstream(num) >> number;
    numbers.push_back(number);
}

void permutation(vector<vector<char>>& operand_priority, vector<char>& operands, int start, int end) {
    if (start == end)
        operand_priority.push_back(operands);
    else {
        for (int i = start; i <= end; i++) {
            swap(operands[start], operands[i]);
            permutation(operand_priority, operands, start + 1, end);
            swap(operands[start], operands[i]);
        }
    }
}

long long solution(string expression) {
    vector<vector<char>> operand_priority;
    vector<char> operands;
    vector<long long> numbers;
    long long answer = 0;

    strtok_s(expression, "*+-", numbers, operands);
    vector<char> operands_kind(operands);

    for (int i = 0; i < operands_kind.size() - 1; i++) {
        for (int j = i + 1; j < operands_kind.size(); j++) {
            if (operands_kind[i] == operands_kind[j]) {
                operands_kind.erase(operands_kind.begin() + j);
                j--;
            }
        }
    }

    permutation(operand_priority, operands_kind, 0, 2);

    for (auto priority : operand_priority) {
        vector<long long> cpNumbers(numbers);
        vector<char> cpOperands(operands);
        for (char c : priority) {
            for (int i = 0; i < cpOperands.size(); i++) {
                if (cpOperands[i] == c) {
                    switch (c) {
                        case '*':
                            cpNumbers[i] *= cpNumbers[i + 1];
                            cpOperands.erase(cpOperands.begin() + i);
                            cpNumbers.erase(cpNumbers.begin() + i + 1);
                            i--;
                            break;
                        case '+':
                            cpNumbers[i] += cpNumbers[i + 1];
                            cpOperands.erase(cpOperands.begin() + i);
                            cpNumbers.erase(cpNumbers.begin() + i + 1);
                            i--;
                            break;
                        case '-':
                            cpNumbers[i] -= cpNumbers[i + 1];
                            cpOperands.erase(cpOperands.begin() + i);
                            cpNumbers.erase(cpNumbers.begin() + i + 1);
                            i--;
                            break;
                        default:;
                    }
                }
            }
        }
        if (abs(cpNumbers[0]) > answer) answer = abs(cpNumbers[0]);
    }

    return answer;
}