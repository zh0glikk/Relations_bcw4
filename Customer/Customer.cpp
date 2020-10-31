#include "Customer.hpp"

Customer::Customer(std::string name) {
    this->name = name;
    this->orders = new std::set<Order*>();
}
Customer::~Customer() {
    std::set<Order*>::iterator it = this->orders->begin();
    for ( ; it != this->orders->end(); ++it ) {
        delete(*it);
    }
    delete(this->orders);
}

const std::set<Order*>& Customer::getOrders() const {
    return *(this->orders);
}

std::string Customer::getName() const {
    return this->name;
}

void Customer::addOrder(Order* order) {
    Order::currentId += 1;
    this->orders->insert(order);
}

void Customer::removeOrder(Order* order) {
    this->orders->erase(order);
}

std::ostream& operator<<(std::ostream& out, const Customer& customer) {
    out << "Custromer: " << customer.getName() << std::endl;
    auto it = customer.getOrders().begin();
    
    for ( ; it != customer.getOrders().end(); ++it ) {
        out << *(*it) << std::endl;
    }
    return out;
}
