from model.Kunde import Customer
from repository.customer_repo import CustomerRepo
from repository.data_repo import DataRepo

def test():

    match = CustomerRepo.find_by_name('customers.json', 'Bob')
    assert len(match) != 0

    match = CustomerRepo.find_by_address('customers.json', 'Florilor 12')
    assert len(match) != 0

    data_repo = DataRepo()
    data_repo._data = [
        Customer(id=501, name='Bob', address='Florilor 5'),
        Customer(id=502, name='Tom', address='Florilor 48'),
        Customer(id=503, name='Tim', address='Florilor 12')
    ]

    new_customer = Customer(id=501, name='Bobby', address='Florilor 5')
    data_repo.update_by_id(501, new_customer)
    updated_customer = next((entity for entity in data_repo._data if entity.id == 501), None)
    assert updated_customer is not None

    total_for_order = order.calculate_total()
    customer_id = 311
    expected_total_for_customer_311 = "72.7"
    assert total_for_order == expected_total_for_customer_311

    file_path = "orders.json"
    with open(file_path, "w") as file:
        json.dump(bestellung.__dict__, file)
    with open(file_path, "r") as file:
        deserialized_bestellung = json.load(file)
    assert deserialized_bestellung == bestellung.__dict__

test()