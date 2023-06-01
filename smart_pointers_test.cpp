#include "smart_pointers.h"

int main(void)
{
  auto Sam = shared_ptr<Hobbit>(new Hobbit("Sam")); 
  Sam->Init();
  auto Frodo = shared_ptr<Hobbit>(new Hobbit("Frodo")); 
  Frodo->Init();

  Frodo->FindRing(new Ring("The one"));
  Sam->FindFood(new Food(10));
  Sam->ShareFood(Frodo);
  Sam->Eat(7);
  Frodo->Eat(9);
  Frodo->Eat(9);
  //Sam->Eat(7);
  //Frodo->FindRing(new Ring("The two"));
  //Frodo->LostRing();
  //Frodo->LostRing();

  if (Frodo->HasRing()) {
    Frodo->PutOnTheRing();
    Frodo->RemoveTheRing();
  }
  Frodo->GiveRing(Sam);
  if (Sam->HasRing()) {
    Sam->PutOnTheRing();
  }
  if (Frodo->HasRing()) {
    Frodo->PutOnTheRing();
  }

  return 0;
}
