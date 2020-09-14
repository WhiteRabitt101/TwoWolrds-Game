
#ifndef ITEMS_H
#define ITEMS_H

class Items
{
private:

    std::string name;
    int Power; //dammage that can be delt
    int w_health;

public:
    void W_stats(std::string Name, int power, int w_health);
    std::string get_Name() { return name; };
    int get_damage() { return Power; };

};

#endif // !ITEMS_H






