#ifndef SQUARES_H
#define SQUARES_H

#include "board/headers/square.h"
#include <array>
using std::array;

class Squares{
public:
  Squares();
  virtual ~Squares();
  Square &operator[](size_t i);
  void clear();
  bool exist_piece_at_position(const int& pos);
  void do_move(const SquareIndices &from, const SquareIndices &to);
private:
  static const size_t board_rwo_sizea = 8;
  static const size_t board_column_sizea = 8;
  std::array<Square, board_rwo_sizea * board_column_sizea> m_squares;  
};

#endif /* SQUARES_H */
