

int solve(int n, int m, int mid) {
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        ans = ans * mid;
        if(ans > m) return 2; // mid^n is greater than m
    }
    if(ans == m) return 1; // mid^n is equal to m
    return 0; // mid^n is less than m
}

int NthRoot(int n, int m) {
    int low = 1;
    int high = m;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        int val = solve(n, m, mid);
        
        if(val == 1) return mid; // Found the nth root
        else if(val == 0) {
            low = mid + 1; // mid^n is less than m, search in the higher range
        } else {
            high = mid - 1; // mid^n is greater than m, search in the lower range
        }
    }

    return -1; // No integer nth root found
}
