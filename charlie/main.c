#include <stdio.h>
#include "play_game.h"

void play_connect_n();
void setup_game();
void play_game();
void announce_results(int player_num);

void setup_game() {
  build_board();  
}

void play_connect_n() {
  setup_game();
  play_game();
  announce_results();
}

void play_game() {
  while (! is_game_over()) {
    get_valid_move();
    do_move();
    change_turn();
  }
}

void announce_results(int player_num) {
  if (someone_won()) {
    printf("Player %d won!\n", player_num);
  }else{
    printf("Tie game.\n");
  }
}


int main(void) {

  play_connect_n();
  
  return 0;
}