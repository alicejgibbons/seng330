//
//  prototype.h
//  assign2prototype
//
//  Created by Alice Gibbons on 2015-11-13.
//  Copyright © 2015 Alice Gibbons. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Member {
public:
    virtual Member* clone() = 0;
    virtual void payFee(int num) = 0;
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
    
};

class YearlyMember: public Member {
public:
    Member* clone(){ return new YearlyMember; }
    void payFee(int num){
        std::cout << "Member " << num << " has paid for the next year\n";
    }
    
};
/*
int main(int argc, char * argv[]) {
    int input;
    std::vector<Member*> members;
    
    while (true) {
        std::cout << "\n\nEnter the member that is paying:\nMonthly (1) \nYearly (2) \nNo member (0) \n";
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1 || input == 2){
            members.push_back(Factory::make_member(input));
        } else {
            std::cout << "You have entered an incorrect member type\n";
        }
    }
    
    for(int i = 0; i < members.size(); ++i){
        members[i]->payFee(i+1);
    }
    
    for(int i =0; i < members.size(); ++i){
        delete members[i];
    }
};*/

Member* Factory::member_prototypes[] = {
    0, new MonthlyMember, new YearlyMember
};

Member* Factory::make_member(int input){
    return member_prototypes[input] -> clone();
};








