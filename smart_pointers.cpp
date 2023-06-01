#include "smart_pointers.h"

Hobbit::Hobbit(string name)
  : name(name) {}

Hobbit::~Hobbit()
{
  cout << "Hobbit " << this->GetName() << " die" << endl;
}

void Hobbit::Init()
{
  this->hand = unique_ptr<Hand>(new Hand(this));
  this->hand->Wave();
}

void Hobbit::Eat(int amount) {
  if (this->food) {
      amount = this->food->Eat(amount);
    if (amount>0) {
      cout << this->GetName() << " have eaten " << amount << " cakes from #" << food->GetId() << " food" << endl;
    }

    if (this->food->IsExpired()) {
      this->food.reset();
      if (amount > 0) {
        return;
      }
    }
    else {
      return;
    }
  }
  cout << "no food for " << this->GetName() << endl;
}

void Hobbit::PutOnTheRing() {
  this->ring->DepartureInInvisibilityEffect();
}

void Hobbit::FindRing(Ring* ring)
{
  this->ring = unique_ptr<Ring>(ring);
  this->ring->SetOwner(this->shared_from_this());
  cout << this->GetName() << " find \'" << this->ring->GetName() << "\' ring" << endl;
}

void Hobbit::LostRing()
{
  if (this->ring) {
    cout << this->GetName() << " lost \'" << this->ring->GetName() << "\' ring" << endl;
    this->ring = nullptr;
  }
  else {
    cout << this->GetName() << " has no ring to lose" << endl;
  }
}

void Hobbit::FindFood(Food* food)
{
  this->food = shared_ptr<Food>(food);
}

void Hobbit::ShareFood(shared_ptr<Hobbit> hobbit)
{
  hobbit->food = this->food;
}

void Hobbit::GiveRing(shared_ptr<Hobbit> hobbit)
{
  if (this->HasRing()) {
    hobbit->ring = move(this->ring);
    hobbit->ring->SetOwner(hobbit->shared_from_this());
  }
  else {
    cout << "no ring to share" << endl;
  }
}

void Hobbit::RemoveTheRing() {
  ring->DisclosureOfInvisibilityEffect();
}

const string& Hobbit::GetName() const {
  return name;
}

Ring::Ring(string name) : name(name) { }

Ring::~Ring()
{}

void Ring::Whisper() const {
  cout << "The Ring whispering..." << endl;
}

void Ring::SetOwner(shared_ptr<Hobbit> owner)
{
  this->owner = weak_ptr<Hobbit>(owner);
}

void Ring::ShowInscriptions() {
  cout << "The Ring showing some text..." << endl;
}

const string& Ring::GetName() const
{
  return name;
}

void Ring::DisclosureOfInvisibilityEffect() {
  if (auto tmp = this->owner.lock()) {
    cout << tmp->GetName() << " becoming visible..." << endl;
  }
}

void Ring::DepartureInInvisibilityEffect() {
  if (auto tmp = this->owner.lock()) {
    cout << tmp->GetName() << " becoming invisible..." << endl;
  }
}

Hand::Hand(Hobbit* hobbit)
  :owner(hobbit->shared_from_this()) {}

void Hand::Wave() {
  if (auto obs = owner.lock()) {
    cout << "Hello, my name is " << obs->GetName() << endl;
  }
  else {
    cout << "owner dead (" << endl;
  }
}

int Food::id_counter = 0;

Food::Food(int quantity)
  :quantity(quantity), id(++id_counter) {}

Food::~Food()
{
  cout << "Food #" << this->id << " ended" << endl;
}

bool Food::IsExpired() const {
  return !(quantity > 0);
}

int Food::Eat(int amount) {
  int res = quantity > amount ? amount : quantity;
  quantity = max(0, quantity - amount);
  return res;
}
