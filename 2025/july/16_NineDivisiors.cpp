Given a positive integer n, you need to count the numbers less than
 or equal to n having exactly 9 divisors.

Examples :

Input: n = 100
Output: 2
Explanation: Numbers which have exactly 9 divisors are 36 and 100.
Input: n = 200
Output: 3
Explanation: Numbers which have exactly 9 divisors are 36, 100, 196. 


// chat gpt code learn the sieve concept (pending)
class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i*i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i*i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    int countNumbers(int n) {
        int count = 0;

        int limit = pow(n, 1.0/8);  
        vector<bool> isPrime = sieve(sqrt(n));  

        
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                long long p8 = 1;
                for (int j = 0; j < 8; j++) p8 *= i;
                if (p8 <= n) count++;
            }
        }

        
        vector<int> primes;
        for (int i = 2; i <= sqrt(n); i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i+1; j < sz; j++) {
                long long prod = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if (prod <= n) count++;
                else break;
            }
        }

        return count;
    }
};



// //1010/1111
// class Solution {
//   public:
//     int countNumbers(int n) {
//         int finalcount = 0;

//         for (int num = n; num >= 36; num--) {
//             int x = num;
//             int count = 1;

//             for (int i = 2; i * i <= x; i++) {
//                 int power = 0;
//                 while (x % i == 0) {
//                     power++;
//                     x /= i;
//                 }
//                 if (power > 0) count *= (power + 1);
//             }

//             if (x > 1) count *= 2;

//             if (count == 9) finalcount++;
//         }

//         return finalcount;
//     }
// };



//1010/1111
// int countNumbers(int n) {
//         int finalcount=0;
        
//         if(n<36) return 0;
        
//         for(int i=n;i>=36;i--)
//         {
//             int count=0;
            
//             for(int j=1;j*j<=i;j++)
//             {
//                 if(i%j==0)
//                 {
//                     if(i/j==j) count++;
//                     else count+=2;
                    
//                 }
//             }
//             if(count==9)
//             {
//                 finalcount++;
//             }
//         }
//         return finalcount;
//     }
