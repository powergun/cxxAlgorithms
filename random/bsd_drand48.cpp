//
// Created by wein on 2/09/18.
//

// source
// https://gist.github.com/mortennobel/8665258

#include "bsd_drand48.hh"

#include <cmath>

namespace bsd_impl {

#define RAND48_SEED_0   (0x330e)
#define RAND48_SEED_1 (0xabcd)
#define RAND48_SEED_2 (0x1234)
#define RAND48_MULT_0 (0xe66d)
#define RAND48_MULT_1 (0xdeec)
#define RAND48_MULT_2 (0x0005)
#define RAND48_ADD (0x000b)

unsigned short _rand48_seed[3] = {
    RAND48_SEED_0,
    RAND48_SEED_1,
    RAND48_SEED_2
};
unsigned short _rand48_mult[3] = {
    RAND48_MULT_0,
    RAND48_MULT_1,
    RAND48_MULT_2
};
unsigned short _rand48_add = RAND48_ADD;

void
_dorand48(unsigned short xseed[3])
{
    unsigned long accu;
    unsigned short temp[2];

    accu = (unsigned long)_rand48_mult[0] * (unsigned long)xseed[0] +
           (unsigned long)_rand48_add;
    temp[0] = (unsigned short)accu;        /* lower 16 bits */
    accu >>= sizeof(unsigned short)* 8;
    accu += (unsigned long)_rand48_mult[0] * (unsigned long)xseed[1] +
            (unsigned long)_rand48_mult[1] * (unsigned long)xseed[0];
    temp[1] = (unsigned short)accu;        /* middle 16 bits */
    accu >>= sizeof(unsigned short)* 8;
    accu += _rand48_mult[0] * xseed[2] + _rand48_mult[1] * xseed[1] + _rand48_mult[2] * xseed[0];
    xseed[0] = temp[0];
    xseed[1] = temp[1];
    xseed[2] = (unsigned short)accu;
}

double erand48(unsigned short xseed[3])
{
    _dorand48(xseed);
    return ldexp((double) xseed[0], -48) +
           ldexp((double) xseed[1], -32) +
           ldexp((double) xseed[2], -16);
}

} // namespace

double bsd_drand48(){
    return bsd_impl::erand48(bsd_impl::_rand48_seed);
}

void bsd_srand48(long seed){
    bsd_impl::_rand48_seed[0] = RAND48_SEED_0;
    bsd_impl::_rand48_seed[1] = (unsigned short)seed;
    bsd_impl::_rand48_seed[2] = (unsigned short)(seed >> 16);
    bsd_impl::_rand48_mult[0] = RAND48_MULT_0;
    bsd_impl::_rand48_mult[1] = RAND48_MULT_1;
    bsd_impl::_rand48_mult[2] = RAND48_MULT_2;
    bsd_impl::_rand48_add = RAND48_ADD;
}
