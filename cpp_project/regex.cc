#include <iostream>
#include <iterator>
#include <regex>
#include <string>

using namespace std;

void search_usage() {
  string s =
      "Some people, when confronted with a problem, think "
      "\"I know, I'll use regular expressions.\" "
      "Now they have two problems.";

  regex self_regex("REGULAR EXPRESSIONS",
                   regex_constants::ECMAScript | regex_constants::icase);
  if (regex_search(s, self_regex)) {
    cout << "Text contains the phrase 'regular expressions'" << endl;
  }

  regex word_regex("(\\w+)");
  auto words_begin = sregex_iterator(s.begin(), s.end(), word_regex);
  auto words_end = sregex_iterator();

  cout << "Found " << distance(words_begin, words_end) << " words\n";

  const int N = 6;
  cout << "Words longer than " << N << " characters:\n";
  for (sregex_iterator i = words_begin; i != words_end; ++i) {
    smatch match = *i;
    string match_str = match.str();
    if (match_str.size() > N) {
      cout << "  " << match_str << '\n';
    }
  }

  regex long_word_regex("(\\w{7,})");
  string new_s = regex_replace(s, long_word_regex, "[$&]");
  cout << new_s << endl;
}

void match_usage() {
  // Simple regular expression matching
  const std::string fnames[] = {"foo.txt", "bar.txt", "baz.dat", "zoidberg"};
  const std::regex txt_regex("[a-z]+\\.txt");

  for (const auto &fname : fnames) {
    std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
  }
  cout << endl;

  // Extraction of a sub-match
  const std::regex base_regex("([a-z]+)\\.txt");
  std::smatch base_match;

  for (const auto &fname : fnames) {
    if (std::regex_match(fname, base_match, base_regex)) {
      // The first sub_match is the whole string; the next
      // sub_match is the first parenthesized expression.
      if (base_match.size() == 2) {
        std::ssub_match base_sub_match = base_match[1];
        std::string base = base_sub_match.str();
        std::cout << fname << " has a base of " << base << '\n';
      }
    }
  }
  cout << endl;

  // Extraction of several sub-matches
  const std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
  std::smatch pieces_match;

  for (const auto &fname : fnames) {
    if (std::regex_match(fname, pieces_match, pieces_regex)) {
      std::cout << fname << '\n';
      for (size_t i = 0; i < pieces_match.size(); ++i) {
        std::ssub_match sub_match = pieces_match[i];
        std::string piece = sub_match.str();
        std::cout << "  submatch " << i << ": " << piece << '\n';
      }
    }
  }
}


int main() { match_usage(); }