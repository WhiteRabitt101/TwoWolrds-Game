#include <iostream>
#include <string>
#include <vector>

class Boss
{
private:
    std::string name{ "The Boss" };
    int rank{};
    int health{ 100000 };
    int xp{ 100000 };

public:
   



};



class Player
{
private:
    std:: string name;
    int rank{};
    int health{ 100 };
    int xp{ 100 };




public:
    std::string player_One;
    
   


     //creating players
   
    void add_xp(int xp_new)
    {  
      //  std::cout << xp ;//shows connection
        //std::cout << "\n XP boost\n";//shows connection
        
        xp = xp + xp_new;
        
       // std::cout << xp<< "\n"; //shows connection
    }
    
    int get_xp()
    {
        return xp;
    }

    void set_Name(std:: string name_val)
    {
     //   std::cout << "\n \n Sending ""Name"" to the World...\n \n \n";  //shows connection
        name = name_val;
    }
    std::string get_name()
    {
        //std:: cout<< "\n \n Retrieving ""Name"" from the World Data.. one moment  \n \n \n"; //shows connection
        return name;
       
    }

    void set_rank(double rank_val){
         rank = rank_val;
        // std::cout << "Sending Rank to World Data..\n"; //shows connection
    }
    double get_rank(){
        // cout is to show connection 
        //std::cout<< "\n \n Going to World Data.. .\n\n\n";  //shows connection
        //

        return rank;
    }

    int add_health(int health_up)
    {
        health = health +health_up;
        return health;
    }
    int lower_health(int health_down)
    {
        health = health - health_down;
        return health;
    }
    int get_health()
    {
        return health;
    }
};

class Games
 {
    private:

        //std::string games{"Color Guessing (main 10 only)", "Higher or Lower", "Heads or Tail"};
        int choice;
        // Color Guessing Game
        std::string Game0;
               

        std::string Game2;
        std::string* Game2_ptr{ nullptr };

        std::string Game1 = { "Higer or Lower" };
        std::string *Game1_ptr{ &Game1};
    public:
        std::string *Game0_ptr{ nullptr };
        
        
      
        void setGame(int gam_Choice)
        {
            int choice;
           // std::string *Game1_ptr;
           // Game1_ptr = &Game1;
            
            choice = gam_Choice;
           // std::cout << Game1_ptr;
            std::cout << " \n\n Sending data to The World..\n \n";
        };

        std::string get_Game()
        {
            // std:: cout <<"\n \n \n get_game Works...\n \n \n ";

            std::string Picked_Game;
            std::string games[3] = {"Color Guessing (main 10 only)", "Higher or Lower", "Heads or Tail"};
            
            Picked_Game = games[choice];

            return Picked_Game;
        
        };

    
        std::string *Game_ptr{ nullptr };
        //Game_ptr = &Picked_Game;

       
        


};



