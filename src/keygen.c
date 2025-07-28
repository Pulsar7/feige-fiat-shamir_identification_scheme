#include "keygen.h"

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    while (b != 0) {
        unsigned long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Generate the private key.
bool generate_private_key(PrivateKey* private_key, const ZKPParameters* zkp_parameters) {
    if (zkp_parameters->n < 3) {
        LOG_ERROR("The given modulus '%lld' is too small!", zkp_parameters->n);
        return false;
    }
    
    // Pick (pseudo-)random number.
    unsigned long long int candidate = 0;

    while (candidate == 0 || gcd(candidate, zkp_parameters->n) != 1) {
        candidate = (rand() % (zkp_parameters->n - 2)) + 2;  // [2, n-1]
    }

    // Set chosen number.
    private_key->key = candidate;

    return true;
}

// Generate the public key.
bool generate_public_key(const PrivateKey* private_key, PublicKey* public_key, ZKPParameters* zkp_parameters) {
    if (private_key->key == 0) {
        LOG_ERROR("Invalid private-key!");
        return false;
    }

    public_key->key = (private_key->key * private_key->key) % zkp_parameters->n;

    return true;
}

// Generate the keypair.
bool generate_keypair(KeyPair* key_pair, ZKPParameters* zkp_parameters) {
    PrivateKey* priv = &(key_pair->private_key);
    PublicKey* pub = &(key_pair->public_key);

    if (!generate_private_key(priv, zkp_parameters)) {
        LOG_ERROR("Couldn't generate private-key!");
        return false;
    }

    if (!generate_public_key(priv, pub, zkp_parameters)) {
        LOG_ERROR("Couldn't generate public-key!");
        return false;
    }

    LOG_DEBUG("Generated key-pair.");
    
    

    return true;
}