#include <stdio.h>
#include <stdlib.h>
#include <openssl/bn.h>

//Print out a big number
void printBN(char *msg, BIGNUM *a){
  // Convert the BIGNUM to number string
  char *number_str = BN_bn2dec(a);
  // Print out the number string
  printf("%s %s\n", msg, number_str);
  // Free the dynamically allocated memory
  OPENSSL_free(number_str);
}


int main(int argc, char *argv[]) {
  BN_CTX *ctx = BN_CTX_new();
  BIGNUM *a = BN_new();

    // Assign a value from a decimal number string
  BN_dec2bn(&a, "12345678901112231223");
  // Assign a value from a hex number string
  BN_hex2bn(&a, "2A3B4C55FF77889AED3F");
  // Generate a random number of 128 bits
  BN_rand(a, 128, 0, 0);
  // Generate a random prime number of 128 bits
  BN_generate_prime_ex(a, 128, 1, NULL, NULL, NULL);

  return 0;
}
