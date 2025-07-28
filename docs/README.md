# Feige-Fiat-Shamir Identification Scheme

## Description

1. Create a private key (secret) and corresponding public key for the __prover__.
2. Prover generates rounds: For each authentication round, the __prover__ creates a __commitment__, receives a __challenge__ from the __verifier__, and computes a response.
3. Verifier verifies all rounds: The __verifier__ checks each __round__’s response __against__ the __commitment__ and __challenge__ to confirm the prover’s identity.