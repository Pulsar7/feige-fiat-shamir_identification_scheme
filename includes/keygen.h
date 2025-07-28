#ifndef FFS_ID_SCHEME_KEY_GENERATOR_H
#define FFS_ID_SCHEME_KEY_GENERATOR_H

#include "zkp.h"
#include "logging.h"
#include "constants.h"

bool generate_keypair(KeyPair* key_pair, ZKPParameters* zkp_parameters);

#endif // FFS_ID_SCHEME_KEY_GENERATOR_H