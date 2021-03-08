//
// Created by Administrator on 2021/3/8 0008.
//
#include <iostream>
#include <vector>
#include "data.h"
#include "json.hpp"
#include <iomanip>
#include <sstream>
#include<fstream>

using json = nlohmann::json;

void test_store_data()
{
    ns::data a = ns::data();
    std::vector<ns::RoomData> rooms;
    std::vector<ns::data> datas;
    rooms.push_back(ns::RoomData{ 1, "Room 1", "Few", 2, 56, 1 });
    rooms.push_back(ns::RoomData{ 2, "Room 2", "Lots", 2, 56, 1 });

    a.id = 1;
    a.name = "Room 1";
    a.maxPlayers = "Few";
    a.questionCount = 2;
    a.timePerQuestion = 56;
    a.isActive = 1;
    datas.push_back(a);
    a.id = 2;
    a.name = "Room 2";
    a.maxPlayers = "Few";
    a.questionCount = 3;
    a.timePerQuestion = 57;
    a.isActive = 2;
    datas.push_back(a);
    //两种遍历方式
    for(auto room:rooms)
    {
        std::cout<<room.id<<room.name<<std::endl;
    }
    for(std::vector<ns::RoomData>::iterator it=rooms.begin();it!=rooms.end();it++)
    {
        std::cout<<(*it).name<<" "<<(*it).id<<std::endl;
    }
    for(auto d:datas)
    {
        std::cout<<"call data from class"<<std::endl;
        std::cout<<d.id<<std::endl;
    }

}
namespace ns
{// Provide from_json and to_json functions in the same namespace as your type
    void from_json(const json& j, ns::RoomData& val)
    {
        j.at("id").get_to(val.id);
        j.at("name").get_to(val.name);
        j.at("maxPlayers").get_to(val.maxPlayers);
        j.at("questionCount").get_to(val.questionCount);
        j.at("timePerQuestion").get_to(val.timePerQuestion);
        j.at("isActive").get_to(val.isActive);
    }

    void to_json(json& j, const ns::RoomData& val)
    {
        j["id"] = val.id;
        j["name"] = val.name;
        j["maxPlayers"] = val.maxPlayers;
        j["questionCount"] = val.questionCount;
        j["timePerQuestion"] = val.timePerQuestion;
        j["isActive"] = val.isActive;
    }
}

void test_load_json()
{
    std::ifstream i("pretty.json");
    json j;
    i >> j;
    std::stringstream ss;
    ss << std::setw(4) << j<<std::endl;
    std::cout<<ss.str()<<std::endl;

    json j2 = json::parse(ss.str());
    j2.get<std::vector<ns::RoomData>>();
    auto rooms2 = j2.get<std::vector<ns::RoomData>>();

    std::cout << "load json from file ";
    for (auto item : rooms2)
    {
        std::cout << "id: " << item.id << ", name: " << item.name
                  << ", maxPlayers: " << item.maxPlayers << "\n";
    }
}

void test_dump_json()
{
    std::vector<ns::RoomData> rooms;
    rooms.push_back(ns::RoomData{ 1, "Room 1", "Few", 2, 56, 1 });
    rooms.push_back(ns::RoomData{ 2, "Room 2", "Lots", 2, 56, 1 });
    std::stringstream ss;
//    ns::to_json(j, rooms[0]);
    json j = rooms;
    std::ofstream o("pretty.json");
    o<<std::setw(4) << j<<std::endl;
    ss << std::setw(4) << j<<std::endl;
    std::cout << "(1)\n" << ss.str() << "\n\n";
    json j2 = json::parse(ss.str());
    j2.get<std::vector<ns::RoomData>>();
    auto rooms2 = j2.get<std::vector<ns::RoomData>>();

    std::cout << "(2)\n";
    for (auto item : rooms2)
    {
        std::cout << "id: " << item.id << ", name: " << item.name
                  << ", maxPlayers: " << item.maxPlayers << "\n";
    }
}

int main()
{
    test_store_data();
    test_dump_json();
    test_load_json();
    return 0;
}

