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

  BIGNUM *a = BN_new();
  BIGNUM *b = BN_new();
  BIGNUM *publica = BN_new();
  BIGNUM *n = BN_new();
  BIGNUM *privada = BN_new();
  BIGNUM *msgCifrada = BN_new();
  BIGNUM *msgDecifrada = BN_new();
  BIGNUM *msg = BN_new();
  char p[14] = "A top secret!";
  char *decifrada;


  //3.1
  BN_hex2bn(&a, "F7E75FDC469067FFDC4E847C51F452DF");
  BN_hex2bn(&b, "E85CED54AF57E53E092113E62F436F4F");
  BN_hex2bn(&publica, "0D88C3");
  BN_hex2bn(&msg,"4120746f702073656372657421");
  BN_mul(n, a, b, ctx);
  BN_mod_exp(privada, a, b, n, ctx);
  //3.2
  BN_hex2bn(&publica, "010001");
  printBN("publica is : ", publica);
  BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
  BN_hex2bn(&privada, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
  BN_mod_exp(msgCifrada, msg, n, publica, ctx);
  //3.3
  BN_mod_exp(msgDecifrada, msgCifrada, n, privada, ctx);
  decifrada = BN_bn2hex(msgDecifrada);
  printf("%s\n", decifrada );

  return 0;
}
