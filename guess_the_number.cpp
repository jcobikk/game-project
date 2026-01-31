#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
// różne reakce programu na wpisywane liczby
vector<string> too_high = {
        "Za duzo! Sprobuj mniejsza liczbe.",
        "Ups, to za wysoko!",
        "Nie, liczba jest mniejsza.",
        "Za duza! Zmniejsz troche."
    };
vector<string> too_low =  {
        "Za malo! Sprobuj wieksza liczbe.",
        "Nie, liczba jest wieksza.",
        "Za nisko! Podnies troche.",
        "Za mala! Sprobuj wyzej."
    };
// klasy na podstawie których tworzona jest tabela wyników
class Player
{
public:
    string name;
    int score;
};
class Player_diff
{
    public:
    string name;
    int score;
    string difficulty;
};
// wektory potrzebne do tabeli wyników
vector<Player_diff> TOP;
vector<Player> TOP_easy;
vector<Player> TOP_medium;
vector<Player> TOP_hard;
// funkcje sortujące tabele wyników
void sort(vector<Player>& list){
    for(int a = 0; a < list.size(); a++){
        for(int b = 0; b < list.size() - 1; b++){
            if(list[b].score > list[b + 1].score){
                swap(list[b], list[b + 1]);
            }
        }
    }
}
void sort2(vector<Player_diff>& list){
    for(int a = 0; a < list.size(); a++){
        for(int b = 0; b < list.size() - 1; b++){
            if(list[b].score > list[b + 1].score){
                swap(list[b], list[b + 1]);
            }
        }
    }
}
// właściwy program
int main(){
    int nav_menu = 0;
    int diff_choice = 0;
    while (nav_menu != 3){ // menu główne
        int nav_top = -1;
        cout << "===== Witaj w grze Zgadnij liczbe! =====\n\n";
        cout << "1. Rozpocznij nowa gre\n";
        cout << "2. Sprawdz aktualne TOP5 wynikow\n";
        cout << "3. Wyjdz z aplikacji\n";
        cout << "Wybierz jedna z opcji: ";
        cin >> nav_menu;
        switch (nav_menu) { // wybór trudności przed rozpoczęciem gry
            case 1:{
                cout << "\nWybierz poziom trudnosci gry\n";
                cout << "1. Latwy (zakres od 1-50)\n";
                cout << "2. Sredni (zakres od 1-100)\n";
                cout << "3. Trudny (zakres od 1-250)\n";
                cout << "Wybierz jedna z opcji: ";
                cin >> diff_choice;
                // dalej są rozgrywane 3 trudności 
                switch (diff_choice) {
                    case 1:{
                        int guess;
                        int counter = 1; // licznik prób
                        srand(time(0));
                        int number = rand() % 50 + 1;
                        cout << "\nZgadnij liczbe od 1 do 50!\n";
                        while (guess != number){
                            cout << "\nTo twoja " << counter << " proba";
                            cout << "\nTwoj strzal: ";
                            cin >> guess;
                            counter++;

                            if (guess > number){ // za duża 
                                int index = rand() % too_high.size();
                                cout << too_high[index] << "\n";
                            }
                            else if (guess < number){ // za niska 
                                int index = rand() % too_low.size();
                                cout << too_low[index] << "\n";
                            }
                            else { // koniec gry, podanie imienia gracza i dodanie go do tablicy wyników
                                string name;
                                cout << "Brawo trafiles w " << counter - 1 << " probach!\n";
                                cout << "Podaj swoje imie: ";
                                cin >> name;
                                Player_diff temp; // dodanie do tabeli ogólnej
                                temp.name = name;
                                temp.score = counter - 1;
                                temp.difficulty = "latwy";
                                TOP.push_back(temp);
                                Player temp2; // dodanie do tabeli względem trudności która była rozgrywana  
                                temp2.name = name;
                                temp2.score = counter - 1;
                                TOP_easy.push_back(temp2);
                                cout << "\n\n";
                                sort2(TOP); // sortowanie wyników
                                sort(TOP_easy);
                            }
                        }
                        break;
                    }
                    case 2:{ // powtarzające się komentarze jak w case 1 
                        int guess;
                        int counter = 1;
                        srand(time(0));
                        int number = rand() % 100 + 1;
                        cout << "\nZgadnij liczbe od 1 do 100!\n";
                        while (guess != number){
                            cout << "\nTo twoja " << counter << " proba";
                            cout << "\nTwoj strzal: ";
                            cin >> guess;
                            counter++;

                            if (guess > number){
                                int index = rand() % too_high.size();
                                cout << too_high[index] << "\n";
                            }
                            else if (guess < number){
                                int index = rand() % too_low.size();
                                cout << too_low[index] << "\n";
                            }
                            else {
                                string name;
                                cout << "Brawo trafiles w " << counter - 1 << " probach!\n";
                                cout << "Podaj swoje imie: ";
                                cin >> name;
                                Player_diff temp;
                                temp.name = name;
                                temp.score = counter - 1;
                                temp.difficulty = "sredni";
                                TOP.push_back(temp);
                                Player temp2;
                                temp2.name = name;
                                temp2.score = counter - 1;
                                TOP_medium.push_back(temp2);
                                cout << "\n\n";
                                sort2(TOP);
                                sort(TOP_medium);
                            }
                        }
                        break;
                    }
                    case 3:{ // powtarzające się komentarze jak w case 1 
                        int guess;
                        int counter = 1;
                        srand(time(0));
                        int number = rand() % 250 + 1;
                        cout << "\nZgadnij liczbe od 1 do 250!\n";
                        while (guess != number){
                            cout << "\nTo twoja " << counter << " proba";
                            cout << "\nTwoj strzal: ";
                            cin >> guess;
                            counter++;

                            if (guess > number){
                                int index = rand() % too_high.size();
                                cout << too_high[index] << "\n";
                            }
                            else if (guess < number){
                                int index = rand() % too_low.size();
                                cout << too_low[index] << "\n";
                            }
                            else {
                                string name;
                                cout << "Brawo trafiles w " << counter - 1<< " probach!\n";
                                cout << "Podaj swoje imie: ";
                                cin >> name;
                                Player_diff temp;
                                temp.name = name;
                                temp.score = counter - 1;
                                temp.difficulty = "trudny";
                                TOP.push_back(temp);
                                Player temp2;
                                temp2.name = name;
                                temp2.score = counter - 1;
                                TOP_hard.push_back(temp2);
                                cout << "\n\n";
                                sort2(TOP);
                                sort(TOP_hard);
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 2:{ // topka wyników
                while(nav_top != 0){
                    cout << "\nTOP5 wynikow wszystkich poziomow trudnosci:\n";
                    for(int i = 0; i < TOP.size() && i < 5; i++){
                        cout << TOP[i].name << " - " << TOP[i].score << " proba/y - " << TOP[i].difficulty << " poziom trudnosci\n";
                    }
                    cout << "\nWprowadz '0' aby wrocic do menu glownego\nWprowadz '1' aby wyswietlic wyniki tylko z poziomu latwego\nWprowadz '2' aby wyswietlic wyniki tylko z poziomu sredniego\nWprowadz '3' aby wyswietlic wyniki tylko z poziomu trudnego\n";
                    cin >> nav_top;
                    switch(nav_top){ // możliwośc przejścia do menu głownego lub sortowania pod względem trudności
                        case 0:{
                            break;
                        }
                        case 1:{
                            cout << "\nTOP5 wynikow poziomu latwego:\n";
                            for(int x = 0; x < TOP_easy.size() && x < 5; x++){
                                cout << TOP_easy[x].name << " - " << TOP_easy[x].score << " proba/y\n";
                            }
                            system("pause");
                            break;
                        }
                        case 2:{
                            cout << "\nTOP5 wynikow poziomu sredniego:\n";
                            for(int y = 0; y < TOP_medium.size() && y < 5; y++){
                                cout << TOP_medium[y].name << " - " << TOP_medium[y].score << " proba/y\n";
                            }
                            system("pause");
                            break;
                        }
                        case 3:{
                            cout << "\nTOP5 wynikow poziomu trudnego:\n";
                            for(int z = 0; z < TOP_hard.size() && z < 5; z++){
                                cout << TOP_hard[z].name << " - " << TOP_hard[z].score << " proba/y\n";
                            }
                            system("pause");
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{ // wyjście z programu 
                cout << "Do zobaczenia!\n";
                break;
            }
            default:{ // instrukcje jeśli jest wpisywane coś innego niż powinno 
                cout << "\nJesli nie potrafisz poruszac sie po menu przeczytaj plik README.md\n";
                cout << "Sprobuj ponownie!\n\n";
                break;
            }
        }
    }
    system("pause");
    return 0;  
}