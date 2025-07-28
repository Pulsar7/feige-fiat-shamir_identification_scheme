#ifndef FFS_ID_SCHEME_CONSTANTS_H
#define FFS_ID_SCHEME_CONSTANTS_H
#define DEBUG 1
#define DEFAULT_MODULUS 3233
#define DEFAULT_ROUNDS 10

#include <stdbool.h>

typedef struct PublicKey {
    unsigned long long int key;
} PublicKey;

typedef struct PrivateKey {
    unsigned long long int key;
} PrivateKey;

typedef struct KeyPair {
    PublicKey public_key;
    PrivateKey private_key;
} KeyPair;

typedef struct ZKPParameters {
    unsigned long long int n; // modulus
} ZKPParameters;

#endif // FFS_ID_SCHEME_CONSTANTS_H