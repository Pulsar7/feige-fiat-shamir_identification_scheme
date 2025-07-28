# Feige-Fiat-Shamir Identification Scheme

## Description

- __Prover (P)__: Knows the secret.
  - __r__ is a random number chosen by the Prover.
  - `x = r^2 mod n` is the commitment.
- __Verifier (V)__: Verifies the proof without learning the secret.
  - `e ∈ {0,1}` is the challenge from the Verifier.
