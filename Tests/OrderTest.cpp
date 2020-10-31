#include "catch.hpp"
#include "../Item/Item.hpp"
#include "../Category/Category.hpp"
#include "../Order/Order.hpp"
#include "../Customer/Customer.hpp"

TEST_CASE("Items in order", "[Order]") {
    Category* cat = new Category("Gadgets");
    
    Item* it1 = new Item(1000, "Iphone", cat);
    Item* it2 = new Item(900, "Iphone12", cat);
    Item* it3 = new Item(800, "Iphone12mini", cat);
    
    Customer* customer = new Customer("Zhoglik");
    Customer* customer2 = new Customer("Zhoglikk");
    
    SECTION("consructor test") {
        std::set<Item*>* items = new std::set<Item*>();
        items->insert(it1);
        items->insert(it2);

        std::set<Item*>::iterator it = items->begin();
        REQUIRE(*it == it1);
        ++it;
        REQUIRE(*it == it2);

        Order* order1 = new Order(customer, items);
        REQUIRE(&order1->getCustomer() == customer);
               
        
        REQUIRE(*order1->getItems().begin() == it1);
        REQUIRE(*(order1->getItems().begin().operator++()) == it2);
    }
    
    SECTION("0 items test") {
        std::set<Item*>* items = new std::set<Item*>();
        try {
            Order* order = new Order(customer, items);
        } catch(OrderCantExistWithoutItems e) {
            
        }
        
    }
    
    
}
