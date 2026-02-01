#include "game_functions.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::vector<std::string> too_high = {
    "Za duzo! Sprobuj mniejsza liczbe.",
    "Ups, to za wysoko!",
    "Nie, liczba jest mniejsza.",
    "Za duza! Zmniejsz troche."
};

std::vector<std::string> too_low = {
    "Za malo! Sprobuj wieksza liczbe.",
    "Nie, liczba jest wieksza.",
    "Za nisko! Podnies troche.",
    "Za mala! Sprobuj wyzej."
};

void sort(std::vector<Player>& list) {
    for (size_t a = 0; a < list.size(); a++) {
        for (size_t b = 0; b < list.size() - 1; b++) {
            if (list[b].score > list[b + 1].score) std::swap(list[b], list[b + 1]);
        }
    }
}

void sort2(std::vector<Player_diff>& list) {
    for (size_t a = 0; a < list.size(); a++) {
        for (size_t b = 0; b < list.size() - 1; b++) {
            if (list[b].score > list[b + 1].score) std::swap(list[b], list[b + 1]);
        }
    }
}

void play_game(std::string diff_name, int range, std::vector<Player_diff>& total_top, std::vector<Player>& category_top) {
    int guess = -1;
    int counter = 1;
    srand(time(0));
    int number = rand() % range + 1;

    system("cls");
    std::cout << "\nZgadnij liczbe od 1 do " << range << "!\n";

    while (guess != number) {
        std::cout << "\nTo twoja " << counter << " proba. Twoj strzal: ";
        if (!(std::cin >> guess)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "To nie jest liczba!\n";
            continue;
        }
        counter++;

        if (guess > number) {
            std::cout << too_high[rand() % too_high.size()] << "\n";
        } else if (guess < number) {
            std::cout << too_low[rand() % too_low.size()] << "\n";
        } else {
            std::string name;
            std::cout << "Brawo! Trafiles w " << counter - 1 << " probach!\n";
            std::cout << "Podaj swoje imie: ";
            std::cin >> name;

            Player_diff temp = {name, counter - 1, diff_name};
            total_top.push_back(temp);

            Player temp_cat = {name, counter - 1};
            category_top.push_back(temp_cat);

            sort2(total_top);
            sort(category_top);
            std::cout << "\nWynik zapisany! Nacisnij Enter...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
        }
    }
}

void display_top(const std::vector<Player_diff>& list) {
    system("cls");
    std::cout << "=== TOP5 WYNIKOW WSZYSTKICH POZIOMOW ===\n\n";
    if (list.empty()) {
        std::cout << "Brak wynikow.\n";
    } else {
        for (size_t i = 0; i < list.size() && i < 5; i++) {
            std::cout << i + 1 << ". " << list[i].name << " - " << list[i].score 
                      << " prob/y [" << list[i].difficulty << "]\n";
        }
    }
}

void display_top(const std::vector<Player>& list, std::string title) {
    system("cls");
    std::cout << "=== TOP5 WYNIKOW: " << title << " ===\n\n";
    if (list.empty()) {
        std::cout << "Brak wynikow dla tego poziomu.\n";
    } else {
        for (size_t i = 0; i < list.size() && i < 5; i++) {
            std::cout << i + 1 << ". " << list[i].name << " - " << list[i].score << " prob/y\n";
        }
    }
    system("pause");
}