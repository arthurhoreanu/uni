class Identifiable:
    def __init__(self, id: int):
        self._id = id

        if type(self) == Identifiable:
            raise NotImplementedError("Abstract class cannot be instantiated")

    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, value):
        self._id = value