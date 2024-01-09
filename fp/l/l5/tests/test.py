from model.Kunde import Customer
from repository.customer_repo import CustomerRepo
from repository.data_repo import DataRepo

def test():
    match = CustomerRepo.find_by_name('customers.json', 'Bob')
    assert len(match) != 0

    match = CustomerRepo.find_by_address('customers.json', 'Florilor 12')
    assert len(match) != 0

test()