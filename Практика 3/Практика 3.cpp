// Практика 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
union Info {
    struct{
        char FIO_mother; // ФИО матери
        char FIO_father; // ФИО отца
    };
    int countChildren; // количество детей
};
struct Form {
    char FIO; // ФИО
    int age; // возраст
    Info info; // структура с дополнительной информацией
    bool adult; // взрослый

    Form() :FIO(), age(0), adult(false) { // конструктор по умолчанию
        info.countChildren = 0;
    }
    Form(char fio, int age, int children) :FIO(fio), age(age), adult(true) { // конструктор для взрослых
        info.countChildren = children;
    }
    Form(char fio, int age, char mother, char father) :FIO(fio), age(age), adult(false) { // конструктор для несовершеннолетних
        info.FIO_father = father;
        info.FIO_mother = mother;
    }
    void Print() { // вывод анкеты
        std::cout << "ФИО:" << FIO << "\n";
        std::cout << "Возраст:" << age << "\n";
        if (adult) {
            std::cout << "Количество детей:" << info.countChildren << "\n";
        }
        else {
            std::cout << "ФИО отца:" << info.FIO_father << "\n";
            std::cout << "ФИО матери:" << info.FIO_mother << "\n";
        }
    }
};
void Sort(Form adults[], int count) { // сортировка методом пузырька
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (adults[j].info.countChildren < adults[j + 1].info.countChildren) {
                Form temp = adults[j];
                adults[j] = adults[j + 1];
                adults[j + 1] = temp;
            }
        }
    }
}
int main()
{
    const int max = 100;
    Form persons[max];
    Form adults[max];
    std::cout << "Введите количество анкет:\n";
    int n = 0;
    int countAdult = 0;
    std::cin >> n;
    if (n > max || n <= 0) {
        return 0;
    }
    for (int i = 0; i < n;i++) {
        std::cout << "Анкета " << i + 1 << "\n";
        char fio, father, mother;
        int age, children = 0;
        std::cout << "Введите ФИО:\n";
        std::cin >> fio;
        std::cout << "Введите возраст:\n";
        std::cin >> age;
        if (age < 18) {
            std::cout << "Введите ФИО отца:\n";
            std::cin >> father;
            std::cout << "Введите ФИО матери:\n";
            std::cin >> mother;
            persons[i] = Form(fio, age, father, mother);
            persons[i].Print();
        }
        else {
            std::cout << "Введите количество детей:\n";
            std::cin >> children;
            persons[i] = Form(fio, age, children);
            persons[i].Print();
            adults[countAdult] = persons[i];
            countAdult++;
        }
    }
    Sort(adults, countAdult);
    std::cout << "Совершеннолетние граждане (в порядке убывания по кол-ву детей):\n";
    if (countAdult == 0) {
        std::cout << "Совершеннолетних граждан нет \n";
    }
    else {
        for (int i = 0; i < countAdult;i++) {
            adults[i].Print();
        }
    }
    std::cout << "Все анкеты: \n";
    for (int i = 0; i < n;i++) {
        persons[i].Print();
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
