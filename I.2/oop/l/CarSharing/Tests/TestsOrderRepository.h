#ifndef TESTSORDERREPOSITORY_H
#define TESTSORDERREPOSITORY_H

#include "../Repository/OrderRepository.h"

class TestsOrderRepository {
public:
    void testAllOR();
private:
    void testSaveOrder(OrderRepository &repository); // Test saving an order
    void testUpdateOrder(OrderRepository &repository); // Test updating an order
    void testDeleteOrder(OrderRepository &repository); // Test deleting an order
    void testSearchOrder(OrderRepository &repository); // Test searching an order by ID
    void testListAllOrders(OrderRepository &repository); // Test listing all orders
};

#endif // TESTSORDERREPOSITORY_H
