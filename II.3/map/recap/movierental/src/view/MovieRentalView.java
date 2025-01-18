package view;

import controller.MovieRentalController;
import model.Customer;
import model.Film;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MovieRentalView {

    private final MovieRentalController controller = new MovieRentalController();
    private final Scanner scanner = new Scanner(System.in);

    public void menu() {
        while (true) {
            System.out.println("Welcome to the movie rental!");
            System.out.println("1. Add Film");
            System.out.println("2. Show All Films");
            System.out.println("3. Update Film");
            System.out.println("4. Delete Film");
            System.out.println("5. Add Customer");
            System.out.println("6. Show All Customers");
            System.out.println("7. Update Customer");
            System.out.println("8. Delete Customer");
            System.out.println("9. Buy Films");
            System.out.println("10. Filter Films by Genre");
            System.out.println("11. Filter Customer by Director");
            System.out.println("12. Sort films in ascending/descending order");
            System.out.println("0. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1 -> addFilm();
                case 2 -> showAllFilms();
                case 3 -> updateFilm();
                case 4 -> deleteFilm();
                case 5 -> addCustomer();
                case 6 -> showAllCustomer();
                case 7 -> updateCustomer();
                case 8 -> deleteCustomer();
                case 9 -> buyFilms();
                case 10 -> filterFilmsByGenre();
                case 11 -> filterCustomerByDirector();
                case 12 -> sortFilmsByPrice();
            }
        }
    }

    // CRUD Film
    private void addFilm() {
        System.out.println("Enter the film ID");
        int filmID = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the film title");
        String filmTitle = scanner.nextLine();
        System.out.println("Enter the film director");
        String filmDirector = scanner.nextLine();
        System.out.println("Enter the film genre");
        String filmGenre = scanner.nextLine();
        System.out.println("Enter the film price");
        double filmPrice = scanner.nextDouble();

        controller.addFilm(new Film(filmID, filmTitle, filmDirector, filmGenre, filmPrice));
    }

    private void showAllFilms() {
        controller.getFilms().forEach(System.out::println);
    }

    private void updateFilm() {
        showAllFilms();
        System.out.println("Enter the film ID");
        int filmID = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the film title");
        String filmTitle = scanner.nextLine();
        System.out.println("Enter the film director");
        String filmDirector = scanner.nextLine();
        System.out.println("Enter the film genre");
        String filmGenre = scanner.nextLine();
        System.out.println("Enter the film price");
        double filmPrice = scanner.nextDouble();
        scanner.nextLine();
        controller.updateFilm(filmID, filmTitle, filmDirector, filmGenre, filmPrice);
    }

    private void deleteFilm() {
        System.out.println("Enter the film ID");
        int filmID = scanner.nextInt();
        controller.deleteFilm(filmID);
    }

    // CRUD Customer
    private void addCustomer() {
        System.out.println("Enter the customer ID");
        int customerID = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the customer name");
        String customerName = scanner.nextLine();
        controller.addCustomer(new Customer(customerID, customerName));
    }

    private void showAllCustomer() {
        controller.getCustomers().forEach(System.out::println);
    }

    private void updateCustomer() {
        showAllCustomer();
        System.out.println("Enter the customer ID");
        int customerID = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the customer name");
        String customerName = scanner.nextLine();
        controller.updateCustomer(customerID, customerName);
    }

    private void deleteCustomer() {
        System.out.println("Enter the customer ID");
        int customerID = scanner.nextInt();
        controller.deleteCustomer(customerID);
    }

    // Buy Films
    private void buyFilms() {
        showAllFilms();
        System.out.println("Enter the customer ID");
        int customerID = scanner.nextInt();
        System.out.println("Enter the film ID");
        int filmID = scanner.nextInt();
        controller.buyFilms(customerID, filmID);
    }

    private void filterFilmsByGenre() {
        System.out.println("Enter a genre");
        String genre = scanner.nextLine();
        controller.filterFilmsByGenre(genre).forEach(System.out::println);
    }

    private void filterCustomerByDirector() {
        System.out.println("Enter a director");
        String director = scanner.nextLine();
        controller.filterCustomerByDirector(director).forEach(System.out::println);
    }

    private void sortFilmsByPrice() {
        showAllCustomer();
        System.out.println("Enter the customer ID");
        int customerID = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Sort ascending? (true/false)");
        boolean ascending = scanner.nextBoolean();
        controller.sortFilmsByPrice(customerID, ascending).forEach(System.out::println);
    }

}