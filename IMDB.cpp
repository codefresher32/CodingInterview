#include <iostream>
#include <vector>

using namespace std;

struct Movie {
  string title, category, releaseDate, budget;
  vector < string > cast;
};
vector < Movie > allMovies;

struct User {
  string email, name;
  vector < Movie > favoriteMovies;
};
unordered_map < string, User > registeredUsers;

Movie getDummyMovie() {
  Movie newMovie;
  newMovie.title = "troy";
  newMovie.category = "action";
  newMovie.releaseDate = "2007";
  newMovie.budget = "120M";
  newMovie.cast.push_back("brad");
  return newMovie;
}

User getDummyUser() {
  User newUser;
  newUser.email = "mostaq@gmail.com";
  newUser.name = "polok";
  Movie curMovie = getDummyMovie();
  newUser.favoriteMovies.push_back(curMovie);
  allMovies.push_back(curMovie);
  return newUser;
}

void addUser() {
  auto curUser = getDummyUser();
  registeredUsers[curUser.email] = curUser;
}

User seeUserDetails(string email) {
  if (registeredUsers.count(email)) {
    return registeredUsers[email];
  }
  return ;
}

void addFavMovieToUser(string email, string title) {
  if (!registeredUsers.count(email)) return ;
  for (auto tp : allMovies) {
    if (tp.title == title) {
      registeredUsers[email].favoriteMovies.push_back(tp);
    }
  }
}

void removeFavMovieFromUser(string email, string title) {
  if (!registeredUsers.count(email)) return ;
  int id = -1;
  for (int i = 0; i < registeredUsers[email].favoriteMovies.size(); i++) {
    if (registeredUsers[email].favoriteMovies[i].title == title) {
      id = i;
      break;
    }
  }
  registeredUsers[email].favoriteMovies.erase(registeredUsers[email].favoriteMovies.begin() + id);
}

static bool comTitle(Movie &a, Movie &b) {
  return a.title < b.title;
}

vector < Movie > searchByTitle(string email, string title) {
  vector < Movie > searchedMovies;
  if (!registeredUsers.count(email)) return ;
  for (auto &tp : registeredUsers[email].favoriteMovies) {
    if (tp.title == title) {
      searchedMovies.push_back(tp);
    }
  }
  sort(searchedMovies.begin(), searchedMovies.end(), comTitle);
  return searchedMovies;
}

vector < Movie > searchByCategory(string email, string category) {
  vector < Movie > searchedMovies;
  if (!registeredUsers.count(email)) return ;
  for (auto &tp : registeredUsers[email].favoriteMovies) {
    if (tp.category == category) {
      searchedMovies.push_back(tp);
    }
  }
  sort(searchedMovies.begin(), searchedMovies.end(), comTitle);
  return searchedMovies;
}

vector < Movie > searchByCast(string email, string cast) {
  vector < Movie > searchedMovies;
  if (!registeredUsers.count(email)) return ;
  for (auto &tp : registeredUsers[email].favoriteMovies) {
    for (auto &tpr : tp.cast) {
      if (tpr == cast) {
        searchedMovies.push_back(tp);
        break;
      }
    }
  }
  sort(searchedMovies.begin(), searchedMovies.end(), comTitle);
  return searchedMovies;
}

vector < Movie > getAllMovies() {
  return allMovies;
}

int main() {

}