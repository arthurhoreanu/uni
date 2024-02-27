from ex4.account import Account

def test_cash_out():
    bankAccount = Account('23', 'Arthur', 400)
    bankAccount.cash_out(200)
    assert bankAccount.sum == 200