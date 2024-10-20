#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 函数：将数字按升序排列，返回最小的数
long long getMinNumber(string num) {
    sort(num.begin(), num.end());
    return stoll(num);  // 使用stoll以支持更大范围的数值
}

// 函数：将数字按降序排列，返回最大的数
long long getMaxNumber(string num) {
    sort(num.begin(), num.end(), greater<char>());
    return stoll(num);
}

// 函数：执行卡普雷卡常数操作
long long kaprekarProcess(long long num, int n, int max_iterations = 100) {
    for (int i = 0; i < max_iterations; ++i) {
        // 将数字转换成字符串，方便排序
        string strNum = to_string(num);

        // 补齐位数，确保是 n 位数（前导0不会影响排序结果）
        while (strNum.length() < n) {
            strNum = "0" + strNum;
        }

        // 获取最大数和最小数
        long long maxNum = getMaxNumber(strNum);
        long long minNum = getMinNumber(strNum);

        // 计算差值
        long long result = maxNum - minNum;
        cout << maxNum << " - " << minNum << " = " << result << endl;

        // 如果当前差值等于 num，说明已经稳定
        if (result == num) {
            cout << "Stable number found after " << i + 1 << " iterations: " << result << endl;
            return result;
        }

        // 更新 num 进行下一次迭代
        num = result;

        // 如果结果已经稳定为 0
        if (num == 0) {
            cout << "Reached zero, stopping iteration." << endl;
            break;
        }
    }

    cout << "No stability found within " << max_iterations << " iterations." << endl;
    return -1;
}

int main() {
    int n;
    long long num;

    // 输入位数 n 和 n 位整数
    cout << "Enter the number of digits (n): ";
    cin >> n;
    cout << "Enter a " << n << "-digit number: ";
    cin >> num;

    // 开始卡普雷卡常数操作，最大迭代100次
    kaprekarProcess(num, n);

    return 0;
}

