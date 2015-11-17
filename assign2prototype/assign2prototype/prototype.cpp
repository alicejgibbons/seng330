//
//  prototype.cpp
//  assign2prototype
//
//  Created by Alice Gibbons on 2015-11-13.
//  Copyright © 2015 Alice Gibbons. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>


class Member {
public:
    virtual Member* clone() = 0;
    virtual void payFee(int num) = 0;
    virtual void serialize() = 0;
    template <class Archive>
    void serialize( Archive & archive ){
    }
};

class Factory{
public:
    static Member* make_member(int input);
private:
    static Member* member_prototypes[3];
};

class MonthlyMember: public Member {
public:
    Member* clone(){ return new MonthlyMember; }
    void payFee(int num){
        std::cout << "Member " << num << " has paid for the next month\n";
    }
    void serialize(){
    }
};

class YearlyMember: public Member {
public:
    Member* clone(){ return new YearlyMember; }
    void payFee(int num){
        std::cout << "Member " << num << " has paid for the next year\n";
    }
    void serialize(){
    }
    
};

//using smart pointers instead of raw pointers
class Ptr{
    Member *ptr;
public:
    explicit Ptr(Member *p = NULL) { ptr = p; }
    ~Ptr(){ delete(ptr); }
    Member &operator *(){ return *ptr; }
    template <class Archive>
    void serialize(Archive & archive){
        archive(*ptr);
    }
    
};

int main() {
    int input;
    //std::vector<Member*> members;
    std::vector<Ptr> members;//??
   // Ptr ptr(Factory::make_member(1));

    {
        //read in from from serialized data
        std::ifstream ifs( "membersPaid.json" );
        cereal::JSONInputArchive archive( ifs );
        archive(members);
    }
    
    while (true) {
        std::cout << "\n\nEnter the member that is paying:\nMonthly (1) \nYearly (2) \nNo member (0) \n";
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1 || input == 2){
            Ptr ptr(Factory::make_member(input));
            members.push_back(ptr);
        } else {
            std::cout << "You have entered an incorrect member type\n";
        }
    }
    
    for(int i = 0; i < members.size(); ++i){
        members[i].operator*().payFee(i+1);
    }
    
    {
        //serialize data to file
        std::ofstream ofs("membersPaid.json");
        cereal::JSONOutputArchive archive(ofs);
        archive(members);
    }
};

Member* Factory::member_prototypes[] = {
    0, new MonthlyMember, new YearlyMember
};

Member* Factory::make_member(int input){
    return member_prototypes[input] -> clone();
};








