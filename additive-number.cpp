class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; max(j, i) <= n - i - j; ++j) {
                if (isValid(i, j, num)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isValid(int i, int j, string& num) {
        if (num[0] == '0' && i > 1) {
            return false;
        }
        if (num[i] == '0' && j > 1) {
            return false;
        }
        string sum;
        string num1 = num.substr(0, i);
        string num2 = num.substr(i, j);
        for (int start = i + j; start != num.size(); start += sum.size()) {
            sum = add(num1, num2);
            num1 = num2;
            num2 = sum;
            if (num.find(sum, start) != start) {
                return false;
            }
        }
        return true;
    }
    string add(string& num1, string& num2) {
        string res;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            res.push_back(tmp % 10 + '0');
            i -= 1;
            j -= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};