#ifndef DEFS_H
#define DEFS_H

#include <unistd.h>

typedef uint64_t U64;
// GLOBALS
extern U64 SetMask[64];
extern U64 ClearMask[64];

enum SquareIndices : int  {
  A1, B1, C1, D1, E1, F1, G1, H1,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A8, B8, C8, D8, E8, F8, G8, H8,

  Squarebegin = A1, 
  SquareEnd = H8 + 1,
};

enum CastleSquares : int {
  NO_CASTLE_POS = SquareEnd,

  WK_CA_INITIAL_POS = E1,
  BK_CA_INITIAL_POS = E8,

  WK_CA_KING_SIDE_END_POS = G1,  // WKCA
  WK_CA_QUEEN_SIDE_END_POS = C1, // WQCA

  BK_CA_KING_SIDE_END_POS = G8,  // BKCA
  BK_CA_QUEEN_SIDE_END_POS = C8, // BQCA

  ROOK_WHITE_CA_KING_SIDE_FROM_POS = H1, // WKCA
  ROOK_WHITE_CA_KING_SIDE_TO_POS = F1, // WKCA

  ROOK_WHITE_CA_QUEEN_SIDE_FROM_POS = A1, // WQCA
  ROOK_WHITE_CA_QUEEN_SIDE_TO_POS = D1, // WQCA

  ROOK_BLACK_CA_KING_SIDE_FROM_POS = H8, // BKCA
  ROOK_BLACK_CA_KING_SIDE_TO_POS = F8, // BkCA
 
  ROOK_BLACK_CA_QUEEN_SIDE_FROM_POS = A8, // BQCA
  ROOK_BLACK_CA_QUEEN_SIDE_TO_POS = D8, // BQCA
};

enum CastlePermission {
  NO_CASTLING = 0,
  WKCA = 1,
  WQCA = 2,
  BKCA = 3,
  BQCA = 4,
};

const int BitTable[64] = {
  63, 30, 3,  32, 25, 41, 22, 33,
  15, 50, 42, 13, 11, 53, 19, 34,
  61, 29, 2,  51, 21, 43, 45, 10,
  18, 47, 1,  54, 9,  57, 0,  35,
  62, 31, 40, 4,  49, 5,  52, 26,
  60, 6,  23, 44, 46, 27, 56, 16,
  7,  39, 48, 24, 59, 14, 12, 55,
  38, 28, 58, 20, 37, 17, 36, 8
};

static const U64 ZERO = 0;
/**
 * @brief A bitboard containing only the square a1. (ie. the number 1)
 */
static const U64 ONE = 1;
static const U64 BLANK = 0b0000000000000000000000000000000000000000000000000000000000000000;
static const U64 FULL =   0b1111111111111111111111111111111111111111111111111111111111111111;

static const U64 ROWMASK[] = {
  0b0000000000000000000000000000000000000000000000000000000011111111,
  0b0000000000000000000000000000000000000000000000001111111100000000,
  0b0000000000000000000000000000000000000000111111110000000000000000,
  0b0000000000000000000000000000000011111111000000000000000000000000,
  0b0000000000000000000000001111111100000000000000000000000000000000,
  0b0000000000000000111111110000000000000000000000000000000000000000,
  0b0000000011111111000000000000000000000000000000000000000000000000,
  0b1111111100000000000000000000000000000000000000000000000000000000
};

static const int RBits[64] = {
  12, 11, 11, 11, 11, 11, 11, 12,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  12, 11, 11, 11, 11, 11, 11, 12
};

static const int BBits[64] = {
  6, 5, 5, 5, 5, 5, 5, 6,
  5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 7, 7, 7, 7, 5, 5,
  5, 5, 7, 9, 9, 7, 5, 5,
  5, 5, 7, 9, 9, 7, 5, 5,
  5, 5, 7, 7, 7, 7, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5,
  6, 5, 5, 5, 5, 5, 5, 6
};

static const U64 NOT_H_FILE = 0b0111111101111111011111110111111101111111011111110111111101111111;
static const U64 NOT_GH_FILE = 0b0011111100111111001111110011111100111111001111110011111100111111;
static const U64 NOT_A_FILE = 0b1111111011111110111111101111111011111110111111101111111011111110;
static const U64 NOT_AB_FILE = 0b1111110011111100111111001111110011111100111111001111110011111100;

const U64 ALLWHITESTART =
0b0000000000000000000000000000000000000000000000001111111111111111;
const U64 ALLBLACKSTART =
0b1111111111111111000000000000000000000000000000000000000000000000;

#endif /* DEFS_H */

