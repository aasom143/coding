int main() {
    vector<int> d;
    for (int i = 1; i <= n; i++) {
        int x=a[i];
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    printf("LIS = %d", d.size());
    return 0;
}
