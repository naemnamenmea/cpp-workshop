#pragma once

#include <memory>
#include <algorithm>
#include <iostream> 
#include <string> 
using namespace std;

class Food {
public:
  Food(int quantity);
  ~Food();

  bool IsExpired() const;

  int GetId() const {
    return id;
  }

  int Eat(int amount);

private:
  static int id_counter;
  int id;
  int quantity;
};

class Hobbit;

class Hand {
public:
  Hand(Hobbit* hobbit);
  
  void Wave();
private:
  weak_ptr<Hobbit> owner;
};

class Ring {
public:
  Ring(string name);
  ~Ring();
  void Whisper() const;
  void SetOwner(shared_ptr<Hobbit> owner);
  void ShowInscriptions();
  const string& GetName() const;
  void DisclosureOfInvisibilityEffect();
  void DepartureInInvisibilityEffect();
protected:
  weak_ptr<Hobbit> m_owner;
  string m_name;
};

class Hobbit : public enable_shared_from_this<Hobbit> {
public:
  Hobbit(string name);
  ~Hobbit();

  void Init();
  void Eat(int amount);
  void PutOnTheRing();
  void FindRing(Ring* ring);
  bool HasRing() const {
    return !(this->m_ring == nullptr);
  }

  void LostRing();
  void FindFood(Food* food);
  void ShareFood(shared_ptr<Hobbit> hobbit);
  void GiveRing(shared_ptr<Hobbit> hobbit);
  void RemoveTheRing();
  const string& GetName() const;

private:
  unique_ptr<Hand> m_hand;
  string m_name;
  unique_ptr<Ring> m_ring;
  shared_ptr<Food> m_food;
};