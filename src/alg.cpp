// Copyright 2023 Your Name

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i > 0 && arr[i] == arr[i-1]) continue;
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
        while (j + 1 < len && arr[j] == arr[j+1]) j++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int left_val = arr[left];
      int left_count = 0;
      while (left < len && arr[left] == left_val) {
        left++;
        left_count++;
      }
      int right_val = arr[right];
      int right_count = 0;
      while (right >= 0 && arr[right] == right_val) {
        right--;
        right_count++;
      }
      count += left_count * right_count;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i > 0 && arr[i] == arr[i-1]) continue;
    int target = value - arr[i];
    if (target < arr[i]) break;
    int pos = binarySearch(arr, i + 1, len - 1, target);
    if (pos != -1) {
      count++;
      int j = pos + 1;
      while (j < len && arr[j] == target) {
        count++;
        j++;
      }
    }
  }
  return count;
}
