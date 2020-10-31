#ifndef Category_hpp
#define Category_hpp

#include <iostream>
#include <set>
#include "../Item/Item.hpp"

class Item;

class Category {
private:
    std::string title;
    std::set<Item*>* items;
public:
    Category(std::string title);
    virtual ~Category();
    
    std::string getTitle() const;
    const std::set<Item*>& getItems() const;
    
    void setTitle(std::string title);
    
    void addItem(Item* item);
    void removeItem(Item* item);
};

std::ostream& operator<<(std::ostream& out, const Category& item);

#endif /* Category_hpp */
