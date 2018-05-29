// there are bug(s) here. Fix them and ensure the class works as it should
// In this case, there are 7 bugs. You can probably expect to have not quite this many in an exam question, but the more bugs you see, the better practice it is

#include <algorithm>
#include <string>
#include <vector>

class User {
public:
  bool is_admin() {
    return false;
  }

  const std::string& get_username() const { return username; }

private:
  std::string username;
};

class Admin: public User {
public:
  bool is_admin() {
    return true;
  }

  void add_child(const User* user) {
    children.push_back(user);
  }

private:
  std::vector<const User*> children;
};

class Computer {
  auto get_user(const std::string& username) {
    const auto username_match = [&username] (const auto& user) { return user.get_username() == username; };
    return std::find_if(users.begin(), users.end(), username_match);
  }

  bool login(const std::string& username) {
    auto user = get_user(username);
    if (user == users.end())
      return false;
    current_user = &*user;
    return true;
  }

  bool delete_user(const std::string& username) {
    if (!current_user->is_admin())
      return false;
    users.erase(get_user(username));
    return true;
  }

  bool add_user(const User user) {
    if (current_user->is_admin()) {
      static_cast<Admin*>(current_user)->add_child(&user);
      users.push_back(user);
      return true;
    }
    return false;
  }

private:
  std::vector<User> users;
  User* current_user;
};


int main() {
  Computer c;
}
