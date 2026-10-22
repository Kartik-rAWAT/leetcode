int totalWaviness(int num1, int num2) {
    if (num1 >= 1 && num2 >= num1 && num2 <= 100000) {
        int i, n, w = 0;
        for (n = num1; n <= num2; n++) {
            int arr[7], N = n, j = 0;
            while (N > 0 && j < 6) {
                arr[j] = N % 10;
                N /= 10;
                j++;
            }
            for (int i = 1; i < j-1 ; i++) {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                    w++;
                else if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) 
                    w++;
            }
        }
        return w;
    }
    return 0;
}