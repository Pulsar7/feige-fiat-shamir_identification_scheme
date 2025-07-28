# Feige-Fiat-Shamir Identification Scheme

## Description

1. Create a private key (secret) and corresponding public key for the __prover__.
2. Prover generates rounds: For each authentication round, the __prover__ creates a __commitment__, receives a __challenge__ from the __verifier__, and computes a response.
3. Verifier verifies all rounds: The __verifier__ checks each __round__’s response __against__ the __commitment__ and __challenge__ to confirm the prover’s identity.

>__WARNING__: This is a very simple implementation of the „Feige-Fiat-Shamir-Identification-Scheme” and should only be used for educational learning purposes. Cryptographically unsafe functions like `rand` are being used, which is absolutely **not recommended** for real-world implementation! Furthermore, there is currently no overflow-preventing function implemented if big numbers are being used. Please keep that in mind, when playing around.

This program allows you to configure key parameters via command-line arguments:

- **`n` (modulus):** The modulus used for modular arithmetic. Defaults to `DEFAULT_MODULUS`.
- **`rounds`:** The number of authentication rounds (security parameter). Defaults to `DEFAULT_ROUNDS`.

Both default values are defined in the `constants.h` header file.

### Usage

You can override these values when running the program:

```bash
./build/feige_fiat_shamir_id_scheme [modulus] [rounds]
```