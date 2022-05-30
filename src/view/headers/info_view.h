#ifndef INFO_VIEW_H
#define INFO_VIEW_H

#include <array>
#include <memory>
#include <string>
#include <vector>
#include "board/headers/savable.h"
#include "graphics/headers/game_drawings.hpp"
#include "graphics/headers/section.h"
#include "game/headers/game_turn_observer.h"
#include "view/headers/view.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::array;

using players = GameTurn::players;

class InfoView : public GameTurnObserver, public View {
 public:
    InfoView();
    virtual ~InfoView();
    void draw();
    void update_turn(const PlayerInfo &info);
    void update_moves(const string &s);
    void update_captures(const string &s);
    void update_game_info(const string &i);

 private:
    const unsigned int kRowMaxLen = Banner::width - 4/*┃  ┃*/;
    static const size_t players_size = GameTurn::kSize;
    static const size_t color_size = Color::SIZE;

    void clear();
    void clear_block();
    void clear_all_sections();
    void update_banner(GameTurn::players p);
    void set_content_to_block_recursively(
        shared_ptr<Section>&, string msg, int cur_row);
    void format_block(shared_ptr<Section>&, string msg);
    bool has_block_space_for_content(
        const shared_ptr<Section>& block, const string& message);
    string format_line(string);

    array<const vector<string>*, players_size> p_banners { &Banner::player1, &Banner::player2};

    shared_ptr<Section> p_top_section;
    shared_ptr<Section> p_player_banner;

    array<shared_ptr<Section>, color_size> p_moves;
    array<shared_ptr<Section>, color_size> p_captures;

    shared_ptr<Section> p_game_info;
    shared_ptr<Section> p_bottom_section;

    PlayerInfo m_turn_info;
};


#endif /* INFO_VIEW_H */
