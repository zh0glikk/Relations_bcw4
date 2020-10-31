#ifndef Item_hpp
#define Item_hpp

#include "../Category/Category.hpp"
#include <stdio.h>

class Category;

class Item {
private:
    double price;
    std::string title;
    Category* category;
public:
    Item(double price, std::string title, Category* category);
    virtual ~Item();
    
    double getPrice() const;
    std::string getTitle() const;
    Category& getCategory() const;
    
    void setPrice(double price);
    void setTitle(std::string title);
    void setCategory(Category* category);
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif /* Item_hpp */
