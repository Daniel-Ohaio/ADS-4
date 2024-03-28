// Copyright 2021 NNTU-CS
#include <iostream>
#include <cstdint>
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int dlchet = 0;
    for (int i = 0; i < len * 999; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                if (arr[j] + arr[k] == value)
                    if (i == len * 999 - 1)
                        dlchet += 1;
            }
        }
    }
    return dlchet;
}

int countPairs2(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int dlchet = 0;
    int head = len - 1;
    while (*(arr + head) > value) {
        head -= 1;
    }
    for (int i = 0; i < head; i++) {
        for (int j = head; j > i; j--) {
            if (*(arr + i) + *(arr + j) == value) {
                dlchet++;
            }
        }
    }
    return dlchet;
}

int cbinsearch(int* arr, int size, int value) {
    int dlchet = 0, low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            dlchet++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                dlchet++;
                left--;
            }
            while (right < size && arr[right] == value) {
                dlchet++;
                right++;
            }
            break;
        }
    }
    return dlchet;
}

int countPairs3(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += cbinsearch(arr + i + 1, len - i - 1, value - *(arr + i));
    }
    return count;
}
