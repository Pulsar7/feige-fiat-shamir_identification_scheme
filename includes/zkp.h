#ifndef FIS_ID_SCHEME_ZKP_H
#define FIS_ID_SCHEME_ZKP_H

#include "keygen.h"
#include "constants.h"

typedef enum Challenge {
    ZERO = 0,
    ONE = 1
} Challenge;

typedef struct ZKPRoundData {
    unsigned long long int r;    // Random number from the prover
    unsigned long long int x;    // Commitment: x = r² mod n
    Challenge challenge;         // Challenge e (0 or 1)
    unsigned long long int y;    // Response: y = r or r*s mod n
} ZKPRoundData;

bool generate_proof(ZKPParameters* zkp_parameters, PrivateKey* private_key, ZKPRoundData* rounds, unsigned int rounds_amount);
bool verify_proof(ZKPParameters* zkp_parameters, PublicKey* public_key, ZKPRoundData* rounds, unsigned int rounds_amount);

#endif // FIS_ID_SCHEME_ZKP_H