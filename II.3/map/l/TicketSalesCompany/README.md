# TicketSalesCompany
Imagine you're a devoted fan of music and sports, always searching for your next unforgettable experience. Maybe your favorite band is finally coming to your city, or perhaps that star athlete you admire is set to compete in a high-stakes game nearby. But how do you keep track of it all? Enter our ticket sales company – your ultimate companion for staying right at the heart of the action.

## AccountService
To get started, users need to create an account by entering a username, password, and email address. The email domain determines whether the account created is a customer or admin account: corporate domain emails automatically create admin accounts (createAccount). Once an account is created, users can log in (login) and log out (logout) as needed. If a user decides to close their account, they can delete it at any time (deleteUser).

## User: Customer and Admin
There are two main types of users in the system: customers and admins, both derived from a base User class through inheritance.

Customer: Each customer has a shopping cart and can mark events, artists, and athletes as favorites (addToFavourites). Customers can also view their order history (viewOrderHistory) and cancel their current order (cancelOrder).

Admin: Admins have permissions to create and update events, artists, and athletes (manageEvent, manageArtist, and manageAthlete). They can also search for users by username (findUserByUsername) and retrieve a list of all users (getAllUsers).

## Event: Concert and SportsEvent
Event is an abstract class representing a generic event. Admins can create specific types of events, such as Concert or SportsEvent. Key features include:
Ticket Availability: Customers can check if tickets are available (getAvailableTickets). If tickets are sold out, a "sold out" notification is triggered (isSoldOut).
Event Status: Events can have one of three statuses: SCHEDULED, CANCELLED, or COMPLETED.

## Artist and Athlete
Each Artist and Athlete has a profile that customers can mark as a favorite. Within the profile, customers can view upcoming and past events associated with the artist or athlete (showEventList), with the option to filter by event status.

## Venue, Section and Seat
Events take place in designated Venues, which are divided into Sections, each containing multiple Seats.
Venue: Holds information about the location and capacity.
Section: Represents different areas in the venue and provides methods for checking available seats (getAvailableSeats).
Seat: Each seat has a unique identifier and can be reserved if purchased. Our system recommends the best available seats based on customer preferences (recommendedSeat) and marks purchased seats as reserved (markAsReserved).

## Ticket and ShoppingCart
Tickets are associated with seats and come in three types: STANDARD, VIP, and EARLY_ACCESS.

ShoppingCart: Customers can add or remove tickets (addTicket and removeTicket). When checking out, the system calculates the total price (calculateTotalPrice) and processes the purchase (checkout). Customers can also clear their cart if they wish to remove all items (clear).

## Order and PaymentProcessor
Upon checkout, a new Order is automatically created:

Order: Stores information about the customer's purchase, including ticket details and purchase date.
PaymentProcessor: Handles payment validation (validatePaymentDetails) and processes transactions (processPayment). After payment is confirmed, the customer receives a summary of their processed order (showProcessedOrder).

## Notificationt
The Notification interface is implemented by both the Event and ShoppingCart classes, using an Observer Design Pattern. Events and the shopping cart act as subjects, while Notification serves as the observer.

Event Notifications: Notifies customers when an event is almost sold out.
ShoppingCart Notifications: Alerts customers if a ticket in their shopping cart is reserved by another user in the meantime.
These notifications ensure customers stay informed about event availability and ticket status in real-time.

## UML
![TicketSalesCompany-2024-10-29-210642](https://github.com/user-attachments/assets/28d82a0c-89db-4c60-a3cb-9b1339dd6347)
