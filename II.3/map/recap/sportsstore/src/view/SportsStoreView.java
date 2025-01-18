package view;

import controller.SportsStoreController;
import model.Customer;
import model.Product;

import java.util.Scanner;

/**
 * Console-based UI for managing the sports store.
 */
public class SportsStoreView {

    private final SportsStoreController controller = new SportsStoreController();
    private final Scanner scanner = new Scanner(System.in);

    /**
     * Main menu.
     */
    public void start() {
        while (true) {
            System.out.println("\n----- Sports Store Management -----");
            System.out.println("1. Add Product");
            System.out.println("2. Update Product");
            System.out.println("3. Delete Product");
            System.out.println("4. Show All Products");
            System.out.println("5. Add Customer");
            System.out.println("6. Update Customer");
            System.out.println("7. Delete Customer");
            System.out.println("8. Show All Customers");
            System.out.println("9. Filter Customers by Place");
            System.out.println("10. Filter Customers by Product Season");
            System.out.println("11. Sort Products by Customer");
            System.out.println("12. Buy Product (Add Product to Client)");
            System.out.println("13. Exit");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1 -> addProduct();
                case 2 -> updateProduct();
                case 3 -> deleteProduct();
                case 4 -> showAllProducts();
                case 5 -> addCustomer();
                case 6 -> updateCustomer();
                case 7 -> deleteCustomer();
                case 8 -> showAllCustomers();
                case 9 -> filterCustomersByPlace();
                case 10 -> filterCustomersByProductSeason();
                case 11 -> sortProductsByCustomer();
                case 12 -> buyProductForClient();
                case 13 -> {
                    System.out.println("Exiting...");
                    return;
                }
                default -> System.out.println("Invalid choice. Please try again.");
            }
        }
    }
    
    private void addProduct() {
        System.out.print("Product Name: ");
        String name = scanner.nextLine();
        System.out.print("Price: ");
        double price = scanner.nextDouble();
        scanner.nextLine(); // Consume newline
        System.out.print("Season: ");
        String season = scanner.nextLine();
        controller.addProduct(new Product(name, price, season));
        System.out.println("Product added successfully!");
    }

    private void updateProduct() {
        System.out.print("Enter the name of the product to update: ");
        String productName = scanner.nextLine();
        System.out.print("New Name: ");
        String newName = scanner.nextLine();
        System.out.print("New Price: ");
        double newPrice = scanner.nextDouble();
        scanner.nextLine(); // Consume newline
        System.out.print("New Season: ");
        String newSeason = scanner.nextLine();
        controller.updateProduct(productName, newName, newPrice, newSeason);
    }

    private void deleteProduct() {
        System.out.print("Enter the name of the product to delete: ");
        String name = scanner.nextLine();
        controller.deleteProduct(name);
        System.out.println("Product deleted successfully!");
    }

    private void showAllProducts() {
        controller.getProducts().forEach(System.out::println);
    }

    private void addCustomer() {
        System.out.print("Customer ID: ");
        int id = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("Customer Name: ");
        String name = scanner.nextLine();
        System.out.print("Customer Place: ");
        String place = scanner.nextLine();
        controller.addCustomer(new Customer(id, name, place));
        System.out.println("Customer added successfully!");
    }

    private void updateCustomer() {
        System.out.print("Enter the ID of the customer to update: ");
        int customerId = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("New ID: ");
        int newId = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("New Name: ");
        String newName = scanner.nextLine();
        System.out.print("New Place: ");
        String newPlace = scanner.nextLine();
        controller.updateCustomer(customerId, newId, newName, newPlace);
    }

    private void deleteCustomer() {
        System.out.print("Enter the ID of the customer to delete: ");
        int id = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        controller.deleteCustomer(id);
        System.out.println("Customer deleted successfully!");
    }

    private void showAllCustomers() {
        controller.getCustomers().forEach(System.out::println);
    }

    private void filterCustomersByPlace() {
        System.out.print("Enter place to filter by: ");
        String place = scanner.nextLine();
        controller.filterCustomersByPlace(place).forEach(System.out::println);
    }

    private void filterCustomersByProductSeason() {
        System.out.print("Enter season to filter by: ");
        String season = scanner.nextLine();
        controller.filterCustomersByProductsSeason(season).forEach(System.out::println);
    }

    private void sortProductsByCustomer() {
        controller.getCustomers().forEach(System.out::println);
        System.out.print("Enter the ID of the customer: ");
        int customerId = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("Sort ascending? (true/false): ");
        boolean ascending = scanner.nextBoolean();

        for (Customer customer : controller.getCustomers()) {
            if (customer.getId() == customerId) {
                controller.sortProductsByCustomer(customer, ascending).forEach(System.out::println);
            } else {
            System.out.println("Customer not found!");
        }
        }
    }

    private void buyProductForClient() {
        controller.getProducts().forEach(System.out::println);

        System.out.print("Enter the ID of the client who wants to buy: ");
        int clientId = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter the name of the product to buy: ");
        String productName = scanner.nextLine();

        controller.addProductToClient(clientId, productName);
    }

}
