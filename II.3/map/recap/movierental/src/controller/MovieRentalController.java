package controller;

import model.Customer;
import model.Film;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MovieRentalController {

    private List<Film> filmList = new ArrayList<>();
    private List<Customer> customerList= new ArrayList<>();

    // CRUD Film
    public void addFilm(Film film) {
        filmList.add(film);
    }

    public List<Film> getFilms() {
        return filmList;
    }

    public void updateFilm(int id, String newTitle, String newDirector, String newGenre, double newPrice) {
        for (Film film : filmList) {
            if (film.getId() == id) {
                film.setTitle(newTitle);
                film.setDirector(newDirector);
                film.setGenre(newGenre);
                film.setPrice(newPrice);
            }
        }
    }

    public void deleteFilm(int id) {
        for (Film film : filmList) {
            if (film.getId() == id) {
                filmList.remove(film);
            }
        }
    }

    // CRUD Customer
    public void addCustomer(Customer customer) {
        customerList.add(customer);
    }

    public List<Customer> getCustomers() {
        return customerList;
    }

    public void updateCustomer(int id, String newName) {
        for (Customer customer : customerList) {
            if (customer.getId() == id) {
                customer.setName(newName);
            }
        }
    }

    public void deleteCustomer(int id) {
        customerList.removeIf(customer -> customer.getId() == id);
    }

    // buyFilms
    public void buyFilms(int customerID, int filmID) {
        for (Customer customer : customerList) {
            if (customer.getId() == customerID) {
                for (Film film : filmList) {
                    if (film.getId() == filmID) {
                        customer.getFilms().add(film);
                    }
                }
            }
        }
    }

    // filterFilmsByGenre
    public List<Film> filterFilmsByGenre(String genre) {
        List<Film> filteredList = new ArrayList<>();
        for (Film film : filmList) {
            if (film.getGenre().equals(genre)) {
                filteredList.add(film);
            }
        }
        return filteredList;
    }

    // filterCustomerByDirector
    public List<Customer> filterCustomerByDirector(String director) {
        List<Customer> filteredCustomers = new ArrayList<>();
        for (Customer customer : customerList) {
            for (Film film : customer.getFilms()) {
                if (film.getDirector().equals(director)) {
                    filteredCustomers.add(customer);
                }
            }
        }
        return filteredCustomers;
    }

    // sort FilmsByPrice
    public List<Film> sortFilmsByPrice(int customerID, boolean ascending) {
        for (Customer customer : customerList) {
            if (customer.getId() == customerID) {
                List<Film> sortedFilms = new ArrayList<>(customer.getFilms());
                if (ascending) {
                    sortedFilms.sort(Comparator.comparing(Film::getPrice));
                } else {
                    sortedFilms.sort(Comparator.comparing(Film::getPrice).reversed());
                }
                return sortedFilms;
            }
        }
        return new ArrayList<>();
    }

}
