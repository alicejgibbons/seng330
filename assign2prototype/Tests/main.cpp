//
//  main.cpp
//  Tests
//
//  Created by Alice Gibbons on 2015-11-13.
//  Copyright © 2015 Alice Gibbons. All rights reserved.
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "prototype.h"

TEST (Prototype, MonthlyMember){
    std::vector<Member*> members;
    members.push_back(Factory::make_member(1));
    for(int i = 0; i < members.size(); ++i){
        EXPECT_EQ(members[i]->payFee(i), "Member 0 has paid for the next month\n");
    }
    for (int i=0; i < members.size(); ++i){
                delete members[i];
    }
}

TEST (Prototype, YearlyMember){
    std::vector<Member*> members;
    members.push_back(Factory::make_member(2));
    for(int i = 0; i < members.size(); ++i){
        EXPECT_EQ(members[i]->payFee(i), "Member 0 has paid for the next year\n");
    }
    for (int i=0; i < members.size(); ++i){
        delete members[i];
    }
}

TEST (Prototype, YearlyMember){
    std::vector<Member*> members;
    members.push_back(Factory::make_member(2));
    //serialze to file
    
    //read from file and expect it to equal the json
    for(int i = 0; i < members.size(); ++i){
        EXPECT_EQ(members[i]->payFee(i), "Member 0 has paid for the next year\n");
    }
    for (int i=0; i < members.size(); ++i){
        delete members[i];
    }
}

TEST (Prototype, YearlyMember){
    std::vector<Member*> members;
    members.push_back(Factory::make_member(2));
    
    //serialize in from file
    
    //epect members to contain the right stuff
    for(int i = 0; i < members.size(); ++i){
        EXPECT_EQ(members[i]->payFee(i), "Member 0 has paid for the next year\n");
    }
    for (int i=0; i < members.size(); ++i){
        delete members[i];
    }
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
