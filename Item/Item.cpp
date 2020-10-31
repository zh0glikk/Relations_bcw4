#include "Item.hpp"

Item::Item(double price, std::string title, Category* category) {
    this->price = price;
    this->title = title;
    this->category = category;
    this->category->addItem(this);
}

Item::~Item() {
    this->category->removeItem(this);
}

double Item::getPrice() const {
    return this->price;
}

std::string Item::getTitle() const {
    return this->title;
}

Category& Item::getCategory() const {
    return *this->category;
}

void Item::setPrice(double price) {
    this->price = price;
}

void Item::setTitle(std::string title) {
    this->title = title;
}

void Item::setCategory(Category* category) {
    this->category = category;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getTitle() << "(";
    out << item.getCategory().getTitle() << ", ";
    out << item.getPrice() << ")";
    return out;
}
