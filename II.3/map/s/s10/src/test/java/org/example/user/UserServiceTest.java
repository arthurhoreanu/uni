package org.example.user;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.ArgumentCaptor;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.ArgumentMatchers.eq;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
class UserServiceTest {

    @Mock
    private UserRepository userRepository;

    @InjectMocks
    private UserService userService;

    @Test
    void testCallArg() {
        String name = "test";
        Integer age = 20;
        User user = userService.createUser(name, age);

        verify(userRepository).save(eq(user));
    }

    @Test
    void testCallCaptor() {
        String name = "test";
        Integer age = 20;
        userService.createUser(name, age);

        ArgumentCaptor<User> captor = ArgumentCaptor.forClass(User.class);

        verify(userRepository, times(2)).save(captor.capture());
        User user = captor.getValue();
        assertEquals(name, user.getName());
        assertEquals(age, user.getAge());
    }

    @Test
    void testInteractions(){
        String name = "test";
        Integer age = 20;
        userService.createUser(name, age);

        verify(userRepository,times(2)).save(any(User.class));
        verifyNoMoreInteractions(userRepository);

    }
  
}