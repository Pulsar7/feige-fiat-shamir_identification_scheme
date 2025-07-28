#ifndef FIS_ID_SCHEME_KEY_GENERATOR_H
#define FIS_ID_SCHEME_KEY_GENERATOR_H

#include "zkp.h"
#include "logging.h"
#include "constants.h"

bool generate_keypair(KeyPair* key_pair, ZKPParameters* zkp_parameters);

#endif // FIS_ID_SCHEME_KEY_GENERATOR_H