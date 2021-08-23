#include <iostream>

#include <cstdint>
#include <x86intrin.h>

#include "aes_ni.h"

using namespace std;


int AES_TEST()
{
    uint8_t plain[]      = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    uint8_t enc_key[]    = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t cipher[]     = {0x39, 0x25, 0x84, 0x1d, 0x02, 0xdc, 0x09, 0xfb, 0xdc, 0x11, 0x85, 0x97, 0x19, 0x6a, 0x0b, 0x32};

    unsigned int lo,hi;

    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    auto n_cycle_start = (static_cast<uint64_t>(hi) << 32) | lo;

    AES_ENC(cipher, enc_key, plain);

    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    auto n_cycle_stop = (static_cast<uint64_t>(hi) << 32) | lo;
    cout << "Cycle count: " << n_cycle_stop - n_cycle_start << endl;

    return 0;
}

int main()
{
    cout << "Hello World!" << endl;
    AES_TEST();
    return 0;
}
