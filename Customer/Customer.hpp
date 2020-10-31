#ifndef Customer_hpp
#define Customer_hpp

#include <iostream>
#include <set>

#include "../Order/Order.hpp"

class Order;

class Customer {
private:
    std::set<Order*>* orders;
    std::string name;
public:
    Customer(std::string name);
    virtual ~Customer();
    
    const std::set<Order*>& getOrders() const;
    std::string getName() const;
    
    void addOrder(Order* order);
    void removeOrder(Order* order);
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif /* Customer_hpp */
