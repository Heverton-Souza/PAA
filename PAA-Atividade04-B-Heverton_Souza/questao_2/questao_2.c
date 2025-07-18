void insertion_sort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int value = v[i];
        int j;

        for (j = i - 1; (j >= 0) && (value < v[j]); j--) {
            v[j + 1] = v[j];
        }

        v[j + 1] = value;
    }
}