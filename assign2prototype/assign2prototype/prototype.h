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

/* Member prototype base class */
class Member {
public:
    virtual Member* clone() = 0;
    virtual void payFee(int num) = 0;
    virtual void serialize() = 0;
    template <class Archive>
    void serialize( Archive & archive ){
    }
};

/* Member prototype factory */
class Factory{
public:
    static Member* make_member(int input);
private:
    static Member* member_prototypes[3];
};

/* Derived type MonthlyMember */
class MonthlyMember: public Member {
public:
    Member* clone(){ return new MonthlyMember; }
    void payFee(int num){
        std::cout << "Member " << num << " has paid for the next month\n";
    }
    void serialize(){
    }
};

/* Derived type YearlyMember */
class YearlyMember: public Member {
public:
    Member* clone(){ return new YearlyMember; }
    void payFee(int num){
        std::cout << "Member " << num << " has paid for the next year\n";
    }
    void serialize(){
    }
};

/* Convert *Member to be a smart pointer instead of a raw pointer for cereal serialization */
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

/* List of possible member types (derived classes) */
Member* Factory::member_prototypes[] = {
    0, new MonthlyMember, new YearlyMember
};

/* Function called to clone the protypes  */
Member* Factory::make_member(int input){
    return member_prototypes[input] -> clone();
};








