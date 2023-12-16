import pickle

class StudentRepo:
    def __init__(self):
        self.students = []

    def add(self, student):
        self.students.append(student)

    def find(self, id):
        for student in self.students:
            if student.id == id:
                return student
        return None

class FileStudentRepository(StudentRepo):
    def __init__(self, filename):
        super().__init__()
        self.filename = filename

        def save(self):
            file = open(self.filename, 'wb')
            pickle.dump(self.students, file)
            file.close()

        def load(slef):
            file = open(self.filename, 'rb')
            self.students = pickle.load(file)
            file.close()

        def add(self, student):
            super().add(student)
            self.save()