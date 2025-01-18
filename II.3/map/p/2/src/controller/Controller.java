package controller;

import model.*;
import model.Character;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Controller {

    private List<Product> productList = new ArrayList<>();
    private List<model.Character> characterList= new ArrayList<>();

    // CRUD Product

    /**
     * Adds product to the InMemory repository.
     * @param product
     */
    public void addProduct(Product product) {
        productList.add(product);
    }

    /**
     * Gets all products from the InMemory repository.
     * @return
     */
    public List<Product> getProductList() {
        return productList;
    }

    /**
     * Updates products from the InMemory repository.
     * @param id
     * @param newName
     * @param newPrice
     * @param newRegion
     */
    public void updateProduct(int id, String newName, double newPrice, String newRegion) {
        for (Product product : productList) {
            if (product.getId() == id) {
                product.setName(newName);
                product.setPrice(newPrice);
                product.setRegion(newRegion);
            }
        }
    }

    /**
     * Deletes products from the InMemory repository.
     * @param id
     */
    public void deleteProduct(int id) {
        productList.removeIf(product -> product.getId() == id);
    }

    // CRUD Character

    /**
     * Adds character to the InMemory repository.
     * @param character
     */
    public void addCharacter(model.Character character) {
        characterList.add(character);
    }

    /**
     * Gets all characters from the InMemory repository.
     * @return
     */
    public List<model.Character> getCharacterList() {
        return characterList;
    }

    /**
     * Updates characters from the InMemory repository.
     * @param id
     * @param newName
     * @param newRegion
     */
    public void updateCharacter(int id, String newName, String newRegion) {
        for (model.Character character : characterList) {
            if (character.getId() == id) {
                character.setName(newName);
                character.setRegion(newRegion);
            }
        }
    }

    /**
     * Deletes characters from the InMemory repository.
     * @param id
     */
    public void deleteCharacter(int id) {
        characterList.removeIf(character -> character.getId() == id);
    }

    // Helper method: buy

    /**
     * Helper method in order for characters to buy products.
     * @param characterID
     * @param productID
     */
    public void buyProducts(int characterID, int productID) {
        for (model.Character character : characterList) {
            if (character.getId() == characterID) {
                for (Product product : productList) {
                    if (product.getId() == productID) {
                        character.getProducts().add(product);
                    }
                }
            }
        }
    }

    // Filter: characters by region

    /**
     * Filter region by region (user input from view).
     * @param region
     * @return
     */
    public List<model.Character> filterCharactersByRegion(String region) {
        List<model.Character> filteredList = new ArrayList<>();
        for (model.Character character : characterList) {
            if (character.getRegion().equals(region)) {
                filteredList.add(character);
            }
        }
        return filteredList;
    }

    // Filter: characters by product's region

    /**
     * Filters characters that have bought products from a specific region (user input from view).
     * @param region
     * @return
     */
    public List<model.Character> filterCharacterByProductRegion(String region) {
        List<model.Character> filteredCustomers = new ArrayList<>();
        for (model.Character character : characterList) {
            for (Product product : character.getProducts()) {
                if (product.getRegion().equals(region)) {
                    filteredCustomers.add(character);
                }
            }
        }
        return filteredCustomers;
    }

    // Sort: character's products in ascending/descending order

    /**
     * Sorts a character's products in ascending/descending order.
     * @param characterID
     * @param ascending
     * @return
     */
    public List<Product> sortCharactersProducts(int characterID, boolean ascending) {
        for (Character character : characterList) {
            if (character.getId() == characterID) {
                List<Product> sortedFilms = new ArrayList<>(character.getProducts());
                if (ascending) {
                    sortedFilms.sort(Comparator.comparing(Product::getPrice));
                } else {
                    sortedFilms.sort(Comparator.comparing(Product::getPrice).reversed());
                }
                return sortedFilms;
            }
        }
        return new ArrayList<>();
    }

}
