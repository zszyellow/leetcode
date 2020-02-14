Three solutions:
1. normal binary search
    ```cpp
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (num / mid > mid) l = mid + 1;
            else if (num / mid < mid ) r = mid - 1;
            else {
                if (num % mid == 0) return true;
                else return false;
            }
        }
        return false;
    }
    ```
    Time Complexity: O(logN)
2. Newton Method
    ```cpp
    bool isPerfectSquare(int num) {
        long x = num;
        while (x*x > num) {
            x = (x + num/x) >> 1;
        }
        return x * x == num;
    }
    ```
    Time Complexity: O(logN)
3. Use the feature that a perfect square would be Num = 1 + 3 + 5 + ...
   ```cpp
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
   ```
   Time Complexity: O(sqrt(N))