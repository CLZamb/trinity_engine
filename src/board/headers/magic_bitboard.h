#ifndef MAGIC_BITBOARD_H
#define MAGIC_BITBOARD_H

#include <iostream>
#include "bit_utilities.h"
#include <assert.h>

class MagicBitboard
{
  private:
    struct SMagic {
      U64* attacks;  // pointer to attack_table for each particular square
      U64 mask;  // to mask relevant squares of both lines (no outer squares)
      U64 magic;  // magic 64-bit factor
      int shift;  // shift right
    };

    const int RBits[64] = {
      12, 11, 11, 11, 11, 11, 11, 12,
      11, 10, 10, 10, 10, 10, 10, 11,
      11, 10, 10, 10, 10, 10, 10, 11,
      11, 10, 10, 10, 10, 10, 10, 11,
      11, 10, 10, 10, 10, 10, 10, 11,
      11, 10, 10, 10, 10, 10, 10, 11,
      11, 10, 10, 10, 10, 10, 10, 11,
      12, 11, 11, 11, 11, 11, 11, 12
    };

    const int BBits[64] = {
      6, 5, 5, 5, 5, 5, 5, 6,
      5, 5, 5, 5, 5, 5, 5, 5,
      5, 5, 7, 7, 7, 7, 5, 5,
      5, 5, 7, 9, 9, 7, 5, 5,
      5, 5, 7, 9, 9, 7, 5, 5,
      5, 5, 7, 7, 7, 7, 5, 5,
      5, 5, 5, 5, 5, 5, 5, 5,
      6, 5, 5, 5, 5, 5, 5, 6
    };

    static const U64 RookMagic[64];
    static const U64 BishopMagic[64];

    SMagic m_rook_tbl[SquareEnd];
    SMagic m_bishop_tbl[SquareEnd];

    U64 m_rook_table[64][4096];
    U64 m_bishop_table[64][512];

    U64 m_rook_occupancy[64][4096];
    U64 m_bishop_occupancy[64][512];

    constexpr U64 batt(int sq, U64 block);
    constexpr U64 ratt(int sq, U64 block);
    constexpr U64 bmask(int sq);
    constexpr U64 rmask(int sq);
    U64 set_occupancy(int index, int bits, U64 m);
    void _init_bitmasks();
    void _init_slider_masks_shifs_occupancies(int isRook);
    void _init_tables(int isRook);

 public:
    MagicBitboard();
    virtual ~MagicBitboard();

    U64 rook_attacks(U64 occ, SquareIndices sq);
    U64 bishop_attacks(U64 occ, SquareIndices sq);
    U64 queen_attacks(U64 occ, SquareIndices sq);
};

#endif /* MAGIC_BITBOARD_H */
