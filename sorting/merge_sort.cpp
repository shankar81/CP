#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int> &a, int low, int mid, int high) {
    vector<int> arr;
    int i = low, j = mid + 1, count = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) arr.push_back(a[i++]);
        else {
            count += (mid - i) + 1;
            arr.push_back(a[j++]);
        }
    }

    while (i <= mid) arr.push_back(a[i++]);
    while (j <= high) arr.push_back(a[j++]);

    for (int i = low; i <= high; i++) a[i] = arr[i - low];
    return count;
}


int mergeSort(vector<int> &a, int low, int high) {
    int count = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        count += mergeSort(a, low, mid);
        count += mergeSort(a, mid + 1, high);
        count += merge(a, low, mid, high);
    }

    return count;
}

int main() {
    vector<int> a;
    int n = a.size();
    mergeSort(a, 0, n - 1);

    return 0;
}