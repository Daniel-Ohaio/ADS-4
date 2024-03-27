// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>
int cbinsearch(int* arr, int size, int value);
int countPairs1(int* arr, int len, int value);
int countPairs2(int* arr, int len, int value);
int countPairs3(int* arr, int len, int value);

int countPairs1(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int dlchet = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                dlchet += 1;
        }
    }
    return countPairs2(arr, len, value);
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
    return countPairs3(arr, len, value);
}

int cbinsearch(int* arr, int size, int value) {
    int count = 0, low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            count++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                count++;
                left--;
            }
            while (right < size && arr[right] == value) {
                count++;
                right++;
            }
            break;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(arr + i + 1, len - i - 1, value - *(arr + i));
    }
    return count;
}
