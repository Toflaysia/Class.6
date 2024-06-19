#include <iostream>
#include <cmath>

using namespace std;

class Contribution {
public:
    int percent;
    bool possibility;
    int term;
    float sum;

    Contribution() {
        this->percent = 0;
        this->possibility = true;
        this->term = 0;
        this->sum = 0;
    }
    Contribution(int percent, bool possibility, int term, float sum) {
        this->percent = percent;
        this->possibility = possibility;
        this->term = term;
        this->sum = sum;
    }

    float calculation() {
        double future = 0;
        future = sum * pow(((percent / 100.0)+1.0), term); 
        return future;
    }

    Contribution operator + (const float sum) {
        if (possibility == 1) {                      
            this->sum = sum + this->sum;
            return *this;                                 //возвращаю ссылку на это же измененный класс
        }
        else {
            return *this;                                 //ссылка на это же класс
        }
    }

    Contribution operator - (const float sum) {
        if (possibility == 1) {
            this->sum = this->sum - sum;
            return *this;
        }
        else{ 
            return *this; 
        }
    }

    friend ostream& operator << (ostream& stream, const Contribution& a) {                  //перегрузка оператора вывода
        stream << "Процентная ставка: " << a.percent << "%" << endl << "Возможность снятия/пополнения (0 - нет, 1 - да): "
            << a.possibility << endl << "Срок вклада: " << a.term << " лет" << endl << "Сумма вклада: " << a.sum << " рублей" << endl;

        return stream;
    }

    friend istream& operator >> (istream& in, Contribution& a) {                  //перегрузка оператора ввода
        int percent;
        bool possibility;
        int term;
        float sum;
        cout << "Введите следующие значения: Процентная ставка, Возможность снятия/пополнения (0 - нет, 1 - да), Срок вклада, Сумма вклада " << endl;
        in >> percent >> possibility >> term >> sum;
        a.percent = percent;                                                       //перегружаем не собственный оператор, а чужой, поэтому здесь не this
        a.possibility = possibility;
        a.term = term;
        a.sum = sum;

        return in;
    }

};


int main()
{
    setlocale(LC_ALL, "ru");
    float sum;
    Contribution a;
    cin >> a;
    cout << "Введите сумму пополнения: " << endl;
    cin >> sum;
    a.calculation();
    cout << (a + sum);
    cout << a.calculation() << endl;


    




    return 0;
}
