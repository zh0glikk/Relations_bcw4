#include "Order.hpp"

int Order::currentId = 0;

Order::Order(Customer* customer, std::set<Item*>* items) {
    if ( items->size() <= 0) {
        throw OrderCantExistWithoutItems();
    }
    
    this->customer = customer;
    this->items = new std::set<Item*>();
    for ( auto it = items->begin(); it != items->end(); it++) {
        this->items->insert(*it);
    }
    
    this->customer->addOrder(this);
    this->id = Order::currentId;
}

Order::~Order() {
    this->customer->removeOrder(this);
//    std::set<Item*>::iterator it = this->items->begin();
//    for ( ; it != this->items->end(); ++it ) {
//        delete(*it);
//    }
    delete(this->items);
}

Customer& Order::getCustomer() const {
    return *this->customer;
}

const std::set<Item*>& Order::getItems() const {
    return *(this->items);
}

int Order::getId() const {
    return this->id;
}

void Order::addItem(Item* item) {
    this->items->insert(item);
}

void Order::removeItem(Item* item) {
    this->items->erase(item);
}

std::ostream& operator<<(std::ostream& out, const Order& order) {
    out << "Order N:" << order.getId() << std::endl;
    out << "Customer:" << order.getCustomer().getName() << std::endl;
    std::set<Item*>::iterator it = order.getItems().begin();
    for ( ; it != order.getItems().end(); ++it ) {
        out << "  --" << *(*it) << std::endl;
    }
    return out;
}
