#include "game_functions.h"

using namespace std;

vector<Player_diff> TOP;
vector<Player> TOP_easy, TOP_medium, TOP_hard;

int main() {
    int nav_menu = 0;
    while (nav_menu != 3) {
        cout << "\n===== Witaj w grze Zgadnij liczbe! =====\n\n";
        cout << "1. Rozpocznij nowa gre\n";
        if (!TOP.empty()) cout << "2. Sprawdz aktualne TOP5 wynikow\n";
        cout << "3. Wyjdz z aplikacji\n";
        cout << "Wybierz opcje: ";

        if (!(cin >> nav_menu) || nav_menu < 1 || nav_menu > 3) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        if (nav_menu == 1) {
            system("cls");
            int diff_choice;
            cout << "1. Latwy (1-50)\n2. Sredni (1-100)\n3. Trudny (1-250)\nWybor: ";
            cin >> diff_choice;
            if (diff_choice == 1) play_game("latwy", 50, TOP, TOP_easy);
            else if (diff_choice == 2) play_game("sredni", 100, TOP, TOP_medium);
            else if (diff_choice == 3) play_game("trudny", 250, TOP, TOP_hard);
        } 
        else if (nav_menu == 2 && !TOP.empty()) {
            int nav_top = -1;
            while (nav_top != 0) {
                display_top(TOP);
                cout << "0. Powrot | 1. LATWY | 2. SREDNI | 3. TRUDNY\nWybor: ";
                cin >> nav_top;
                if (nav_top == 1) display_top(TOP_easy, "POZIOM LATWY");
                else if (nav_top == 2) display_top(TOP_medium, "POZIOM SREDNI");
                else if (nav_top == 3) display_top(TOP_hard, "POZIOM TRUDNY");
            }
        }
    }
    cout << "Do zobaczenia!\n";
    return 0;
}