/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Erick Olivo"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(const std::string& filename) {
  std::set<std::string> applicants;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Unable to open this file: " << filename << std::endl;
    return applicants;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty()) {
      applicants.insert(line);
    }
  }

  file.close();
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::string get_initials(const std::string& name) {
  std::string initials;
  bool new_word = true;

  for (char c : name) {
    if (new_word && std::isalpha(c)) {
      initials += c;
      new_word = false;
    }
    else if (c == ' ') {
      new_word = true;
    }
  }
  return initials;
}

std::queue<const std::string*> find_matches(const std::string& name, const std::set<std::string>& students) {     // Encontrar coincidiencas en iniciales
  std::queue<const std::string*> matches;                 // Cola de punteros a strings
  std::string target_initials = get_initials(name);

  for (const auto& student : students) {
    if (get_initials(student) == target_initials) {
      matches.push(&student);                       // Guardar puntero en la queue
    }
  }

  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) {
    std::cout << "NO MATCHES FOUND" << std::endl;
    return "";
  }

  std::vector<const std::string*> match_students;

  while (!matches.empty()) {
    match_students.push_back(matches.front());
    matches.pop();
  }

  // Seleccionar un match al azar
  int random_index = std::rand() % match_students.size();
  return *match_students[random_index];

}


/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
