/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 */
struct Course {
  std::string title;
  std::string number_of_units;
  std::string quarter;
};

/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  std::ifstream file(filename); // Me permite leer línea por línea

  if (!file.is_open()) {         // Compruebo si realmente se abre el archivo
    std::cerr << "File not found" << std::endl;
    return;
  }

  std::string line;
  std::getline(file, line); // Lee e ignora la primera línea (header), ya que solo contiene el nombre de las columnas
  while (std::getline(file, line)) {  // Leer línea por línea
    std::vector<std::string> tokens = split(line, ',');   // Convierto cada línea en un stream

    // This extracts the necessary course information from the tokens (a vector of strings from split())
    std::string title = tokens[0]; // Extracts course title from the parsed line.
    std::string number_of_units = tokens[1]; // Extracts course Units from the parsed line
    std::string quarter = tokens[2]; // Extracts the quarter information.

    // Creates and stores a Course object in courses.
    courses.push_back({title, number_of_units, quarter});
  }
  file.close();
}


/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */

void write_courses_offered(std::vector<Course>& all_courses) {
  std::ofstream file(COURSES_OFFERED_PATH);

  if (!file.is_open()) {
    std::cerr << "Unable to open file for writing!" << std::endl;
    return;
  }

  // Escribir el header del CSV
  file << "Title,Number of Units,Quarter\n";

  // Para guardar los cursos no ofrecidos
  std::vector<Course> filtered_courses;

  // Itera sobre todos los cursos y escribe los ofrecidos
  for (const Course& course : all_courses) {
    if (course.quarter != "null") { // Filter courses that are offered
      file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
    }
    else { // Not-offered course, Keep in filtered_courses
      filtered_courses.push_back(course); // Si no está ofertado, lo conservamos
    }
  }
  file.close();

  // Replace all_courses with the filtered list (los cursos no ofertados)
  all_courses = std::move(filtered_courses);

  /*
  ce// Ahora, eliminamos del vector todos los cursos ofertados usando delete_elem_from_vector.
  // Debido a que no es seguro eliminar elementos mientras iteramos, usamos un bucle while
  // que busque y elimine cursos ofertados uno a uno.
  bool foundOffered = true;
  while (foundOffered) {
    foundOffered = false;
    for (const Course& course : all_courses) {
      if (course.quarter != "null") {  // Encontramos un curso ofertado
        delete_elem_from_vector(all_courses, course);
        foundOffered = true;
        break;  // Rompemos el bucle para reiniciar la búsqueda en el vector modificado
  */
}

/**
 * This function writes the courses NOT offered to the file
 * "student_output/courses_not_offered.csv".
 *
 * This function is ALWAYS called after the `write_courses_offered` function.
 * `unlisted_courses` will trivially contain classes that are not offered
 * since you delete offered classes from `all_courses` in the
 * `write_courses_offered` function.
 *
 * HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(std::vector<Course>& unlisted_courses) {
  std::ofstream file(COURSES_NOT_OFFERED_PATH);

  if (!file.is_open()) {
    std::cerr << "Unable to open file for writing!" << std::endl;
    return;
  }

  // Escribir header del CSV
  file << "Title,Number of Units,Quarter\n";

  for (const Course& course : unlisted_courses) {
    file << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
  }
  file.close();
}

int main(void) {
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!"); // Si is_valid_course<Course> es falsa, la compilación fallará y se mostrará el mensaje

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}
