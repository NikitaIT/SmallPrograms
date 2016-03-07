/* Template of the assignment 1 */
#include <cstdio> // stdio.h Содержит прототипы стандартных библиотечных функций ввода-вывода и используемую ими информацию.
#include <fstream>// Включает информацию для выполнения операций с файлами;
#include <string> // string.h Содержит прототипы функций для обработки строк стиля C
using namespace std;
int main() {
    // РЕЗЕРВИРУЕМ ЯЧЕЙКУ ПАМЯТИ ПОД ФАЙЛ(ВРЕМЕННОЕ ПОМЕЩЕНИЕ)
    ifstream sample;

    //ОТКРЫТИЕ ФАЙЛА
    sample.open("rosalind_GC.txt");

    //НАЙДЕН ЛИ ФАЙЛ?
    if (!sample.good()) { //.good Возвращает ненулевое значение если не установлен ни один флаг состояния (ошибок нет).
        printf("%s\n", "Bad file. Does it exist?");
        return -1;
    }  

    //МАССИВ СТРОК ИЗ 9 ПЕРЕМЕННЫХ ДЛЯ ИМЕНИ ids() И СОДЕРЖАНИЯ strands() И НОМЕРА ИМЕНИ pos 
    const unsigned int STRANDS_AMOUNT = 9; // 0...2^32
    string ids[STRANDS_AMOUNT];
    string strands[STRANDS_AMOUNT];
    int pos = -1;
    string currentLine;

    //ЧТЕНИЕ ДО КОНЦА 
    while (!sample.eof()) {
        getline(sample, currentLine); // читаем одну строку из txt
        if (currentLine[0] == '>') { // ЕСЛИ ВСТРЕЧЕН СИМВОЛ "БОЛЬШЕ" ТО УВЕЛИЧИВАЕМ НОМЕР ИМЕНИ
            pos++;
            ids[pos] = currentLine.substr(1, currentLine.length()); // ПОМЕЩЕНИЕ ИМЕНИ В МАССИВ ПОД НОМЕРОМ роs
            strands[pos] = "";
        } else { // ПОМЕЩЕНИЕ СОДЕРЖАНИЯ В ЯЧЕЙКУ НОМЕР pos
            int winReturnPos = currentLine.rfind('\r'); // A dirty hack aganst a windows file format
            strands[pos] += currentLine.substr(0, 
                (winReturnPos < 0) ? currentLine.length() : winReturnPos);
        };
    };
    // НАТУРАЛЬНЫЙ НОМЕР ЭЛЕМЕНТА В МАССИВЕ ИМЕН И ДЕЙСТВИТЕЛЬНЫЙ ПРОЦЕНТ
    int maxValuePosition = 0;// -2^31...2^31
    double maxValue = 0.0;//3.4*10308 (15 знаков) 

    // ============ YOUR CODE HERE =======================


    // ПОИСК ПО strands С ПОЗИЦИИ pos = 0 СТРОКИ GV, УВЛИЧЕНИЕ gc
double GC = 0.0;
pos = 0;
while (pos < STRANDS_AMOUNT){
for (int i = 0; i < strands[pos].length(); i++){
if ((strands[pos][i] == 'C')||(strands[pos][i] == 'G')) GC++;}
if (GC*100/strands[pos].length()>maxValue){
maxValue = GC*100/strands[pos].length();
maxValuePosition = pos;
};
GC = 0;
pos++;
};
    // ====================================================
 
    printf("%s\n%.2f%%\n" , ids[maxValuePosition].c_str(), maxValue);
 
    sample.close();
    return 0;
};