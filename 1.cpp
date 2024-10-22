#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    const int etazh = 5;         // Количество этажей
    const int podest = 4;       // Количество подъездов
    const int kvart = 2;        // Количество квартир на этаже

    int lv[etazh][podest][kvart] = {    // Массив для хранения количества жильцов в каждой квартире
      {{2, 3}, {4, 1}, {5, 2}, {3, 4}}, // 1 этаж
      {{1, 2}, {3, 5}, {2, 4}, {1, 3}}, // 2 этаж
      {{4, 1}, {2, 3}, {6, 2}, {5, 1}}, // 3 этаж
      {{3, 2}, {1, 4}, {4, 3}, {2, 2}}, // 4 этаж
      {{2, 1}, {5, 3}, {3, 4}, {4, 2}}  // 5 этаж
    };
    // Ввод номера квартиры
    int etazh0, podest0, kvart0;
    cout << "Введите номер этажа: ";
    cin >> etazh0;
    cout << "Введите номер подъезда: ";
    cin >> podest0;
    cout << "Введите номер квартиры: ";
    cin >> kvart0;

    if (etazh0 < 1 || etazh0 > etazh || podest0 < 1 || podest0 > podest || //проверка на корректность
        kvart0 < 1 || kvart0 > kvart) {
        cout << "Некорректный номер квартиры!" << endl;
        return 1;
    }
    // а) Количество жильцов в выбранной квартире и ее соседей
    cout << "В квартире " << etazh0 << "-" << podest0 << "-" << kvart0
        << " проживает " << lv[etazh0 - 1][podest0 - 1][kvart0 - 1]
        << " человек." << endl;
    cout << "Соседи на этом этаже:" << endl;
    for (int i = 0; i < kvart; i++) {
        if (i != kvart0 - 1) {
            cout << "Квартира " << etazh0 << "-" << podest0 << "-" << i + 1
                << ": " << lv[etazh0 - 1][podest0 - 1][i] << " человек" << endl;
        }
    }
    // б) Суммарное количество жильцов в каждом подъезде
    cout << endl << "Суммарное количество жильцов в каждом подъезде:" << endl;
    for (int i = 0; i < podest; i++) {
        int sumlv = 0;
        for (int j = 0; j < etazh; j++) {
            for (int k = 0; k < kvart; k++) {
                sumlv += lv[j][i][k];
            }
        }
        cout << "Подъезд " << i + 1 << ": " << sumlv << " человек" << endl;
    }
    // в) Номера квартир, где проживают многодетные семьи
    cout << endl << "Номера квартир с многодетными семьями:" << endl;
    for (int i = 0; i < etazh; i++) {
        for (int j = 0; j < podest; j++) {
            for (int k = 0; k < kvart; k++) {
                if (lv[i][j][k] > 5) {
                    cout << "Квартира " << i + 1 << "-" << j + 1 << "-" << k + 1 << endl;
                }
            }
        }
    }
    return 0;
}
