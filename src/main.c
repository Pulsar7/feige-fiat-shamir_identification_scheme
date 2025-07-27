#include "main.h"

int main(int argc, const char** argv) {
    unsigned long long int n = DEFAULT_MODULUS;
    if (argc == 2) {
        n = strtoull(argv[1], NULL, 10);
    }

    // Set seed for pseudorandom-number-selection.
    srand(time(NULL));

    // Generate key-pair
    ZKPParameters zkp_params;
    zkp_params.n = n;
    KeyPair key_pair;
    if (!generate_keypair(&key_pair, &zkp_params)) {
        LOG_ERROR("Couldn't generate key-pair.");
        return 1;
    }

    LOG_DEBUG("Generated private-key: %lld | public-key: %lld", 
        key_pair.private_key.key,
        key_pair.public_key.key
    );

    return 0; // OK
}
