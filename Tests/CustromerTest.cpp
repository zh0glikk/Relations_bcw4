#include "catch.hpp"
#include "../Item/Item.hpp"
#include "../Category/Category.hpp"
#include "../Order/Order.hpp"
#include "../Customer/Customer.hpp"

TEST_CASE("Customer's orders", "[Customer]") {
    Category* cat = new Category("Gadgets");
    
    Item* it1 = new Item(1000, "Iphone", cat);
    Item* it2 = new Item(900, "Iphone12", cat);
    Item* it3 = new Item(800, "Iphone12mini", cat);
    
    Customer* customer = new Customer("Sasha");
    
    SECTION("Customer output") {
        std::set<Item*>* items = new std::set<Item*>();
        items->insert(it1);
        items->insert(it2);
        
        Order* order1 = new Order(customer, items);
        
        Order* order2 = new Order(customer, items);
        order2->addItem(it3);
        
        std::set<Order*>::iterator orders = customer->getOrders().begin();
        REQUIRE(*orders == order1);
        REQUIRE(*(orders.operator++()) == order2);
        
        REQUIRE(*(*orders)->getItems().begin() == it1);
        REQUIRE(*(*orders)->getItems().begin().operator++() == it2);
        
        REQUIRE(*order2->getItems().begin() == it1);
        REQUIRE(*order2->getItems().begin().operator++() == it2);
    }
}
