#include "main.h"

int main(int argc, const char** argv) {
    unsigned long long int n = DEFAULT_MODULUS;
    unsigned int rounds = DEFAULT_ROUNDS;
    if (argc >= 2) {
        n = strtoull(argv[1], NULL, 10);
        if (argc == 3) {
            rounds = strtoul(argv[2], NULL, 5);
        }
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

    // Prover generates rounds.
    ZKPRoundData proof[rounds];
    if (!generate_proof(&zkp_params, &(key_pair.private_key), proof, rounds)) {
        LOG_ERROR("Couldn't generate proof!");
        return 1;
    }

    LOG_INFO("Generated proof.");

    // Verifier verifies all rounds.
    if (!verify_proof(&zkp_params, &(key_pair.public_key), proof, rounds)) {
        LOG_ERROR("Couldn't verify proof!");
        return 1;
    }

    LOG_INFO("Verified proof!");


    return 0; // OK
}
