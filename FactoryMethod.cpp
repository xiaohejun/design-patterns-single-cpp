#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    virtual string Operation() = 0;
    virtual ~Product() {}
};

class ConcreteProductA : public Product {
public:
    string Operation() override {
        return "产品A";
    }
};

class ConcreteProductB : public Product {
public:
    string Operation() override {
        return "产品B";
    }
};

class Creator {
public:
    virtual Product* CreateProduct() const = 0;

    string SomeOperation() const {
        Product *product = CreateProduct();
        string result = "Creator: 创建者使用产品工作 ==> " + product->Operation();
        delete product;

        return result;
    }

    virtual ~Creator() {}
};

class ConcreteCreatorA : public Creator {
public:
    Product* CreateProduct() const override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* CreateProduct() const override {
        return new ConcreteProductB();
    }
};

void ClientCode(const Creator &creator) {
    cout << "客户端代码：不关心创建者是谁: " << creator.SomeOperation() << endl;
}

int main(int, char**) {
    vector<Creator*> creators{new ConcreteCreatorA(), new ConcreteCreatorB()};
    for (auto creator : creators) {
        ClientCode(*creator);
        delete creator;
    }
    return 0;
}
