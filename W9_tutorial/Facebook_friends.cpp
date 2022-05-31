#include <iostream>
#include <vector>
#include <string>

class FBuser
{
    public:
        std::string name;
        std::vector<FBuser*> friends;

        //Constructor
        FBuser(){}

        FBuser(std::string name)
        {
            this->name = name;
        }

        //Method to add a friend
        void addFriend(FBuser &another)
        {
            friends.push_back(&another);
            another.friends.push_back(this);
        }

        //Show Friends
        void showFriends()
        {

            std::cout << "Friend list of " << name << ": ";
            for(FBuser *name_list: friends)
            {
                std::cout << "\t" << name_list->name <<", ";
            }
            std::cout << "\n";
        }
        //show friends of friend
        void FriendsOfFriend(FBuser another)
        {
            int i = 0;
            for(auto another_list: another.friends)
            {
                if(another_list->name == name)
                {
                    another.friends.erase(another.friends.begin() + i);
                }
                i++;
            }

            std::cout << "Friends of " << another.name << ": ";
            for(auto another_list: another.friends)
            {
                std::cout << another_list->name << ", ";
            }
            std::cout << "\n\n";
        }

        
        //mutual Friends
        void mutualFriends(FBuser &another)
        {
            std::vector<std::string> mutual_name_list;
            std::string temp;
            for(auto this_list: friends)
            {
                for(auto another_list: another.friends)
                {
                    if(this_list->name == another_list->name)
                    {
                        mutual_name_list.push_back(this_list->name);
                    }
                }
            }

            std::cout << "Mutual Friends of " << this->name << " and " << another.name << ": ";
            for(auto name_list: mutual_name_list)
            {
                std::cout << name_list << ", ";
            }
            std::cout << "\n\n";
        }

};

int main()
{
    FBuser user1("Khang");
    FBuser user2("Duy");
    FBuser user3("Loan");
    FBuser user4("Nguyen");

    user1.addFriend(user2);
    user1.addFriend(user3);
    user3.addFriend(user2);
    user4.addFriend(user1);
    user4.addFriend(user3);

    user1.showFriends();
    user2.showFriends();
    user3.showFriends();
    

    user1.mutualFriends(user3);
    user1.FriendsOfFriend(user3);
    user3.showFriends();

    return 0;
}