class Solution {
public:
    vector<bool> prime;
    int countPrimes(int n) {
        int res = 0;
        sieve(n);
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                //is a prime
                res++;
            }
        }
        return res;
    }
    
    void sieve(int n) {
        prime.clear();
        prime = vector<bool>(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                //anything that is divisible by prime[i] will be considered as non-prime
                for (int j = i * i; j <= n; j+= i) {
                    prime[j] = false;
                }
            }
        }
    }
};
