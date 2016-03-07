#include <iostream>
#include <cstdlib>
#include <vector>
typedef std::vector<std::vector<bool> > matrix;
typedef unsigned int uint;
typedef unsigned int size_t;
/* работа с консолью(выводом) весь файл */
namespace Console {
 
    // Clear console in *nix
    void clearUnix() {
        system("clear");
    }
 
    // чистим консоль
    void clearWin() {
        system("cls");
    }
 
    // рисуем табличку в консоли drawField-процедурой field[строка][столбец]
    void drawField(matrix &field) {
        // по строке еззбошит
        for (uint i = 0; i < field.size(); i++) {
            std::cout << '|';
            // по столбцам 0..j ебошит в строку номер i
            for (uint j = 0; j < field[0].size(); j++) { std::cout << (field[i][j] ? '*' : ' ') << ' ';}// (условие булево) ? true : false; и пробел между символами
            std::cout << "|\n";
        }
    }
}