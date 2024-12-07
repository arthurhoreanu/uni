package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

public class BookManagementApp {

    private static final String DB_URL = "jdbc:mysql://localhost:3306/db";
    private static final String DB_USER = "user";
    private static final String DB_PASSWORD = "password";

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            while (true) {
                System.out.println("Choose an operation:");
                System.out.println("1. Add a new book");
                System.out.println("2. View all books");
                System.out.println("3. Update a book");
                System.out.println("4. Delete a book");
                System.out.println("5. Exit");
                int choice = scanner.nextInt();
                scanner.nextLine();

                switch (choice) {
                case 1:
                    addBook(scanner);
                    break;
                case 2:
                    viewBooks();
                    break;
                case 3:
                    updateBook(scanner);
                    break;
                case 4:
                    deleteBook(scanner);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
                }
            }
        }
    }

    private static void addBook(Scanner scanner) {
        try(Connection connection = DriverManager.getConnection(DB_URL,DB_USER,DB_PASSWORD)) {
            System.out.println("Enter title:");
            String title = scanner.nextLine();
            System.out.println("Enter author:");
            String author = scanner.nextLine();
            System.out.println("Enter ISBN:");
            String isbn = scanner.nextLine();
            System.out.println("Enter publication year:");
            int publicationYear = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            String sql =  "INSERT INTO books (title, author, isbn, publication_year) VALUES (?, ?, ?, ?)";
            try(PreparedStatement statement = connection.prepareStatement(sql)){
                statement.setString(1, title);
                statement.setString(2, author);
                statement.setString(3, isbn);
                statement.setInt(4, publicationYear);

                int executeUpdate = statement.executeUpdate();

                if(executeUpdate == 1){
                    System.out.println("Book added successfully");
                } else {
                    System.out.println("Book already exists");
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private static void viewBooks() {
        try(Connection connection = DriverManager.getConnection(DB_URL,DB_USER,DB_PASSWORD)){
            String sql = "SELECT * FROM books";

            try(PreparedStatement statement = connection.prepareStatement(sql)){
                ResultSet resultSet = statement.executeQuery();
                while (resultSet.next()){
                    System.out.println("ID: "+ resultSet.getInt("id"));
                    System.out.println("Title: "+resultSet.getString("title"));
                    System.out.println("Author: "+resultSet.getString("author"));
                    System.out.println("ISBN: "+resultSet.getString("isbn"));
                    System.out.println("Publication year: "+resultSet.getInt("publication_year"));
                    System.out.println("-----------------------------------------");
                }
            }
        } catch (SQLException e){
            throw new RuntimeException(e);
        }
    }

    private static void updateBook(Scanner scanner) {
        try(Connection connection = DriverManager.getConnection(DB_URL,DB_USER,DB_PASSWORD)){
            System.out.println("Enter the ID of the book to update:");
            int id = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            System.out.println("Enter new title:");
            String title = scanner.nextLine();
            System.out.println("Enter new author:");
            String author = scanner.nextLine();
            System.out.println("Enter new ISBN:");
            String isbn = scanner.nextLine();
            System.out.println("Enter new publication year:");
            int publicationYear = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            String sql = "UPDATE books SET title = ?, author = ?, isbn = ?, publication_year = ? WHERE id = ?";

            try(PreparedStatement statement = connection.prepareStatement(sql)){
                statement.setString(1, title);
                statement.setString(2, author);
                statement.setString(3, isbn);
                statement.setInt(4, publicationYear);
                statement.setInt(5, id);

                int executeUpdate = statement.executeUpdate();

                if(executeUpdate == 1){
                    System.out.println("Book updated successfully");
                }else {
                    System.out.println("Book not found");
                }
            }
        }catch (SQLException e){
            throw new RuntimeException(e);
        }
    }

    private static void deleteBook(Scanner scanner) {
        try(Connection  connection = DriverManager.getConnection(DB_URL,DB_USER,DB_PASSWORD)){
            System.out.println("Enter the ID of the book to update:");
            int id = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            String sql = "DELETE FROM books WHERE id = ?";

            try(PreparedStatement statement = connection.prepareStatement(sql)){
                statement.setInt(1, id);
                statement.executeUpdate();
            }

        } catch (SQLException e){
            throw new RuntimeException(e);
        }
    }
}