class Controller:
    def __init__(self, repo):
        self.repo = repo

    def sortStudents(self):
        return sorted(self.repo.students)

    def addStudent(self, student):
        self.repo.add(student)