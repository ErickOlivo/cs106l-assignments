#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* TODO: Implement this method */
  // 1. Encontrar los iteradores a los espacios (y extremos)
  auto whitespace_its = find_all(source.begin(), source.end(), isspace);

  // 2. Crear set de tokens
  std::set<Token> tokens;

  // 3. Transformar pares consecutivos de iteradores en Tokens
  std::transform(
      whitespace_its.begin(), whitespace_its.end() - 1,    // primer rango
      whitespace_its.begin() + 1,                           // segundo rango (desplazado)
      std::inserter(tokens, tokens.end()),                  // inserta en el set
      [&source](auto it1, auto it2) {
          return Token(source, it1, it2);                   // construye un Token
      }
  );

  // 4. Eliminar tokens vacíos
  std::erase_if(tokens, [](const Token& t) {
      return t.content.empty();
  });

  // 5. Retornar
  return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;

  // Paso 1: filtrar solo los tokens que no están en el diccionario
  auto misspelled_view = source
      | rv::filter([&dictionary](const Token& token) {
          return !dictionary.contains(token.content);
      });

  // (Temporal) Imprimir cuántos tokens mal escritos encontramos
  std::cout << "Misspelled tokens: "
            << std::ranges::distance(misspelled_view.begin(), misspelled_view.end())
            << std::endl;

  return std::set<Mispelling>();

};

/* Helper methods */

#include "utils.cpp"
