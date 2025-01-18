package view;

import model.Product;
import model.Character;
import controller.*;

import java.util.Scanner;

public class View {

    private final Controller controller = new Controller();
    private final Scanner scanner = new Scanner(System.in);

    public void menu() {
        while (true) {

            // First object
            System.out.println("Welcome to the Westeros!");
            System.out.println("1. Add Product");
            System.out.println("2. Show All Products");
            System.out.println("3. Update Product");
            System.out.println("4. Delete Product");

            // Second object
            System.out.println("5. Add Character");
            System.out.println("6. Show All Characters");
            System.out.println("7. Update Character");
            System.out.println("8. Delete Character");

            // Helper „Buy” method
            System.out.println("9. Buy Product");

            // First filter
            System.out.println("10. Filter Characters by Region");

            // Second filter
            System.out.println("11. Filter Characters by product's region");

            // Sort
            System.out.println("12. Sort Products in ascending/descending order");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1 -> addProduct();
                case 2 -> showAllProducts();
                case 3 -> updateProduct();
                case 4 -> deleteProduct();
                case 5 -> addCharacter();
                case 6 -> showAllCharacters();
                case 7 -> updateCharacter();
                case 8 -> deleteCharacter();
                case 9 -> buyProducts();
                case 10 -> filterCharacterByRegion();
                case 11 -> filterCharacterByProductRegion();
                case 12 -> sortCharactersProducts();
            }
        }
    }

    // CRUD Film

    /**
     * Creates product to the InMemory repository.
     */
    private void addProduct() {
        System.out.println("Enter the product ID");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the product name");
        String name = scanner.nextLine();
        System.out.println("Enter the product price");
        double price = scanner.nextDouble();
        scanner.nextLine();
        System.out.println("Enter the product region");
        String region = scanner.nextLine();

        controller.addProduct(new Product(id, name, price, region));
    }

    /**
     * Gets all products from the InMemory repository.
     */
    private void showAllProducts() {
        controller.getProductList().forEach(System.out::println);
    }

    /**
     * Updates products to the InMemory repository.
     */
    private void updateProduct() {
        showAllProducts();
        System.out.println("Enter the product ID");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the product name");
        String name = scanner.nextLine();
        System.out.println("Enter the product price");
        double price = scanner.nextDouble();
        scanner.nextLine();
        System.out.println("Enter the product region");
        String region = scanner.nextLine();
        controller.updateProduct(id, name, price, region);
    }

    /**
     * Deletes products from the InMemory repository.
     */
    private void deleteProduct() {
        System.out.println("Enter the product ID");
        int id = scanner.nextInt();
        controller.deleteProduct(id);
    }

    // CRUD Character

    /**
     * Adds character to the InMemory repository.
     */
    private void addCharacter() {
        System.out.println("Enter the character ID");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the character name");
        String name = scanner.nextLine();
        System.out.println("Enter the character region");
        String region = scanner.nextLine();
        controller.addCharacter(new Character(id, name, region));
    }

    /**
     * Gets all characters from the InMemory repository.
     */
    private void showAllCharacters() {
        controller.getCharacterList().forEach(System.out::println);
    }

    /**
     * Updates character from the InMemory repository.
     */
    private void updateCharacter() {
        controller.getCharacterList().forEach(System.out::println);
        System.out.println("Enter the character ID");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter the character name");
        String name = scanner.nextLine();
        System.out.println("Enter the character region");
        String region = scanner.nextLine();
        controller.updateCharacter(id, name, region);
    }

    /**
     * Deletes character from the InMemory repository.
     */
    private void deleteCharacter() {
        System.out.println("Enter the character ID");
        int id = scanner.nextInt();
        controller.deleteCharacter(id);
    }

    /**
     * Helper method: characters buy products.
     */
    private void buyProducts() {
        showAllCharacters();
        showAllProducts();
        System.out.println("Enter the character ID");
        int characterID = scanner.nextInt();
        System.out.println("Enter the product ID");
        int productID = scanner.nextInt();
        controller.buyProducts(characterID, productID);
    }

    /**
     * Filter character by their region (user input).
     */
    private void filterCharacterByRegion() {
        System.out.println("Enter the character region");
        String region = scanner.nextLine();
        controller.filterCharactersByRegion(region).forEach(System.out::println);
    }

    /**
     * Filter characters that have bought products from a specific region.
     */
    private void filterCharacterByProductRegion() {
        System.out.println("Enter the product region");
        String region = scanner.nextLine();
        controller.filterCharacterByProductRegion(region).forEach(System.out::println);
    }

    /**
     * Sorts characters' products in ascending/descending order.
     */
    private void sortCharactersProducts() {
        controller.getCharacterList().forEach(System.out::println);
        System.out.println("Enter the character ID");
        int characterID = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Sort ascending? (true/false)");
        boolean ascending = scanner.nextBoolean();
        controller.sortCharactersProducts(characterID, ascending).forEach(System.out::println);
    }
}