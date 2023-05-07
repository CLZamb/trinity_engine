#ifndef BOARD_PANE_H
#define BOARD_PANE_H

#include <memory>

#include "board/board_window/board_pane/squares/square_drawings.h"
#include "board/position/position_fen.h"
#include "input/keyboard/keyboard_input.h"
#include "ui_components/pane.h"

class BoardPane : public Pane {
 public:
  BoardPane();
  explicit BoardPane(const FenFields &fen);
  virtual void make_move(const Move &mv);
  void parse_fen(const FenFields &fen);
  void update_drawing();

 protected:
  void clear();
  void clear_square_on_range(const int start_pos, const int end_pos);
  bool is_number(char c);
  bool is_middle_of_square(const int &col);
  string left_border(const int &row, const int &col);

  const string m_top_section = "top";
  const string m_board_section = "board";
  const string m_bottom_section = "bottom";

  SquaresDrawings m_squares_drawings;
  static const size_t Kboard_pane_size{44};
};

#endif   // !BOARD_PANE_H
