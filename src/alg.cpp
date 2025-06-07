// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int count1 = 0;
for (int i = 0; i < len; ++i) {
for (int j = i + 1; j < len; ++j) {
if (arr[i] + arr[j] == value) {
count1++;
}
}
}
return count1;
}

int countPairs2(int* arr, int len, int value) {
int count2 = 0;
int end = len - 1;
while (end > 0) {
if (arr[end] > value) {
end--;
} else {
break;
}
}
for (int i = 0; i < len; i++) {
for (int j = end; j > i; j--) {
if (arr[i] + arr[j] == value)
count2++;
}
}
return count2;
}

int binarySearch(int* arr, int low, int high, int value) {
int first = -1;
int left = low;
int right = high;
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] >= value) {
right = mid - 1;
if (arr[mid] == value) {
first = mid;
}
} else {
left = mid + 1;
}
}
if (first == -1) return 0;
int last = first;
left = first;
right = high;
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] <= value) {
left = mid + 1;
if (arr[mid] == value)
last = mid;
} else {
right = mid - 1;
}
}
return last - first + 1;
}

int countPairs3(int* arr, int len, int value) {
int count3 = 0;
for (int i = 0; i < len; ++i) {
count3 += binarySearch(arr, i + 1, len - 1, value - arr[i]);
}
return count3;
}
