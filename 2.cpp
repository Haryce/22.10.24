#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    const int jan = 31; //Количество дней в январе
    int temp[jan] = { -5, -10, -3, -7, -8, -2, -6, -1, -4, -9, -12, -7, -3, -5, -8, -2, -4, -6, -10, -3, -2, -8, -5, -6, -4, -9, -7, -1, -2, -8, -3 }; // Массив с температурами
    int met; //Метка для температуры

    cout << "Введите температуру для нижеуказаной метки: ";
    cin >> met;

    //а) среднюю температуру за месяц
    int sum = 0;
    for (int i = 0; i < jan; i++) {
        sum += temp[i];
    }
    double avg = static_cast<double>(sum) / jan;

    //б) сколько раз температура воздуха опускалась ни- жеуказанной метки
    int met0 = 0;
    for (int i = 0; i < jan; i++) {
        if (temp[i] < met) {
            met0++;
        }
    }

    // Вывод результатов
    cout << "Средняя температура за январь: " << avg << "°C" << endl;
    cout << "Количество дней с температурой ниже " << met << "°C: " << met0 << endl;

    return 0;
}
