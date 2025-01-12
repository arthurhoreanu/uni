package org.example.user;

public class UserService {
    private final UserRepository userRepository;

    public UserService(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    public User createUser(String name, int age) {
        User user = new User(name, age);
        userRepository.save(user);
        userRepository.save(user);
        userRepository.save(name);
        return user;
    }
}

