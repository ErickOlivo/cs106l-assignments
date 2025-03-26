/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name); // Named constructor
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /**
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  User();                   // Constructor
  User(const User& other);  // Copy constructor
  ~User();                  // Destructor
  std::string get_friends() const;
  friend std::ostream& operator << (std::ostream& out, const User& user);

  // PART 2
  User& operator=(const User& user);

  User(User&& user) = delete;
  User& operator=(User&& user) = delete;


  // PART 3
  User& operator+=(User& rhs); // Agregar amigo mutuo
  bool operator<(const User& rhs) const; // Comparación alfabética

private:
  std::string _name;
  std::string* _friends;
  /*
  Si se reemplazara el raw pointer con un vector
  std::vector<std::string> _friends;
  No se necesitaría_size ni _capacity, porque el std::vector lo manejaría
  */
  size_t _size;
  size_t _capacity;
};
