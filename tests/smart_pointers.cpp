#include "smart_pointers.h"

Hobbit::Hobbit(string name)
  : m_name(name) {}

Hobbit::~Hobbit()
{
  cout << "Hobbit " << this->GetName() << " die" << endl;
}

void Hobbit::Init()
{
  this->m_hand = unique_ptr<Hand>(new Hand(this));
  this->m_hand->Wave();
}

void Hobbit::Eat(int amount) {
  if (this->m_food) {
      amount = this->m_food->Eat(amount);
    if (amount>0) {
      cout << this->GetName() << " have eaten " << amount << " cakes from #" << m_food->GetId() << " food" << endl;
    }

    if (this->m_food->IsExpired()) {
      this->m_food.reset();
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
  this->m_ring->DepartureInInvisibilityEffect();
}

void Hobbit::FindRing(Ring* ring)
{
  this->m_ring = unique_ptr<Ring>(ring);
  this->m_ring->SetOwner(this->shared_from_this());
  cout << this->GetName() << " find \'" << this->m_ring->GetName() << "\' ring" << endl;
}

void Hobbit::LostRing()
{
  if (this->m_ring) {
    cout << this->GetName() << " lost \'" << this->m_ring->GetName() << "\' ring" << endl;
    this->m_ring = nullptr;
  }
  else {
    cout << this->GetName() << " has no ring to lose" << endl;
  }
}

void Hobbit::FindFood(Food* food)
{
  this->m_food = shared_ptr<Food>(food);
}

void Hobbit::ShareFood(shared_ptr<Hobbit> hobbit)
{
  hobbit->m_food = this->m_food;
}

void Hobbit::GiveRing(shared_ptr<Hobbit> hobbit)
{
  if (this->HasRing()) {
    hobbit->m_ring = move(this->m_ring);
    hobbit->m_ring->SetOwner(hobbit->shared_from_this());
  }
  else {
    cout << "no ring to share" << endl;
  }
}

void Hobbit::RemoveTheRing() {
  m_ring->DisclosureOfInvisibilityEffect();
}

const string& Hobbit::GetName() const {
  return m_name;
}

Ring::Ring(string name) : m_name(name) { }

Ring::~Ring()
{}

void Ring::Whisper() const {
  cout << "The Ring whispering..." << endl;
}

void Ring::SetOwner(shared_ptr<Hobbit> owner)
{
  this->m_owner = weak_ptr<Hobbit>(owner);
}

void Ring::ShowInscriptions() {
  cout << "The Ring showing some text..." << endl;
}

const string& Ring::GetName() const
{
  return m_name;
}

void Ring::DisclosureOfInvisibilityEffect() {
  if (auto tmp = this->m_owner.lock()) {
    cout << tmp->GetName() << " becoming visible..." << endl;
  }
}

void Ring::DepartureInInvisibilityEffect() {
  if (auto tmp = this->m_owner.lock()) {
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
