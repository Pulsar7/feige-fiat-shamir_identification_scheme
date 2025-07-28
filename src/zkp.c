#include "zkp.h"

// Simulating, that the verifier sends the prover the challenge.
Challenge get_challenge_from_verifier() {
    // For learning purposes.
    return rand() % 2;
}

// Generate round-proof for the proover.
bool generate_proof_round(ZKPParameters* zkp_parameters, PrivateKey* private_key, ZKPRoundData* round_data) {
    // Step 1: Choose random r in [1, n-1]
    round_data->r = (unsigned long long)(rand() % (zkp_parameters->n - 1)) + 1;

    // Step 2: Compute x = r^2 mod n
    round_data->x = (round_data->r * round_data->r) % zkp_parameters->n;

    // Step 3: Generate random challenge e (0 or 1)
    round_data->challenge = get_challenge_from_verifier();

    // Step 4: Compute response y
    if (round_data->challenge == 0) {
        round_data->y = round_data->r; // y = r
    } else {
        round_data->y = (round_data->r * private_key->key) % zkp_parameters->n; // y = r * s mod n
    }

    return true;
}

// Generate whole proof for the proover.
bool generate_proof(ZKPParameters* zkp_parameters, PrivateKey* private_key, ZKPRoundData* rounds) {
    for (size_t i = 0; i < zkp_parameters->rounds_amount; i++) {
        if (!generate_proof_round(zkp_parameters, private_key, &rounds[i])) {
            LOG_ERROR("Couldn't generate proof for round %zu", i);
            return false;
        } else {
            LOG_DEBUG("Generated proof for round %zu -> r=%lld; x=%lld; challenge=%d; y=%lld", 
                i+1, rounds[i].r, rounds[i].x, rounds[i].challenge, rounds[i].y);
        }
    }

    return true;
}

// Verifies a single challenge-response.
bool verify_round(ZKPParameters* zkp_parameters, PublicKey* public_key, ZKPRoundData* round_data) {
    /*
        1. The prover sends a commitment (x)
        2. The verifier sends a random challenge (e)
        3. The prover responds with a value (y)
        4. The verifier checks if y is valid
    */

    // Left-hand side of the equation
    unsigned long long lhs = (round_data->y * round_data->y) % zkp_parameters->n;

    if (round_data->challenge == ZERO) {
        // Verifier's challenge is ZERO
        // Prover claims y = r → check y^2 ≡ x mod n
        return lhs == round_data->x;
    } else {
        // Verifier's challenge is ONE
        // Prover claims y = r * s → check y^2 ≡ x * v mod n
        // Right-hand side of the equation
        unsigned long long rhs = (round_data->x * public_key->key) % zkp_parameters->n;
        
        return lhs == rhs;
    }
}

// Verifies the whole authentication proof (multiple rounds).
bool verify_proof(ZKPParameters* zkp_parameters, PublicKey* public_key, ZKPRoundData* rounds) {
    for (size_t i = 0; i < zkp_parameters->rounds_amount; i++) {
        if (!verify_round(zkp_parameters, public_key, &rounds[i])) {
            LOG_ERROR("Couldn't verify proof for round %zu", i);
            return false;
        } else {
            LOG_DEBUG("Verified proof for round %zu -> r=%lld; x=%lld; challenge=%d; y=%lld", 
                i+1, rounds[i].r, rounds[i].x, rounds[i].challenge, rounds[i].y);
        }
    }

    return true;
}