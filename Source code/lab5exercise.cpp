#include <iostream>
#include <stdlib.h>
#include<ctime>
using namespace std;

class Dice
{
public:
  Dice(){

  }
  int roll(){
    return rand()%6 + 1;
  }
};

class Player
{
public:
  string id;
  string name;
  int score;
  Player(string id, string name){
    this->id = id;
    this->name = name;
    score = 0;
  }
  void updateScore(Dice *d1, Dice *d2){
    int i = d1->roll() + d2->roll();
    if(i%2==0){
      return;
    }
    score += i;
  }
  string toString(){
    string s = name;
    s += "  ";
    cout<<name<<"  "<<score<<endl;
    return s;
  }
};

class Game
{
public:
  Player *playerA;
  Player *playerB;
  Player *playerC;
  Dice *d1;
  Dice *d2;
  Game(){
    playerA = new Player("pA", "Askar");
    playerB = new Player("pB", "Arman");
    playerC = new Player("pC", "Arai");
    d1 = new Dice();
    d2 = new Dice();
  }
  Player *winner(Player *p, Dice *d1, Dice *d2){
    p->updateScore(d1, d2);
    return p;
  }
  void play(int n){
    for (int i = 0; i < n; ++i)
    {
      playerA->updateScore(d1, d2);
      playerB->updateScore(d1, d2);
      playerC->updateScore(d1, d2);
      playerA->toString();
      playerB->toString();
      playerC->toString();
    }
    cout<<endl;
  }
};

int main()
{
  srand(time(0));
  int n;
  cin>>n;
  Game *g = new Game();
  g->play(n);
  cin>>n;
  return 0;

}
