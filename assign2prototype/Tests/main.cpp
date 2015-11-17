//
//  main.cpp
//  Tests for prototype.cpp
//
//  Created by Alice Gibbons on 2015-11-13.
//  Copyright © 2015 Alice Gibbons. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "gtest/gtest.h"
#include "prototype.h"

TEST (Prototype, MonthlyMember){
    std::vector<Ptr> members;
    Ptr ptr(Factory::make_member(1));
    members.push_back(ptr);
    for(int i = 0; i < members.size(); ++i){
        EXPECT_EQ(members[i].operator*().payFee(i), "Member 0 has paid for the next month\n");
    }
}

TEST (Prototype, YearlyMember){
    std::vector<Ptr> members;
    Ptr ptr(Factory::make_member(2));
    members.push_back(ptr);
    for(int i = 0; i < members.size(); ++i){
        EXPECT_EQ(members[i].operator*().payFee(i), "Member 0 has paid for the next year\n");
    }
}

TEST (Prototype, YearlyMember1){
    std::vector<Ptr> members;
    Ptr ptr(Factory::make_member(2));
    members.push_back(ptr);
    Ptr ptr1(Factory::make_member(2));
    members.push_back(ptr1);
    for(int i = 0; i < members.size(); ++i){
        if(i == 0){
            EXPECT_EQ(members[i].operator*().payFee(i), "Member 1 has paid for the next year\n");
        } else {
            EXPECT_EQ(members[i].operator*().payFee(i), "Member 2 has paid for the next year\n");
        }
    }
}

TEST (Prototype, MonthlyMember1){
    std::vector<Ptr> members;
    Ptr ptr(Factory::make_member(1));
    members.push_back(ptr);
    Ptr ptr1(Factory::make_member(1));
    members.push_back(ptr1);
    for(int i = 0; i < members.size(); ++i){
        if(i == 0){
            EXPECT_EQ(members[i].operator*().payFee(i), "Member 1 has paid for the next month\n");
        } else {
            EXPECT_EQ(members[i].operator*().payFee(i), "Member 2 has paid for the next month\n");
        }
    }
}

int main(int argc, char * argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
