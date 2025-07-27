#ifndef FIS_ID_SCHEME_CONSTANTS_H
#define FIS_ID_SCHEME_CONSTANTS_H
#define DEBUG 1
#define DEFAULT_MODULUS 3233

#include <stdbool.h>

typedef struct ZKPParameters {
    unsigned long long int n; // modulus
} ZKPParameters;

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


#endif // FIS_ID_SCHEME_CONSTANTS_H