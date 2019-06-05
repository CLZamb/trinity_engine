#include "board.h"
#include <algorithm>

Board::Board() {
  // parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete p_squares[i];
}

void Board::_init() {
  m_bb._init();
  create_board_squares();
  parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  movement_controller._init(turn->has_black_pieces());
}

void Board::set_players(Player* player1, Player* player2) {
  this->player1 = player1;
  this->player2 = player2;
  this->turn = player1;
}

void Board::undo_square_move(int piece, int piece_captured, SquareIndices from, SquareIndices to) {
  move_squares(m_bb.get_piece(piece), from, to);

  if (piece_captured)
    add_to_board(piece_captured, from);
}

void Board::move_piece_to_square(int piece, SquareIndices from, SquareIndices to) {
  move_squares(m_bb.get_piece(piece), from, to);
  move_piece_bits(piece, from, to);
}

void Board::move_squares(Piece* piece, SquareIndices from, SquareIndices to) {
  if (!piece || !get_square_at_pos(from) || !get_square_at_pos(to))
    return;

  get_square_at_pos(from)->clear_square();
  get_square_at_pos(to)->set_piece(piece);
}

Piece* Board::get_piece_at_square(int pos) {
  if (!get_square_at_pos(pos))
    return nullptr;

  return get_square_at_pos(pos)->get_piece();
}

PlayerMove Board::get_next_move() { return turn->get_next_move(); }
Player* Board::active_player() {  return turn; }

std::ostream& operator<<(std::ostream& os, Board& board) {
  system(CLEAR);
  vector<string> right_border = board.get_board_info();
  os << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n";
  // need to be print upside down so that the bottom begins at row 0
  // for each board row
  int right_border_counter = 0;
  for (int row = 7; row >= 0; --row) {
    // for each box row
    for (int k = 0; k < box::kRowSize; ++k) {
      os << board.left_border(row, k) << "┃";
      // for each board column
      for (int col = 0; col < 8; col++)
        os << board.p_squares[(row * 8) + col]->at(k);

      os <<
        "┃" << right_border[right_border_counter++] << "\n";
    }
  }
  os
    << " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃┃                                                          ┃\n"
    << " ┃    A        B        C        D        E        F        G       H     ┃┃                                                          ┃\n"
    << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
  return os;
}

char Board::left_border(int row, int col) {
  return (col + 1) % 3 ? ' ' :  ('0' + row + 1);
}

string Board::right_border(vector<string> info, int col) {
  return info[col];
}

vector<string> Board::get_board_info() {
  return m_info.get_info();
}

int Board::get_score() { return m_bb.evaluate_board();  }

Board::Square* Board::get_square_at_pos(int pos) { return p_squares[pos]; }

void Board::create_board_squares() {
  create_squares_drawing();
  char squareColor = 'w';

  int position = 0;
  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;
      if (squareColor == 'b') {
        squareColor = 'w';
        p_squares[position] = new Square(&wSquare, false);
      } else {
        squareColor = 'b';
        p_squares[position] = new Square(&bSquare, true);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

void Board::create_squares_drawing() {
  wSquare = *PieceDrawing("BaseWhiteSquare").get_drawing();
  bSquare = *PieceDrawing("BaseBlackSquare").get_drawing();
}

void Board::parser_fen(string fen) {
  char char_piece = ' ';
  SquareIndices square = A1;
  int piece_int;
  static std::map <char, int> piece_map = {
    {'P', bP}, {'R', bR}, {'N', bN}, {'B', bB}, {'Q', bQ}, {'K', bK},
    {'p', wP}, {'r', wR}, {'n', wN}, {'b', wB}, {'q', wQ}, {'k', wK},
  };

  m_bb.reset_all_pieces_bitboard();
  for (unsigned int i = 0; i < fen.length() && square < SquareEnd; ++i) {
    char_piece = fen[i];
    piece_int = piece_map[char_piece];
    if (piece_int) {
      m_bb.set_piece_at_pos(piece_int, square);
      add_to_board(piece_int, square);
      square = SquareIndices(square + 1);

    } else if (is_number(char_piece)) {
      square = SquareIndices(square + (char_piece - '0'));
    }
  }
}

void Board::add_to_board(int type, SquareIndices position) {
  get_square_at_pos(position)->set_piece(m_bb.get_piece(type));
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
}

void Board::undo_last_move() {
  movement_controller.undo_last_move();
}

void Board::move_piece(PlayerMove p_mv) {
  Move move = p_mv.get_move();
  string move_str = p_mv.get_input();
  movement_controller.move_piece(move);
  turn->save_played_moves(piece_str_name.at(move.get_piece())
      + "-" +  move_str);
}

bool Board::is_valid_move(Move mv) {
  return movement_controller.is_valid_move(mv);
}

bool Board::get_checkmate() {
  return movement_controller.get_checkmate();
}

Movement* Board::get_movement() {
  return &movement_controller;
}

void Board::generate_all_moves(bool side, MoveList* moveList) {
  return m_bb.generate_all_moves(side, moveList);
}

void Board::move_piece_bits(int piece, SquareIndices from, SquareIndices to) {
  m_bb.make_move_bb(piece, from, to);
}

void Board::update_killers(Move mv) {
  m_bb.update_killers(mv);
}

void Board::update_search_history(int piece, int to, int depth) {
  m_bb.update_search_history(piece, to, depth);
}

void Board::capture_piece(Move mv, SquareIndices pos) {
  Piecetype captured_piece = mv.get_captured_piece();

  capture_piece_bit(captured_piece, pos);
  turn->save_captured_pieces(piece_str_name.at(captured_piece));
}

void Board::capture_piece_bit(int piece_captured, SquareIndices pos) {
  m_bb.capture_piece(piece_captured, pos);
}

void Board::undo_move(int piece, int piece_captured, SquareIndices from, SquareIndices to) {
  m_bb.undo_move(piece, piece_captured, from, to);
}

void Board::clear_killer_moves() { m_bb.clear_killer_moves(); }
void Board::clear_search_history() { m_bb.clear_search_history(); }
void Board::reset_ply() { m_bb.reset_ply(); }

U64 Board::get_piece_attacks(int type, int from) {
  return m_bb.get_piece_attacks(type, SquareIndices(from));
}

U64 Board::get_non_attack_moves(int type, int from) {
  return m_bb.get_non_attack_moves(type, SquareIndices(from));
}

U64 Board::get_own_pieces_occ(bool is_black) {
  if (is_black) return m_bb.get_all_b_bitboard();

  return  m_bb.get_all_w_bitboard();
}

U64 Board::get_all_pieces_bitboard() const {
  return m_bb.get_all_pieces_bitboard();
}

U64 Board::get_piece_bitboard(int piece) const {
  return m_bb.get_piece_bitboard(piece);
}

Piecetype Board::get_piece_at(int pos) {
  return m_bb.get_piece_at_pos(pos);
}

int Board::evaluate_board() { return m_bb.evaluate_board(); }

// Board::Square
Board::Square::Square(box* baseDrawing, bool blackBox)
    : p_base_drawing(baseDrawing), p_cur_drawing(baseDrawing),
      m_is_black_square(blackBox) {}

Board::Square::~Square() {}

void Board::Square::set_piece(Piece* piece) {
  this->p_piece = piece;
  p_cur_drawing = piece->get_drawing(m_is_black_square);
}

void Board::Square::clear_square() {
  p_cur_drawing = p_base_drawing;
  p_piece = nullptr;
}

char* Board::Square::at(int i) { return p_cur_drawing->content[i]; }
bool Board::Square::is_black_square() { return m_is_black_square; }
Piece* Board::Square::get_piece() { return this->p_piece; }
box* Board::Square::get_current_drawing() { return p_cur_drawing; }

Board::Info::Info(Board* b) : p_board(b) {}
Board::Info::~Info() {}

// vector<string> Board::Info::get_info() { return m_info; }
vector<string> Board::Info::get_info() {
  if (p_board->turn == p_board->player1)
    std::copy(Drawing::player1.begin(), Drawing::player1.end(), m_info.begin());
  else
    std::copy(Drawing::player2.begin(), Drawing::player2.end(), m_info.begin());

  Player* turn = p_board->get_active_player();
  Player* opponent = p_board->get_opponent();

  string score = std::to_string(p_board->get_score());
  string moved = turn->get_played_moves();
  string opp_moved = opponent->get_played_moves();
  string captured = turn->get_captured_pieces();
  string opp_captured = opponent->get_captured_pieces();
  format_block("Board Score", score, start_score_pos);
  format_block("Captures", captured, start_capture_pos);
  format_block("Opponent's captures", opp_captured, start_capture_opp_pos);
  format_block("Your Moves", opp_moved, start_moved_pos);
  format_block("Opponent's moves", moved, start_moved_opp_pos);
  return m_info;
}

void Board::Info::format_block(string title, string msg, int start) {
  recursive_block(title + ": " + msg, start);
}

void Board::Info::recursive_block(string msg, int index) {
  if (msg.size() < line_max_len) {
    m_info[index] = format_line(msg);
    return;
  }

  string resized_line = msg.substr(0, line_max_len);
  m_info[index] = format_line(resized_line);

  msg = msg.substr(line_max_len/* to_end */);
  recursive_block(msg, ++index);
}

string Board::Info::format_line(string line) {
  int num_spaces = line_max_len - line.size()/*┃  ┃*/;
  return  "┃ " + line + std::string(num_spaces, ' ') + " ┃";
}
