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
  //Variável temporária
  BN_CTX *ctx = BN_CTX_new();

  BIGNUM *p = BN_new();
  BIGNUM *q = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *res = BN_new();
  BIGNUM *phi = BN_new();
  BIGNUM *tmp = BN_new();
    // Assign a value from a decimal number string
  // BN_dec2bn(&a, "12345678901112231223");
  // Assign a value from a hex number string
  BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  BN_hex2bn(&e, "0D88C3");
  BN_mul(res, a, b, ctx);
  BN_mul(phi, a-1, b-1, ctx);
  BN_mul(tmp, e, b-1, ctx);
  // BN_mod_exp(res, a, b, n, ctx);
  // Generate a random number of 128 bits
  // BN_rand(a, 128, 0, 0);
  // Generate a random prime number of 128 bits
  // BN_generate_prime_ex(a, 128, 1, NULL, NULL, NULL);

  return 0;
}
