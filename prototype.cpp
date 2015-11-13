#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Member {
public:
    virtual Member* clone() = 0;
    virtual void payFee() = 0;
};

class Factory{
public:
    static Member* make_member( int input );
private:
    static Member* member_prototypes[3];
};

class MonthlyMember: public Member {
public:
    Member* clone(){ return new MonthlyMember; }
    void payFee(){
        std::cout << "Membership fee is paid for the next month\n";
    }

};

class YearlyMember: public Member {
public:
    Member* clone(){ return new YearlyMember; }
    void payFee(){
        std::cout << "Membership fee is paid for the next year\n";
    }

};

int main() {
	int input;
    std::vector<Member*> members;

    while (true) {
        std::cout << "\n\nEnter the members that are paying:\nMonthly(1) \nYearly(2) \nNo more(0) \n";
        std::cin >> input;
        if(input == 0){
            break;
        } else if(input == 1 || input == 2){
            members.push_back(Factory::make_member(input));
        } else {
            std::cout << "You have entered an incorrect member type\n";
        }
    }

	for(int i =0; i < members.size(); ++i){
        members[i]->payFee();
	}
        
    for(int i =0; i < members.size(); ++i){
        delete members[i];
    }
};

Member* Factory::member_prototypes[] = {
    0, new MonthlyMember, new YearlyMember
};

Member* Factory::make_member(int input){
    return member_prototypes[input] -> clone();
};
            
            
            
            
            
            
            
            
