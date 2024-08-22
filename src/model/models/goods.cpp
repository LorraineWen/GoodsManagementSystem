#include"../../../include/model/models/goods.h"
Goods::Goods(const std::string& name,int price,int number):name(name),price(price),number(number)
{           
}
Goods::~Goods()
{
}
Goods::Goods(const Goods &othergoods)
{
    name=othergoods.name;
    price=othergoods.price;
}
Goods& Goods::operator=(const Goods &othergoods)
{   
    if(&othergoods==this)return *this;
    name=othergoods.name;
    price=othergoods.price;
    return *this;
}
std::string Goods::getName()const
{
    return this->name;
}
void Goods::setName(std::string name)
{
    this->name = name;
}
int Goods::getPrice()const
{
    return this->price;
}
void Goods::setPrice(int price)
{
    this->price = price;
}
int Goods::getNumber()const
{
    return this->number;
}
void Goods::setNumber(int number)
{
    this->number = number;
}