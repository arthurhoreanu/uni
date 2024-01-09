import json


class DataRepo:
    def __init__(self, file):
        self._data = []
        self._file = file

    def add(self, cooked_dish):
        self._data.append(cooked_dish)

    def get_all(self):
        return self._data


    def get_by_id(self, id):
        return next(filter(lambda entity: entity.id == id, self._data), None)

    def delete_by_id(self, id):
        self._data = list(filter(lambda entity: entity.id != id, self._data))

    def update_by_id(self, id, new_entity):
        self._data = [new_entity if entity.id == id else entity for entity in self._data]

    def read_file(self):
        with open(self._file) as inputfile:
            dictionary_list_from_json = json.load(inputfile)
            self._data = self.convert_from_string(dictionary_list_from_json)

    def write_to_file(self):
        with open(self._file, 'w') as outfile:

            json.dump(self.convert_to_string(self.get_all()), outfile, indent=5)


    def convert_to_string(self, object_list):
        pass


    def convert_from_string(self, dictionary_list_from_json):
        pass