// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int dlchet = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                dlchet += 1;
        }
    }
    return dlchet;
}

int countPairs2(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int dlchet = 0, dlleft = 0, dlright = len - 1;
    while (dlleft < dlright) {
        int a = 1, b = 1;
        if (arr[dlleft] + arr[dlright] == value) {
            if (arr[dlleft] == arr[dlright]) {
                dlchet += ((dlright - dlleft + 1) / 2) * (dlright - dlleft);
                break;
            } else if (arr[dlleft] == arr[dlleft + 1]) {
                a = 2;
                for (int i = 1; arr[dlleft + 1 + i] == arr[dlleft]; i++) {
                    a += 1;
                }
            }
            if (arr[dlright] == arr[dlright - 1]) {
                b = 2;
                for (int i = 1; arr[dlright - 1 - i] == arr[dlright]; i++) {
                    b += 1;
                }
            }
            dlchet += a * b;
            dlleft += a;
            dlright -= b;
        } else if (arr[dlleft] + arr[dlright] < value) {
            dlleft++;
        } else {
            dlright--;
        }
    }
    return dlchet;
}

int binarySearch(int arr[], int size, int value) {
    int chet2 = 0;
    if (size == 0) {
        return 0;
    }
    if (arr[size / 2] == value) {
        chet2 += 1;
        if (arr[size / 2 + 1] == value) {
            for (int i = 1; (arr[size / 2 + i] == value) && \
                (size / 2 + i) <= size; i++) {
                chet2 += 1;
            }
        }
        if (arr[size / 2 - 1] == value) {
            for (int i = 1; (arr[size / 2 - i] == value) && \
                (size / 2 - i) >= 0; i++) {
                chet2 += 1;
            }
        }
        return chet2;
    } else if (arr[size / 2] < value) {
        return binarySearch(arr + size / 2, \
            size / 2 + (size == 1 ? 0 : size % 2), value);
    } else {
        return binarySearch(arr, size / 2, value);
    }
}

int countPairs3(int arr[], int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += binarySearch(arr + i + 1, len - i - 1, value - arr[i]);
    }
    return count;
}
