#include "catch.hpp"
#include "../Item/Item.hpp"
#include "../Category/Category.hpp"

TEST_CASE("Items in Caregory", "[Item]") {
    Category* cat = new Category("Gadgets");
    
    Item* it1 = new Item(1000, "Iphone", cat);
    Item* it2 = new Item(900, "Iphone12", cat);
    Item* it3 = new Item(800, "Iphone12mini", cat);
    
    SECTION("constructor test") {
        REQUIRE(it1->getPrice() == 1000);
        REQUIRE(it1->getTitle() == "Iphone");
    }

    SECTION("Category items test") {
        std::set<Item*>::iterator it = cat->getItems().begin();
        
        REQUIRE((*it) == it1);
        ++it;
        REQUIRE((*it) == it2);
        ++it;
        REQUIRE((*it) == it3);
    }
    
}
