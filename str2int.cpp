#include <iostream>
#include <string>
using namespace std;

int str2int(string str) {
    int sz = str.size();
    long long res = 0;
    int i = 0, flag = 1;
    if (str[0] == '+') {
        flag = 1;
        ++i;
    } else if (str[0] == '-') {
        flag == -1;
        ++i;
    }
    for (; i < sz; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            res += res * 10 + str[i] - 0x30;
            if (flag == 1 && res > INT_MAX) return P_OVERFLOW;
            if (flag == -1 && res > INT_MAX + 1LL) return N_OVERFLOW;
        } else {
            return INPUT_UNVALID;
        }
    }
    return res * flag;
}
