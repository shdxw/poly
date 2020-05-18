#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Pizza {
protected:
    string name;
    unsigned int salt;
    unsigned int cheese;
    unsigned int size;
public:
    virtual string getName() = 0;
    virtual string getKomment() = 0;
    virtual unsigned int getPrice() = 0;

    Pizza(unsigned int s,unsigned int c,unsigned int si) {
        salt = s;
        cheese = c;
        size = si;
    }

    int getSalt() const {
        return salt;
    }

    int getCheese() const {
        return cheese;
    }

    int getSize() const {
        return size;
    }
};

class CheesePizza : public Pizza {


public:
    CheesePizza(unsigned int s, unsigned int c, unsigned int si) :Pizza(s, c, si) {

    }
    string getName() override {
        return "Сырная пицца";
    };

    string getKomment() override {
        return "классная, сочная пицца под пивас";
    };

    unsigned int getPrice() override {
        return size * 1 + cheese * 100 + salt * 10;
    }
};

class CalmarPizza : public Pizza {


public:
    CalmarPizza(unsigned int s, unsigned int c, unsigned int si) :Pizza(s, c, si) {

    }
    string getName() override {
        return "Кальмарная пицца";
    };

    string getKomment() override {
        return "пицца, со дна морского!";
    };

    unsigned int getPrice() override {
        return size * 2 + cheese * 10 + salt * 30;
    }
};

class ChinaPizza : public Pizza {


public:
    ChinaPizza(unsigned int s, unsigned int c, unsigned int si) :Pizza(s, c, si) {

    }
    string getName() override {
        return "Китайская пицца";
    };

    string getKomment() override {
        return "Однажды пельмешек раздавали и получилось это";
    };

    unsigned int getPrice() override {
        return size * 0 + cheese * 100 + salt * 10;
    }
};

class BloodPizza : public Pizza {


public:
    BloodPizza(unsigned int s, unsigned int c, unsigned int si) :Pizza(s, c, si) {

    }
    string getName() override {
        return "Кровавая пицца";
    };

    string getKomment() override {
        return "Однажды повариха... Добавила вишневое повидло на тесто!";
    };

    unsigned int getPrice() override {
        return size * 4 + cheese * 100 + salt * 10;
    }
};

class SurprizePizza : public Pizza {


public:
    SurprizePizza(unsigned int s, unsigned int c, unsigned int si) :Pizza(s, c, si) {

    }
    string getName() override {
        return "Секретная пицца";
    };

    string getKomment() override {
        return "вы платите и ничего не происходит, она слишком секретная";
    };

    unsigned int getPrice() override {
        return size * 100 + cheese * 100 + salt * 10;
    }
};






class Order {
    vector< Pizza *> Pizzas;
    unsigned int money = 0;
private:
    void extra(unsigned int &salt, unsigned int &cheese, unsigned int &size) {
        cout << "введите кол-во соли, сыра и размер (25,30,35,40)" << endl;

        while ((size != 25) && (size != 30) && (size != 35) && (size != 40)) {
            cout << "введите размер" << endl;
            cin >> size;
        }
        while (salt <= 0) {
            cout << "введите кол-во соли" << endl;
            cin >> salt;
        }
        while (cheese <= 0) {
            cout << "введите кол-во сыра" << endl;
            cin >> cheese;
        }
    }

public:
    void add(Pizza *Pizza) {
        Pizzas.push_back(Pizza);
    }

    void takeOrder(){
        int choice = 10;
        unsigned int salt, cheese, size;



        while (choice > 0) {

            salt = 0, cheese = 0, size = 0;
            cout << "1 - сырная, 2 - китайская, 3 - кальмарная, 4 - кровавая, 5 - сюрприз" << endl;
            cout << "1,2,3,4,5 для выбора вида пиццы, 0 для завершения заказа" << endl;
            cin >> choice;

            switch (choice) {
                case 0: {
                    cout << "завершаем заказ!" << endl;
                    break;
                }
                case 1: {
                    cout << "выбрана сырная пицца" << endl;
                    extra(salt, cheese, size);
                    add(new CheesePizza(salt, cheese, size));
                    break;
                }
                case 2: {
                    cout << "выбрана китайская пицца" << endl;
                    extra(salt, cheese, size);
                    add(new ChinaPizza(salt, cheese, size));
                    break;
                }

                case 3: {
                    cout << "выбрана кальмарная пицца" << endl;
                    extra(salt, cheese, size);
                    add(new CalmarPizza(salt, cheese, size));
                    break;
                }

                case 4: {
                    cout << "выбрана кровавая пицца" << endl;
                    extra(salt, cheese, size);
                    add(new BloodPizza(salt, cheese, size));
                    break;
                }

                case 5: {
                    cout << "выбрана сюрприз пицца" << endl;
                    extra(salt, cheese, size);
                    add(new SurprizePizza(salt, cheese, size));
                    break;
                }
                default: {
                    cout << "выбрана сюрприз пицца" << endl;
                    extra(salt, cheese, size);
                    add(new SurprizePizza(salt, cheese, size));
                    break;
                }

            }
        }


    }

    void print() {
        size_t size = Pizzas.size();

        if (size == 0) {
            cout << "нет товаров в корзине";
        }
        else {
            for (size_t i = 0, size = Pizzas.size(); i < size; i++) {
                cout << (i + 1) << ". " << Pizzas[i]->getName();
                cout << " - " << Pizzas[i]->getPrice() << " руб." << " - ";
                cout << Pizzas[i]->getSalt() << " соль - ";
                cout << Pizzas[i]->getCheese() << " сыр - ";
                cout << Pizzas[i]->getSize() << " размер - ";
                cout << " описание: " << Pizzas[i]->getKomment() << endl;
                money += Pizzas[i]->getPrice();
            }
            cout << "Сумма вашего заказа: " << money << " шекелей";
        }
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    Order order;
    order.takeOrder();
    order.print();

    return 0;
}
