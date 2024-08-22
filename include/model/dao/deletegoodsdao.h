#ifndef DELETEGOODSDAO_HEADER
#define DELETEGOODSDAO_HEADER
#include<string>
class DeleteGoodsDao
{
    public:
        DeleteGoodsDao();
        ~DeleteGoodsDao();
        bool deletegoodsdao(const std::string name);
};
#endif