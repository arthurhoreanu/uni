package controller;

import model.*;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;


public class SportsStoreController {

    private List<Product> products = new ArrayList<>();
    private List<Customer> customers = new ArrayList<>();

    // Product CRUD
    public void addProduct(Product product) {
        products.add(product);
    }

    public List<Product> getProducts() {
        return products;
    }

    public void updateProduct(String productName, String newName, double newPrice, String newSeason) {
        Product product = products.stream()
                .filter(p -> p.getName().equalsIgnoreCase(productName))
                .findFirst()
                .orElse(null);

        if (product != null) {
            product.setName(newName);
            product.setPrice(newPrice);
            product.setSeason(newSeason);
        } else {
            System.out.println("Product not found.");
        }
    }

    public void deleteProduct(String name) {
        products.removeIf(p -> p.getName().equalsIgnoreCase(name));
    }

    // Customer CRUD
    public void addCustomer(Customer customer) {
        customers.add(customer);
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public void updateCustomer(int customerId, int newId, String newName, String newPlace) {
        Customer customer = customers.stream()
                .filter(c -> c.getId() == customerId)
                .findFirst()
                .orElse(null);

        if (customer != null) {
            customer.setId(newId);
            customer.setName(newName);
            customer.setPlace(newPlace);
        } else {
            System.out.println("Customer not found.");
        }
    }

    public void deleteCustomer(int id) {
        customers.removeIf(c -> c.getId() == id);
    }

    /**
     * Filters customers based on their place.
     * @param place
     * @return
     */
    public List<Customer> filterCustomersByPlace(String place) {
        List<Customer> filtered = new ArrayList<>();
        for (Customer customer : customers) {
            if (customer.getPlace().equalsIgnoreCase(place)) {
                filtered.add(customer);
            }
        }
        return filtered;
    }

    /**
     * Filters customers based on a given season of the products they have purchased.
     * @param season
     * @return
     */
    public List<Customer> filterCustomersByProductsSeason(String season) {
        return customers.stream()
                .filter(customer -> customer.getProducts().stream()
                        .anyMatch(product -> product.getSeason().equalsIgnoreCase(season)))
                .collect(Collectors.toList());
    }

    /**
     * All the products bought by a given customer
     * @param customer
     * @param ascending
     * @return
     */
    public List<Product> sortProductsByCustomer(Customer customer, boolean ascending) {
        if (customer.getProducts() == null) {
            return new ArrayList<>();
        }

        Comparator<Product> comparator = Comparator.comparing(Product::getPrice);
        if (!ascending) {
            comparator = comparator.reversed();
        }

        return customer.getProducts().stream()
                .sorted(comparator)
                .collect(Collectors.toList());
    }

    /**
     * Client buying products (adding the product to their list of products).
     * @param customerID
     * @param productName
     */
    public void addProductToClient(int customerID, String productName) {
        Customer customer = customers.stream()
                .filter(c -> c.getId() == customerID)
                .findFirst()
                .orElse(null);

        if (customer == null) {
            System.out.println("Client not found!");
            return;
        }

        Product product = products.stream()
                .filter(p -> p.getName().equalsIgnoreCase(productName))
                .findFirst()
                .orElse(null);

        if (product == null) {
            System.out.println("Product not found!");
            return;
        }

        customer.getProducts().add(product);
        System.out.println("Product added to customer successfully!");
    }

}
