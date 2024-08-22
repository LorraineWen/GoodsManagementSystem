#ifndef GOODS_HEADER
#define GOODS_HEADER
#include<string>
class Goods
{
    public:
        Goods(const std::string& name="",int price=-1,int number=-1);
        ~Goods();
        Goods(const Goods &othergoods);
        Goods& operator=(const Goods &othergoods);
        std::string getName()const;
        void setName(std::string name);
        int getPrice()const;
        void setPrice(int price);
        int getNumber()const;
        void setNumber(int number);
    private:
        std::string name;
        int price;
        int number;
};
#endif