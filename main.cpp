#include <iostream>
#include <numeric>
#include <random>
using namespace std;

// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y); 
  
// Function to find modulo inverse of a 
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) {
        cout << "Inverse doesn't exist"; 
        return -1;
      } else { 
        // m is added to handle negative x 
        int res = (x%m + m) % m; 
        return res; 
    } 
} 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 


pair<int, int> rsaGenerateKeypair(int p, int q){
  int modulus, carmichael, e, d;
  modulus = p*q;
  carmichael = lcm(p-1, q-1);

  random_device rd; // obtain a random number from hardware
  mt19937 gen(rd()); // seed the generator
  uniform_int_distribution<> distr(2, carmichael - 1); // between 1 < e < lambda(n)

  e = distr(gen);
  d = modInverse(e, modulus);

  pair<int, int> keys = make_pair(e, d);
  return keys;
}

string rsaEncrypt(int modulus, int pubkey, string plaintext){
  string ciphertext = "";
  //create ciphertext from plaintext

  return ciphertext;
}

string rsaDecrypt(int modulus, int privkey, string ciphertext){
  string plaintext = "";
  //create plaintext from ciphertext

  return plaintext;
}

int main() {
  std::cout << "Hello World!\n";
}