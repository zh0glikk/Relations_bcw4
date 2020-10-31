#ifndef Order_hpp
#define Order_hpp

#include "../Customer/Customer.hpp"
#include "../Item/Item.hpp"
#include "../Exceptions.hpp"

class Customer;

class Order {
private:
    int id;
    Customer* customer;
    std::set<Item*>* items;
public:
    Order(Customer* customer, std::set<Item*>* items);
    virtual ~Order();
    
    static int currentId;
    
    Customer& getCustomer() const;
    const std::set<Item*>& getItems() const;
    int getId() const;
    
    void addItem(Item* item);
    void removeItem(Item* item);
};

std::ostream& operator<<(std::ostream& out, const Order& order);



#endif /* Order_hpp */
