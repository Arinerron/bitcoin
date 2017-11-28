// Copyright (c) 2017 The Jobecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef JOBECOIN_CRYPTO_CHACHA20_H
#define JOBECOIN_CRYPTO_CHACHA20_H

#include <stdint.h>
#include <stdlib.h>

/** A PRNG class for ChaCha20. */
class ChaCha20
{
private:
    uint32_t input[16];

public:
    ChaCha20();
    ChaCha20(const unsigned char* key, size_t keylen);
    void SetKey(const unsigned char* key, size_t keylen);
    void SetIV(uint64_t iv);
    void Seek(uint64_t pos);
    void Output(unsigned char* output, size_t bytes);
};

#endif // JOBECOIN_CRYPTO_CHACHA20_H
