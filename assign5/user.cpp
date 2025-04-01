#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/**
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
User::User()
  : _name("")
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{}

// Copy constructor
User::User(const User& other) : _name(other._name), _friends(other._friends), _size(other._size), _capacity(other._capacity) {
  _friends = new std::string[_capacity];
  for (size_t i = 0; i < _size; ++i) {
    _friends[i] = other._friends[i];
  }
}

// Destructor
User::~User() {
  // Cleanup code
  delete[] _friends;
}
std::string User::get_friends() const{
  std::string concatenatedString = "";
  for (size_t i = 0; i < _size; ++i) {
    concatenatedString = concatenatedString + _friends[i];
    if (i < _size - 1) {
      concatenatedString += ", ";
    }
  }
  return concatenatedString;
}

std::ostream& operator << (std::ostream& out, const User& user) {
  out << "User(name=" << user.get_name() << ", " << "friends=[" << user.get_friends() << "])";
  return out;
}

// PART 2

User& User::operator=(const User& other)
{
  if (this != &other) {
    // Liberar memoria
    delete[] _friends;

    // Copiar los valores del otro objeto
    _name = other._name;
    _size = other._size;
    _capacity = other._capacity;

    // Asignar nuevo arreglo de amigos
    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      _friends[i] = other._friends[i];
    }
  }

  return *this;
}

// PART 3
/*
  Agregar usuario como amigo
*/

User& User::operator+=(User& rhs) {
  // Agregar a rhs a *this si no está ya
  bool already_friend = false;
  for (size_t i = 0; i < _size; ++i) {
    if (_friends[i] == rhs.get_name()) {
      already_friend = true;
      break;
    }
  }
  if (!already_friend) {
    add_friend(rhs.get_name());
  }

  // Agregar *this a rhs si no está ya
  already_friend = false;
  for (size_t i = 0; i < rhs._size; ++i) {
    if (rhs._friends[i] == this->get_name()) {
      already_friend = true;
      break;
    }
  }
  if (!already_friend) {
    rhs.add_friend(this->get_name());
  }

  return *this;
}

/*
  Comparar usuarios por orden alfabético según el nombre
*/

bool User::operator<(const User& rhs) const {
  return _name < rhs._name;
}

