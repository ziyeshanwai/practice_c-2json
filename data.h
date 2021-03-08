//
// Created by Administrator on 2021/3/8 0008.
//
#include "string"

#ifndef JSON_PRACTICE_DATA_H
#define JSON_PRACTICE_DATA_H

#endif //JSON_PRACTICE_DATA_H
namespace ns {
    struct RoomData
    {
        unsigned int id;
        std::string name;
        std::string maxPlayers;
        unsigned int questionCount;
        unsigned int timePerQuestion;
        unsigned int isActive;
    }; // 用结构体存储自定义数据结构
    class data
    {
        // 定义类必须要有public private
    public:
        unsigned int id;
        std::string name;
        std::string maxPlayers;
        unsigned int questionCount;
        unsigned int timePerQuestion;
        unsigned int isActive;
        data()
        {
//            std::cout<<"function"<<std::endl;
        }
        ~data()
        {
//            std::cout<<"destory function"<<std::endl;
        }

    private:
        double num;
    };
}