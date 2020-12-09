#include <iostream>
#include <time.h>

const int MAXSIZE = 100000;

void bubbleSort(int *arr, int len);
void insertionSort(int *arr, int len);
void selectionSort(int *arr, int len);
void shellSort(int *arr, int len);
void mergeSort(int *arr, int len, int left, int right);
void quickSort(int *arr, int len, int left, int right);
void HeapSort(int *arr, int len);
void bucketSort(int *arr);
void radixSort(int *arr);

int main() {
    clock_t begin, end;
    int arr[MAXSIZE];
//    srand(time(nullptr));
    for (int i = 0; i < MAXSIZE; i++) {
        arr[i] = rand() % 100;
    }

    std::cout << "原：\n";
    for (int i = 0; i < MAXSIZE; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';


    int temp[MAXSIZE + 1];
    std::copy(arr, arr + MAXSIZE, temp);
    begin = clock();
    bubbleSort(temp, MAXSIZE);
    end = clock();
    std::cout << "冒泡:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    std::copy(arr, arr + MAXSIZE, temp);
    begin = clock();
    insertionSort(temp, MAXSIZE);
    end = clock();
    std::cout << "插入:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    std::copy(arr, arr + MAXSIZE, temp);
    begin = clock();
    selectionSort(temp, MAXSIZE);
    end = clock();
    std::cout << "选择:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    std::copy(arr, arr + MAXSIZE, temp);
    begin = clock();
    shellSort(temp, MAXSIZE);
    end = clock();
    std::cout << "希尔:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    std::copy(arr, arr + MAXSIZE, temp);
    begin = clock();
    mergeSort(temp, MAXSIZE, 0, MAXSIZE - 1);
    end = clock();
    std::cout << "归并:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    std::copy(arr, arr + MAXSIZE, temp);
    begin = clock();
    quickSort(temp, MAXSIZE, 0, MAXSIZE - 1);
    end = clock();
    std::cout << "快排:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    std::copy(arr, arr + MAXSIZE, temp + 1);
    begin = clock();
    HeapSort(temp, MAXSIZE);
    end = clock();
    std::cout << "堆排:\n";
//    for (int i = 0; i < MAXSIZE; i++) {
//        std::cout << temp[i] << ' ';
//    }
    std::cout << '\n' << double(end - begin) / CLOCKS_PER_SEC * 1000 << "ms\n";

    return 0;
}

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

void selectionSort(int *arr, int len) {
    int minPos;
    for (int i = 0; i < len; i++) {
        minPos = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        std::swap(arr[i], arr[minPos]);
    }
}

void shellSort(int *arr, int len) {
    for (int div = len / 2; div > 0; div /= 2) {
        for (int i = 0; i < div; i++) {
            for (int j = i + div; j < len; j += div) {
                for (int k = j; k >= div && arr[k] < arr[k - div]; k -= div) {
                    std::swap(arr[k], arr[k - div]);
                }
            }
        }
    }
}

void mergeSort(int *arr, int len, int left, int right) {
    if (left == right) {
        return;
    }
    mergeSort(arr, len, left, (left + right) / 2);
    mergeSort(arr, len, (left + right) / 2 + 1, right);

    int *arr1 = arr + left,
            *arr2 = arr + (left + right) / 2 + 1;

    int res[MAXSIZE];
    int count = 0;

    while (arr1 <= arr + (left + right) / 2 && arr2 <= arr + right) {
        if (*arr1 < *arr2) {
            res[count++] = *arr1++;
        } else {
            res[count++] = *arr2++;
        }
    }
    while (arr1 <= arr + (left + right) / 2) {
        res[count++] = *arr1++;
    }
    while (arr2 <= arr + right) {
        res[count++] = *arr2++;
    }

    for (int i = 0; i <= right - left; i++) {
        *(arr + left + i) = res[i];
    }
}

void quickSort(int *arr, int len, int left, int right) {
    if (left >= right) {
        return;
    }

    int p1 = left,
        p2 = right;

    int pivot = arr[left];

    while (1) {
        while (arr[p2] > pivot && p1 < p2) {
            p2--;
        }

        while (arr[p1] <= pivot && p1 < p2) {
            p1++;
        }

        if (p1 == p2) {
            std::swap(arr[left], arr[p1]);
            break;
        }

        std::swap(arr[p1], arr[p2]);
    }

    quickSort(arr, len, left, p1 - 1);
    quickSort(arr, len, p1 + 1, right);
}

void HeapSort(int *arr, int len) {
    int count = 0;
    int res[len];

    for (int i = len; i > 1; i--) {
        if (arr[i] < arr[i / 2]) {
            std::swap(arr[i], arr[i / 2]);
            int j = i;
            while (1) {
                bool flag = 0;
                if (j * 2 + 1 < len - count) {
                    if (arr[j] > arr[j * 2 + 1] || arr[j] > arr[j * 2]) {
                        if (arr[j * 2 + 1] < arr[j * 2]) {
                            std::swap(arr[j], arr[j * 2 + 1]);
                            j = j * 2 + 1;
                            flag = 1;
                        } else {
                            std::swap(arr[j], arr[j * 2]);
                            j = j * 2;
                            flag = 1;
                        }
                    }
                } else if (j * 2 < len - count) {
                    if (arr[j] > arr[j * 2]) {
                        std::swap(arr[j], arr[j * 2]);
                        j = j * 2;
                        flag = 1;
                    }
                } else {
                    break;
                }

                if(!flag) {
                    break;
                }
            }
        }
    }

    while (len - count > 1) {
        res[count++] = arr[1];
        arr[1] = arr[len - count + 1];

        int j = 1;
        while (1) {
            bool flag = 0;
            if (j * 2 + 1 <= len - count) {
                if (arr[j] > arr[j * 2 + 1] || arr[j] > arr[j * 2]) {
                    if (arr[j * 2 + 1] < arr[j * 2]) {
                        std::swap(arr[j], arr[j * 2 + 1]);
                        j = j * 2 + 1;
                        flag = 1;
                    } else {
                        std::swap(arr[j], arr[j * 2]);
                        j = j * 2;
                        flag = 1;
                    }
                }
            } else if (j * 2 <= len - count) {
                if (arr[j] > arr[j * 2]) {
                    std::swap(arr[j], arr[j * 2]);
                    j = j * 2;
                    flag = 1;
                }
            } else {
                break;
            }

            if(!flag) {
                break;
            }
        }
    }
    res[len - 1] = arr[1];
    std::copy(res, res + len, arr);
}
