#include <iostream>
#include <string>

class Product {
public:
  virtual ~Product() {

  }
  virtual std::string Operation() const = 0;
};

class ConcretProduct1 : public Product {
public:
  std::string Operation() const override {
    return "{Result of the concreteProduct1}";
  }
};

class ConcretProduct2 : public Product {
public:
  std::string Operation() const override {
    return "{Result of the concreteProduct2}";
  }
};

class Creator {
public:
  virtual ~Creator() {
  }
  virtual Product* FactortMethod() const = 0;

  std::string SomeOperation() const {
    Product* product = this->FactortMethod();
    std::string result = "Creator: The same creator's code has just workd with " + product->Operation();
    delete product;
    return result;
  }
};

class ConcretCreator1 : public Creator {
public:
  Product* FactortMethod() const override {
    return new ConcretProduct1();
  }
};

class ConcretCreator2 : public Creator {
public:
  Product* FactortMethod() const override {
    return new ConcretProduct2();
  }
};

void ClientCode(const Creator& creator) {
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
    << creator.SomeOperation() << std::endl;
}

int main() {
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  Creator* creator = new ConcretCreator1();
  ClientCode(*creator);
  std::cout << "\n\n";
  std::cout << "App: Launched with the ConcreteCreator2.\n";
  Creator* creator2 = new ConcretCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;

  return 0;
}