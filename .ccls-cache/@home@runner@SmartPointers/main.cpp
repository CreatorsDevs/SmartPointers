#include <iostream>
#include <memory>
using namespace std;

class Player
{
protected:
    int health, lives;

public:
    Player(int h, int l)
    {
        health = h;
        lives = l;
        cout << "\nI am a player, I just got spawned!\nHealth is: " << health << " and lives is:  " << lives << endl;
    }

    ~Player()
    {
      health = 0;
      cout << "\nI am a player and I died!\nCurrent Health is: " << health << endl;
    }
};

class FastPlayer : public Player
{
private:
    int speed;

public:
    FastPlayer(int s, int l) : Player(200, l)        
    {   
        speed = s;
        cout << "\nI am a fast player, I just got spawned!\nHealth is: " << health << ", lives is: " << lives << " and Speed is: " << speed << endl;
    }

    ~FastPlayer()
    {
    health = 0;
    cout << "\nI am a fast player and I died!\nCurrent Health is: "<< health << endl;
    }
};

void LocalObjects()
{
    unique_ptr<Player> player(new Player(90,11));
    unique_ptr<FastPlayer> roadRunner(new FastPlayer(500,10));
}

int main()
{
    unique_ptr<Player> player1(new Player(50,7));
    unique_ptr<Player> player2(new Player(100,3));
    unique_ptr<Player> player3(new Player(80,5));

    LocalObjects();

    return 0;
}