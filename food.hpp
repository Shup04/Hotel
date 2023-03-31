#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MenuItem {
public:
    MenuItem(const string& name, double price): name_(name), price_(price){}
    const string& getName() const {return name_;}
    double getPrice() const {return price_;}

private:
    string name_;
    double price_;
};

class Order {
public:
    Order(const MenuItem& item, int quantity)
        : item_(item), quantity_(quantity)
    {}

    const MenuItem& getItem() const {
        return item_;
    }

    int getQuantity() const {
        return quantity_;
    }

private:
    MenuItem item_;
    int quantity_;
};

class Table {
public:
    void takeOrder(const Order& order) {
        orders_.push_back(order);
    }

    double getTotalBill() const {
        double total = 0.0;
        for (const auto& order : orders_) {
            total += order.getItem().getPrice() * order.getQuantity();
        }
        return total;
    }

    void printBill() const {
        cout << "Items\tQuantity\tPrice" << endl;
        for (const auto& order : orders_) {
            const MenuItem& item = order.getItem();
            int quantity = order.getQuantity();
            double price = item.getPrice() * quantity;
            cout << item.getName() << "\t" << quantity << "\t\t$" << price << endl;
        }
        cout << "Total bill: $" << getTotalBill() << endl;
    }

private:
    vector<Order> orders_;
};

class Kitchen {
public:
    void takeOrder(const Order& order) {
       
    }
};

class Bar {
public:
    void takeOrder(const Order& order) {
        
    }
};

int main() {

    MenuItem burger("Burger", 8.99);
    MenuItem pizza("Pizza", 10.99);
    MenuItem fries("Fries", 2.99);
    MenuItem coke("Coke", 1.99);
    MenuItem beer("Beer", 4.99);


    Table table;


    table.takeOrder(Order(burger, 2));
    table.takeOrder(Order(pizza, 1));
    table.takeOrder(Order(fries, 3));
    table.takeOrder(Order(coke, 4));
    table.takeOrder(Order(beer, 2));


    table.printBill();

    return 0;
}