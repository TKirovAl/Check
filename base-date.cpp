#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product { //создаём класс продукт с соотвествующими параметрами
public:
    int id;
    string seller;
    string brand;
    string category;
    string name;

    Product(int id, string seller, string brand, string category, string name) {
        this->id = id; // this это указатель 
        this->seller = seller;
        this->brand = brand;
        this->category = category;
        this->name = name;
    }
};

class Seller { //создаем класс продавца с его айди и именем
public:
    int id;
    string name;

    Seller(int id, string name) { // принимая значения айди и имени продавца, указываем
        this->id = id;
        this->name = name;
    }
};

class Category { //создаём класс категории с айди и именем
public:
    int id;
    string name;

    Category(int id, string name) {
        this->id = id;
        this->name = name;
    }
};

class Brand { // созда1м класс брэнда
public:
    int id;
    string name;

    Brand(int id, string name) {
        this->id = id;
        this->name = name;
    }
};

int main() {
 // создаём 5 различных продуктов, категорий и т.д
    vector<Product> products = {
            Product(1, "Volkswagen Group", "Audi", "Transport", "AudiA1"),
            Product(2, "Apple", "Apple", "Device", "Iphone 13"),
            Product(3, "Baltika", "Baltika", "Alcohol", "Baltika 9"),
            Product(4, "Lego Group", "Lego", "Toy", "Death Star"),
            Product(5, "Nvidia", "Nvidia", "PC_components", "GeForce GT 1030")
    };

    vector<Seller> sellers = {
            Seller(1, "Volkswagen Group"),
            Seller(2, "Apple"),
            Seller(3, "Baltika"),
            Seller(4, "Lego Group"),
            Seller(5, "Nvidia")
    };

    vector<Category> categories = {
            Category(1, "Transport"),
            Category(2, "Device"),
            Category(3, "Alcohol"),
            Category(4, "Toy"),
            Category(5, "PC_components")
    };

    vector<Brand> brands = {
            Brand(1, "Audi"),
            Brand(2, "Apple"),
            Brand(3, "Baltika"),
            Brand(4, "Lego"),
            Brand(5, "Nvidia")
    };

    // Вывод базы данных по категориям
    cout << "База данных по категориям: " << endl;
    for (int i = 0; i < categories.size(); i++) {
        cout << "Категория: " << categories[i].name << endl;
        for (int j = 0; j < products.size(); j++) {
            if (products[j].category == categories[i].name) {
                cout << "Айди: " << products[j].id << ", Название: " << products[j].name
                     << ", Продавец: " << products[j].seller << ", Бренд: " << products[j].brand << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
