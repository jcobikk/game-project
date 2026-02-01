#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>

// Struktury i klasy
struct Player {
    std::string name;
    int score;
};

struct Player_diff {
    std::string name;
    int score;
    std::string difficulty;
};

// Prototypy funkcji
void sort(std::vector<Player>& list);
void sort2(std::vector<Player_diff>& list);
void play_game(std::string diff_name, int range, std::vector<Player_diff>& total_top, std::vector<Player>& category_top);
void display_top(const std::vector<Player_diff>& list);
void display_top(const std::vector<Player>& list, std::string title);

#endif